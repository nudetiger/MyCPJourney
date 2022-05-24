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
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    
    int n, d;
    cin >> n >> d;

    int a[n]; cin >> a[0];
    int ans = 0;

    for(int i = 1; i < n; i++) {
        cin >> a[i];
        int x = (a[i-1] - a[i] + d) / d;
        if(x >= 1) a[i] += x * d, ans += x;
    }

    cout << ans << endl;

    return 0;
}