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
    cin >> n;
    if(n > 45) {
        cout << -1 << endl;
        return;
    }
    if(n <= 9) {
        cout << n << endl;
        return;
    }
    n -= 9;
    if(n <= 8) {
        cout << n << 9 << endl;
        return;
    }
    n -= 8;
    if(n <= 7) {
        cout << n << 89 << endl;
        return;
    }
    n -= 7;
    if(n <= 6) {
        cout << n << 789 << endl;
        return;
    }
    n -= 6;
    if(n <= 5) {
        cout << n << 6789 << endl;
        return;
    }
    n -= 5;
    if(n <= 4) {
        cout << n << 56789 << endl;
        return;
    }
    n -= 4;
    if(n <= 3) {
        cout << n << 456789 << endl;
        return;
    }
    n -= 3;
    if(n <= 2) {
        cout << n << 3456789 << endl;
        return;
    }
    n -= 2;
    if(n == 0) cout << 23456789 << endl;
    else cout << 123456789 << endl;

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