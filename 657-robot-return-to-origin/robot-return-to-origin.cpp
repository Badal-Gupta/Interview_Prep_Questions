class Solution {
public:
    bool judgeCircle(string moves) {
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};// L,R,U,D 
        int row = 0;
        int col = 0;
        for(int i = 0; i<moves.size(); i++){
            if(moves[i] == 'L'){
                row += dir[0].first;
                col +=dir[0].second;
            }else if(moves[i]=='R'){
                row += dir[1].first;
                col +=dir[1].second;
            }else if(moves[i]=='U'){
                row += dir[2].first;
                col +=dir[2].second;
            }else{
                row += dir[3].first;
                col +=dir[3].second;
            }
        }
        if(row == 0 && col == 0){
            return true;
        }else{
            return false;
        }

    }
};