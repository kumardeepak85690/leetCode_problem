class Solution {
public:
    bool check(vector<int>& nums) {
        int cntD=count_if(nums.begin(), nums.end(), [&,i=-1](int x) mutable{
            return ++i==0?0:x<nums[i-1];});
        return (nums[0]>=nums.back() && cntD==1) || cntD==0;
    }
};