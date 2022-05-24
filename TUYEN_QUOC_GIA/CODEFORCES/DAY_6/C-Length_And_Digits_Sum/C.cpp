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
    
    int m, s;
    cin >> m >> s;
    
    if((m > 1 && s == 0) || (9*m < s)) {
        cout << "-1 -1\n";
        return 0;
    }
    if(m == 1 && s == 0) {
        cout << "0 0\n" << endl;
        return 0;
    }
    
    char ans1[m], ans2[m];

    int s1 = s;
    for(int i = 0; i < m; i++) {
        if(s1 <= 9) {
            ans1[i] = s1 + '0';
            s1 = 0;
            continue;
        }
        for(int j = 9; j >= 0; j--) {
            ans1[i] = j + '0';
            if(s1 - j >= 0) {
                s1 -= j;
                break;
            }
        }
    }

    int s2 = s-1;
    ans2[0] = '1';
    for(int i = m-1; i >= 1; i--) {
        if(s2 <= 9) {
            ans2[i] = s2 + '0';
            s2 = 0;
            continue;
        }
        for(int j = 9; j >= 0; j--) {
            ans2[i] = j + '0';
            if(s2 - j >= 0) {
                s2 -= j;
                break;
            }
        }
    }

    if(s2 >= 1) ans2[0] = s2 + 1 + '0';

    for(int i = 0; i < m; i++) {
        cout << ans2[i];
    }
    cout << " ";
    for(int i = 0; i < m; i++) {
        cout << ans1[i];
    }

    return 0;
}