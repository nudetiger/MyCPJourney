#pragma GCC optimize("Ofast")

#include <iostream>
#include <iterator>
#include <set>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
 
#define int long long
#define INF 2147483647 

using namespace std;

void solve(int x, int y) {

    if(x == y) {
        cout << 0 << " " << 0;
        return;
    }

    int dis = abs(x - y);

    int t = 1;
    if(dis >= 1) t = log2(abs(dis-1)) + 2;

    if((y > x && t % 2 == 1) || (x > y && t % 2 == 0)) t++;

    int p2 = 1 << (t-2);
    cout << t << " " << 4*p2 - 2 + dis;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("WALK.INP", "r", stdin);
    freopen("WALK.OUT", "w", stdout);

    int x, y;
    cin >> x >> y;

    // int i = 1;
    // int dis = 0, ldif = 0;
    // while(1) {
    //     int dif = pow(-1, i & 1) * (1 << (i-1));
    //     int f = x + dif;
    //     dis += abs(dif) + ldif;
    //     ldif = abs(dif);

    //     if((y < 0 && f <= y) || (y > 0 && f >= y)) {
    //         dis -= abs(f) - abs(y);
    //         break;
    //     }
    //     i ++;
    // }


    // cout << i << " " << dis << endl;
    solve(x, y);

    return 0;
}