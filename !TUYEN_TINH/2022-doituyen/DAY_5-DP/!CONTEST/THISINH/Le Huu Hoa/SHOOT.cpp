#include <bits/stdc++.h>

using namespace std;

int n, c = 0;

void solve(int k, bool sec, bool trung) {

    if(k == n-2) {
        if(!trung && sec) {
            c++;
        } else if(trung) {
            if(sec) {
                c += 2;
            }
            else {
                c++;
            }
        }
        return;
    }
    if(trung) {
        solve(k+1, sec, 0);
        solve(k+1, 1, 1);
    } else {
        solve(k+1, sec, 1);
    }
}

int main() {

    freopen("SHOOT.INP", "r", stdin);
    freopen("SHOOT.OUT", "w", stdout);

    cin >> n;
    solve(0, 0, 0);
    solve(0, 0, 1);

    cout << c;

    return 0;
}