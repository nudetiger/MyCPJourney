#include <bits/stdc++.h>

#define int long long

using namespace std;

const int SIZE = 200000;

int m, n, cnt;
stack<int> stack;
vector<int> low(SIZE);
vector<int> num(SIZE);
vector<vector<int>> mt(SIZE);

void tarjan() {

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("SCONNECT.INP", "r", stdin);
    freopen("SCONNECT.OUT", "w", stdout);

    cin >> n >> m;

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1].push_back(v-1);
        mt[v-1].push_back(u-1);
    }
    
    for(int i = 0; i < n; i++) {
        sort(mt[i].begin(), mt[i].end());
    }

    tarjan();

    return 0;
}