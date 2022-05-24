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

    int a, b, c;
    cin >> a >> b >> c;

    int x = 2 * abs(a-b);

    if(a > x || b > x || c > x) {
        cout << -1 << endl;
    } else {
        int f = c + x/2;
        int f2 = c - x/2;

        if(1 <= f && f <= x) {
            cout << f << endl;
        } else {
            cout << f2 << endl;
        }
    }
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