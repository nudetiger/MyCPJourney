#include <bits/stdc++.h>
#define ll long long
#define name "FLOWER"
#define opcl freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);

using namespace std;

long long n, a;

ll bcnn(ll a, ll b)
{
    return 1ULL * (a * b) / __gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    opcl;
    cin >> n;
    queue<ll> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        arr.push(a);
    }
    ll ans = 1;
    while(!arr.empty())
    {
        ans = bcnn(ans, arr.front());
        arr.pop();
    }
    cout << ans;
    return 0;
}
