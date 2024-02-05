// Question Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

/*
84. Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4
 
Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104
*/


class Solution {
public:
    vector<int> nextSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }


    vector<int> previousSmallerElement(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
    
        for(int i=0; i<n; i++){
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    
        return ans;
    }   


    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmaller;
        vector<int> previousSmaller;
        int n = heights.size();

        nextSmaller = nextSmallerElement(heights);
        previousSmaller = previousSmallerElement(heights);
        int maxi = 0;

        for(int i=0; i<n; i++){
            if(nextSmaller[i] == -1){
                nextSmaller[i] = n;
            }
            int width = nextSmaller[i] - previousSmaller[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }

        return maxi;
    }
};
