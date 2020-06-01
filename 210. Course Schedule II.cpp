
class Solution {

	int graph[2000][2000];
	int visited[2000];
	int indegree[2000];
	queue <int> qq;
	vector <int> ans;

	


	


public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& arr) {

		ans.clear();
		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


		

		memset(visited, false , sizeof visited);
		
		for (auto it : arr) {
			vector <int> tmp = it;
			int a = tmp[0];
			int b = tmp[1];
			graph[b][a] = 1;
			indegree[a]++;
		}


		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0 and visited[i] == false) {
				visited[i] = true;
				qq.push(i);
			}
		}
		
		while (!qq.empty()) {
			int x = qq.front();
			qq.pop();
			//cout << x << " ";
			ans.push_back(x);

			for (int i = 0; i < numCourses; i++)
			{
				if (graph[x][i] == 1 and visited[i] == 0)
				{
					indegree[i]--;
					if (indegree[i] == 0)
					{
						qq.push(i);
						visited[i] = true;
					}
				}
			}




		}
        if(ans.size()==numCourses)
		return ans;
        else{
            ans.clear();
            return ans;
        }


	}
};
