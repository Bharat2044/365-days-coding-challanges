// Question Link: https://leetcode.com/problems/map-sum-pairs/

/*
677. Map Sum Pairs

Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 
Example 1:
Input
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
Output
[null, null, 3, null, 5]

Explanation:
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 
Constraints:
1 <= key.length, prefix.length <= 50
key and prefix consist of only lowercase English letters.
1 <= val <= 1000
At most 50 calls will be made to insert and sum.
*/



struct TrieNode {
  vector<shared_ptr<TrieNode>> children;
  int sum = 0;
  TrieNode() : children(26) {}
};

class MapSum {
 public:

  void insert(string key, int val) {
    const int diff = val - keyToVal[key];
    shared_ptr<TrieNode> node = root;
    for (const char c : key) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        node->children[i] = make_shared<TrieNode>();
      node = node->children[i];
      node->sum += diff;
    }
    keyToVal[key] = val;
  }

  int sum(string prefix) {
    shared_ptr<TrieNode> node = root;
    for (const char c : prefix) {
      const int i = c - 'a';
      if (node->children[i] == nullptr)
        return 0;
      node = node->children[i];
    }
    return node->sum;
  }
  
 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();
  unordered_map<string, int> keyToVal;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
