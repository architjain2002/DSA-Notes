class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size(), col = matrix[0].size(), left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1, direction = 1;
        vector<int> order;

        while (order.size() < row * col)
        {
            switch (direction)
            {
            case 1:
                for (int i = left; i <= right; i++)
                    order.push_back(matrix[top][i]);
                direction = 2;
                top++;
                break;

            case 2:
                for (int i = top; i <= bottom; i++)
                    order.push_back(matrix[i][right]);
                direction = 3;
                right--;
                break;

            case 3:
                for (int i = right; i >= left; i--)
                    order.push_back(matrix[bottom][i]);
                direction = 4;
                bottom--;
                break;

            case 4:
                for (int i = bottom; i >= top; i--)
                    order.push_back(matrix[i][left]);
                direction = 1;
                left++;
                break;
            }
        }
        return order;
    }
};