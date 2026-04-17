#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    bool unite(int a, int b, int &maxSize) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return false;

        // union by size
        if (size[pa] < size[pb])
            swap(pa, pb);

        parent[pb] = pa;
        size[pa] += size[pb];

        maxSize = max(maxSize, size[pa]);
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    int components = n;
    int maxSize = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (dsu.unite(a, b, maxSize)) {
            components--;
        }

        cout << components << " " << maxSize << "\n";
    }

    return 0;
}