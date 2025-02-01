class Solution {
public:
    bool safehai(int row,int col,vector<string>&board,int n){
        int a=row;
        int b=col;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        col=b;
        row=a;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=a;
        col=b;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            col--;
            row++;
        }
        return true;
    }

    void queen(int col,int n, vector<string>&board,vector<vector<string>>&result){
        if(col==n){
            result.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(safehai(i,col,board,n)){
                board[i][col]='Q';
                queen(col+1,n,board,result);
                board[i][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result ; 
        vector<string>board(n);
        string s (n,'.');
        for(int i=0; i<n;i++){
            board[i]=s;
        }
        queen(0,n,board,result);
        return result;
    }
};