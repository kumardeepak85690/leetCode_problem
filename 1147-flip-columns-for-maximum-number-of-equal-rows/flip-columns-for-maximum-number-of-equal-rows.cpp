class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> mp;

        for(const auto& row : matrix){
            string temp = "";
            for(int j = 0; j < m; ++j){
                temp += (row[j] == row[0] ? '1' : '0');
            }
            mp[temp]++;
        }

        int maxi = 0;
        for(auto it : mp){
            maxi = max(maxi, it.second);
        }

        return maxi;
    }
};