#include <algorithm>
#include <vector>
#include <iostream>
void gameOfLife(std::vector<std::vector<int>>& board)
{
	int r = board.size();
	int c = r ? board[0].size() : 0;
	int cnt {0};
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cnt = 0;
			for (int p = std::max(i - 1, 0); p < std::min(i + 2, r); p++)
			{
				for (int q = std::max(j - 1, 0); q < std::min(j + 2, c); q++)
				{
					cnt += board[p][q] & 1;
				}
			}

			if (cnt == 3 || cnt - board[i][j] == 3)
			{
				board[i][j] |= 2;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			board[i][j] >>= 1;
		}
	}
}
