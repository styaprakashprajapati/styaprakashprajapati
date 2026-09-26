class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        // endWord dictionary mein hi nahi hai
        if (words.find(endWord) == words.end()) {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string current = q.front();
                q.pop();

                // Destination mil gaya
                if (current == endWord) {
                    return steps;
                }

                for (int i = 0; i < current.size(); i++) {

                    char original = current[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == original) {
                            continue;
                        }

                        current[i] = ch;

                        // Agar dictionary mein word hai
                        if (words.find(current) != words.end()) {

                            q.push(current);

                            // Dobara use nahi karna
                            words.erase(current);
                        }
                    }

                    current[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};