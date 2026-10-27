class Solution {
public:
    bool isPal(int left,int right,string s){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            right--;
            left++;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left =0;
        int right = s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return (isPal(left+1,right,s) || isPal(left,right-1,s));
            }
            left++;
            right--;
        }
        return true;
    }
};