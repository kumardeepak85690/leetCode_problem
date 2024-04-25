class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        long temp = x;
        long rev=0;
        while(temp!=0){
            int ld=temp%10;
            rev= (rev*10)+ld;
            temp=temp/10;
        }
        if(x==rev){
            return true;
        }
        return false;
    }
};