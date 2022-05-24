#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t main() {

    freopen("POSTER.INP", "r", stdin);
    freopen("POSTER.OUT", "w", stdout);

    int n, m, k;
    int a, b, c, d;
    cin >> n >> m >> k;
    vector<vector<int>> board(m+2, vector<int>(n+2, 0));

    for(int i = 0; i < k; i ++) {
        cin >> b >> a >> d >> c;

        board[a][b] += 1;
        board[c+1][d+1] += 1;
        board[a][d+1] -= 1;
        board[c+1][b] -= 1;
    }

    int ans = 0;
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j++) {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
            if(board[i][j] >= 2) ans += board[i][j] - 1;
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << ans;


    return 0;
}