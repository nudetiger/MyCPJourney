#include <iostream>
#include <string>
#include <algorithm>

#define ll long long

using namespace std;

string rkd(string x, int k) {

    int n = x.size();
    if(k >= n) return "0";
    int i = 0;
    int start = 0;
    int max = 9;
    while(k > 0) {
        for(i = 0; i < n; i++) {
            if(k == 0) break;
            if(x[i] == 'x') continue;
            if(i == n-1) {
                while(k > 0) {
                    for(i = 0; i < n; i++) {
                        if(k == 0) break;
                        char sad[1];
                        sprintf(sad, "%d", max);
                        if(x[i] == sad[0]) {
                            x[i] = 'x';
                            k--;
                        }
                    }
                    max--;
                }
                break;
            }
            if(x[i] > x[i+1]) {
                x[i] = 'x';
                k--;
            }
        }
    }
    string ans;
    for(i = 0; i < n; i++) {
        if(x[i] != 'x') {
            if(ans.empty() && x[i] == '0') continue;
            ans += x[i];
        }
    }
    if(ans.empty()) ans = "0";
    return ans;
}

int main() {

    freopen("RKD.INP", "r", stdin);
    freopen("RKD.OUT", "w", stdout);
    int x, k;
    cin >> x >> k;
    string ans = rkd(to_string(x), k);
    cout << ans;
    return 0;
}