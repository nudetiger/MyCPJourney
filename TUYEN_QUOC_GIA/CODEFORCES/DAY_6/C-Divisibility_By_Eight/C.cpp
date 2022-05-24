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
    
    string s;
    cin >> s;

    string arr[28115];

    if(s.length() == 1) {
        if(s[0] == '8' || s[0] == '0') {
            cout << "YES\n" << s << endl;
        } else cout << "NO\n";
        return 0;
    } else if(s.length() == 2) {
        if(s[0] == '8' || s[0] == '0') {
            cout << "YES\n" << s[0] << endl;
        } else if(s[1] == '8' || s[1] == '0') {
            cout << "YES\n" << s[1] << endl;
        } else if(((s[0] - '0') * 10 + (s[1] - 0)) % 8 == 0) {
            cout << "YES\n" << s << endl;
        } else cout << "NO\n";
        return 0;
    }

    for (int i = 0; i <= 992; i+= 8) arr[i/8] = to_string(i);

    for (int i = 0; i < 125; i++) {
        int pos = s.length() - 1, j = arr[i].length()-1;
        while(true) {
            if(s[pos] == arr[i][j]) j--;
            if(j == -1) {
                cout << "YES" << endl << arr[i] << endl;
                return 0;
            }
            pos--;
            if(pos == -1) break;
        }
    }
    cout << "NO" << endl;

    return 0;
}