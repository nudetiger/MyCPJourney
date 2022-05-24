#include <bits/stdc++.h>

#define pii pair<int,int>
#define mp(a, b) make_pair(a, b)

using namespace std;

int move_x[4] = {1, 0, -1, 0};
int move_y[4] = {0, 1, 0, -1};


int bfs(int r, int c, pii start, vector<string>& matrix) {

    vector<vector<int>> visit(r, vector<int>(c, 0));
    vector<vector<int>> dis(r, vector<int>(c, 0));
    queue<pii> q;
    q.push(mp(start.first, start.second));

    visit[start.first][start.second] = 1;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = max(min(u.first + move_x[i], r-1), 0);
            int y = max(min(u.second + move_y[i], c-1), 0);
            if(!visit[x][y] && matrix[x][y] == '.') { 
                dis[x][y] = dis[u.first][u.second] + 1;
                visit[x][y] = 1;
                q.push(mp(x, y));
            }
            if(matrix[x][y] == 'B') {
                return dis[u.first][u.second] + 1;
            }
        }
    }

    return -1;
}

int32_t main() {

    freopen("VMUNCH.INP", "r", stdin);
    freopen("VMUNCH.OUT", "w", stdout);

    int r, c;
    pii bpos, cpos;
    cin >> r >> c;
    vector<string> inp(r);
    for(int i = 0; i < r; i++) {
        cin >> inp[i];
    }

    int found = 0;
    for(int i = 0; i < r; i++) {
        cin >> inp[i];
        for (int j = 0; j < c && found == 0; j++) {
            if(inp[i][j] == 'C') {
                cpos = mp(i, j);
                found = 1;
                break;
            }
        }
    }

    int ans = bfs(r, c, cpos, inp);

    cout << ans;

    return 0;
}