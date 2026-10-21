class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int best =0;
        unordered_set<char> window;

        for(int right=0; right < s.size();right++){
            while(window.count(s[right])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            best = max(best,right-left+1);
        }

        return best;
    }
};
