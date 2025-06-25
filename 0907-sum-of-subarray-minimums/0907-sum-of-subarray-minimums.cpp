class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> st1, st2;

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] > arr[i])
                st1.pop();
            if (st1.empty())
                left[i] = i + 1;
            else
                left[i] = i - st1.top();
            st1.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();
            if (st2.empty())
                right[i] = n - i;
            else
                right[i] = st2.top() - i;
            st2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % mod;
        }
        return res;
    }
};
