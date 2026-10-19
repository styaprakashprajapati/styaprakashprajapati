
class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
            }
            else if (c == '+' || c == '-') {
                // Sign is allowed only at the start
                // or immediately after e/E
                if (i > 0 && s[i - 1] != 'e' &&
                    s[i - 1] != 'E') {
                    return false;
                }
            }
            else if (c == '.') {
                // Only one decimal point, before exponent
                if (dot || exp) {
                    return false;
                }
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                // Exponent needs a number before it
                // and must appear only once
                if (exp || !digit) {
                    return false;
                }

                exp = true;
                digit = false;
            }
            else {
                return false;
            }
        }

        return digit;
    }
};
