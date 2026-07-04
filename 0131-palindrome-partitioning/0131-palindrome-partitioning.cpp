class Solution {
public:

    vector<vector<string>> ans;
    vector<string> path;

    bool isPalindrome(string &s, int st, int end)
    {
        while (st < end)
        {
            if (s[st] != s[end])
                return false;

            st++;
            end--;
        }

        return true;
    }

    void solve(int index, string &s)
    {
        // Base Case
        if (index == s.length())
        {
            ans.push_back(path);
            return;
        }

        // Try every substring
        for (int end = index; end < s.length(); end++)
        {
            if (isPalindrome(s, index, end))
            {
                path.push_back(s.substr(index, end - index + 1));

                solve(end + 1, s);

                // Backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        solve(0, s);

        return ans;
    }
};