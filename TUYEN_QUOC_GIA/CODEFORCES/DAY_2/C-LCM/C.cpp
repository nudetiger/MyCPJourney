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

    int n;
    cin >> n;

    if(n == 1 || n == 2) {
        cout << n << endl;
        return 0;
    }
    if(n == 3) {
        cout << 6 << endl;
        return 0;
    }

    if(n & 1) {
        cout << n * (n-1) * (n-2) << endl;
    } else if(n % 3 == 0 && n % 2 == 0) {
        cout << (n-1) * (n-2) * (n-3) << endl;
    } else {
        cout << n * (n-1) * (n-3) << endl;
    }

    return 0;
}