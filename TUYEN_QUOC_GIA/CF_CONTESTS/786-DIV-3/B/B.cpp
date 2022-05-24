#include <bits/stdc++.h>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

map<string, int> alp;

void precompute() {
    int k = 1;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j) continue;
            char x = i + 'a'; char y = j + 'a';
            string s = "ab";
            s[0] = x; s[1] = y;
            alp[s] = k;
            k++;
        }
    }

}

void solve() {

    string s;
    cin >> s;
    cout << alp[s] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);

    precompute();

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}