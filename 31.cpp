//31. Next Permutation



class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(v[i] < v[i+1])
            {
                idx=i;
                break;
            }
        }

        if(idx==-1)
        {
            reverse(v.begin(),v.end());
            return;
        }
        
        reverse(v.begin()+idx+1,v.end());

        int j=idx;
        
        while(j<n-1)
        {
            if(v[j]>v[idx])
            break;
            j++;
        }

        int t = v[idx];
        v[idx] = v[j];
        v[j]    = t;

        return;
    }
};
