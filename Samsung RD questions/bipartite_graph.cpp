class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int c = color[node];

                    for(int adj:graph[node]) {
                        if(color[adj] == -1) {
                            color[adj] = color[node]^1;
                            q.push(adj);
                        } else {
                            if(color[adj] == color[node]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;

    }
};
