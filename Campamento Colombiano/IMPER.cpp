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

vector<VI> g;
VI visit;
int lastNode, mx;

int DFS (int n, int d) {
    if (visit[n])
        return 0;
    if(d > mx) {
        mx = d;
        lastNode = n;
    }
    visit[n] = 1;

    int res = 0;
    for (auto& v : g[n]) {
        res = max(res, DFS(v, d + 1) + 1);
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n; cin >> n && n > -1; ) {
        g.assign(n, VI());
        int u, dist;
        for (int i = 1; i < n; i++) {
            cin >> u;
            u--;
            g[i].PB(u);
            g[u].PB(i);
        }

        visit.assign(n, 0);
        mx = 0;
        dist = DFS(0, 0);
        visit.assign(n, 0);
        dist = DFS(lastNode, 0);

        cout << dist / 2 << "\n";
    }

return 0;
}
