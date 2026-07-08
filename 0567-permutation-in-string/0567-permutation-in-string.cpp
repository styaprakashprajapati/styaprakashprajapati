class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        // Frequency of s1
        for (char ch : s1) {
            need[ch - 'a']++;
        }

        // First window
        for (int i = 0; i < n; i++) {
            window[s2[i] - 'a']++;
        }

        if (need == window)
            return true;

        // Sliding Window
        for (int i = n; i < m; i++) {

            window[s2[i] - 'a']++;           // Add new character
            window[s2[i - n] - 'a']--;       // Remove old character

            if (need == window)
                return true;
        }

        return false;
    }
};