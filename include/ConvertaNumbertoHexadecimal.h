std::string toHex(int num)
{
    if (num == 0) { return "0";}

    std::string hex{ "" };
    std::string hexTable = "0123456789abcdef";
    unsigned int unsignedNum = num;

    if (unsignedNum < 0)
    {
        unsignedNum = std::pow(2, 32) + unsignedNum;
    }

    while (unsignedNum > 0)
    {
        hex += hexTable[(unsignedNum % 16)];
        unsignedNum /= 16;
    }
    std::reverse(hex.begin(), hex.end());
    return hex;
}
