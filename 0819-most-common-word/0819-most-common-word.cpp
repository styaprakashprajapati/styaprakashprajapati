class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word = "";
        string ans = "";
        int maxFreq = 0;

        paragraph += ' ';   // Last word process karne ke liye

        for (char ch : paragraph) {

            if (isalpha(ch)) {
                word += tolower(ch);
            }
            else if (!word.empty()) {

                if (!ban.count(word)) {
                    freq[word]++;

                    if (freq[word] > maxFreq) {
                        maxFreq = freq[word];
                        ans = word;
                    }
                }

                word = "";
            }
        }

        return ans;
    }
};