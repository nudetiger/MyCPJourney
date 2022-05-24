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
    string s;
    cin >> s;

    int n = s.length();
    int ans = 1;
    for(int i = 0; i <= 9; i++) {
        for(int j = 0; j <= 9; j++) {
            int x = i, y = j, cnt = 0;
            for(int k = 0; k < n; k++) {
                if(s[k] - '0' == x) {
                    cnt++;
                    swap(x, y);
                }
            }
            if(x != y && cnt & 1) cnt--;

            ans = max(ans, cnt);
        }
    }
    cout << n - ans << endl;
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