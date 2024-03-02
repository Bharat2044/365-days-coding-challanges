// Question Link: https://www.interviewbit.com/problems/lru-cache/

/*
LRU Cache

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :
Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
*/



#define ll long long 
ll n;
vector<pair<int,int>> cache;
map<int,int> mp;

LRUCache::LRUCache(int capacity) {
    n = capacity;
    cache.clear();
    mp.clear();
}

int LRUCache::get(int key) {

    if(mp.find(key)==mp.end())
        return -1; 

    ll partner = mp[key];

    pair<int,int> p = make_pair(key,partner);
    vector<pair<int,int>>:: iterator it;

    it = find(cache.begin(),cache.end(),p);

    if(it==cache.end())
        return -1; 
    else { 
        cache.erase(it);
        cache.push_back(p); 
        return partner; 
    }

}


void LRUCache::set(int key, int value) {

    if(mp.find(key)==mp.end()) {
        if(cache.size()==n)
            cache.erase(cache.begin()); 

        cache.push_back(make_pair(key,value));
    }
    else {
        vector<pair<int,int>>:: iterator it;
        pair<int,int> p = make_pair(key,mp[key]);

        it = find(cache.begin(),cache.end(),p);

        if(it!=cache.end()) 
            cache.erase(it);
        else {
            if(cache.size()==n)
                 cache.erase(cache.begin()); 
        }   
        
        cache.push_back(make_pair(key,value));
    }

    mp[key] = value;
}



