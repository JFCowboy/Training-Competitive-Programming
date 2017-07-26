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

vector< pair<int, PII> > order;
VI memo;

int doDP(int idx) {
    if (idx >= LEN(order))
        return 0;

    if(memo[idx] != -1)
        return memo[idx];

    //cout << idx << "ini\n";
    int res = doDP(idx + 1), i;
    for (i = idx + 1; i < LEN(order); i++) {
        if (order[idx].FS + order[idx].SC.FS <= order[i].FS) {
            res = max(res, doDP(i) + order[idx].SC.SC);
            break;
        }
    }

    if (i == LEN(order))
        res = max(res, order[idx].SC.SC);

    //cout << idx << ": " << res << "ini\n";
    return memo[idx] = res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;

    for (int cas = 0; cas < t; cas++) {
        cin >> n;
        memo.assign(n + 1, -1);
        order.assign(n, pair<int, PII>());
        for (auto& ord : order) {
            cin >> ord.FS >> ord.SC.FS >> ord.SC.SC;
        }

        sort(ALL(order));

        cout << doDP(0) << "\n";
    }

return 0;
}
