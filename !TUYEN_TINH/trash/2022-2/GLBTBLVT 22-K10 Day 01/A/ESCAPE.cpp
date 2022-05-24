#include <iostream>
#include <vector>

using namespace std;

static vector<int> w;
static int m = 0;

void xuly(int x[]) {
    int ans = 0;
    int n = w.size();
    for(int i = 0; i < n; i++) {
        ans += x[i];
    }
    m = max(ans, m);
    
}

bool check(int a, int b) {
    for(int i = 0; i < 10; i++) {
        if(a%10 + b%10 > 9) return false;
        a/= 10; b/= 10;
    }
    return true;
}

void backtrack(int x[], int k, int sum) {
    if(k >= w.size()){
        xuly(x);
        return;
    }
    x[k] = 0;
    backtrack(x, k+1, sum);
    x[k] = 1;
    if(check(sum, w[k] * x[k])) {
        sum += x[k] * w[k];
        backtrack(x, k+1, sum);
    }

}



int main() {

    freopen("ESCAPE.INP", "r", stdin);
    freopen("ESCAPE.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> weight;
    int a;
    for(int i = 0; i < n; i++) {
        cin >> a;
        weight.push_back(a);
    }
    w = weight;
    int x[weight.size()];
    backtrack(x, 0, 0);
    cout << m;

    return 0;
}