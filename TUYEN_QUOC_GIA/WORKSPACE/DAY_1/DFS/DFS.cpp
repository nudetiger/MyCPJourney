#include <bits/stdc++.h>

#define int long long

using namespace std;

int m, n;
vector<vector<int>> mt;
vector<int> vst;
vector<int> pre;

void dfs(int s) {
    for(int i = 0; i < mt[s].size(); i++) {
        int v = mt[s][i];
        if(vst[v] == 1) continue;
        pre[v] = s;
        if(v == n-1) {
            int f = v;
            stack<int> st;
            while(pre[f] != -1) {
                st.push(f+1);
                f = pre[f];
            }
            st.push(1);
            while(!st.empty()) {
                cout << st.top() << " ";
                st.pop();
            }
            exit(0);
            return;
        }
        vst[v] = 1;
        dfs(v);
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("DFS.INP", "r", stdin);
    freopen("DFS.OUT", "w", stdout);

    cin >> n >> m;
    mt.resize(n);
    pre.resize(n);
    vst.resize(n, 0);
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1].push_back(v-1);
    }
    for(int i = 0; i < n; i++) {
        sort(mt[i].begin(), mt[i].end());
    }

    pre[0] = -1;
    vst[0] = 1;
    dfs(0);

    return 0;
}