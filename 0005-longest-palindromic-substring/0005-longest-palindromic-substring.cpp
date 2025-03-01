class Solution {
public:
    string odd(int n,string s){
        string a="";
        for(int i=0;i<n;i++){
            int j=i-1;
            int k=i+1;
            while(j>=0&&k<n&&s[j]==s[k]){
                j--;
                k++;
            }
            if(a.size()<k-j-1){
                a= s.substr(j+1,k-j-1);
            }
        }
                return a;
    }
    string even(int n,string s){
        string a ="";
        for(int i=0;i<n;i++){
            int b =i; 
            while(s[b]==s[b+1]){
                b++;
            }
            int j=i-1;
            int k=b+1;
            while(j>=0 && k<n&&s[j]==s[k]){

                    j--;
                    k++;
            }
            if(a.size()<k-j-1){
                a= s.substr(j+1,k-j-1);
            }
        }
        return a;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        if(odd(n,s).size()>even(n,s).size()){
            return odd(n,s);
        }else{
            return even(n,s);
        }
        
    }
};