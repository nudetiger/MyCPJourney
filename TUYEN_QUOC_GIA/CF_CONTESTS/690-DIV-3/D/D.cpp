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

    int pre[n+2], a[n+2];
    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i] + pre[i-1];
    }

    int ans = 1;
    int x, f, l;
    for(int i = 1; i < n; i++) {
        ans = 1; 
        f = pre[i], l = i, x = 1;
        for(int j = i+1; j <= n; j++) {
            if(pre[j] - pre[l] == f) {
                ans ++; 
                l = j;
                x = 1;
                continue;
            }
            if(pre[j] - pre[l] > f) {
                x = 0;
                break;
            } else x = 0;
        }
        if(x == 1) {
            cout << n - ans << endl;
            return;
        }
    }

    cout << n-1 << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}