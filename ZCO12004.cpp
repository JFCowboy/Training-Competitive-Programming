#include<bits/stdc++.h>
#define INF 0x7fffffff
#define INFLL 1e17
#define PI 2*acos(0.0)
#define show(x) cout<< #x <<" is "<< x <<"\n"
using namespace std;

#define FS first
#define SC second
#define PB(t) push_back(t)
#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))
#define POPCOUNT __builtin_popcount

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<PII> VPII;

VI cost;
vector<VI> memo;

int do_DP(int idx, int used, int n) {
    if (idx >= n)
        return 0;
    if (memo[used][idx] != -1)
        return memo[used][idx];
    if (used)
        return do_DP(idx + 1, 0, n) + cost[idx];

    return memo[used][idx] = min (do_DP(idx + 1, 0, n) + cost[idx]
                , do_DP(idx + 1, 1, n));
}

int solve(int n) {
    int res = 0;

    memo.assign(2, VI(n, -1));
    res = do_DP(1, 0, n) + cost[0];
    memo.assign(2, VI(n, -1));
    res = min(res, do_DP(1, 1, n - 1) + cost[n - 1]);

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n; cin >> n;) {
        cost.assign(n, 0);

        for (auto& val : cost)
            cin >> val;

        cout << solve(n) << "\n";
    }

return 0;
}
