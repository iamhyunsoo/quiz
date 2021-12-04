#include <algorithm>
#include <any>
#include <deque>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <variant>
#include <vector>
using namespace std;

// Suppose all inputs are valid in this problem.
// There are five operations, [ add, lt, if, eq, not ]
// Ex] add 3 6           =>   9
// Ex] lt 3 9            =>  TRUE    
// Ex] lt 6 3            =>  FALSE
// Ex] if TRUE 3 6       =>   3
// Ex] if FALSE 6  4     =>   4
// Ex] eq 4 4            =>  TRUE
// Ex] eq 4 2            =>  FALSE
// Ex] eq TRUE TRUE      =>  TRUE
// Ex] not TRUE          =>  FALSE
// Ex] not FALSE         =>  TRUE



/*
 * A lexer node, representing one of the possible token types,
 * as well as children in a recusrive manner when appropriate
 */
struct lexerNode
{
	enum type_t { BOOLEAN, INTEGER, NAME, EQUALS, SEQ } type;
	string token;
	vector<lexerNode> children;

	lexerNode(type_t type, const string& token, vector<lexerNode> children = {}) :
		type(type),
		token(token),
		children(move(children)) {}
};

/*
 * A single program
 */
struct program
{
	vector<vector<lexerNode>> definitions;
	vector<lexerNode> expression;

	program
	(
		vector<vector<lexerNode>> definitions, vector<lexerNode> expression
	)
		: definitions{ definitions }, expression{ expression }
	{
		if (definitions.size())
		{
			for (auto const& exp : definitions)
			{
				int ret = helper(exp);
				if (mIsRetInt)
				{
					cout << ret << endl;
				}
				else
				{
					auto tf = ret ? "TRUE" : "FALSE";
					cout << tf << endl;
				}
				mIsRetInt = true;
			}
		}

		int ret = helper(expression);
		if (mIsRetInt)
		{
			cout << ret << endl;
		}
		else
		{
			auto tf = ret ? "TRUE" : "FALSE";
			cout << tf << endl;
		}
	}

	int helper(vector<lexerNode> expr)
	{
		for (auto const& node : expr)
		{
			if (node.type == lexerNode::BOOLEAN)
			{
				if (node.token == "TRUE")
				{
					mBools.push(true);
				}
				else {
					mBools.push(false);
				}

				mIntOrBool.push(false);
			}
			else if (node.type == lexerNode::INTEGER)
			{
				mNums.push(std::stoi(node.token));
				mIntOrBool.push(true);
			}
			else if (node.type == lexerNode::NAME)
			{
				mOps.push(node.token);
			}
			else if (node.type == lexerNode::EQUALS)
			{

			}
			else if (node.type == lexerNode::SEQ)
			{
				int result = helper(node.children);
			}
		}

		int ret{ 0 };
		int y{ 0 };
		int x{ 0 };
		bool by{ true };
		bool bx{ true };

		std::string op = mOps.top();
		mOps.pop();

		if (op == "not")
		{
			bool b = mBools.top();
			mBools.pop();
			mIntOrBool.pop();

			ret = !b;

			if (!mOps.size())
			{
				mIsRetInt = false;
			}
			else
			{
				mBools.push(ret);
				mIntOrBool.push(false);
			}
		}
		else
		{
			bool isIntTurn = mIntOrBool.top();
			if (isIntTurn)
			{
				y = mNums.top();
				mNums.pop();
				mIntOrBool.pop();

				x = mNums.top();
				mNums.pop();
				mIntOrBool.pop();
			}
			else
			{
				by = mBools.top();
				mBools.pop();
				mIntOrBool.pop();

				bx = mBools.top();
				mBools.pop();
				mIntOrBool.pop();
			}

			if (op == "add")
			{
				ret = x + y;
				if (mOps.size())
				{
					mNums.push(ret);
					mIntOrBool.push(true);
				}
			}
			else if (op == "if")
			{
				bool b = mBools.top();
				mBools.pop();
				mIntOrBool.pop();

				if (isIntTurn)
				{
					if (b)
					{
						ret = x;
					}
					else
					{
						ret = y;
					}
				}
				else
				{
					if (b)
					{
						ret = bx;
					}
					else {
						ret = by;
					}
				}

				if (!mOps.size())
				{
					mIsRetInt = isIntTurn;
				}
				else
				{
					if (isIntTurn)
					{
						mNums.push(ret);
						mIntOrBool.push(true);
					}
					else
					{
						mBools.push(ret);
						mIntOrBool.push(false);
					}
				}
			}
			else if (op == "lt")
			{
				ret = (x < y) ? 1 : 0;
				if (!mOps.size())
				{
					mIsRetInt = false;
				}
				else
				{
					mBools.push(ret);
					mIntOrBool.push(false);
				}
			}
			else if (op == "eq")
			{

				if (isIntTurn)
				{
					if (x == y)
					{
						ret = 1;
					}
					else {
						ret = 0;
					}
				}
				else
				{
					if (bx == by)
					{
						ret = 1;
					}
					else {
						ret = 0;
					}
				}

				if (!mOps.size())
				{
					mIsRetInt = false;
				}
				else
				{
					mBools.push(ret);
					mIntOrBool.push(false);
				}
			}
		}
		return ret;
	}

private:
	std::stack<std::string> mOps;
	std::stack<int> mNums;
	std::stack<bool> mBools;
	std::stack<bool> mIntOrBool;
	bool mIsRetInt = true;
};

