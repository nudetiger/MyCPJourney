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

set<int> g[200005];
int inp[200005];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int n;
    cin >> n;

    int u, v;
    for(int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    int x, ans = 1;
    cin >> x;
    if(x != 1) ans = 0;
    inp[0] = x;

    int last = x, li = 0;
    for(int i = 1; i <= n-1; i++) {
        cin >> x;
        inp[i] = x;

        if(g[last].size() == 0) {
            last = inp[++li];
            if(g[last].count(x) == 0) {
                ans = 0;
            }
            g[last].erase(x);
            g[x].erase(last);
        } else {
            if(g[last].count(x) == 1) {
                g[last].erase(x);
                g[x].erase(last);
            } else {
                ans = 0;
            }
        }     
    }

    if(ans == 0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}