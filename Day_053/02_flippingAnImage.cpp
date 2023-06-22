// Question Link: https://leetcode.com/problems/flipping-an-image/

/*
832. Flipping an Image

Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].
 
Example 1:
Input: image = [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:
Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 

Constraints:
n == image.length
n == image[i].length
1 <= n <= 20
images[i][j] is either 0 or 1.
*/


// Time Complexity = O(n^2), Space Complexity = O(1)
class Solution {
public:
    void inversion(vector<vector<int>>& arr) {
        for (int i = 0; i < arr.size(); i++){
            for (int j = 0; j < arr[i].size(); j++)
                arr[i][j] ^= 1;   //arr[i][j] = !arr[i][j];
        }
    }

    void swapCols(vector<vector<int>>& arr) {
        
        for (int i = 0; i < arr.size(); i++){
            int end= arr[i].size() - 1;
            int front = 0;

            while (front < end){
                swap((arr[i][front]), (arr[i][end]));
                front++;
                end--;
            }
        }
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& arr) {

        // swap first and last cols
        swapCols(arr);

        // convert 0 with 1 and 1 with 0
        inversion(arr);

        return arr;
    }
};




