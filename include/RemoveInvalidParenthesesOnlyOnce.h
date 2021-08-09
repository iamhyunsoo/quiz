// Make the parentheses valid by deleting only one invalid parenthesis.

int solution(std::string s)
{
  int len = s.length();
  if (len <= 1) return 0;
  std::stack<char> st;
  char prevPrev;
  char prev;
  bool limit = true;

  for (int i = 0; i < len; i++)
  {
    char c = s[i];
    if (c == ')' || c == '}' || c == ']' ||
        c == '(' || c == '{' || c == '[')
    {
      if (c == ')' || c == ']' || c == '}')
      {
            if (!st.size() ||
            (c == ')' && st.top() != '(') ||
            (c == ']' && st.top() != '[') ||
            (c == '}' && st.top() != '{'))
            {
              if (limit)
              {
                limit = false;
                if (c == prevPrev)
                {
                  st.pop();
                }
                else
                {
                  continue;
                }
              }
              else
              {
                return 0;
              }
            }
            st.pop();
      }
      else
      {
        st.push(c);
      }
      prevPrev = prev;
      prev = c;
    }
  }
  return st.size() ? false : true;
}
