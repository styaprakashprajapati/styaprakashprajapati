class Solution {
public:
    string removeDuplicateLetters(string s) {

        // Last occurrence of every character
        vector<int> last(26, 0);

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        // Check whether character is already in stack
        vector<bool> used(26, false);

        string st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Already present
            if (used[ch - 'a'])
                continue;

            // Remove bigger characters
            // if they appear again later
            while (!st.empty() &&
                   st.back() > ch &&
                   last[st.back() - 'a'] > i) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            // Add current character
            st.push_back(ch);
            used[ch - 'a'] = true;
        }

        return st;
    }
};