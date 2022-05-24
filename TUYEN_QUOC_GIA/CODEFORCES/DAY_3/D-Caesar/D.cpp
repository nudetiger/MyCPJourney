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

const int MOD = 100000000; 

int cnt[101][101][11][11];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
 
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            for(int x = 0; x <= k1; x++) {
                for(int y = 0; y <= k2; y++) {
                    int ans;
                    if(i + j == 0) ans = 1; 
                    else {
                        ans = 0;
                        if(i > 0 && x > 0) ans = (ans + cnt[i - 1][j][x - 1][k2]) % MOD;
                        if(j > 0 && y > 0) ans = (ans + cnt[i][j - 1][k1][y - 1]) % MOD;
                    }
                    cnt[i][j][x][y] = ans;
                }
            }
        }
    }

    cout << cnt[n1][n2][k1][k2] << endl;
    return 0;
}