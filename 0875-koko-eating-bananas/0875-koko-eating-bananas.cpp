class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end()); 
        while(low<=high){
            long long total = 0;
            int mid = (low+high)/2;
            for(int  i : piles){
                total+= (i+mid-1)/mid;
            }
            if(total<=h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};