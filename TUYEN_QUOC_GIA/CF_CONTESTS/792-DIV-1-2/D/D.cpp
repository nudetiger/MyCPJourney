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
    int n, k;
    cin >> n >> k;

    int arr[n+1];
    int dp[n+2][k+2];
    for (int i = 1; i <= n; i++) cin >> arr[i];

    arr[0] = 0;
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(k, i); j++) {
            if(i == 0) {
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = dp[i-1][j] + arr[i] + j;
            if(j > 0) {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int ans = INF;
    for(int i = 0; i <= k; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}