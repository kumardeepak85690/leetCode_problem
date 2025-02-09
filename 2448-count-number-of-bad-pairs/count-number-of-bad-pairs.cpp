class Solution {
public:
    long countBadPairs(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        long good = 0;

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] - i;
            good += freq[key]; // Get the count of good pairs for this key
            freq[key]++; // Increment the count for this key
        }

        long totalPairs = static_cast<long>(nums.size()) * (nums.size() - 1) / 2; // Total pairs (i, j) with i < j
        return totalPairs - good; // Bad pairs = Total pairs - Good pairs
    }
};