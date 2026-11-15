
class Solution {
public:
    int getMaxRepetitions(string s1, int n1,
                          string s2, int n2) {

        int n = s1.size();
        int m = s2.size();

        // next position of s2 after processing s1
        int j = 0;

        // Total completed repetitions of s2
        int count = 0;

        // Store previously seen states
        unordered_map<int, pair<int, int>> seen;

        for(int k = 1; k <= n1; k++) {

            // Process one copy of s1
            for(char ch : s1) {

                if(ch == s2[j]) {
                    j++;
                }

                // One complete s2 found
                if(j == m) {
                    j = 0;
                    count++;
                }
            }

            // Check if same state appeared before
            if(seen.count(j)) {

                int prevK = seen[j].first;
                int prevCount = seen[j].second;

                // Cycle information
                int cycleK = k - prevK;
                int cycleCount = count - prevCount;

                // Remaining copies of s1
                int remaining = n1 - k;

                // Complete cycles possible
                int cycles = remaining / cycleK;

                count += cycles * cycleCount;

                k += cycles * cycleK;

                // Process leftover copies normally
                while(k < n1) {

                    for(char ch : s1) {

                        if(ch == s2[j]) {
                            j++;
                        }

                        if(j == m) {
                            j = 0;
                            count++;
                        }
                    }

                    k++;
                }

                return count / n2;
            }

            // Save current state
            seen[j] = {k, count};
        }

        return count / n2;
    }
};