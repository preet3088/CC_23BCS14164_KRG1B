// Data structure to know whether two nodes belong to the same connected component or not in O(1)

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




/*
1)  Time Complexity - O( 4alpha ) -> alpha is almost constant
    Space Complexity - O(V)

2)  Rank does not store the actual height of the components.

*/