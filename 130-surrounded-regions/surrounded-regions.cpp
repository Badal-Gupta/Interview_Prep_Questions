class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m));
        queue<pair<int,int>>q;
        for(int i =0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=true;
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1] = true;
            }
        }
        for(int i =0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=true;

            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                vis[n-1][i]=true;
            }
        }
        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i =0 ;i<4;i++){
                int r = row + dir[i].first;
                int c = col + dir[i].second;
                if(r>=0 && c>=0 && r<n && c<m && !vis[r][c] && board[r][c]=='O'){
                    q.push({r,c});
                    vis[r][c] = true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==false && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};