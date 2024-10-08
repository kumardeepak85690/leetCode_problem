class Solution {
public:
    int minSwaps(string brackets) {
        int swapCount = 0;  // Stores the number of swaps needed
        int imbalance = 0;  // Tracks the imbalance between opening and closing brackets
        
        // Traverse the string to check for imbalance
        for(char bracket : brackets) {
            if(bracket == ']') {  // When we encounter a closing bracket
                if(imbalance == 0) {  // No matching opening bracket
                    swapCount++;  // Need a swap
                    imbalance++;  // Adjust imbalance to account for the swap
                } else {
                    imbalance--;  // A matching opening bracket is available, so balance out
                }
            } else {
                imbalance++;  // Encountered an opening bracket, increase the imbalance
            }
        }
        
        return swapCount;  // Return the total number of swaps needed
    }
};