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

int pol[100005];

void precompute() {
    int id = 1;
    for(int i = 1; i <= 100000; i++) {
        if(i % 3 == 0 || i % 10 == 3) continue;
        pol[id] = i;
        id ++;
    }
}

void solve() {
    int k;
    cin >> k;
    cout << pol[k] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
    
    precompute();

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}