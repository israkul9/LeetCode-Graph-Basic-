
class Solution {



public:
	vector < vector <int> > floodFill( vector<vector<int>>& image, int sr, int sc, int newColor) {

		vector <int> temp = image[0];


		int row = image.size();
		int col = temp.size();


		//cout << row << " " << col << endl;

		int dx[] = { 0, 0, +1, -1 };
		int dy[] = { +1, -1, 0, 0 };


		stack < pair < int, int > > st;


		bool visit[55][55];

		memset(visit, false, sizeof visit);


		int cc = image[sr][sc];
		st.push({ sr,sc });
		visit[sr][sc] = true;
		image[sr][sc] = newColor;



		while (!st.empty()) {


			int x1 = st.top().first;
			int y1 = st.top().second;

			st.pop();

			for (int i = 0; i < 4; i++) {

				int u = x1 + dx[i];
				int v = y1 + dy[i];

				if (u >= 0 and u < row and v >= 0 and v < col) {

					if (visit[u][v] == false and image[u][v] == cc) {
						st.push({ u,v });
						image[u][v] = newColor;/// new color
						visit[u][v] = true;

					}

				}


			}

		}

		/*for (auto it : image) {
			vector < int > tt = it;

			for (auto x : tt)
				cout << x << " ";
			cout << endl;

		}*/

		return image;


	}
};
