class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int arr[26];
        arr['I' - 'A'] = 1;
        arr['V' - 'A'] = 5;
        arr['X' - 'A'] = 10;
        arr['L' - 'A'] = 50;
        arr['C' - 'A'] = 100;
        arr['D' - 'A'] = 500;
        arr['M' - 'A'] = 1000;

        int total = 0;
        int pre = 0;
        int val = 0;
        for(int i = 0;i<n;i++){
            val = arr[s[i] - 'A'];
            if(val<=pre){
                total+=val;
            }else{
                total+= val - (2*pre);
            }
            pre = val;
        }
        return total;
    }
};