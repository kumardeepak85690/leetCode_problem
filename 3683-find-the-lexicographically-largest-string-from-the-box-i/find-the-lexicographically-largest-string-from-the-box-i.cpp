class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        
        if (numFriends == 1) {
            return word;
        }
        
        string result = "";
        
        // For each possible starting position
        for (int i = 0; i < n; i++) {
            // Calculate the maximum length we can take from position i
            // We need to leave at least (numFriends - 1) positions for other parts
            int maxLength = n - (numFriends - 1);
            
            // But we can't exceed the remaining string length from position i
            maxLength = min(maxLength, n - i);
            
            if (maxLength > 0) {
                string candidate = word.substr(i, maxLength);
                if (candidate > result) {
                    result = candidate;
                }
            }
        }
        
        return result;
    }
};