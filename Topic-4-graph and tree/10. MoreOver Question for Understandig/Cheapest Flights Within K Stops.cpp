
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> minH;
        vector<pair<int,int>> graph[n];
        for(auto vec : flights){
            graph[vec[0]].push_back({vec[1],vec[2]});
        }
        
        minH.push(make_tuple(0,src,0));
        while(minH.size()>0){
            auto [cost,u,stop] = minH.top();
            minH.pop();
            
            if(u == dst) return cost;
            if(stop>k) continue;
            for(auto [v,w] : graph[u]){
                minH.push(make_tuple(cost+w,v,stop+1));
            }
        }
        
        return -1;
        
        
    }
};













