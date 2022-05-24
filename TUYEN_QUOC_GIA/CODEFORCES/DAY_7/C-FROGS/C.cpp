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
    
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        s += "R";

        int n = s.length();
        int ans = -1;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == 'R') {
                ans = max(ans, i - last + 1);
                last = i+1;
            }
        }
        if(ans == -1) ans = n+1;
        cout << ans << endl;
    }

    return 0;
}