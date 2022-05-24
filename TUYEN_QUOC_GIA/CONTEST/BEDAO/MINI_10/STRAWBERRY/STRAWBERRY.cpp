#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <time.h>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

int n, k;
int arr[32000];

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("STRAWBERRY.INP", "r", stdin);
    freopen("STRAWBERRY.OUT", "w", stdout);

    int n, x;
    int ans = 0;

    cin >> n >> x;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        int y = (x-1) / arr[i];
        ans = ans + (arr[i] * y * (y+1))/ 2;
    }

    cout << ans;

    return 0;
}