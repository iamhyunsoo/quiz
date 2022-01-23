
#include <cctype>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

bool isNumber(std::string const& str)
{
    for (char const& c : str) 
    {
        if (std::isdigit(c) == 0) 
        {
            return false;
        }
    }
    return true;
}

int NumberOfElements(std::string const& str)
{  
  auto parsed = str | std::ranges::views::split(',') | std::ranges::views::transform(
    [](auto c)
    { 
      return std::string_view(&*c.begin(), std::ranges::distance(c));
    }
  );
  std::vector<std::string> v(parsed.begin(), parsed.end());
  for (int i = 0; i < v.size(); i++)
  {
    std::string elem = v[i];
    int k = 0;
    
    while (elem[k] == ' ') 
    {
      k++;
    }
  
    v[i] = elem.substr(k);
    
    if (!isNumber(v[i]))
    {
      return -1;
    }
  }
  
  return static_cast<int>(v.size());
}

int main() 
{
  std::vector<std::string> lines;
  std::string line;
  while (std::getline(std::cin, line)) 
  {
    lines.push_back(line);
  }
  
  std::string A = lines[0];
  std::string B = lines[1];
  std::string C = lines[2];
 
  A = A.substr(1, A.length() - 2);
  B = B.substr(1, B.length() - 2);
  C = C.substr(1, C.length() - 2);
  
  int aLen = NumberOfElements(A);
  int bLen = NumberOfElements(B);
  
  if (aLen == -1 || bLen == -1) 
  { 
    std::cout << "-1" << std::endl; 
  }
  else
  {
    auto parsed = C | std::ranges::views::split(',') | std::ranges::views::transform(
      [](auto c)
      { 
        return std::string_view(&*c.begin(), std::ranges::distance(c));
      }
    );
    std::vector<std::string> vecC(parsed.begin(), parsed.end());
    int i = std::stoi(vecC[0]);
    int j = std::stoi(vecC[1]);

    std::cout << i * bLen + j << std::endl; 
  }
}

/*
Input:
[1, 2, 3]
[6, 3]
(2, 1)
*/
