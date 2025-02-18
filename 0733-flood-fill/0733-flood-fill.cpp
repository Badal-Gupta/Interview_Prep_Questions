class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int a = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0 ;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==a && vis[nr][nc]!=1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc] = color;
                } 
            }
        }
        return image;
    }
};