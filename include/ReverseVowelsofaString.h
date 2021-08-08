#include <string>

std::string reverseVowels(std::string s)
{
  const std::string vowels = "aeiouAEIOU";
  int l = 0;
  int r = s.length() - 1;
  while (l < r)
  {
    l = s.find_first_of(vowels, l);
    r = s.find_last_of(vowels, r);
    if (l < r)
    {
      std::swap(s[l++], s[r--]);
    }
  }
  return s;
}
