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

    vector<II> t, a(n); 
    for(int i = 0; i < n; i++) cin >> a[i].fs;
    for(int i = 0; i < n; i++) cin >> a[i].sc;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                t.push_back(mp(j+1, j+2));
            }
        }
    }

    for(int i = 1; i < n; i++) {
        if(a[i].sc < a[i-1].sc) {
            cout << -1 << endl;
            return;
        }
    }

    cout << t.size() << endl;
    for(int i = 0; i < t.size(); i++) {
        cout << t[i].fs << " " << t[i].sc << endl;
    }

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