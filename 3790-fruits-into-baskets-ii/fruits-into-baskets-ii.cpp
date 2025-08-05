class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int count = 0;
        for(int i=0;i<n;i++){
            bool a = false;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=-1;
                    a=true;
                    break;
                }
            }
            if(!a){
                count++;
            }
        }
            return count;
    }
};