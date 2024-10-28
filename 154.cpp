// 154. Find Minimum in Rotated Sorted Array II

// case 1:  4 5 6 7 1 2 3
// case 2:  1 2 3 4 5 6 7
// case 3:   3 3 3 1 2   
// case 4:   1 2 3 3 3 
// case 5:   3 1 3 3 3  ||  3 3 3 1 3 
class Solution {
public:
    int solve(int l,int h,vector<int>& v)
    {
        if(l==h) return l;
        int m=(l+h)/2;
        if(v[m]>v[h]) return solve(m+1,h,v);
        else if(v[l]<v[m]) return solve(l,m-1,v);
        else if(v[l]==v[m]&&v[h]!=v[m]) return solve(m,h-1,v);
        else if(v[l]!=v[m]&&v[h]==v[m]) return solve(l+1,m,v);
        else {
            int a=solve(l,m,v);
            int b=solve(m+1,h,v);
            if(v[a]<v[b]) return a;
            return b;
        }
    }
    int findMin(vector<int>& v) {
        int l=0,h=v.size()-1;
        return v[solve(l,h,v)];
    }
};
