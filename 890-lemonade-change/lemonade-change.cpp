class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int total = 0;
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for (int i = 0; i < bills.size(); i++) {
            bool flag = false;
            if (i == 0) {
                if (bills[i] > 5) {
                    return false;
                } else {
                    total += bills[i];
                    five++;
                }
            } else {
                int rest = bills[i] - 5;
                if (rest <= total) {
                    if (rest == 15) {
                        if (ten > 0 && five > 0){
                             flag = true;
                             ten--;
                             five--;
                        }else if(five > 2) {
                            flag = true;
                            five-=3;
                        }
                        total += 5;
                        twenty++;
                    } else if (rest == 5) {
                        if (five > 0) {
                            five--;
                            flag = true;
                        }
                        total += 5;
                        ten++;
                    } else {
                        flag = true;
                        total += 5;
                        five++;
                    }
                } else {
                    return false;
                }
                if (flag == true) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};