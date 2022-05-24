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
    int n; string s;
    cin >> n;
    cin >> s;

    if(s.length() == 1) {
        cout << s << endl;
        return;
    }

    string ans = "";
    int i;
    if(s[0] == '0') {
        for(i = 0; i < n; i++) {
            if(s[i] == '0') {
                ans += "0";
            } else break;
        }
    }
    for(int j = n-1; j >= i; j--) {
        if(s[j] == '1') {
            ans += "1";
        } else {
            ans = "0" + ans;
            break;
        }
    }
    cout << ans << endl;
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