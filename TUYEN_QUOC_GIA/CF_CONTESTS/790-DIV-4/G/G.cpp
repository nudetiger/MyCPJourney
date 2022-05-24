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
 
int ans = 0;
int n; string s;
vector<vector<int> > g(5000, vector<int>());
 
int dfs(int u) {
    int bal = 0;
    if(s[u-1] == 'W') bal += 1;
    else bal -= 1;
    if(g[u].empty()) return bal;
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        bal += dfs(v);
    }
    if(bal == 0) ans += 1;
    return bal;
}
 
void solve() {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
    }
    ans = 0;
 
    cin >> n;
 
    int inp;
    for(int i = 2; i <= n; i++) {
        cin >> inp;
        g[inp].push_back(i);
    }
    cin >> s;
    dfs(1);
 
    cout << ans << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) solve();
 
 
    return 0;
}