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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C1.INP", "r", stdin);
    freopen("C1.OUT", "w", stdout);
    
    int n;
    cin >> n;
    int arr[n+1];
    vector<vector<int>> dp(n+1, vector<int>(2005, -INF));

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int ans = 0; 
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(dp[i-1][j-1] + arr[i] < 0) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1] + arr[i], dp[i-1][j]);
                if(dp[i][j] >= 0) ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}