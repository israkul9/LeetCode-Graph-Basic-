class Solution
{


public:

    vector < vector <int> >  updateMatrix(vector<vector<int>>& matrix)
    {

        int m = matrix.size();
      if (m < 1) return matrix;
      int n = matrix[0].size();
       if (n < 1) return matrix;


        int row = matrix.size();
        int col = matrix[0].size();


        for(int i = 0 ; i < matrix.size(); i++)
        {

            for(int j = 0 ; j < matrix[i].size() ; j++)
            {

                bfs(i,j,matrix,row,col);

               // cout<< matrix[i][j];
            }
           // cout<<endl;


        }
        
        return matrix;
        
        



    }

private:



    int dx[4] = {0, 0, +1, -1};
    int dy[4] = {+1, -1, 0, 0};
    // int dist[1000][1000];



    void bfs(int start_row, int start_col, vector<vector<int>>&matrix, int r, int c)
    {


        queue< data > q;

        int dist = 0;
        q.push({{start_row, start_col, dist}});
        while ( ! q.empty() )
        {
            data curr = q.front();
            q.pop();
            int row = curr.arr[0];
            int  col = curr.arr[1];
            int  dist = curr.arr[2];
            if (matrix[row][col] == 0)
            {
                matrix[start_row][start_col] = dist;
                return;
            }
            for (auto i = 0; i < 4; ++i)
            {
                int new_row = row + dx[i];
                int new_col = col + dy[i];
                if (new_row >=0 and new_row < r and new_col >=0 and new_col < c)
                {
                    q.push({new_row, new_col, dist+1 });

                }

            }
        }


    }


    struct data
    {
        int   arr[100];

    } ;


};