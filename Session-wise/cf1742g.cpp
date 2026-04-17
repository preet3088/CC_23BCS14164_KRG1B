//1742 G Codeforces

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> a(n);
        for(auto &x : a) cin >> x;

        vector<int> used(n,0);
        vector<long long> ans;

        long long cur = 0;

        for(int step=0; step<n; step++){
            long long best_val = cur;
            int best_idx = -1;

            for(int i=0;i<n;i++){
                if(used[i]) continue;

                long long val = (cur | a[i]);

                if(val > best_val){
                    best_val = val;
                    best_idx = i;
                }
            }

            if(best_idx == -1) break;

            used[best_idx] = 1;
            ans.push_back(a[best_idx]);
            cur |= a[best_idx];
        }

        for(int i=0;i<n;i++){
            if(!used[i]) ans.push_back(a[i]);
        }

        for(auto x : ans) cout << x << " ";
        cout << "\n";
    }
}
