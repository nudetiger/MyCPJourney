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

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    char x = s[n/2];
    int ans = 0;
    for(int i = n / 2; i < n; i++) {
        if(s[i] == s[n/2]) ans++;
        else break;
    }
    ans = ans * 2;
    if(n & 1) ans --;

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}