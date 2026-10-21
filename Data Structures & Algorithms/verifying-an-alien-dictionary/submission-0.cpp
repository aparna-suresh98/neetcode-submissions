class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.empty()) return false;
        
        int rank[26];                //create a rank array with the order in the alphabetic
        for(int i=0;i<26;i++){
            rank[order[i]-'a'] = i;
        }

        string first = words[0];
        for(int i=1;i<words.size();i++){
            string next = words[i];
            int j=0;

            //loop till the alphabet is same
            while(j<first.size() && j<next.size() && first[j] == next[j]){
                j++;
            }

            //check the size
            if(j == first.size() || j == next.size()){
                if(first.size() > next.size()) return false;
            } else if (rank[first[j]-'a'] > rank[next[j]-'a']) {
                return false;
            }
            first = next;

        }
        return true;
    }
};