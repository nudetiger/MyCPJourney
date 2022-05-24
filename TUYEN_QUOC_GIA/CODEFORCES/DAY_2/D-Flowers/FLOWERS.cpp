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

const int MOD = 1000000007;
const int SIZE = 100001;

int dp[SIZE];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);

    int t, k;
    cin >> t >> k;

    for(int i = 0; i <= k; i++) dp[i] = 1;

    for (int i = k; i < SIZE; i++) {
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
    }

    for (int i = 1; i < SIZE; i++) {
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }

    int a, b;
    while (t--) {
        cin >> a >> b;
        cout << (dp[b] - dp[a-1] + MOD) % MOD << endl;
    }
    

    return 0;
}