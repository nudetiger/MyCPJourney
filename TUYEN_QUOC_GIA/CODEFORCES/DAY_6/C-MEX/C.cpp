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

vector<int> g[100005];
int ans[100005];
II edges[100005];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int n;
    cin >> n;

    int u, v;
    int d = INF, d2 = INF;
    int x = INF, x2 = INF;
    for(int i = 1; i <= n-1; i++) {
        cin >> u >> v;
        g[u].push_back(i);
        g[v].push_back(i);

        ans[i] = -1;
    }

    if(n <= 4) {
        for(int i = 0; i < n-1; i++) {
            cout << i << endl;
        }
        return 0;
    }

    II mx = {0, 0};
    for(int i = 1; i <= n; i++) {
        int x = g[i].size();
        mx = max(mx, mp(x, i));
    }

    int cur = 0;
    for(int i : g[mx.second]) {
        ans[i] = cur++;
    }

    for(int i = 1; i <= n-1; i++) {
        if(ans[i] == -1) ans[i] = cur++;
        cout << ans[i] << endl;
    }
    return 0;
}