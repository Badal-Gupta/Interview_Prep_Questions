class Solution {
public:
    int ladderLength(string start, string end, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({start,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == end) return step;
            for(int i = 0; i<word.size();i++){
                char original = word[i];
                for( char j='a';j<='z';j++){
                    word[i] = j;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;
            } 
        }
        return 0;
    }
};