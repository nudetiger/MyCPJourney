#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <bitset>

using namespace std;

const int MINUS = 255;
const int MAX_N = 65026;

int moves[4] = {1, -1, 4, -4};

int vst[MAX_N];
vector<int> dis(MAX_N, 0);

string start, stop; 

string tb(int n) {
    bitset<16> bs(n + MINUS);
    return bs.to_string();
}

int val(string s) {
    int value = bitset<16>(s).to_ulong();
    return value-MINUS;
}

vector<int> gen(string s) {
    vector<int> ret;
    for(int i = 0; i < 16; i++) if(s[i] == '1') {
        for(int j = 0; j < 4; j++) 
            if(i + moves[j] >= 0 && i + moves[j] < 16) 
                if(s[i + moves[j]] == '0') {
                    string s2 = s;
                    s2[i + moves[j]] = '1';
                    s2[i] = '0';
                    ret.push_back(val(s2));
                }

    }
    return ret;
}

void bfs() {

    int x = val(start);
    int y = val(stop);

    queue<int> q;
    vst[x] = 1;
    q.push(x);

    while(!q.empty()) {
        
        int u = q.front();
        q.pop();

        string s = tb(u);

        vector<int> vec = gen(s);
        for(int i = 0; i < vec.size(); i++) {
            int v = vec[i];
            if(v == y) {
                cout << dis[u] + 1;
                return;
            }
            if(vst[v] == 1) continue;
            vst[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }

    }


}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("CHESSCBG.INP", "r", stdin);
    freopen("CHESSCBG.OUT", "w", stdout);

    string inp;
    cin >> start;
    cin >> inp; start += inp;
    cin >> inp; start += inp;
    cin >> inp; start += inp;
    cin >> stop;
    cin >> inp; stop += inp;
    cin >> inp; stop += inp;
    cin >> inp; stop += inp;

    bfs();

    return 0;
}