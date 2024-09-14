class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                ans=0;
                count=1;
                ans=max(ans,count);
            }
            else if(nums[i]==maxi){
                count++;
                ans=max(ans,count);
            }else{
                count=0;
            }
        }
        return ans;
    }
};