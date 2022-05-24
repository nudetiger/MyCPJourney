#include <iostream>

#define int long long

using namespace std;

struct node {int u = 0, v = 0;};
node g[100000];
int ans[100000];

void dfs(int s) {
    if(g[s].u == 0) return;
    ans[g[s].u] = ans[s] + 1;
    ans[g[s].v] = ans[s] + 1;
    dfs(g[s].u);
    dfs(g[s].v);
}

void solve() {
    int n, c, e, a, b;
    cin >> n >> c;
    for(int i = 0; i < c; i++) {
        cin >> e >> a >> b;
        g[e-1].u = a-1; g[e-1].v = b-1;
    }
    ans[0] = 1;
    dfs(0);
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("VCOLDWAT.INP", "r", stdin);
    freopen("VCOLDWAT.OUT", "w", stdout);

    solve();
}