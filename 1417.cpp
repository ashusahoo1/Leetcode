//1417. Reformat The String



class Solution {
public:
    string reformat(string s) {
        string num;
        string alpha;
        string ans;
        if(s.length()==1)
          return s;

        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
              alpha.push_back(s[i]);
            else
              num.push_back(s[i]);
        }
        
       int y = abs(static_cast<int>(alpha.length()) - static_cast<int>(num.length()));

        if(y>=2)
          return ans;

        if(num.length()==0||alpha.length()==0)
           return ans;

        int k=0;
        int l=0;

        bool p=false;


        if(alpha.length()>num.length())
        {
            p=true;
        }
        



        for(int i=0;i<min(alpha.length(),num.length());i++)
        {
            if(p==true)
            {
                ans.push_back(alpha[l++]);
                ans.push_back(num[k++]);

            }
            else
           { ans.push_back(num[k++]);
            ans.push_back(alpha[l++]);}
        }
        if(alpha.length()==num.length())
           return ans;


        if(p==true)
        {
              ans.push_back(alpha[l]);
        }
        else
        {
            ans.push_back(num[k]);
        }
        
        return ans;
    }
};
