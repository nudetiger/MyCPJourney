#include <bits/stdc++.h>

#define int long long
#define INF 9223372036854775807

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("BOREDOM.INP", "r", stdin);
    freopen("BOREDOM.OUT", "w", stdout);

    int n, inp;
    cin >> n;

    vector<int> arr(100005, 0), dp(100005);
    for(int i = 0; i < n; i++) {
        cin >> inp;
        arr[inp] ++;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for(int i = 2; i <= 100000; i++) {
        dp[i] = max(dp[i-1], arr[i]*i + dp[i-2]);
    }

    cout << dp[100000];
    
    return 0;
}