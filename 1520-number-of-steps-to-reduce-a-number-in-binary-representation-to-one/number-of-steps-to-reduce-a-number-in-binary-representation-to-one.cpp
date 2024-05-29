class Solution {
public:
    int numSteps(string s) {
        int zeroBetweenOne = 0; // record the number of times '0' appears between '1'
        int oneCount = 0; // record the number of times 1 appears
        int strSize = s.size();

        // traverse the string from the end using a for loop
        for(int i = strSize-1; i >= 0; i--) {
            if(s[i] == '1') {
                oneCount++;
            }
            else if(oneCount > 0){
                zeroBetweenOne++;  // count '0' between '1's
            }
        }

        if(oneCount == 1) {
            return strSize - 1; // only one '1' in string, we need size-1 steps
        }
        else {
            return zeroBetweenOne + 1 + strSize; // number of add steps + origin digit length
        }
    }
};