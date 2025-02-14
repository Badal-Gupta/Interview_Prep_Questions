class ProductOfNumbers {
public:
    vector<int>stream;
    ProductOfNumbers() {
        // chaa mudao 
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int size = stream.size()-k;
        int product = 1;
        
        for(int i =size ;i<stream.size() ; i++){
             product = product * stream[i];
        }
        return product;
    }
};
