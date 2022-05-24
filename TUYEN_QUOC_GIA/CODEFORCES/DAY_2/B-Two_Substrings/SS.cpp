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
    
    freopen("SS.INP", "r", stdin);
    freopen("SS.OUT", "w", stdout);

    string s;
 
    cin >> s;
    
    int phase = 0;
    int f = 0;
    for(int i = 1; i < s.length(); i++) {
        if(phase == 0) {
            if(s[i] == 'A' && s[i-1] == 'B') {
                phase = 1;
                i ++;
            }
        } else {
            if(s[i] == 'B' && s[i-1] == 'A') {
                f = 1;
                break;
            }
        }
    }
 
    if(f == 1) {
        cout << "YES";
        return 0;
    }

    phase = 0;
    for(int i = 1; i < s.length(); i++) {
        if(phase == 0) {
            if(s[i] == 'B' && s[i-1] == 'A') {
                phase = 1;
                i ++;
            }
        } else {
            if(s[i] == 'A' && s[i-1] == 'B') {
                f = 1;
                break;
            }
        }
    }

    if(f == 1) cout << "YES";
    else cout << "NO";
 
    return 0;
}