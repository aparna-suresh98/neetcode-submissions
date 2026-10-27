class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left =0;
        int best =0;
        for(int right=0;right<s.size();right++){
            count[s[right]-'A']++;
            int max_freq = *max_element(count.begin(),count.end());
            while((right-left+1)-max_freq > k){
                count[s[left]-'A']--;
                left++;
                max_freq = *max_element(count.begin(),count.end());
            }
            best = max(best,right-left+1);
        }
        return best;
    }
};
