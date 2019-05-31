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

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n, k, aux, p; cin >> n >> k; ) {
        vector< set<int> > seq(n);
        VI inSet(n, 0);
        inSet[0] = 1;

        for (int i = 0; i < n; i++) {
            cin >> p;
            for (int j = 0; j < p; j++) {
                cin >> aux;
                seq[i].insert(aux);
            }
        }

        queue<int> q;
        q.push(0);
        int idx, res = 1;
        while (!q.empty()) {
            idx = q.front(); q.pop();

            for (int i = 0; i < n; i++) {
                if (!inSet[i]) {
                    set<int> inter;
                    set_intersection(seq[idx].begin(), seq[idx].end(), seq[i].begin(), seq[i].end(), inserter(inter, inter.begin()));
                    if (inter.size() >= k) {
                        inSet[i] = 1;
                        q.push(i);
                        res ++;
                    }
                }
            }
        }

        cout << res << "\n";
    }

return 0;
}
