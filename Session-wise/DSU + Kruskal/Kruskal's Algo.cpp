// Function to find MST (based on 15. Disjoint Set)

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent;

    // This is used to know which of the two nodes is smaller so that the smaller can be connected to the larger ranked node (does not not exactly store height)
    vector<int> rank;
    vector<int> size;
    public:
    
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }

    // Find ultimate Parent of the node
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]); // Assigning the returned value leads to path compression, to save number of iterations for the later part
    }

    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }

        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(size[ulp_u] < size[ulp_v]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else{
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};

vector<pair<int,pair<int,int>>> Kruskal(int n, vector<vector<int>> &edges){
    DisjointSet ds(n);

    vector<pair<int,pair<int,int>>> adj;
        // edges is a vector of {u,v,w}
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj.push_back({w,{u,v}});
        }

    sort(adj.begin(),adj.end());

    vector<pair<int,pair<int,int>>> MST;
    int MSTcost = 0;
    for(int i = 0; i<adj.size(); i++){
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        int w = adj[i].first;
    
        if(ds.findUPar(u) != ds.findUPar(v)){
            MST.push_back({w,{u,v}});
            MSTcost += w;
            ds.unionByRank(u,v);
        }
    }
    return MST;
}

/*
1)  Time Complexity - O( ElogE + E(4alpha) )
    Space Complexity - O(V+E)

2)  This is for 0-indexed, for 1 indexed nodes, do n+1. Here n represents number of nodes(V)

3)  Always check on ultimate parent & not the parent vector.
*/