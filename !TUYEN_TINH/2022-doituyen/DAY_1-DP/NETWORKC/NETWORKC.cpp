#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int network(int n, vector<int>& w) {

    int m = INT_MAX-1;
    int dp[n];
    dp[0] = w[0];
    dp[1] = w[0] + w[1];
    dp[2] = dp[0] + w[2];
    for(int i = 3; i < n; i ++) {
        dp[i] = min(dp[i-2], dp[i-3] + w[i-1]) + w[i]; 
    }
    return dp[n-1];
}

int main() {

    freopen("NETWORKC.INP", "r", stdin);
    freopen("NETWORKC.OUT", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> w(n-1);
    for(int i = 0; i < n-1; i++) {
        cin >> w[i];
    }

    int ans = network(n-1, w);
    cout << ans;

    return 0;
}