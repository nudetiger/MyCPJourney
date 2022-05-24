#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include <vector>
#include <bitset>
#include <set>
#include <string>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF 9223372036854775807

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("KNAPSACK.INP", "r", stdin);
    freopen("KNAPSACK.OUT", "w", stdout);

    int n, c;
    cin >> n >> c;

    int dp[n+1][c+1];
    int w[n+1], v[n+1];

    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= c; j++) {
            if(i == 0 || j == 0) 
                dp[i][j] = 0;
            else if(w[i - 1] <= j) 
                dp[i][j] = max(dp[i - 1][j], dp[i-1][j - w[i - 1]] + v[i-1]);
            else 
                dp[i][j] = dp[i-1][j];
            
        }
    }
    
    cout << dp[n][c] << endl;
    return 0;
}