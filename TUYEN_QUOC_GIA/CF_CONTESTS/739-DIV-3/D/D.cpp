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
 
string p[64];
 
int cal(string s, string s2) {
    int p1 = 0, p2 = 0;
 
    int ans = 0;
    while(p1 < s.length() && p2 < s2.length()) {
        if(s[p1] == s2[p2]) p2++, ans++;
        p1++;
    }
 
    return s.length() + s2.length() - 2*ans; 
}
 
void solve() {
 
    string s;
    cin >> s;
 
    int ans = s.length() + 1;
    for(int i = 0; i < 64; i++) {
        ans = min(ans, cal(s, p[i]));
    }
    
    cout << ans << endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("D.INP", "r", stdin);
    freopen("D.OUT", "w", stdout);
    
    long long x = 1;
    for(int i = 0; i < 64; i++) {
        p[i] = to_string(x);
        x *= 2;
    }
 
    int t;
    cin >> t;
    while (t--) solve();
 
    return 0;
}