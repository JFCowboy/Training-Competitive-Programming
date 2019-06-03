//run: g++ -std=c++14 -o run_sol.exe solution.cpp -DLOCAL_JUDGE
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

vector<VI> triangles(6, VI(3));

int solve(int mask, int val, int ini) {
    if (mask == (1<<6) - 1) {
        if (val != ini) {
            return -INF;
        }
        return 0;
    }
    int res = -INF;
    for (int i = 0; i < 6; i++) {
        if ((mask & (1<<i)) == 0) {
            for (int j = 0; j < 3; j++) {
                if (triangles[i][j] == val) {
                    res = max(res, solve(mask | (1<<i), triangles[i][(j + 1) % 3], ini) + triangles[i][(j + 2) % 3]);
                }
            }
        }
    }

    return res;
}

int solve() {
    int res = -INF;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            res = max(res, solve(1<<i, triangles[i][(j + 1) % 3], triangles[i][j]) + triangles[i][(j + 2) % 3]);
        }
    }

    return res;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    string end = "*";
    while (end != "$") {

        for (int i = 0; i < 6; i++) {
            cin >> triangles[i][0] >> triangles[i][1] >> triangles[i][2];
        }

        int res = solve();

        if (res < 0) {
            cout << "none\n";
        } else {
            cout << res << "\n";
        }

        cin >> end;
    }

return 0;
}