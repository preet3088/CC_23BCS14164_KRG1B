#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    vector<long long> b(n);
    for (auto &it : b) {
        scanf("%lld", &it);
    }
    
    vector<long long> closed(n);
    long long sum = 0, cnt = 0, ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum -= cnt;
        cnt -= closed[i];
        b[i] -= sum;
        if (b[i] <= 0) {
            continue;
        }
        int el = min(i + 1, k);
        long long need = (b[i] + el - 1) / el;
        sum += need * el;
        cnt += need;
        ans += need;
        if (i - el >= 0) {
            closed[i - el] += need;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
