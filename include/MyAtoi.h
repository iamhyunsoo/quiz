#include <bits/stdc++.h>
#include <string>

int myAtoi(std::string str)
{
    int len = str.length();
    if (len == 0)
    {
        return 0;
    }

    int i    {0};
    int sign {1};
    int ret  {0};

    while (i < len && str[i] == ' ')
    {
        i++;
    }

    if (i < len && (str[i] == '-' || str[i] == '+'))
    {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    while (i < len && str[i] >= '0' && str[i] <= '9')
    {
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
        {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ret = ret * 10 + (str[i++] - '0');
    }
    
    return ret * sign;
}