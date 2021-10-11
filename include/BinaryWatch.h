std::vector<std::string> readBinaryWatch(int turnedOn)
{
  std::vector<std::string> ret;
  for (int h = 0 ; h < 12; h++)
  {
    for (int m = 0; m < 60; m++)
    {
      if (std::bitset<10>(h << 6 | m).count() == turnedOn)
      {
        ret.push_back(
          std::to_string(h) +
          (m < 10 ? ":0" : ":") +
          std::to_string(m)
        );
      }
    }
  }
  return ret;
}
