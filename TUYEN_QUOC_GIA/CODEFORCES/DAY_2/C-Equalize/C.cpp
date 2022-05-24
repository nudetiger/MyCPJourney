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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int n;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    
    int dp[n+1];

    if(a[0] == b[0]) dp[0] = 0;
    else dp[0] = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] == b[i]) {
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] + 1;
            if(a[i-1] != b[i-1] && a[i-1] != a[i]) {
                dp[i]--;
                a[i] = a[i-1];
                a[i-1] = b[i-1];
            }
        }
    }

    cout << dp[n-1];

    return 0;
}