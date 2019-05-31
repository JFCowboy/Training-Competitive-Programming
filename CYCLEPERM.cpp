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

vector< VI > res;
VI path, visit;
int idx;

void DFS (int u) {
    res[idx].PB(u);
    if (visit[u]) {
        return;
    }
    visit[u] = 1;
    DFS(path[u]);
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n; cin >> n; ) {
        path.assign(n, 0);
        visit.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> path[i];
            path[i] --;
        }
        idx = 0;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                res.PB(VI());
                DFS(i);
                idx++;
            }
        }

        cout << LEN(res) << "\n";
        for (int i = 0; i < LEN(res); i++) {
            for (int j = 0; j < LEN(res[i]); j++) {
                cout << res[i][j] + 1 << " ";
            }
            cout << "\n";
        }
    }

return 0;
}
