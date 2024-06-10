#include <bits/stdc++.h>
using namespace std;
#define ll long long

/**
Problem link :: https://cses.fi/problemset/task/1636/

Approach :: 
        
        Example :: n = 3 :: {2,3,5} and x = 9
        
        Start from the first coin. Make two branches :: 
                    1. We use the coin ci and move further. Now in next iteration we might or might not use the same coin.
                    2. We dont use the coin ci and move further. We will never use the coin ci now.
        
        At the end if we are able to make x = 0 then increment the answer by 1.
        
        Let pair be :: (target,  currentCoin)
        
        (9,2)
        (9,3){we will not use coin with value 2 and move to coin with value = 3}, (7,2) {we use coin with value = 2 and stayed there.}
         
        Answer will be = number of valid results from (9,3) and (7,2)
        
        -> (9,3) = (9,5), (6,3)
        -> (7,2) = (7,3), (5,3).
        
        and so on tree banate jao.
        We will use dp here.
        
        For :: dp[i][sum] = number of answers that (sum, coin[i]) will generate
                          = depends on 2 things :: dp[i][sum - coins[i]] :: that is if we use coin :: ci int the sum = then dp[i][sum] += number of valid answes that can be gnerated by (sum - ci, ci)
                                                   dp[i-1][sum] :: that is if we do not use coin : ci in the sum. = then dp[i][sum] += number of valid answrs generated by (sum, c(i-1)). 

**/

int main() {
    
    int n, x;
    cin >> n >> x;
    int mod = 1e9 + 7;
    
    vector<int> coins(n+1);
    for(int i=1; i<=n; i++) {
        cin >> coins[i];
    }
    
    int dp[n+1][x+1];
    
    for(int i=1; i<=n; i++) {
        
        for(int sum =0; sum<=x; sum++) {
            
            if(sum == 0) {
                dp[i][sum] = 1;
                // setting the condition that if required sum = 0 then answer++;
            } else {
                
                // case 1:: when we will use the coin[i] in sum
                ll operation1 = 0;
                if(sum - coins[i] >= 0) {
                    operation1 = dp[i][sum - coins[i]];
                }
                
                // case 2:: when we do not use coin[i] in sum
                ll operation2 = 0;
                if(i > 1) {
                    operation2 = dp[i-1][sum];
                }
                
                ll ans = (operation1 + operation2)%mod;
                dp[i][sum] = ans;
            }
        }
    }
    
    cout << dp[n][x];
     
    return 0;
}