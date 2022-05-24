#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

double arr[100005];

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("RAID.INP", "r", stdin);
    freopen("RAID.OUT", "w", stdout);

    int n;
    double sm = 0, ans = 0;
    cin >> n;
    double arr[n], pre[n+1];
    cin >> arr[0]; pre[0] = arr[0];
    for(int i = 1; i < n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1] + arr[i]; 
    }
    
    int l = 0, r = n-1;
    double sum = arr[l] + arr[r], best = sum/2;
    for(int l = 1; l < n - 1; l++) {
        sum = pre[l];
        for(int r = n-2; r > l+1; r--) {
            int s = l - r + n - 1;
            sum += arr[r];
            best = min(best, sum / s);
        }
    }

    cout << fixed << setprecision(3) << best << endl;


    return 0;
}