class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ret = "";
        int len = 0;
        for (auto& word : dictionary) {
            int j = 0;
            int i = 0;
            while (i < s.length() && j < word.length()) {
                if (s[i] == word[j]) {
                    j++;
                }
                i++;
            }
            if (j == word.length()) {
                if (len == j) {
                    if (ret.compare(word) > 0) {
                        ret = word;
                    }
                } else if (len < j) {
                    len = j;
                    ret = word;
                }
            }
        }
        return ret;
    }
};
