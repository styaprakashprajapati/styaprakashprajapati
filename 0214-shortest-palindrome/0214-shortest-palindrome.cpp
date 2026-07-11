class Solution {
public:
    string shortestPalindrome(string s) {

        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> lps(temp.size(), 0);

        int len = 0;
        int i = 1;

        while (i < temp.size()) {

            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {

                if (len != 0) {
                    len = lps[len - 1];
                }
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longestPrefix = lps.back();

        string remain = s.substr(longestPrefix);

        reverse(remain.begin(), remain.end());

        return remain + s;
    }
};