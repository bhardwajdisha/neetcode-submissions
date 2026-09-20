class Solution {
public:
    static bool compare(const pair<int,int>& a,const pair<int,int>& b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<pair<int,int>> freq(mp.begin(), mp.end());
        sort(freq.begin(),freq.end(),compare);
        vector<int> ans;
        for(int i=0;i<freq.size()&& k>0;i++ ){
            ans.push_back(freq[i].first);
            k--;
        }
        return ans;
    }
};
