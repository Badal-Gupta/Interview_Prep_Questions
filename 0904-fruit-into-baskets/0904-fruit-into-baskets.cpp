class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int n = arr.size(); 
        unordered_map<int,int>mp;
        int s = 0;
        int count = 0;
        int max=INT_MIN;
        for(int i =0;i<n;i++){
            if(mp.size()<2){
                mp[arr[i]]++;
                count++;
                if(count>max)max=count;
            }else{
                if(mp.count(arr[i])){
                    mp[arr[i]]++;
                    count++;
                    if(count>max)max=count;
                }else{
                    mp[arr[i]]++;
                    count++;
                    while(mp.size()>2){
                        mp[arr[s]]--;
                        if(mp[arr[s]]==0){
                            mp.erase(arr[s]);
                        }
                        s++;
                        count--;               
                    }
                    if(count>max)max=count;
                }
            }
        }
        return max;
    }
};