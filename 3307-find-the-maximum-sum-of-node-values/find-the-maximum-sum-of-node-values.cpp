class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        long long totalSum = 0;
        
        // Calculate benefits and original sum
        vector<int> benefits;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
            int benefit = (nums[i] ^ k) - nums[i];
            benefits.push_back(benefit);
        }
        
        // Sort benefits in descending order
        sort(benefits.begin(), benefits.end(), greater<int>());
        
        // Try all possible even counts of flipped nodes
        long long maxSum = totalSum;
        long long currentBonus = 0;
        
        for (int count = 0; count < n - 1; count += 2) {
            // Add benefit of flipping two more nodes
            currentBonus += benefits[count] + benefits[count + 1];
            maxSum = max(maxSum, totalSum + currentBonus);
        }
        
        return maxSum;
    }
};