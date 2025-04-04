class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int start =s.size()-1;
        int end=s.size()-1;
        while(start>=0){
            string temp="";
            while(s[start]!=' ' && start>0){
                start--;
            }
            for(int i=start;i<=end;i++){
                if(s[i]!=' ')
                    temp+=s[i];
            }
            if(temp.size()>0){
                res+=res.size()>0?" "+temp:temp;
            }
            start--;
            end=start;
        }
                    
            return res;
        }
};