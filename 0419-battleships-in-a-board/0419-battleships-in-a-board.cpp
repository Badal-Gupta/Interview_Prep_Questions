class Solution {
public:
    // void dfs(vector<vector<char>>&arr , int row , int col , int n , int m , vector<vector<bool>>&vis){
    //     if(row<0 || col<0 || row>=n || col >=m || vis[row][col] || arr[row][col]=='.'){
    //         return ;
    //     }
    //     vis[row][col]=true;
    //     vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    //     for(int i = 0 ;i <4;i++){
    //         int nr = row + dir[i].first;
    //         int nc = col + dir[i].second;
    //         dfs(arr,nr,nc,n,m,vis);
    //     }
    // }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i==0 && j==0 && board[i][j]=='X'){
                    count++;
                }
                if(i==0 && j>0 && board[i][j]=='X'&& board[i][j-1]!='X'){
                    count++;
                }
                if(i>0 && j==0 && board[i][j]=='X' && board[i-1][j]!='X'){
                    count++;
                }
                if(i>0 && j>0 && board[i][j]=='X'&& board[i-1][j]!='X' && board[i][j-1]!='X'){
                    count++;
                }
            }
        }
        return count;
    }
};