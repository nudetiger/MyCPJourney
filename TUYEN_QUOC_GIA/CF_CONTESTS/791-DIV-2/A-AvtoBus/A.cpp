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
    
    int x = n/4;
    if(n < 4) {
        cout << -1 << endl;
        return;
    }
    if(n % 4 == 0) {
        if(n % 6 == 0) {
            cout << n/6 << " " << n/4 << endl;
        } else {
            if((n - 4) % 6 == 0) {
                cout << 1 + (n-4)/6 << " " << n/4 << endl;
            } else {
                cout << 2 + (n-8)/6 << " " << n/4 << endl;
            }
        }
    } else if(n % 6 == 0) {
        cout << n/6 << " " << 1 + (n-6) / 4 << endl;
    } else if(n % 2 == 0) {

        if((n - 4) % 6 == 0) {
                cout << 1 + (n-4)/6 << " " << 1 + (n-6)/4 << endl;
        } else {
                cout << 2 + (n-8)/6 << " " << 1 + (n-6)/4 << endl;
        }

    } else {
        cout << -1 << endl;
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