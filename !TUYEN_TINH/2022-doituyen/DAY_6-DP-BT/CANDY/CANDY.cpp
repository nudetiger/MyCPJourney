#include <bits/stdc++.h>

using namespace std;

int n, k, c = 0;

void backtrack(int in, int v, int sum) {
    if(in == k-1) {
        
    }
}

int main() {

    freopen("CANDY.INP", "r", stdin);
    freopen("CANDY.OUT", "w", stdout);

    if(k == 1) {
        cout << 1;
        return;
    }
    if (k == 2) {
        cout << (n-1)/2;
        return;
    }
    if(k*(k+1)/2 > n) {
        cout << 0;
        return;
    }


    backtrack(1, 1, 0);
    return 0;
}