#include <iostream>
#include <vector>

using namespace std;

int exp(int n, int s, vector<int>& arr) {

    int dp[n+1][s+1];
    int i,j;
    dp[0][0] = 1;
    dp[1][arr[0]] = 1;

    for(int j = 1; j <= s; j++) {
        dp[0][j] = 0;
    }
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= s; j++) {
            dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j + arr[i-1]];

        }
    }

    return dp[n][s];

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("EXP.INP", "r", stdin);
    freopen("EXP.OUT", "w", stdout);

    int n, s;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> s;

    bool ans = exp(n, s, arr);

    if(ans) cout << "YES";
    else cout << "NO";

    return 0;
}