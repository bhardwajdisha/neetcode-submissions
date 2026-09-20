class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
        if(s1!=t1) return false;
        unordered_map<char,int> mp1, mp2;
        for(char c:s) mp1[c]++;
        for(char c:t) mp2[c]++;
        if(mp1==mp2) return true;
        return false;
    }
};
