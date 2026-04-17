// 165 C CodeForce


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k;
    string s;
    cin >> k >> s;

    unordered_map<long long, long long> freq;
    long long prefix = 0;
    long long ans = 0;

    freq[0] = 1;

    for(char c : s) {
        if(c == '1') prefix++;

        if(freq.count(prefix - k))
            ans += freq[prefix - k];

        freq[prefix]++;
    }

    cout << ans << endl;
}
