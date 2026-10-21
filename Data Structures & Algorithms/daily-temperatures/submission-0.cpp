class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> result(N,0);
        stack<int>st;

        for(int i =0; i<N;i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                result[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
};
