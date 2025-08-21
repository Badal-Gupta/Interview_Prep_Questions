class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int k = -1;
        for(int i = n-1 ; i>0 ; i--){
            if(arr[i]>arr[i-1]){
                k = i-1;
                break;
            }
        }
        if(k==-1){
            reverse(arr.begin(),arr.end());
            return;
        }

        int a = arr[k];
        int mini = k+1;
        for(int i = k ;i<n;i++){
            if(arr[i]<=arr[mini] && arr[i]>a){
                mini = i;
            }
        }
        swap(arr[k],arr[mini]);
        reverse(arr.begin()+k+1, arr.end());



    }
};