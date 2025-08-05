class MyHashMap {
public:
    vector<pair<int, int>> hash;
    MyHashMap() {}
    void put(int key, int value) {
        int n = hash.size();
        for (int i = 0; i < n; i++) {
            if (hash[i].first == key) {
                hash[i].second = value;
                return;
            }
        }
        hash.push_back({key, value});
        return;
    }

    int get(int key) {
        int n = hash.size();
        for (int i = 0; i < n; i++) {
            if (hash[i].first == key) {
                return hash[i].second;
            }
        }
        return -1;
    }
    void remove(int key) {
        int n = hash.size();
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (hash[i].first == key) {
                hash.erase(hash.begin() + i);
                break;
            }
        }
    }
};
