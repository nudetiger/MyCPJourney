#include <bits/stdc++.h>
#define ll long long
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define name "BRACKET"
#define opcl freopen(name".inp", "r",stdin); freopen(name".out", "w",stdout);

using namespace std;
int n, x[27], d, ans = 0, ok;

int main()
{
    faster;
    opcl;
    cin >> n;
    if (n % 2 == 0)
    {
        ll sj, sl;
        n /= 2;
        ll si = sj = sl = 1;
        for (int i = 1; i <= 2*n; i++)
        {
            if (i >= n + 2)
                sj *= i;
            if (i <= n)
                si *= i;
        }
        //cout << si << ' ' << sj <<' ' << sl << endl;
        cout << sj / si;
    }
    else cout << 0;
    return 0;
}
