#include <iostream>
#include <vector>
#include <algorithm>

#define pii pair<int,int>
using namespace std;

int main() {

    freopen("STADIUM.INP", "r", stdin);
    freopen("STADIUM.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pii> t(n);
    int a,b;
    for(int i = 0; i < n; i ++) {
        cin >> a >> b;
        t[i] = make_pair(a,b);
    }

    return 0;
}