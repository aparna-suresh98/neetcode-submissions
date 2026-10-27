class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int left = 0;
        int right = 0;
        while(left < word1.size() || right < word2.size()){
            if(left < word1.size()){
                ans+=word1[left];
                left++;
            }
            if(right<word2.size()){
                ans+=word2[right];
                right++;
            }
            
        }

        return ans;
    }
};