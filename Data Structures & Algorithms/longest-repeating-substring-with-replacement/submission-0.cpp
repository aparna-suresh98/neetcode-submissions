class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0, maxFreq=0, best =0;
        unordered_map<char,int> freq;
        for(int right=0; right < s.size();right++){
            freq[s[right]]++;
            maxFreq=max(maxFreq,freq[s[right]]);
            while(((right-left+1)-maxFreq) > k){
                freq[s[left]]--;
                left++;
            }
            best = max(best,right-left+1);
        }
        return best;
    }
};
