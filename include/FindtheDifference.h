    char findTheDifference(string s, string t)
    {
      char ret = 0;
      for (auto const& c : s)
      {
        ret ^= c;
      }
      for (auto const& c : t)
      {
        ret ^= c;
      }
      return ret;
    }
