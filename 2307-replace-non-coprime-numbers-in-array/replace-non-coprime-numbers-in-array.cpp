class Solution {
public:
    static inline int gcd(int x, int y){
        int bz=min(__builtin_ctz(x), __builtin_ctz(y));
        if (bz>0) return gcd(x>>bz, y>>bz)<<bz;
        int r=x%y;
        return r?gcd(y, r):y;
    }
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        int top=-1;
        for (int x : nums) {
            int cur=x;
            while (top!=-1) {
                int g=gcd(nums[top], cur);
                if (g==1) break;
                // the following can replace by cur=nums[top]/g*cur;
                // which computes lcm directly, 
                // no need for function lcm thanks to @hj-core
                cur=lcm(nums[top], cur);
                top--;// pop 
            }
            nums[++top]=cur;
        }
        nums.resize(top+1);
        return nums;
    }
};