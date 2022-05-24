#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

#define int long long
#define II pair<int,int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF LLONG_MAX

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("NKREZ.INP", "r", stdin);
    freopen("NKREZ.OUT", "w", stdout);

    int n;
    cin >> n;
    
    II arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i].sc >> arr[i].fs;
    sort(arr, arr + n);

    int dp[n+1];
    dp[0] = 0; dp[1] = arr[0].fs - arr[0].sc; 

    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i-1];
        int ind = lower_bound(arr, arr + i-1, mp(arr[i-1].second, 281105ll)) - arr;

        if(dp[ind] + arr[i-1].fs - arr[i-1].sc > dp[i]) dp[i] = dp[ind] + arr[i-1].fs - arr[i-1].sc;
    }

    cout << dp[n];

    return 0;
}