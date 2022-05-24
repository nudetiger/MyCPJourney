#include <bits/stdc++.h>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF 2147483647

using namespace std;

int n, m, k;

int val[200002];
vector<int> g[200002];

int dfs(int s, int move, int v) {

    int x = max(v, val[s]);
    

    if(move == 1) return x;

    // cout << move << " " << s << " " << x << endl;
    if(g[s].size() == 0) return -1;


    int mv = INF;
    for(int i = 0; i < g[s].size(); i++) {
        int to = g[s][i];
        mv = min(mv, dfs(to, move - 1, x));
    }
    return mv;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    cin >> n >> m >> k;


    for(int i = 0; i < n; i++) cin >> val[i];
    if(k > n && m <= k) {
        cout << -1;
        return 0;
    }
    if(k > n) {
        int mv = 0;
        for(int i = 0; i < n; i++) mv = max(mv, val[i]);
        cout << mv;
        return 0;
    }

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u-1].push_back(v-1);
    }
    int mv = INT_MAX;
    for(int i = 0; i < n; i++) {
        int x = dfs(i, k, 0);
        if(x == -1) continue;
        mv = min(mv, x);
    }

    if(mv == INF) {
        cout << -1 << endl;
        return 0;
    }

    cout << mv << endl;

    return 0;
}