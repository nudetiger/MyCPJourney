#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>

#define int long long
#define bs bitset<20>
#define INF 9223372036854775807

using namespace std;

int n, k, ans = 0;
vector<int> d(1 << 21, INF);
queue<int> q;

void bfs() {
    int v;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < k; i++) {
            v = u ^ (1 << i);
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                ans = max(ans, d[v]);
                q.push(v);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("STONE.INP", "r", stdin);
    freopen("STONE.OUT", "w", stdout);

    cin >> n >> k;

    int x; bs inp;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        x = bs(inp).to_ullong();
        d[x] = 0;
        q.push(x);
    }

    bfs();
    
    cout << k - ans;

    return 0;
}