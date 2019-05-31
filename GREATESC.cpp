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

int BFS(int s, int t) {
    queue<int> q;
    VI visit(LEN(g), 0);
    int dist;

    q.push(s);
    q.push(0);

    while (!q.empty()) {
        s = q.front();q.pop();
        dist = q.front();q.pop();

        if (s == t)
            return dist;
        if (visit[s])
            continue;
        visit[s] = 1;

        for (int v, i = 0; i < LEN(g[s]); i++) {
            v = g[s][i];
            q.push(v);
            q.push(dist + 1);
        }

    }


    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n, m, u, v, s, t; cin >> n >> m; ) {
        g.assign(n, VI());

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u --;v --;
            g[u].PB(v);
            g[v].PB(u);
        }

        cin >> s >> t;
        s--; t--;
        cout << BFS(s, t) << "\n";
    }

return 0;
}
