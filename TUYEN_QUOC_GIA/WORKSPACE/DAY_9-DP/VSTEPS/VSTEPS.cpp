#include <iostream>
#include <stdio.h>
#include <iomanip>

#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int dp[n+1], h[n+2];

    for(int i = 1; i <= n; i++) cin >> h[i];
    
    dp[0] = 0; dp[1] = 1;

    int l = 1;
    for(int i = 2; i <= n; i++) {
        if(i > h[l]) l++;
        if(i == h[l]) {
            dp[i] = 0;
            continue;
        }
        dp[i] = (dp[i-1] + dp[i-2]) % 14062008;
    }

    cout << dp[n];
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("VSTEPS.INP", "r", stdin);
    freopen("VSTEPS.OUT", "w", stdout);

    solve();

    return 0;
}