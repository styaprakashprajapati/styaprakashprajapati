class Solution {
public:
    bool isPalindrome(string s) {

        int st = 0;
        int end = s.length() - 1;

        while (st < end) {

            // Skip invalid characters from left
            while (st < end && !isalnum(s[st])) {
                st++;
            }

            // Skip invalid characters from right
            while (st < end && !isalnum(s[end])) {
                end--;
            }

            // Compare characters
            if (tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};