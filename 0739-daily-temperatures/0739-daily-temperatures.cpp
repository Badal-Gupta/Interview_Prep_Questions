class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                int index = st.top();
                st.pop();
                ans[index] = i - index; 
            }
            st.push(i);
        }

        return ans;
    }
};
