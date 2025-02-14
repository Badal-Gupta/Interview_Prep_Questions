class ProductOfNumbers {
public:
    vector<int>stream;
    int product =1;
    ProductOfNumbers() {
        // chaa mudao 
    }
    
    void add(int num) {
        if(num==0){
            stream.clear();
            product =1;
        }else{
            product = product*num;
            stream.push_back(product);
        }
    }
    
    int getProduct(int k) {
        if (k > stream.size()) {
            return 0; 
        }
        int size = stream.size()-k;
        long long d = (k==stream.size()) ? 1: stream[size-1];
        return stream[stream.size()-1]/d;
    }
};
