class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])){
                temp+= tolower(s[i]);
            }else if(isdigit(s[i])){
                temp+=s[i];
            }
        }
        int j = temp.size()-1, i=0;
        while(i<=j){
            if(temp[i]!=temp[j]) return false;
            i++;j--;
        }
        return true;
    }
};
