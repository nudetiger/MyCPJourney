#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, k;
vector<int> arr;

void solve() {

    int dp[n-1];
    dp[0] = 0;
    dp[1] = arr[0];
    if(n == 3) cout << dp[1];
    dp[2] = dp[1] + arr[1];
    if(n == 4) cout << dp[2];
    dp[3] = arr[0] + arr[2];
    
    for(int i = 4; i < n-1; i++) {
        dp[i] = min(dp[i-3] + arr[i-2], dp[i-2]) + arr[i-1];
    }
    cout << dp[n-2];
}

int32_t main() {

    freopen("FORTRESS.INP", "r", stdin);
    freopen("FORTRESS.OUT", "w", stdout);

    cin >> n >> k;
    int a;
    for(int i = 0; i < n-1; i++) {
        if(i != k-1) {
            cin >> a;
            arr.push_back(a);
        } else {
            cin >> a;
            if(k >= 2) arr[k-2] += a;
        }
    } 

    solve();
    return 0;
}