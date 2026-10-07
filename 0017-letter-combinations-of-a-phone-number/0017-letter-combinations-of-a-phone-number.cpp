class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> phone = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        string current;

        function<void(int)> backtrack = [&](int index) {

            // All digits processed
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }

            // Get letters for current digit
            string letters = phone[digits[index] - '0'];

            for (char ch : letters) {
                current.push_back(ch);

                // Move to next digit
                backtrack(index + 1);

                // Undo choice
                current.pop_back();
            }
        };

        backtrack(0);

        return ans;
    }
};