#include <iostream>
#include <map>

using namespace std;

int n, m;
int c = 0;
int v[20], v2[20];
map<int, int> sums;

void solve1(int k, int a, int sum) {
    if(a == 1) {
        sum += v[k];
        if(sum >= m){
            if(sum == m) c++;
            return;
        } 
        
        if(sums.find(sum) == sums.end()) {
            sums[sum] = 1;
        } else {
            sums[sum]++;
        }
    }
    if(k >= n/2-1) return;
    solve1(k+1, 0, sum);
    solve1(k+1, 1, sum);
}

void solve2(int k, int a, int sum) {
    if(a == 1) {
        sum += v2[k];
        if(sum >= m){
            if(sum == m) c++;
            return;
        } 
        if(sums.find(m-sum) != sums.end()) {
            c += sums[m-sum];
        }
    }
    if(k >= n-n/2-1) return;
    solve2(k+1, 0, sum);
    solve2(k+1, 1, sum);
}

int main() {

    freopen("BALANCE.INP", "r", stdin);
    freopen("BALANCE.OUT", "w", stdout);

    cin >> n >> m;
    for(int i = 0; i < n/2; i++) {
        cin >> v[i];
    }
    for(int i = n/2; i < n; i++) {
        cin >> v2[i-n/2];
    }

    solve1(0, 0, 0);
    solve1(0, 1, 0);
    solve2(0, 0, 0);
    solve2(0, 1, 0);

    cout << c;
    return 0;
}