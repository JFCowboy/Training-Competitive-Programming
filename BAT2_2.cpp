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

VI nums;
vector<VI> memo;

int do_DP(int idx, int lis, int lds) {
    if (idx == nums.size())
        return 0;

    if( memo[lis][lds] != -1)
        return memo[lis][lds];

    int res = do_DP(idx + 1, lis, lds) + 1;
    if (lis == 0 || nums[idx] > nums[lis])
        res = min(res, do_DP(idx + 1, idx, lds));
    if (lds == 0 || nums[idx] < nums[lds])
        res = min(res, do_DP(idx + 1, lis, idx));

    return memo[lis][lds] = res;
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
        nums.assign(n + 1, 0);
        memo.assign(n + 1, VI(n, -1));

        for (int i = 1; i <= n; i++)
            cin >> nums[i];

        cout << n - do_DP(0, 0, 0) << "\n";
    }

return 0;
}
