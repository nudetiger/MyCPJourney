#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

int m, n, cnt = 0, ans = 0;
vector<int> g[MAX_N];
int low[MAX_N], num[MAX_N];

stack<int> st;

void tarjan(int u) {
    
    low[u] = num[u] = ++cnt;
    st.push(u);

    for(int i = 0; i < int(g[u].size()); i++) {
        int v = g[u][i];
        if(num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(num[u] == low[u]) {
        ans ++;
        int tmp;
        do {
            tmp = st.top();
            st.pop();
            num[tmp] = low[tmp] = INT_MAX;
        } while (tmp != u);
    }

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
        g[u-1].push_back(v-1);
    }

    for(int i = 0; i < n; i++) {
        if(!num[i]) tarjan(i);
    }

    cout << ans;

    return 0;
}