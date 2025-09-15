class Solution {
public:
    // string exact_match(vector<string>& wordlist, string a) {
    //     for (auto i : wordlist) {
    //         if (a == i) {
    //             return i;
    //         }
    //     }
    //     return "";
    // }
    string exact_match(unordered_set<string>& exact_lookup, string a) {
        return exact_lookup.count(a) ? a : "";
    }

    // string capitalize_match(vector<string>& wordlist, string a) {
    //     for (auto i : wordlist) {
    //         string s = i;

    //         for (auto& x : s) {
    //             x = tolower(x);
    //         }
    //         string d = a;

    //         for (auto& x : d) {
    //             x = tolower(x);
    //         }
    //         if(d==s){
    //             return i;
    //         }
    //     }
    //     return "";
    // }
    string capitalize_match(unordered_map<string,string>& cap_lookup, string a) {
        for (auto &ch : a) ch = tolower(ch);
        return cap_lookup.count(a) ? cap_lookup[a] : "";
    }

    int isVowel(char ch){
        // Make the list of vowels
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }

    string vowel_match(vector<string>&wordlist, string a){
        vector<int>index;
        vector<int>index2;
        for(int i=0;i<a.size();i++){
            if(!isVowel(a[i])){
                index.push_back(i);
            }else{
                index2.push_back(i);
            }
        }
        for(auto i: wordlist){
            bool c = true;
            if(i.size() == a.size()){
                for(auto j:index){
                    if(tolower(i[j])!=tolower(a[j])){
                        c = false;
                    }
                }
                if(c==true){
                    for(auto k : index2){
                        if(!isVowel(i[k])){
                            c=false;
                        }
                    }
                    if(c==true){
                        return i;
                    }
                }
            }
        }
        return "";
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact_lookup(wordlist.begin(), wordlist.end());

        unordered_map<string, string> cap_lookup;

        for (auto &w : wordlist) {
            string lower = w;
            for (auto &ch : lower) ch = tolower(ch);
            // Only store the first occurrence
            if (!cap_lookup.count(lower)) cap_lookup[lower] = w;
        }

        vector<string>result;
        for(auto i: queries){
            bool d = false;
            string a = exact_match(exact_lookup,i);
            if(a!=""){
                result.push_back(a);
                d = true;
            }else{
                string b = capitalize_match(cap_lookup,i);
                if(b!=""){
                    result.push_back(b);
                    d = true;
                }else{
                    string c = vowel_match(wordlist,i);
                    if(c!=""){
                        result.push_back(c);
                        d = true;
                    }
                }
            }
            if(d==false){
                result.push_back("");
            }
        }
        return result;
    }
};