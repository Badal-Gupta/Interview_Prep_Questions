// class Solution {
// public:
//     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<int>result;
//         int count = 0;
//         for(int i=0;i<n;i++){
//             int j = 0;
//             int a = i;
//             count++;
//             vector<int>b;
//             while(j<=i && a>=0 && j<m){
//                 b.push_back(mat[a][j]);
//                 j++;
//                 a--;  
//             }
//             if(count%2!=1){
//                 reverse(b.begin(),b.end());
//                 for(auto k : b){
//                     result.push_back(k);
//                 }
//             }else{
//                 for(auto k : b){
//                     result.push_back(k);
//                 }
//             }

//         }
//         for(int j = 1 ; j<m;j++){
//             int a = n-1;
//             int l = j;
//             count++;
//             vector<int>b;
//             while(l<m && a>=0){
//                 b.push_back(mat[a][l]);
//                 l++;
//                 a--;
//             } 
//             if(count%2!=1){
//                 reverse(b.begin(),b.end());
//                 for(auto k : b){
//                     result.push_back(k);
//                 }
//             }else{
//                 for(auto k : b){
//                     result.push_back(k);
//                 }
//             }
//         }
//         return result;

//     }
// };
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        vector<int> ans;

        int i = 0;
        int j = 0;

        bool upward = true;

        while(ans.size() < row*col){
            ans.push_back(mat[i][j]);

            if(upward){

                if(j == col -1 ){
                    i++;
                    upward = false;
                }else if(i == 0){
                    j++;
                    upward = false;
                }else{
                    i--; j++;
                }
            }else{

                if(i == row - 1){
                    j++;
                    upward = true;
                }else if(j == 0){
                    i++;
                    upward = true;
                }else{
                    i++;
                    j--;
                }
            }


            
        }


        return ans;
    }
};