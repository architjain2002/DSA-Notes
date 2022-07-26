class Solution
{
public:
    /**
     * @param words: a list of words
     * @param word1: a string
     * @param word2: a string
     * @return: the shortest distance between word1 and word2 in the list
     */
    int shortestDistance(vector<string> &words, string &word1, string &word2)
    {
        int i1 = -1;
        int i2 = -1;

        int shortDist = words.size();
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i] == word1)
            {
                i1 = i;
            }
            else if (words[i] == word2)
            {
                i2 = i;
            }

            if (i1 != -1 && i2 != -1)
            {
                shortDist = min(shortDist, abs(i1 - i2));
            }
        }
        return shortDist;
    }
};