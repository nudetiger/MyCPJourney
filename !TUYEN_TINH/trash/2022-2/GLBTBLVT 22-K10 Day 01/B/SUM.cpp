#include <iostream>
#include <map>

using namespace std;

void xuly() {

}

map<int, int> f;
void backtrack(int x[], int n, int s, int k){
    if(k >= n/2) {
        xuly();
        return;
    }
    for(int i = 0; i <= 1; i++) {
        f[sum] ++;
    }
}

int main() {

    freopen("SUM.INP", "r", stdin);

    int n, s;
    cin >> n >> s;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    backtrack(x, n, s);

    return 0;
}