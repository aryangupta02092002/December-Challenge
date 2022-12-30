class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &tmp, int start, int end){
        if(start == end){
            ans.push_back(tmp);
            return;
        }
        for(auto e : graph[start]){
            tmp.push_back(e);
            dfs(graph, ans, tmp, e, end);
            tmp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int mx = 0;
        for(int i=0; i<graph.size(); i++){
            for(int j=0; j<graph[i].size(); j++){
                mx = max(mx, graph[i][j]);
            }
        }
        vector<int> tmp = {0};
        dfs(graph, ans, tmp, 0, mx);
        return ans;
    }
};
