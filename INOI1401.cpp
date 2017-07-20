#include<bits/stdc++.h>
#define INF 0x7fffffff
#define INFLL 1e17
#define PI 2*acos(0.0)
#define show(x) cout<< #x <<" is "<< x <<"\n"
using namespace std;

#define FS first
#define SC second
#define PB(t) push_back(t)
#define LEN(t) ((int)t.size())
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))
#define POPCOUNT __builtin_popcount

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

vector<VI> valid;
vector<vector<VI>> memo;

int TR, TC, D, mod = 20011;

int doDP(int r, int c, int dir) {
    if (TR == r && TC == c)
        return 1;
    //cout << r << ", " << c << "< " << dir << "\n";

    if (memo[dir][r][c] != -1) {
        return memo[dir][r][c];
    }

    int nr, nc;
    LL res = 0;
    for (int i = 1; i <= D; i++) {
        nr = r + i * (1 - dir);
        nc = c + i * (dir);
        if (nr > TR || nc > TC || !valid[nr][nc]) {
            break;
        }
        res += doDP(nr, nc, !dir) % mod;
    }
    //cout << r << ", " << c << "< " << dir << ">>>" << res << "\n";
    return memo[dir][r][c] = (res % mod);
}


int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int r, c, d; cin >> r >> c >>d; ) {
        memo.assign(2, vector<VI>(r, VI(c, -1)));
        TR = r - 1;
        TC = c - 1;
        D = d;
        valid.assign(r, VI(c, 0));

        for (auto& row : valid) {
            for (auto& cel : row) {
                cin >> cel;
            }
        }

        cout << (doDP(0, 0, 0) + doDP(0, 0, 1)) % mod << "\n";
    }


return 0;
}
