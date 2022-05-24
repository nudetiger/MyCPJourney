#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;


int getRandom(){
    return 1 + (int)(rand()*6/(1+RAND_MAX));
}

int main()
{
    srand((unsigned int)time(NULL));
    int att, req, res;
    int limit = 3000000;
    int t = 0;
    int r = 0;
    
//    cin >> req;
	req = 3;
	att = 0;
	for(att = 0; att < limit; att++) {
		t=0;
		for(int i = 0; i < req*6; i++) {
			
			if(getRandom() >= 6) t++;
			if(t >= req) {
				r++;
				break;
			}
		}
	}
	float ans = 100*r/limit;
	cout << ans;

    return 0;
}

