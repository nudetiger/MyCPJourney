#include <bits/stdc++.h>

#define int long long

using namespace std;

const int ZERO = 0;

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int dp[n];

    dp[0] = arr[0];
    dp[1] = arr[1] + max(arr[0], ZERO);
    dp[2] = arr[2] + max(max(ZERO, arr[0]), arr[1]);
    if(n == 3) {
        cout << max(dp[0], max(dp[1], dp[2]));
        return 0;
    }
    dp[3] = arr[3] + max(dp[2], max(dp[1], dp[0]));

    for(int i = 4; i < n; i ++) {
        dp[i] = arr[i] + max(arr[i-1] + dp[i-3], max(dp[i-2], max(dp[i-3], arr[i-1] + dp[i-4])));
    }

    cout << max(dp[n-1], max(dp[n-2], dp[n-3]));

    return 0;
}