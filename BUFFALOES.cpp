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
vector< VLL > memo;


LL doDP(int idx, int left) {
    if (left == 0 or idx >= LEN(nums))
        return 0;
    if (memo[idx][left] != -1)
        return memo[idx][left];

    LL res = doDP(idx + 1, left);

    for (int i = idx + 1; i < nums.size(); i++) {
        if (nums[idx] < nums[i])
            res = max(res, doDP(i + 1, left-1) + nums[i] - nums[idx]);
    }

    return memo[idx][left] = res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n, k; cin >> n >> k ;) {
        nums.assign(n, 0);
        memo.assign(n, VLL(k, -1));
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cout << doDP(0, k / 2) << "\n";
    }

return 0;
}
