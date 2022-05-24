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

int n, m;

int calc(string a, string b) {
    int ans = 0; 
    for(int i = 0; i < m; i++) {
        ans += abs((a[i] - '0') - (b[i] - '0'));
    }
    return ans;    
}

void solve() {
    cin >> n >> m;

    string ss[n];

    for(int i = 0; i < n; i++) {
        cin >> ss[i];
    }

    int ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = min(ans, calc(ss[j], ss[i]));
        }
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) solve();
    

    return 0;
}