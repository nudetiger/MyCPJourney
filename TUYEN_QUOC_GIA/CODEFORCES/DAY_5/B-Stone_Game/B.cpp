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
    int arr[n];

    int maxp, minp;
    int maxv = -INF, minv = INF;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < minv) minv = arr[i], minp = i;
        if(arr[i] > maxv) maxv = arr[i], maxp = i;
    }
    int ans = min(min(max(n-minp, n-maxp), max(minp+1, maxp+1)), min(minp+1 + n - maxp, maxp + 1 + n - minp));
    cout << ans << endl;
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