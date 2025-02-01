class Solution {
public:
    bool search(int index,int i,int j,int n,int m,vector<vector<char>>&board, string word){
        if(index == word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$'){
            return false;
        }
        if(word[index]!=board[i][j]){
            return false;
        }
        char temp  = board[i][j];
        board[i][j]='$';
        if(search(index+1,i+1,j,n,m,board,word)||search(index+1,i-1,j,n,m,board,word)||search(index+1,i,j+1,n,m,board,word)||search(index+1,i,j-1,n,m,board,word)){
            return true;
        }
        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i =0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(word[0]==board[i][j]&& search(0, i ,j, n,m , board, word)){
                    return true;
                }
            }
        }
        return false;
    }
};