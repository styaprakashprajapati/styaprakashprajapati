
class Solution {
public:
    vector<string> ans;

    void backtrack(string& s, int index, int parts, string curr) {
        // All 4 parts must use all digits
        if (parts == 4) {
            if (index == s.size()) {
                curr.pop_back(); // Remove the last dot
                ans.push_back(curr);
            }
            return;
        }

        // Try a part containing 1, 2, or 3 digits
        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
            string part = s.substr(index, len);

            // Leading zero is not allowed
            if (len > 1 && part[0] == '0') {
                break;
            }

            int num = stoi(part);

            // Each part must be between 0 and 255
            if (num > 255) {
                break;
            }

            backtrack(s, index + len, parts + 1,
                      curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }

        backtrack(s, 0, 0, "");
        return ans;
    }
};
