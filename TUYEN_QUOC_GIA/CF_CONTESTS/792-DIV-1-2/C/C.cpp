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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<int> bad;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
        if(!bad.empty()) continue;
        vector<int> ts = g[i];
        sort(ts.begin(), ts.end());
        for(int j = 0; j < m; j++) {
            if(g[i][j] == ts[j]) continue;
            bad.push_back(j);
        }
    }

    if(bad.size() == 0) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    if(bad.size() > 2) {
        cout << -1 << endl;
        return;
    }

    for(int i = 0; i < n; i++) swap(g[i][bad[0]], g[i][bad[1]]);

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++) {
            if(g[i][j] < g[i][j-1]) {
                cout << -1 << endl;
                return;
            }
        }
    
    cout << bad[0] + 1 << " " << bad[1] + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}