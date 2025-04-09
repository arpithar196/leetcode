class Solution {
public:
    string isP(string s,int left,int right){
        while(left>=0 && right < s.length() &&s[left]==s[right])
        {
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string strr=s.substr(0,1);
        for(int i=0;i<s.length();i++){
            string s1=isP(s,i,i);
            string s2=isP(s,i,i+1);
            if(s1.length()>strr.length())
                strr=s1;
            if(s2.length()>strr.length())
                strr=s2;
        }
        return strr;
    }
};