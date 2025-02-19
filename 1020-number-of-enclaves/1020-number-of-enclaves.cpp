class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[i][0]==1){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(board[i][m-1]==1){
                vis[i][m-1]=1;
                q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]==1){
                vis[0][i]=1;
                q.push({0,i});
            }
            if(board[n-1][i]==1){
                vis[n-1][i]=1;
                q.push({n-1,i});
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&!vis[nr][nc]&&board[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1&&!vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};