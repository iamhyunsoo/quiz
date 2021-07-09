#include <algorithm>
#include <stack>
#include <string>
#include <vector>

std::string removeDuplicateLetters(std::string s)	// Stack used 
{
	std::stack<int> st;
	std::vector<bool> visited(26, false);
	std::vector<int> lastIndex(26, 0);
	std::string ans {""};

	for (int i = 0; i < s.length(); ++i)
	{
		lastIndex[s[i] - 'a'] = i; 
	}

	for (int i = 0; i < s.length(); ++i)
	{
		int tmp = s[i] - 'a';
		if (visited[tmp]) 
		{
			continue;
		}

		while (!st.empty() && st.top() > tmp && lastIndex[st.top()] > i)
		{
			visited[st.top()] = false;
			st.pop();
		}

		visited[tmp] = true;
		st.push(tmp);
	}

	while (!st.empty())
	{
		ans += st.top() + 'a';
		st.pop();
	}

	std::reverse(ans.begin(), ans.end());
	return ans;
}

#include <deque>
std::string removeDuplicateLetters2(std::string s) 	// Deque used.
{
	std::deque<int> st;
	std::vector<bool> visited(26, false);
	std::vector<int> lastIndex(26, 0);
	std::string ans {""};

	for (int i = 0; i < s.length(); ++i)
	{
		lastIndex[s[i] - 'a'] = i; 
	}

	for (int i = 0; i < s.length(); ++i)
	{
		int tmp = s[i] - 'a';
		if (visited[tmp]) 
		{
			continue;
		}

		while (!st.empty() && st.back() > tmp && lastIndex[st.back()] > i)
		{
			visited[st.back()] = false;
			st.back();
		}

		visited[tmp] = true;
		st.push_back(tmp);
	}

	while (!st.empty())
	{
		ans += st.front() + 'a';
		st.pop_front();
	}

	return ans;
}