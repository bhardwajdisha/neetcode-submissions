class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1, mp2;
        for(char c: t){
            mp1[c]++;
        }
        int right = 0,left=0,curr=INT_MAX;
        int formed = 0, required =0;
        required = mp1.size();
        pair<int,int> p = {-1,-1};
        string ans;
        while(right<s.size()){
            mp2[s[right]]++;
            if(mp1[s[right]]==mp2[s[right]]) formed++;
        
            while(formed==required && left<= right){
                if(curr>right-left+1){
                    p = make_pair(left,right);
                    curr = right-left+1;
                }
                if(mp1.count(s[left])){
                    if(mp1[s[left]]==mp2[s[left]]) formed--;
                    mp2[s[left]]--;
                }
                left++;
            }
            right++;
        }
        if(p.first==-1)
            return "";
        ans = s.substr(p.first, p.second-p.first+1);
        return ans;
    }
};
