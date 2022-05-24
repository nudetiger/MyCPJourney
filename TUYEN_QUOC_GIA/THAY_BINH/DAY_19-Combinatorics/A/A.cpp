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

int f[1000][1000];

inline void precompute() {
    f[0][0] = 1;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= i; j++) {
            f[i][j] = f[i-1][j-1] + f[i-1][j];
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    
    precompute();

    int p, n, k;
    cin >> n >> k;
    cin >> p;

    int u = n, v = k;
    int xmin = 1;

    cout << f[n][k] << endl;

    int x[k+1];
    for(int i = 1; i <= k; i++) {
        while(p > f[u-1][v-1]) xmin++, p -= f[u-1][v-1], u--;
        x[i] = xmin; v--;
    }

    for(int i = 1; i <= k; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    u = n; v = k; xmin = 1; p = 1;
    for(int i = 1; i <= k; i++) {
        while(x[i] > xmin) p += f[u-1][v-1], xmin ++, u--;
        u--; v--;
    }
    cout << p << endl;

    return 0;
}