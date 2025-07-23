class Solution {
public:
    bool reach(vector<int>&a,vector<int>&b){ // checking if bombs b is in range of bombs a or not
        long long x = a[0] - b[0] ; 
        long long y = a[1] - b[1];
        long long r = a[2];
        if(x*x + y*y <= r*r){ // distance formula 
            return true;
        }else{
            return false;
        }
    }
    void dfs(int i, vector<vector<int>>&fatega, vector<bool>&vis , int &count){
        vis[i] = true;
        count++;
        for(auto j : fatega[i]){
            if(!vis[j]){
                dfs(j,fatega,vis,count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>fatega(n);

        for(int i =0;i<n;i++){
            for(int j =0 ;j<n;j++){
                if(i!=j && reach(bombs[i],bombs[j])){ // if in reach then add in fatega
                    fatega[i].push_back(j);
                }
            }
        }

        int result = 0;

        for(int i=0; i<n; i++){
            vector<bool>vis(n,false);
            int countbomb = 0;
            dfs(i,fatega,vis,countbomb);
            result = max(result,countbomb);
        }
        return result;
    }
};
