//841. Keys and Rooms


class Solution {
public:
    void dfs(set<int>& visited,int src,vector<vector<int>>& rooms){
        // task (marking node as visited so we dont visit it again)
        visited.insert(src);

        // base condition 
        if(rooms[src].size()==0) return;

        for(auto room:rooms[src]){
            // skip if node is already visited
            if(visited.count(room)==0) 

                // Recursive Relation
                dfs(visited,room,rooms);
        }
        return;
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> visited;
        dfs(visited,0,rooms);
        return visited.size()== rooms.size();
        
    }
};
