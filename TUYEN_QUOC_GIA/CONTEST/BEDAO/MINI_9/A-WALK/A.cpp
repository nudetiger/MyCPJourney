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

    cout << t << " " << 4*(1 << (t-2)) - 2 + dis;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);

    int x, y;
    cin >> x >> y;

    solve(x, y);

    return 0;
}