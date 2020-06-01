
// DFS from boundary related problem

class Solution {
	int dx[5] = {0, 0, +1, -1};
    int dy[5] = {+1, -1, 0, 0};
	
	bool visited[200][200];


 void dfs(int x, int y, vector<vector<char>>& graph, int r, int c) {
		 visited[x][y] = true;

		 for (int i = 0; i < 4; i++) {

			 int nowx = dx[i] + x;
			 int nowy = dy[i] + y;
			 if ((nowx >= 0 and nowx < r  and nowy >= 0 and nowy < c)) {
				 if (!visited[nowx][nowy]) {
					 if (graph[nowx][nowy] == 'O')
					 {
						 // bug;

						 graph[nowx][nowy] = '#';

						 dfs(nowx, nowy, graph, r, c);
					 }
				 }
			 }
		 }



	 }

public:
	void solve(vector<vector<char>>& board) {
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        
        if(board.size()==0)return;
        
		int row = board.size();
		int col = board[0].size();
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col ; j++) {
				visited[i][j] = false;
			}
		}


		for (int i = 0; i < row ; i++) {
			for (int j =0 ; j < col ; j++) {
				if (i == 0 and j == 0) {

					if (board[i][j] == 'O' and visited[i][j]==false) {
						dfs(i, j, board, row,col);
						board[i][j] = '#';
					}

					//cout << board[i][j];
				}
				else if (i == 0 and j < col) {
					if (board[i][j] == 'O' and visited[i][j] == false) {
						dfs(i, j, board, row, col);
						board[i][j] = '#';
					}

					//cout << board[i][j];
				}
				else if (i < row and j == 0) {

					if (board[i][j] == 'O' and visited[i][j] == false) {
						dfs(i, j, board, row, col);
						board[i][j] = '#';
					}

					//cout << board[i][j];
				}
				else if (i < row and j == col - 1) {
					if (board[i][j] == 'O' and visited[i][j] == false) {
						dfs(i, j, board, row, col);
						board[i][j] = '#';
					}
					//cout << board[i][j];
				}
				else if (i == row - 1 and j < col) {
					if (board[i][j] == 'O' and visited[i][j] == false) {
						dfs(i, j, board, row, col);
						board[i][j] = '#';
					}
					//cout << board[i][j];
				}
				
			}
			//cout << endl;

		}





		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {

				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == '#')board[i][j] = 'O';
				cout << board[i][j];

			}
			cout << endl;

		}


	}


};