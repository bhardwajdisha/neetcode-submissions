class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0,r = height.size()-1;
        int ans=0;
        int maxH = max(height[l],height[r]);
        while(l<r){
            if(height[l]<maxH){
                ans = max(ans,(r-l)* height[l]);
                l++;
                maxH = max(height[l],maxH);
            }else{
                ans = max(ans,(r-l)*height[r]);
                r--;
                maxH = max(maxH,height[r]);
            }
        }
        return ans;
    }
};
