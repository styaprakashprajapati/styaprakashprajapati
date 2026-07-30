class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size())
            return "";

        vector<int> need(128, 0);

        for (char c : t)
            need[c]++;

        int left = 0;
        int right = 0;

        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {

            if (need[s[right]] > 0)
                required--;

            need[s[right]]--;

            right++;

            while (required == 0) {

                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0)
                    required++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};