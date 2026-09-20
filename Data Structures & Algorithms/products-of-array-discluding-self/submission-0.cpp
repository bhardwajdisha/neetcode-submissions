class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,1);
        pre[0] = 1;
        for(int i=0;i<n-1;i++){   
            pre[i+1] = nums[i] * pre[i];
        }
        vector<int> res;
        int suff = 1;
        for(int i=n-1;i>=0;i--){
            res.push_back(pre[i]*suff);
            suff = suff*nums[i];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
