class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Make a look up dictionary for s1
        std::vector<int> dict(26, 0);
        for (auto const& c : s1)
            dict[c - 'a']++;

        int i = 0;
        int j = 0;
        bool start = false;

        for (int k = 0; k < s2.length(); ++k)
        {
            if (dict[s2[k] - 'a'] > 0)
            {
                if (!start)
                {
                    start = true;
                    i = k;
                }
                dict[s2[k] - 'a']--;
            }
            else
            {
                while (i <= k && dict[s2[k] - 'a'] == 0)
                {
                    dict[s2[i] - 'a']++;
                    i++;
                }
              
                if (dict[s2[k] - 'a'] > 0)
                    dict[s2[k] - 'a']--;
                else
                    start = false;
            }

            if (start && (k - i + 1) == s1.length())
                return true;
        }
        return false;
    }
};

/*
// Brilliant O(n) solution

bool checkInclusion(string s1, string s2) {
    // Edge case : if the size of S2 < S1
    if (s2.size() < s1.size())
        return false;

    // sliding window approach
    // make a frequency array of s1
    vector<int> freqS1(26, 0), window(26, 0);
    for (auto i: s1)
        freqS1[i - 'a']++;

    // window with size s1 to check 
    // if any permuatation of s1 is present in s2 or not
    for (int i = 0; i < s1.length(); ++i)
        window[s2[i] - 'a']++;

    if (freqS1 == window)
        return true;

    // apply sliding window by decreasing the frequency of [i - s1.length]
    // and increasing the frequency of ith element in window
    for (int i = s1.length(); i < s2.length(); ++i)
    {
        // decrease the frequency in window of previous element
        window[s2[i - s1.length()] - 'a']--;

        // increase the frequency in the window of the current element
        window[s2[i] -'a']++;

        // check if the current window matches with the freqS1
        if (freqS1 == window)
            return true;
    }
    // otherwise return false
    return false;
}
*/
