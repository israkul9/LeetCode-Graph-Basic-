                                    <div class="col-lg-8 col-md-9 col-sm-12">
                    class Solution {
    

int color[105];


bool is_Bipartite(int start , vector <vector<int> >&graph)
{

	for (int i = 0; i < graph[start].size(); ++i) {

		int child = graph[start][i];

		if (color[child] == 0) {
			if (color[start] == 10) {
				color[child] = 20;
			}
			else {
				color[child] = 10;
			}
			is_Bipartite(child, graph);
		}
		else if (color[start] == color[child]) {
			return false;
		}
	}
	return true;
}
    
    
    
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int nodes = graph.size();

	   // for (int i = 0; i < nodes; ++i) color[i] = 0;
		
	        for(int i = 0 ; i <nodes ; i++){
                 for (int i = 0; i <= nodes; ++i) color[i] = 0;
                
                if(color[i]==0){
                    color[i] = 10;
                    if( !is_Bipartite(i, graph) ) return false;
                }
                
	
            }
        return true;
        
    }
};                    <select multiple="multiple" class="multi-select" id="my_multi_select1" name="my_multi_select1[]">
                                            <option>Dallas Cowboys</option>
                                            <option>New York Giants</option>
                                            <option selected>Philadelphia Eagles</option>
                                            <option selected>Washington Redskins</option>
                                            <option>Chicago Bears</option>
                                            <option>Nafisa Sabrin</option>
                                            <option>Detroit Lions</option>
                                            <option>Green Bay Packers</option>
                                            <option>Minnesota Vikings</option>
                                            <option selected>Atlanta Falcons</option>
                                            <option>Carolina Panthers</option>
                                            <option>New Orleans Saints</option>
                                            <option>Tampa Bay Buccaneers</option>
                                            <option>Sazzad Hossain</option>
                                            <option>Arizona Cardinals</option>
                                            <option>St. Louis Rams</option>
                                            <option>San Francisco 49ers</option>
                                            <option>Seattle Seahawks</option>
                                        </select>
                                    </div>