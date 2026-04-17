#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<long long> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<long long>& a) {
        n = a.size();
        bit.assign(n + 1, 0);
        for (int i = 0; i < n; i++) update(i, a[i]);
    }

    void update(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) {
        long long sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    long long rangeQuery(int l, int r) {
        return query(r) - (l ? query(l - 1) : 0);
    }
};