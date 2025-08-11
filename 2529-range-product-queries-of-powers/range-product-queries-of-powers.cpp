class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long>a;
        long long b = 1;
        while(n){
            if(n%2==1){
                a.push_back(b);
            }
            n = n/2;
            b = b*2;
        }
        vector<int>result;
        for(auto i: queries){
            int cur = 1;
            for(int j = i[0];j<=i[1];j++){
                cur = cur*a[j]%(1000000007);
            }
            result.push_back(cur);
        }

        return result;

    }
};