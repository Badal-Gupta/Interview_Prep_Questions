class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int>st;
        int result = 0;
        for(int i =0;i<n;i++){
            while(!st.empty()&& height[i]>height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty()){
                    break;
                }
                int distance = i - st.top() -1;
                int width = min(height[i],height[st.top()]) - height[top];
                result+= (distance * width);
            }
            st.push(i);
        }
        return result;
    }
};