class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int>result;
        int count = 0;
        for(int i=0;i<n;i++){
            int j = 0;
            int a = i;
            count++;
            vector<int>b;
            while(j<=i && a>=0){
                b.push_back(mat[a][j]);
                j++;
                a--;  
            }
            if(count%2!=1){
                reverse(b.begin(),b.end());
                for(auto k : b){
                    result.push_back(k);
                }
            }else{
                for(auto k : b){
                    result.push_back(k);
                }
            }

        }
        for(int j = 1 ; j<m;j++){
            int a = n-1;
            int l = j;
            count++;
            vector<int>b;
            while(l<m && a>=0){
                b.push_back(mat[a][l]);
                l++;
                a--;
            } 
            if(count%2!=1){
                reverse(b.begin(),b.end());
                for(auto k : b){
                    result.push_back(k);
                }
            }else{
                for(auto k : b){
                    result.push_back(k);
                }
            }
        }
        return result;

    }
};