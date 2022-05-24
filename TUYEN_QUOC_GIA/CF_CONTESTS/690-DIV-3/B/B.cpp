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
    cin >> n; cin >> s;

    int ans = 0;

    if(s[0] == '2') {
        if(s[1] == '0') {
            if(s[2] == '2')
                if(s[3] == '0' || s[n-1] == '0') ans = 1;
            if(s[n-2] == '2' && s[n-1] == '0') ans = 1;
        }
        if(s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ans = 1;
    }
    
    if(s[n-4] == '2'&& s[n-3] == '0' && s[n-2] == '2' && s[n-1] == '0') ans = 1;

    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}