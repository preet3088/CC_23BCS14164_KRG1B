#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

long long cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool pointInConvex(vector<Point>& A, Point p) {
    int n = A.size();

    if (cross(A[0], A[1], p) > 0) return false;
    if (cross(A[0], A[n-1], p) < 0) return false;

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross(A[0], A[mid], p) <= 0)
            l = mid;
        else
            r = mid;
    }

    long long c = cross(A[l], A[l+1], p);
    return c < 0; // strictly inside (not on edge)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> A(n);
    for (auto &p : A) cin >> p.x >> p.y;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y;

        if (!pointInConvex(A, p)) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
