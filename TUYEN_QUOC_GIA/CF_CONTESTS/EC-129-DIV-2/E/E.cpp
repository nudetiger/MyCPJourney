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
    
    freopen("E.INP", "r", stdin);
    freopen("E.OUT", "w", stdout);
    
    int n;
    cin >> n;

    II door[n-1], door2[n-1];

    for(int i = 0; i < n-1; i++) {
        cin >> door[i].fs >> door[i].sc;
        cin >> door2[i].fs >> door2[i].sc;
        
    }

    return 0;
}