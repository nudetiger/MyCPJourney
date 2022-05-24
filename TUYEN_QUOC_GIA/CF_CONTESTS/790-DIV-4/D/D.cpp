#include <bits/stdc++.h>

#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define LINF 9223372036854775807
#define INF 2147483647

using namespace std;

int calc(int i, int j, vector<vector<int>>& mt, int n, int m) {
    int ans = mt[i][j];
    int ti = i, tj = j;
    while (ti > 0 && tj > 0) {
        ti--, tj--;
        ans += mt[ti][tj];
    }
    ti = i, tj = j;
    while (ti > 0 && tj < m - 1) {
        ti--, tj++;
        ans += mt[ti][tj];
    }
    ti = i, tj = j;
    while (ti < n - 1 && tj < m - 1) {
        ti++, tj++;
        ans += mt[ti][tj];
    }
    ti = i, tj = j;
    while (ti < n - 1 && tj > 0) {
        ti++, tj--;
        ans += mt[ti][tj];
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);

    int t;
    int n, m, ans;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m;

        vector<vector<int>> mt(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mt[i][j];
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, calc(i, j, mt, n, m));
            }
        }

        cout << ans << endl;
    }

    return 0;
}