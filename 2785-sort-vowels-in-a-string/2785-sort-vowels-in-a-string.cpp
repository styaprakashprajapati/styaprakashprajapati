class Solution {
public:

    bool isVowel(char c)
    {
        c = tolower(c);

        return c == 'a' ||
               c == 'e' ||
               c == 'i' ||
               c == 'o' ||
               c == 'u';
    }

    string sortVowels(string s)
    {
        string vowels;

        // Step 1: Collect vowels
        for(char c : s)
        {
            if(isVowel(c))
                vowels.push_back(c);
        }

        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end());

        // Step 3: Put them back
        int index = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = vowels[index];
                index++;
            }
        }

        return s;
    }
};