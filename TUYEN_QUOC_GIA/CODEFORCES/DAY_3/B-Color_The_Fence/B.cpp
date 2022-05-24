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
 
bool cmp(II& a, II& b) {
    if(a.fs < b.fs) return true;
    if(a.fs > b.fs) return false;
    if(a.sc > b.sc) return true;
    return false;
}
 
bool cmp2(II& a, II& b) {
    if(a.sc > b.sc) return true;
    if(a.sc < b.sc) return false;
    if(a.fs < b.fs) return true;
    return false;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("B.INP", "r", stdin);
    freopen("B.OUT", "w", stdout);
 
    int n;
    cin >> n;
 
    int d[10];
    II cost[9];
    int low = INF, dg = 0;
 
    for(int i = 1; i <= 9; i++) {
        cin >> d[i];
        cost[i-1] = mp(d[i], i);
    }
    sort(cost, cost + 9, cmp);
    dg = cost[0].sc;
    if(n < d[dg]) {
        cout << -1 << endl;
        return 0;
    }
 
    sort(cost, cost + 9, cmp2);
 
    string s = "";
    while(n > 0) {
        if(n < d[dg]) {
            break;
        } else {
            n -= d[dg];
            s += dg + '0';
        }
    }
 
    int x = 0;
    for(int i = 0; i < s.size(); i++) {
        int dc = d[s[i] - '0'];
        while(true) {
            if(cost[x].sc == s[i] - '0') break;
            if(cost[x].fs > dc + n) {
                if(x == 8) {
                    cout << s << endl;
                    return 0;
                }
                x++;
                continue;
            }
            s[i] = cost[x].sc + '0';
            n -= abs(cost[x].fs - dc);
            break;
        }
    }
 
    cout << s;
    return 0;
}