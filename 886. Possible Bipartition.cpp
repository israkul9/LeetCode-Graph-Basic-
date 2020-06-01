class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector <int> graph[2000 + 10];
        int color[2000+10];
	bool visit[2000 + 10];
	
	
	//memset(visit, 0, sizeof visit);

	for (auto it : dislikes) {
		vector <int> cur = it;
		int x, y;
		x = cur[0];
		y = cur[1];
		graph[x].push_back(y);
		graph[y].push_back(x);
	}



	for (int i = 1; i <= N; i++)color[i] = 0;

	//bool ans = true;
	

	for (int tt = 1; tt <= N; tt++) {

		if (color[tt] == 0) {

			stack <int> stk;
			color[tt] = 10;
			stk.push(tt);


			while (!stk.empty()) {



				int x = stk.top();
				stk.pop();
				//cout << x << " : " << color[x] << endl;

				for (int i = 0; i < graph[x].size(); i++) {
					int child = graph[x][i];
					if (color[child] == 0) {
						if (color[x] == 10) {
							color[child] = 20;
						}
						else {
							color[child] = 10;
						}
						stk.push(child);
					}
					else if (color[x] == color[child]) {
                        return false;
						//cout << "child ar parent same pawa geche \n";
						
					}
				}

			}


		}



	}
        return true;
        
        
    }
};