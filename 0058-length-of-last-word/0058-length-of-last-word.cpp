class Solution {
public:
    int lengthOfLastWord(string s) {

        int i = s.size() - 1;

        // Ending spaces skip karo
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        int length = 0;

        // Last word count karo
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};