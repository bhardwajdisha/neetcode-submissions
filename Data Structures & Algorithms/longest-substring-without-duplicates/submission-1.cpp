class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,ans=0;
        unordered_map<char,int> mp;
        for(int r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                l = max(mp[s[r]]+1,l);
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