/*
 * Returns whether char 'c' is in the inclusive range: [l, r]
 * This function just uses the numeric (ASCII) values for comparison
 */
bool inRange(char c, char l, char r) { return c >= l && c <= r; }

/*
 * Returns whether the specified 'test' string is present at 'index' in string 's'
 */
bool lookaheadEquals(const string s, int index, const string& test) { return s.substr(index, test.length()) == test; }

/*
 * Returns the index of a matching pair of left/right characters (e.g. parens or braces),
 * in `line`, starting with a left at `start`
 */
unsigned lookaheadMatch(const pair<char, char>& leftRight, const string& line, unsigned start) {
	unsigned s = 0;
	for (unsigned i = start; i < line.size(); ++i) {
		if (line[i] == leftRight.first) {
			++s;
		}
		else if (line[i] == leftRight.second) {
			if (--s == 0)
				return i;
		}
	}
	return start;
}

/*
 * Possible fixed tokens
 */
vector<pair<lexerNode::type_t, string>> tokens{ {lexerNode::EQUALS, "="}, {lexerNode::BOOLEAN, "TRUE"}, {lexerNode::BOOLEAN, "FALSE"} };

/*
 * The possible left/right pairs we need to match (parens, braces, etc)
 */
vector<pair<char, char>> leftRights{ {'(', ')'}, {'[', ']'} };

/*
 * Returns an ordered sequence of lexer nodes for a given set of characters,
 * representing some sort of expression
 */
vector<lexerNode> lexExpression(const string& exprText) {
	vector<lexerNode> nodes;

	optional<lexerNode::type_t> type;
	string token;
	decltype(tokens)::iterator tokenIt;
	for (unsigned i = 0; i < exprText.size(); ++i)
	{
		char c = exprText[i];
		if (type)
		{
			if ((c == ' ') || (c == '"')) {
				nodes.emplace_back(*type, token);
				type = nullopt;

				token = "";
			}
			else {
				token += c;
			}
		}
		else
		{
			if (c == ' ') {
				continue;
			}
			else if ((tokenIt = find_if(tokens.begin(), tokens.end(), [&](auto token) { return lookaheadEquals(exprText, i, token.second); })) != tokens.end()) {
				nodes.emplace_back(tokenIt->first, tokenIt->second);
				i += tokenIt->second.size() - 1;
			}
			else if (inRange(c, '0', '9') || c == '-') {
				type = lexerNode::INTEGER;
				token += c;
			}
			else if (inRange(c, 'a', 'z') || inRange(c, 'A', 'Z')) {
				type = lexerNode::NAME;
				token += c;
			}
			else
			{
				auto leftRightIt = find_if(leftRights.begin(), leftRights.end(), [c](const auto& leftRight) { return c == leftRight.first; });
				if (leftRightIt != leftRights.end()) {
					unsigned matchingRightIndex = lookaheadMatch(*leftRightIt, exprText, i);
					nodes.emplace_back(lexerNode::SEQ, string(1, leftRightIt->first), lexExpression(exprText.substr(i + 1, matchingRightIndex - i - 1)));

					i = matchingRightIndex + 1;

				}
			}
		}
	}
	if (type)
		nodes.emplace_back(*type, token);

	return nodes;
}

/*
 * Returns a program parsed from a stream
 */
program lexProgram(istream& in) {
	vector<vector<lexerNode>> defines;
	vector<lexerNode> expr;

	string line;
	while (getline(in, line)) {
		if (line.empty())
			continue;

		if (!expr.empty())
		{
			defines.emplace_back(move(expr));
		}
		expr = lexExpression(line);
	}

	return program{ defines, expr };
}

FILE* stream;
int main()
{
	freopen_s(&stream, "Text.txt", "r", stdin);		// You need to prepare any text file on which inputs are written. Belows are valid inputs.
                                                /*
                                                    not (lt 5 2)
                                                    if (not TRUE) 5 (if (eq (add 3 4) 6) 13 (if (lt 5 4) 2 143))
                                                    add (if (not TRUE) 3 6) (add 5 10)
                                                    lt 5 9
                                                    add 3 8
                                                */
	program p = lexProgram(cin);
	return 0;
}

// Suppose all inputs are valid in this problem.
// There are five operations, [ add, lt, if, eq, not ]
// Ex] add 3 6           =>   9
// Ex] lt 3 9            =>  TRUE    
// Ex] lt 6 3            =>  FALSE
// Ex] if TRUE 3 6       =>   3
// Ex] if FALSE 6  4     =>   4
// Ex] eq 4 4            =>  TRUE
// Ex] eq 4 2            =>  FALSE
// Ex] eq TRUE TRUE      =>  TRUE
// Ex] not TRUE          =>  FALSE
// Ex] not FALSE         =>  TRUE
