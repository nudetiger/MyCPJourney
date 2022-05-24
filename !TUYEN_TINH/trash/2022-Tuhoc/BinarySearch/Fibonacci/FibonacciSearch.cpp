#include <iostream>
#include <cmath>

#define ull unsigned long long
#define ll long long

using namespace std;

const float ALPHA = (1 + sqrt(5)) / 2;
const float BETA = 1 - ALPHA;

ll log(ull a, double b)
{
    return floor(log(a) / log(b));
}

ull f(ull a) {
    return (pow(ALPHA, a) - pow(BETA, a))/sqrt(5);
}

int fs(ull a, ull b) {
    ull min_power;
    if(a == 0) min_power = 0;
    else min_power = log(a, 1.62) - 1;
    ull max_power = log(b, 1.62) + 2;

     
    while(f(min_power) < a) min_power ++;
    while(f(max_power) > b) max_power --;
    cout << min_power << " " << max_power << "\n";

    return max_power - min_power + 1;
    // return f(a);
}

int main(){

    freopen("FIBONACCISEARCH.INP", "r", stdin);

    ull a,b;
    cin >> a >> b;

    ull ans = fs(a, b);
    cout << ans;
    return 0;
}