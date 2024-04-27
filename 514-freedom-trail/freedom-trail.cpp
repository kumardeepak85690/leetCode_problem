class Solution {
private:
    // Recursive function to perform DFS with memoization
    int dfs(int index, int pos, int n, int m, unordered_map<char, vector<int>>& adj, string key, vector<vector<int>>& dp) {
        // Base Case: If we have processed all characters in the key
        if (index >= m) {
            return 0;
        }
        
        // Check if we have already computed the result for the current position and index
        if (dp[index][pos] != -1) {
            return dp[index][pos]; // Return the memoized result
        }
        
        int min_steps = INT_MAX;
        
        // Iterate over the positions of the current character in the ring
        for (auto it : adj[key[index]]) {
            int steps;
            // Calculate the minimum steps required to move from the current position to 'it'
            if (it >= pos) {
                steps = min(it - pos, pos + n - it);
            } else {
                steps = min(pos - it, it + n - pos);
            }
            // Recursively calculate the minimum steps required for the remaining characters
            min_steps = min(min_steps, (steps + dfs(index + 1, it, n, m, adj, key, dp)));
        }
        
        // Memoize the result and return
        return dp[index][pos] = min_steps + 1; // Add 1 for pressing 'Enter'
    }
    
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(); // Size of the ring
        int m = key.size();  // Size of the key
        unordered_map<char, vector<int>> adj; // Adjacency list to store positions of characters
        
        // Creating a position map (adjacency list)
        for (int i = 0; i < n; i++) {
            adj[ring[i]].push_back(i);
        }
        
        // Initialize the memoization table with -1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // Start DFS from index 0, position 0
        return dfs(0, 0, n, m, adj, key, dp);
    }
};