class Solution
{

    int getDepthSumUsingDFSTraversal(vector<NestedInteger> nestedList, int currentSum)
    {
        int total = currentSum;
        vector<NestedInteger> temp;
        for (auto list : nestedList)
        {
            if (list.isInteger())
                total += list.getInteger();
            else
            {
                for (auto el : list.getList())
                    temp.push_back(el);
            }
        }
        if (!temp.empty())
        {
            return total += getDepthSumUsingDFSTraversal(temp, total);
        }
        return total;
    }

public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    int depthSumInverse(vector<NestedInteger> nestedList)
    {
        int depth = 0;
        return getDepthSumUsingDFSTraversal(nestedList, 0);
    }
};