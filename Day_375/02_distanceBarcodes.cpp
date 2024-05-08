// Question Link: https://leetcode.com/problems/distant-barcodes/

/*
1054. Distant Barcodes

In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.

Example 1:
Input: barcodes = [1,1,1,2,2,2]
Output: [2,1,2,1,2,1]
Example 2:
Input: barcodes = [1,1,1,1,2,2,3,3]
Output: [1,3,1,3,1,2,1,2]
 
Constraints:
1 <= barcodes.length <= 10000
1 <= barcodes[i] <= 10000
*/



class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        short m[10001] = {};
        short max_cnt = 0, max_n = 0, pos = 0;
        
        for (auto n : b) {
            max_cnt = max(max_cnt, ++m[n]);
            max_n = max_cnt == m[n] ? n : max_n;
        }

        for (auto i = 0; i <= 10000; ++i) {
            auto n = i == 0 ? max_n : i;
            while (m[n]-- > 0) {
                b[pos] = n;
                pos = pos + 2 < b.size() ? pos + 2 : 1;
            }
        }

        return b;
    }
};
