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
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
    
    int n;
    string s;

    cin >> n; cin >> s;

    vector<int> dp(n+1), m(2*n+5, -1);
    
    if(s[0] == '1') dp[0] = 1;
    else dp[0] = -1;

    m[dp[0]+n] = 0;

    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '1') dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1] - 1;

        if(m[dp[i]+n] == -1) m[dp[i]+n] = i;
        if(m[dp[i]+n] != -1) ans = max(ans, i - m[dp[i]+n]);
        if(dp[i] == 0) ans = i+1;
    }
    
    cout << ans << endl;

    return 0;
}