//797. All Paths From Source to Target




class Solution {
public:
    vector<vector<int>> res;
    void helper(int index, vector<vector<int>>& graph, vector<int> &path, int n)
    {
        if(path.back() == n)
        {
            res.push_back(path);
            return;
        }
        else
        {
            for(int i = 0; i < graph[index].size(); i++)
            {
                path.push_back(graph[index][i]);
                helper(graph[index][i], graph, path, n);
                path.pop_back();
            }
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size() - 1;
        vector<int> path;
        path.push_back(0);
        helper(0, graph, path, n);
        return res;
    }
};
