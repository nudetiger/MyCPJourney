#include <bits/stdc++.h>

#define pii pair<int,int>
#define mp(a, b) make_pair(a, b)

using namespace std;

int n = 888, m;
vector<int> visited(n, 0);
vector<int> roots(n, 0);
vector<vector<int>> mt(n, vector<int>(n, 0));

void dfs(int strt) {
    visited[strt] = 1;

   stack<int> st;
    st.push(strt);

    while(!st.empty()) {
        int u = st.top();
        st.pop();
        for(int i = 0; i < n; i++) {
            if(mt[u][i] == 0) continue;
            if(visited[i]) continue;
            visited[i] = 1;
            st.push(i);
        }
    }
}

int dfs(int n, vector<vector<int>>& mt) {

    int cnt = 0;

    for(int strt = 0; strt < n; strt++) {
        if(visited[strt]) continue;
        roots[strt] = 1;
        dfs(strt);
    }
    for(int i = 0; i < n; i++) visited[i] = 0;
    for(int strt = n-1; strt >= 0; strt--) {
        if(visited[strt] || roots[strt] == 0) continue;
        cnt ++;
        dfs(strt);
    }

    return cnt;
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("MESSAGE.INP", "r", stdin);
    freopen("MESSAGE.OUT", "w", stdout);

    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        mt[u-1][v-1] = 1;
    }

    int ans = dfs(n, mt);

    cout << ans;

    return 0;
}