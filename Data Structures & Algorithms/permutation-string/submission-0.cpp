class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left=0;
        int n = s1.size(), m = s2.size();
        if(n>m) return false;
        vector<int>s1Count(26,0);
        vector<int>windowCount(26,0);

        for(int right =0;right<n;right++){
            s1Count[s1[right]-'a']++;
            windowCount[s2[right]-'a']++;
        }

        if(s1Count == windowCount) return true;

        for(int right=n; right<m;right++){
            windowCount[s2[right]-'a']++;
            windowCount[s2[right-n]-'a']--;
            
            if(s1Count == windowCount) return true;
        }
        return false;

    }
};
