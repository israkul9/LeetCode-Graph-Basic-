class Solution {
 
    

int dx[8] = {0, 0, -1, +1, -1, -1, +1, +1}, dy[8] = {-1, +1, 0, 0, -1, +1, -1, +1};   //8 Direction Array
int dist[105][105];
bool visit[105][105];
queue < pair <int, int> > qq;


void bfs(int x , int y ,vector < vector <int> > &grid,int row , int col )
{
	memset(visit, false, sizeof visit);
	memset(dist, -1, sizeof dist);
	qq.push({ x,y });
	visit[x][y] = true;
	dist[x][y] = 0;

	while (!qq.empty()) {
		pair <int, int> cur = qq.front();

		//cout << grid[cur.first][cur.second] << " ";

		qq.pop();
		
		for (int i = 0; i < 8; i++) {

			int xx = cur.first + dx[i];
			int yy = cur.second + dy[i];


			if (xx >= 0 and xx < row and yy >= 0 and yy < col) {
				if (!visit[xx][yy] and grid[xx][yy] == 0) {
					qq.push({ xx,yy });
					visit[xx][yy] = true;
					dist[xx][yy] = dist[cur.first][cur.second] + 1;
				}
			}

		}

	}


}

    
    
    
    
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1)return -1;
        
    int row = grid.size();
	int col = grid[0].size();
	bfs(0, 0, grid, row, col);

	int ans = dist[row - 1][col - 1];
        if(ans==-1) return ans;
        else return ans+1;
        
        
    }
};