// 514 C CODEFORCE

#include <bits/stdc++.h>
using namespace std;

const long long P = 31;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<long long> st;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        long long h = 0;
        long long p_pow = 1;

        for(char c : s) {
            h += (c - 'a' + 1) * p_pow;
            p_pow *= P;
        }

        st.insert(h);
    }

    while(m--) {
        string s;
        cin >> s;

        long long h = 0;
        vector<long long> p_pow(s.size());

        p_pow[0] = 1;
        for(int i = 1; i < s.size(); i++)
            p_pow[i] = p_pow[i-1] * P;

        for(int i = 0; i < s.size(); i++)
            h += (s[i] - 'a' + 1) * p_pow[i];

        bool found = false;

        for(int i = 0; i < s.size(); i++) {
            long long original = (s[i] - 'a' + 1) * p_pow[i];

            for(char c : {'a','b','c'}) {
                if(c == s[i]) continue;

                long long new_hash = h - original + (c - 'a' + 1) * p_pow[i];

                if(st.count(new_hash)) {
                    found = true;
                    break;
                }
            }

            if(found) break;
        }

        cout << (found ? "YES\n" : "NO\n");
    }
}
