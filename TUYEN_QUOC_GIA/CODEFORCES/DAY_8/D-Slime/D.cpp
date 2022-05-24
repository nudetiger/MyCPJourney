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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    int n, m = LINF, p, neg = 0, m2 = -LINF;
    cin >> n;

    if(n == 1) {
        cin >> m;
        cout << m << endl;
        return 0;
    }

    int a[n];
    for(int i  = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) neg++;
        if(a[i] < m) {
            m = a[i];
            p = i;
        }
        m2 = max(m2, a[i]);
    }

    int ans = -m;
    for(int i = 0; i < n; i++) {
        if(i == p) continue;
        ans += abs(a[i]);
    }
    if(neg == n) ans = ans + m2*2;
    cout << ans << endl;

    return 0;
}