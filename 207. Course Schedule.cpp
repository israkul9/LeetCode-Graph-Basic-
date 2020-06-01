class Solution
{
    vector < int> graph[100000];
    int visited[100000];
    bool flag = false;

    void dfs(int u, int visited[])
    {

       
        visited[u] = -1;
        for(auto x:graph[u])
        {
            if(visited[x]==0)
            {
                dfs(x,visited);
            }
            else if(visited[x]==-1){
                flag = true;
                return;
            }
        }
        visited[u] = 1;

    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& arr)
    {


        for (auto x : arr)
        {
            vector <int> temp = x;
            int a = temp[0];
            int b = temp[1];
            graph[b].push_back(a);
        }
        memset(visited,false,sizeof visited);

        for(int i = 0 ; i < numCourses ; i++)
        {

            if( visited[i]==0 )
            {
                flag = false;
                dfs(i,visited);
                if(flag)
                {
                    return false;
                }


            }

        }
        return true;

    }
};