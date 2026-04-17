```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> g(26);
    vector<int> indeg(26, 0);

    for (int i = 0; i < n - 1; i++) {
        string &s = a[i], &t = a[i + 1];
        int len = min(s.size(), t.size());
        int j = 0;
        while (j < len && s[j] == t[j]) j++;
        if (j == len) {
            if (s.size() > t.size()) {
                cout << "Impossible";
                return 0;
            }
        } else {
            int u = s[j] - 'a';
            int v = t[j] - 'a';
            g[u].push_back(v);
        }
    }

    for (int i = 0; i < 26; i++) {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
        for (int v : g[i]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    string res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res += char('a' + u);
        for (int v : g[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    if ((int)res.size() != 26) {
        cout << "Impossible";
        return 0;
    }

    cout << res;
    return 0;
}
```
