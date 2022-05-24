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
    
    int n, t, inp;
    cin >> n >> t;

    int f = 1;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        if(f == t) {
            cout << "YES" << endl;
            return 0;
        }
        if(f == i+1) f += inp;
    }
    cout << "NO\n";

    return 0;
}