int countBattleships(vector<vector<char>>& board) 
{
	int battleships{ 0 };
	int row = board.size();
	int col = row ? board[0].size() : 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			battleships += board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X');
		}
	}

	return battleships;
}
