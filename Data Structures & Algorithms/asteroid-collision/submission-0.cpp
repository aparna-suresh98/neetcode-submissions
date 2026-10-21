class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;                               // a vector works as the stack

    for (int a : asteroids) {
        bool alive = true;                        // does `a` survive?

        while (alive && a < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -a) {
                st.pop_back();                    // top explodes, `a` keeps going
            } else if (st.back() == -a) {
                st.pop_back();                    // both explode
                alive = false;
            } else {
                alive = false;                    // `a` explodes
            }
        }

        if (alive) st.push_back(a);
    }
    return st;
    }
};