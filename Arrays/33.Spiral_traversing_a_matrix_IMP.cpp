//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // to store the ans
        vector<int> list;

        // to keep check of direction in which we are traversing
        int direction = 0;
        int top = 0;          // first row
        int bottom = r - 1;   /// last row
        int left = 0;         // first column
        int right = c - 1;    // last column
        if (r == 1 && c == 1) // when there is only one element return tht
        {
            return {matrix[r][c]};
        }

        while (top <= bottom && left <= right)
        {

            // first->left to right in first row
            if (direction == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    list.push_back(matrix[top][i]);
                }

                top++;
            }
            // second->top to bottom
            else if (direction == 1)
            {

                for (int i = top; i <= bottom; i++)
                {
                    list.push_back(matrix[i][right]);
                }
                right--;
            }
            // third-> right to left in last row
            else if (direction == 2)
            {

                for (int i = right; i >= left; i--)
                {
                    list.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            // forth- bottom to top in first column
            else
            {
                for (int i = bottom; i >= top; i--)
                {
                    list.push_back(matrix[i][left]);
                }
                left++;
            }

            // keeps repeating till all elements r traversed spirally
            direction = (direction + 1) % 4; // changing direction as there r only 4
        }

        return list;
    }
};