class S
{
public:
    std::string decodeString(std::string s) 
    {
        int i{ 0 };
        return help(s, i);
    }
private:
    std::string help(std::string const& s, int& i)
    {
        std::string ret;
        int len = s.length();

        while (i < len && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (i < len && isdigit(s[i]))
                {
                    num = (num * 10) + (s[i++] - '0');
                }
                
                i++;
                std::string subStr = help(s, i);
                i++;

                while (num-- > 0)
                {
                    ret += subStr;
                }
            }
            else
            {
                ret += s[i++];
            }
        }
        return ret;
    }
};
