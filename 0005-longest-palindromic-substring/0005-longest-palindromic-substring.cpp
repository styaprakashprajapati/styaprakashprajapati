class Solution {
public:

    int start = 0;
    int maxLength = 0;

    void expand(string &s, int st, int end)
    {
        while (st >= 0 &&
               end < s.length() &&
               s[st] == s[end])
        {
            st--;
            end++;
        }

        int length = end - st - 1;

        if (length > maxLength)
        {
            maxLength = length;
            start = st + 1;
        }
    }

    string longestPalindrome(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};