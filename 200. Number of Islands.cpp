
class Solution
{
public:
    int maxn = 0;



    int numIslands(vector<vector<char>>& grid)
    {


        bool visit[ 600 ][ 600 ];
        memset( visit, false, sizeof visit );


        int dx[] = {0, 0, +1, -1};
        int dy[] = {+1, -1, 0, 0};

        this->maxn = grid.size() ;
        int cnt = 0 ;



        stack < pair <int,int> > stk ;



        for(int i = 0 ; i < maxn ; i++)
        {

            for(int j = 0 ; j < grid[i].size() ; j++ )
            {
                if(  visit[i][j]==false  and grid[i][j]=='1' )
                {
                    cnt++;
                    //cout <<"hello world"<<endl;
                    // this->dfs(i,j);

                    stk.push({i,j});
                    visit[i][j] = true;


                    while( !stk.empty() )
                    {

                        int sx = stk.top().first;
                        int sy = stk.top().second;
                        stk.pop();

                        for(int i = 0 ; i<4 ; i++)
                        {

                            int nowx,nowy;

                            nowx = sx + dx[i];
                            nowy = sy + dy[i];


                            if( nowx >= 0 and nowx < grid.size() and nowy>=0 and nowy < grid[sx].size() )
                            {
                                if( visit[nowx][nowy]==false and grid[nowx][nowy]=='1' )
                                {
                                    visit[nowx][nowy] = true;
                                    stk.push({nowx,nowy});
                                }
                            }

                        }




                    }



                }
            }
        }

        return cnt;

    }


};