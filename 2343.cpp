// 2343. Query Kth Smallest Trimmed Number


#define pr pair<string,int>
//compare class for priority queue
class comp{
    public:
    bool operator() (const pr &a,const pr &b) const{
        if(a.first.size() == b.first.size()){ 
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        return a.first.size() < b.first.size();

    }
};
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        //iterating to all queries
        for(auto query: queries){
            int k = query[0]; //fetching k
            int final_len = query[1]; //fetching required trimmed length
            
            priority_queue<pr,vector<pr>,comp> pq;
            for(int i = 0; i < nums.size(); i++){
                string num = nums[i];
                string trimmed_num = num.substr(num.size() - final_len); //trimming the num using substr function, trimming will be from the leftmost
                pq.push({trimmed_num,i}); //pushing the pair in the priority_queue
            }
            
            //getting the kth smallest value
            while(pq.size() > k){
                pq.pop();
            }
            string kSmallestNum = pq.top().first; //fetching
            int idx = pq.top().second;

            //if smaller index is present for the same value
            while(pq.size() > 0 && pq.top().first == kSmallestNum && pq.top().second < idx){
                idx = pq.top().second;
                pq.pop();
            }

            //we got our answer for the query
            ans.push_back(idx);
        }
        return ans;
    }
};
