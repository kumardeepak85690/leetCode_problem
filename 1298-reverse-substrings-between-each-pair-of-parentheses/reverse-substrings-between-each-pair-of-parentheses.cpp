class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> charStack; 
        
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (charStack.top() != '(') {
                    temp += charStack.top();
                    charStack.pop();
                }
                charStack.pop(); 
                
                for (char rc : temp) {
                    charStack.push(rc);
                }
            } 
            else {
                charStack.push(c);
            }
        }
        
        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }
        
        return result;
    }
};