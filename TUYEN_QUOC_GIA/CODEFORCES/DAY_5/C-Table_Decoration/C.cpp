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
    
    freopen("C.INP", "r", stdin);
    freopen("C.OUT", "w", stdout);
    
    int r, g, b;

    cin >> r >> g >> b;

    int x = max(r, max(g, b));
    int z = min(r, min(g, b));
    int y = r + g + b - x - z;

    int ans = min(z + y, (x + y + z)/3);
    cout << ans << endl;

    return 0;
}