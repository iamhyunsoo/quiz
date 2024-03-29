#include <string>
#include <vector>
using namespace std;
class S
{
public:
    std::vector<std::string> letterComb(std::string digits)
    {
        const int N = digits.size();
        if (!N)
        {
            return std::vector<std::string>{};
        }

        std::vector<std::string> ret;
        ret.reserve(1 << (2 * N));
        std::string soFar(N, '\n');

        generate(ret, digits, soFar, 0, N);

        return ret;
    }

private:
    static constexpr char keys[] = {"abc##" "def##" "ghi##" "jkl##" "mno##" "pqrs#" "tuv##" "wxyz#"};
    static inline const char* getKey(char k)
    {
        return keys + (k - '2') * 5;
    }

    static void generate(std::vector<std::string>& ret, const string& digits, std::string& soFar, int k, const int& N)
    {
        if (k < N)
        {
            for (const char* ck = getKey(digits[k]); *ck != '#'; ++ck)
            {
                soFar[k] = *ck;
                generate(ret, digits, soFar, k+1, N); 
            }
        }   
        else
        {
            ret.emplace_back(soFar);
        }     
    }
};

