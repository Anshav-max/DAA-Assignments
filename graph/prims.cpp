#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>selected;

int prims(int v, vector<vector<pair<int,int>>>& adj){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    // {wt,v} must
    pq.push({0,0});

    vector<int>vis(v,0);
    int mincost = 0;
    int edge = 0;

    while(!pq.empty()){
        pair<int,int>p = pq.top();
        pq.pop();

        int wt = p.first;
        int node = p.second;

        if(vis[node])continue;

        vis[node] = 1;
        for(auto pr : adj[node]){
            if(pr.second == wt){
                selected.push_back({node,pr.first});
            }
        }
        mincost += wt;
        edge++;

        for(auto pr : adj[node]){
            int v = pr.first;
            int w = pr.second;

            if(!vis[v]){
                pq.push({w,v});
            }
        }
    }

    // v bcuz it vertex based
    if(edge != v){
        return -1;
    }
    return mincost;
}

/*
TC = O(ElogE)
SC = O(E)
Vertex based algorithm.
Used for dense graphs.
Uses priority queue.
Negative edge weigths allowed.
*/

int main(){
    int v , e;
    cout<<"Enter number of vertices and edges:\n";
    cin>>v>>e;
    vector<vector<pair<int,int>>>adj(v);

    cout<<"Enter edges:\n";
    for(int i = 0; i < e;i++){
        int u , v , w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int ans = prims(v,adj);
    if(ans == -1){
        cout<<"No any spanning tree obtained\n";
    }
    else{
        cout<<"Selected Edges:\n";
        for(auto p : selected){
            cout<<p.first<<"-->"<<p.second<<endl;
        }
        cout<<"Minimum cost of spanning tree is :"<<ans<<endl;
    }
    return 0;
}