#pragma GCC optimize("Ofast")

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
    double sum = 0;
    cin >> n;
    double arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double best = 0, cs = 0;
    double l = 0, r = 10000;
    double K = (l + r) / 2;

    while(abs(l - r) > 0.0001) {
        
        K = (l + r) / 2;


        cs = arr[1] - K, best = cs;
        for(int i = 2; i < n-1; i++) {
            cs = max(arr[i] - K, cs + arr[i] - K);
            best = max(best, cs);
        }


        if(sum - n * K - best < 0) r = K;
        else l = K;

    }

    cout << fixed << setprecision(3) << K;


    return 0;
}