std::string removeKdigits(std::string num, int k) 
{
    std::string ret {""};
    for (char const& c : num)
    {
      while (k && ret.length() && ret.back() > c)
      {
        k--;
        ret.pop_back();
      }
      if (ret.length() || c != '0')
      {
        ret += c;
      }
    }

    if (k > 0)
    {
      while (ret.length() && k--)
      {
        ret.pop_back();
      }
    }
    
    return ret == "" ? "0" : ret;
}
