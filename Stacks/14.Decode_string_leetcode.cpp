class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> word;
        stack<int> count;

        int k = 0;
        string answer = "";
        for (int i = 0; i < s.length(); i++)
        {
            // char ch = s[i];
            if (isdigit(s[i]))
            {
                while (isdigit(s[i]))
                {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                i--;
            }
            else if (isalpha(s[i]))
            {
                answer = answer + s[i];
            }

            else if (s[i] == '[')
            {
                word.push(answer);
                count.push(k);
                k = 0;
                answer = "";
            }
            else
            {
                int number = count.top();
                count.pop();

                string repeatition = word.top();
                word.pop();
                for (int i = 0; i < number; i++)
                {
                    repeatition = repeatition + answer;
                }
                answer = repeatition;
            }
        }
        return answer;
    }
};