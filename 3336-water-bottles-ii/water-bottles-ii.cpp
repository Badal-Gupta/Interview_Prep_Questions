class Solution {
public:
    int maxBottlesDrunk(int bottle, int rate) {
        int empty = bottle;
        int result = bottle;
        while(empty>=rate){
            empty = empty - rate ;
            rate++;
            result++;
            empty++;
        }
        return result;
    }
};