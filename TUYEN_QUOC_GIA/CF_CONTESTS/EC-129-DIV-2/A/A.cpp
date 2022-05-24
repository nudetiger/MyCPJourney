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
    int n, m, inp;
    cin >> n;
    int a = -INF, b = -INF;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        a = max(a, inp);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> inp;
        b = max(b, inp);
    }

    if(a >= b) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    if(a <= b) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
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