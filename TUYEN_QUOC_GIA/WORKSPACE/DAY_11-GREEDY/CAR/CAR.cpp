#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <algorithm>

#include <vector>
#include <bitset>
#include <set>
#include <string>

#define int long long
#define II pair<int, int>
#define III pair<int, pair<int, int>>
#define DI pair<double, int>
#define fs first
#define sc second
#define mp(a, b) make_pair(a, b)
#define INF 9223372036854775807

using namespace std;

bool cmp(DI a, DI b) {
    return a.fs < b.fs;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("CAR.INP", "r", stdin);
    freopen("CAR.OUT", "w", stdout);

    int n, inp;
    cin >> n;
    DI arr[n]; 
    II tmp[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i].fs;
        tmp[i].fs = arr[i].fs;
        arr[i].sc = i + 1;
    }
    for(int i = 0; i < n; i++) {
        cin >> inp;
        tmp[i].sc = inp;
        arr[i].fs = arr[i].fs / inp;
    }
    sort(arr, arr + n);

    int ans = 0, time = 0;
    for(int i = n-1; i >= 0; i--) {
        int index = arr[i].sc - 1;
        time += tmp[index].sc;
        ans += tmp[index].fs * time;
    }

    cout << ans << "\n";
    for(int i = n-1; i >= 0; i--) {
        cout << arr[i].sc << " ";
    }

    return 0;
}