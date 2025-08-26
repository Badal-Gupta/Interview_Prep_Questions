class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A==B) return 0;

        queue<pair<string,int>>q;
        unordered_set<string>visited;

        q.push({A,0});
        visited.insert(A);

        while(!q.empty()){
            auto [curr , step] = q.front();
            q.pop();

            if(curr==B)return step;

            int i =0;
            while(i<curr.size() && curr[i] == B[i]) i++;

            for(int j = i+1; j<curr.size(); j++){
                if(curr[j]==B[i] && curr[j]!=B[j]){
                    string next = curr;
                    swap(next[i],next[j]);

                    if(!visited.count(next)){
                        visited.insert(next);
                        q.push({next,step+1});
                    }
                }
            }
        }
        return -1;
    }
};