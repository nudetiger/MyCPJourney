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
    int x, y;
    cin >> x >> y;

    if(y % x != 0) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if(x == y) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    int f = y / x;
    cout << 1 << " " << f << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}