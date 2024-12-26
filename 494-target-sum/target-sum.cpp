class Solution {
public:
    void computeSums(const vector<int>& nums, int start, int end,  vector<long long>& sums) {
        sums.push_back(0);
        for (int i = start; i < end; ++i) {
            int num = nums[i];
            int n = sums.size();
            for (int j = 0; j < n; ++j) {
                sums.push_back(sums[j] + num);
                sums[j] -= num;
            }
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int mid = n / 2;
        vector<long long> sums1;
        vector<long long> sums2;
        computeSums(nums, 0, mid, sums1);
        computeSums(nums, mid, n, sums2);
        unordered_map<long long, long long> countMap;
        for (auto sum : sums2) {
            countMap[sum]++;
        }
        long long total = 0;
        for (auto sum : sums1) {
            long long complement = (long long)target - sum;
            if (countMap.find(complement) != countMap.end()) {
                total += countMap[complement];
            }
        }

        return total;
    }
};