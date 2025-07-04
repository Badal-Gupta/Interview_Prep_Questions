class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n =s.size();
        for(int i = 0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> q;
        for(auto m:mp){
            q.push({m.second,m.first});
        }
        string a ="";
        while(!q.empty()){
            int b = q.top().first;
            for(int i=0;i<b;i++){
                a +=q.top().second;
            }
            q.pop();
        }
        return a;
    }
};