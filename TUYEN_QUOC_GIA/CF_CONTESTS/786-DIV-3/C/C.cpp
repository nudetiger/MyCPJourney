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
    string s, t;
    cin >> s >> t;
    
    if(t == "a") {
        cout << 1 << endl;
        return;
    }
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == 'a') {
            cout << -1 << endl;
            return;
        }
    }

    int ans = pow(2, s.length());
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int q;
    cin >> q;
    while(q--) solve();

    return 0;
}