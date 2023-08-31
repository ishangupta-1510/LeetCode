class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lruList; // Keeps track of least recently used keys

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found in cache
        }
        
        // Move the key to the front of the LRU list since it's accessed
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        
        return cache[key].first; // Return the value
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update its value and move it to the front
            lruList.erase(cache[key].second);
        } else if (cache.size() >= capacity) {
            // Remove the least recently used element
            int lruKey = lruList.back();
            lruList.pop_back();
            cache.erase(lruKey);
        }
        
        // Insert the key-value pair and update its position in the LRU list
        lruList.push_front(key);
        cache[key] = {value, lruList.begin()};
    }
};