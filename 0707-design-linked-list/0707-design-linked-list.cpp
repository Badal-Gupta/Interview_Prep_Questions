class MyLinkedList {
public:
    vector<int>arr;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (0 > index || index > arr.size()-1)return -1; 
        return arr[index];
        
    }
    
    void addAtHead(int val) {
        arr.insert(arr.begin(),val);
    }
    
    void addAtTail(int val) {
        arr.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(0>index || index>arr.size())return;
        arr.insert(arr.begin()+index,val);
    }
    
    void deleteAtIndex(int index) {
        if(0>index || index>arr.size()-1)return;
        arr.erase(arr.begin()+index);
    }
};
