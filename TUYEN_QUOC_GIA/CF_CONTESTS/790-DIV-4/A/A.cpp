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

void solve() {
    string s;
    cin >> s;

    int f = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int f2 = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');

    if(f == f2) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}