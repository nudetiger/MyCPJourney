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
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int n;
    cin >> n;
    int x[n+1], h[n+1];
    vector<vector<int>> dp(n+2, vector<int>(3, 0));

    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
    if(n <= 2) {
        cout << n;
        return 0;
    }
    x[n] = INF, h[n] = INF; 
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    if(x[0] + h[0] < x[1]) dp[0][1] ++;
    dp[0][2] = 1;
    for (int i = 1; i < n; i++) {
        int lmax = max(dp[i-1][1], max(dp[i-1][2], dp[i-1][0]));

        dp[i][0] = dp[i][1] = dp[i][2] = lmax;
        if(x[i] + h[i] < x[i+1]) dp[i][1] ++;
        if(x[i] - h[i] > x[i-1]) 
            dp[i][2] = max(max(dp[i-1][2], dp[i-1][0]) + 1, dp[i][2]);

        if(x[i-1] + h[i-1] >= x[i] && x[i] - h[i] > x[i-1]) 
            dp[i][2] = lmax + 1;

        if(x[i-1] + h[i-1] < x[i] - h[i]) 
            dp[i][2] = lmax + 1;
    }

    int a = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    int b = max(dp[n-2][0], max(dp[n-2][1], dp[n-2][2]));

    cout << max(a, b) << endl;
    for(int i = 0; i < n; i++) {
        cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }


    return 0;
}