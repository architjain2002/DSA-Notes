class Solution
{
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel)
    {
        for (int i = 1; i < travel.size(); i++)
        {
            travel[i] = travel[i - 1] + travel[i];
        }
        int count_M = 0;
        int count_P = 0;
        int count_G = 0;
        int last_M = -1;
        int last_G = -1;
        int last_P = -1;

        for (int i = 0; i < garbage.size(); i++)
        {
            for (int j = 0; j < garbage[i].length(); j++)
            {
                if (garbage[i][j] == 'M')
                {
                    last_M = i;
                    count_M++;
                }

                if (garbage[i][j] == 'G')
                {
                    last_G = i;
                    count_G++;
                }
                if (garbage[i][j] == 'P')
                {
                    last_P = i;
                    count_P++;
                }
            }
        }
        int result = count_M + count_G + count_P;
        if (last_M != -1 && last_M != 0)
        {
            result = result + travel[last_M - 1];
        }
        if (last_G != -1 && last_G != 0)
        {
            result = result + travel[last_G - 1];
        }
        if (last_P != -1 && last_P != 0)
        {
            result = result + travel[last_P - 1];
        }
        return result;
    }
};