#include <string>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> res;
    size_t size = words.size();

    for (int i = 0, k, l; i < size; i+=k)   // [i] is just a starting pointer, [k] is how many words we go forward, [l] is length of current words' sum
    {
        for (k = l = 0; i + k < size && l + words[i + k].size() <= maxWidth - k; k++)  // In [ l + words[i + k].size() <= maxWidth - k ]
        {                                                                                      // k is current number of spaces between words
            l += words[i + k].size();
        }

        std::string line = words[i];
        for(int j = 0; j < k - 1; j++)
        {
            if (i + k == size)
            {
                line += " ";
            } 
            else
            {
                line += std::string(( maxWidth - l ) / ( k - 1 ) + (j < (maxWidth - l) % (k -1)), ' ');
            }
            line += words[i + j + 1];
        }
        line += std::string(maxWidth - line.length(), ' ');
        res.push_back(line);
    }
    return res;
}
