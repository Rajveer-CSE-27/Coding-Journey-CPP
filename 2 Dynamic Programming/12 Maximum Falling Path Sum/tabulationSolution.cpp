/**
Problem Statement : We are given an ‘N*M’ matrix. 
					We need to find the maximum path sum from any cell of the first row to any cell of the last row.
					At every cell we can move in three directions: 
					to the bottom cell (↓), to the bottom-right cell(↘), or to the bottom-left cell(↙).
                    
Approach : Using tabulation over memoization to save recursion space. 

Time Complexity = O(m * n) because each cell of the grid needs to be calculated only once.
Space Complexity = O(m * n) dp space
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<int>> dp(n, vector<int>(m));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	
	dp[n-1] = grid[n-1];
	for(int currentRow = n-2; currentRow >=0; currentRow--) {
		for(int j=0; j<m; j++) {
			int direction1 = INT_MIN, direction2 = INT_MIN, direction3 = INT_MIN;
			if(j > 0) {
				direction1 = dp[currentRow + 1][j-1];
			}
			
			direction2 = dp[currentRow + 1][j];
			
			if(j < m-1) {
				direction3 = dp[currentRow + 1][j+1];
			}
			
			dp[currentRow][j] = grid[currentRow][j] + max(direction1, max(direction2, direction3));
		}
	}
	
	int maxPathSum = INT_MIN;
	for(int j=0; j<m; j++) {
		maxPathSum = max(maxPathSum, dp[0][j]);
	}
	
	cout << maxPathSum << '\n';
	return 0;
}
