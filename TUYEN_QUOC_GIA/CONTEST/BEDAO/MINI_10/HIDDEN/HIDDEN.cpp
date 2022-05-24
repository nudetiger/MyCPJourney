#pragma GCC optimize("Ofast")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <time.h>
#include <cmath>

#define int long long
#define II pair<int, int>
#define fs first
#define sc second
#define INF 9223372036854775807

int n, k;
int arr[32000];

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);   
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

vector<int> factor(int n) {
    vector<int> v;
    while (n % 2 == 0) {
        v.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) v.push_back(n);

    return v;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("HIDDEN.INP", "r", stdin);
    freopen("HIDDEN.OUT", "w", stdout);

    int a, T;
    int ans = 0;

    cin >> a >> T;

    if(T % a != 0) {
        cout << -1;
    } else {

        vector<int> v = factor(T);
        int x = v[0];
        int y = 1;
        int f = 0;
        for(int i = 1; i < v.size(); i++) {
            if(v[i] == v[i-1] && f == 0) x *= v[i];
            else {
                f = 1;
                y = y * v[i];
            }
        }

        if(y == 1) cout << -1;
        else cout << x << " " << y;

    }

    return 0;
}