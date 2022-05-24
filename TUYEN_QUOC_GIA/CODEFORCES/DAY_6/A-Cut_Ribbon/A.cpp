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
    
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int x = min(a, min(b, c));
    int z = max(a, max(b, c));
    int y = a + b + c - x - z;

    int m1 = (n/x) + 1;
    int m2 = (n/y) + 1;

    int ans = 0;
    for(int i = 0; i <= m1; i++) {
        for(int j = 0; j <= min(m1 - i, m2); j++) {
            if(i*z + j*y > n) break;
            if((n - i*z - j*y) % x != 0) continue;
            int k = (n - i*z - j*y) / x;
            ans = max(ans, i + j + k);
        }
    }    

    cout << ans << endl;

    return 0;
}