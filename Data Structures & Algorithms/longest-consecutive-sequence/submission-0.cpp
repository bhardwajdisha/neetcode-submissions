class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int num:nums){
            mp.insert(num);
        }
        int curr=0,ans=0;
        for(int num: mp){
            curr=0;
            if(!mp.count(num-1)){
                while(mp.count(num)){
                    curr++;
                    num++;
                }
            }
            ans = max(curr,ans);
        }
        return ans;
    }
};
