class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '[' || c == '(' || c == '{'){
                st.push(c);
            } else {
                if(st.empty()) return false;
                int t = st.top();
                st.pop();
                if(c == ']' && t != '[') return false;
                if(c == ')' && t != '(') return false;
                if(c == '}' && t != '{') return false;
            }
        }
        return st.empty();
    }
};
