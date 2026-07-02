class Solution {
public:

    bool isPalindrome(string &str)
    {
        int st = 0;
        int end = str.size() - 1;

        while(st < end)
        {
            if(str[st] != str[end])
                return false;

            st++;
            end--;
        }

        return true;
    }

    int maxProduct(string s)
    {
        int n = s.size();

        vector<pair<int,int>> palindromes;

        // Generate all subsequences
        for(int mask = 1; mask < (1 << n); mask++)
        {
            string temp = "";

            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    temp += s[i];
                }
            }

            if(isPalindrome(temp))
            {
                palindromes.push_back({mask, (int)temp.size()});
            }
        }

        int ans = 0;

        // Compare every pair
        for(int i = 0; i < palindromes.size(); i++)
        {
            for(int j = i + 1; j < palindromes.size(); j++)
            {
                if((palindromes[i].first & palindromes[j].first) == 0)
                {
                    ans = max(ans,
                              palindromes[i].second *
                              palindromes[j].second);
                }
            }
        }

        return ans;
    }
};