#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    double dp[n+1]; dp[0] = 0; dp[1] = 1; dp[2] = 2;

    for(int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];

    cout << fixed << setprecision(0) << dp[n] << "\n";
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("LATGACH.INP", "r", stdin);
    freopen("LATGACH.OUT", "w", stdout);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}