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

    for (int n; cin >> n; ) {
        VI nums(n);
        for (auto& num : nums)
            cin >> num;
        nums.insert(nums.begin(), 0);

        vector<VI> dp(2, VI(n + 1, -1));
        dp[0][0] = dp[1][0] = 0;
        int idx, res = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i] > 0)
                idx = 0;
            else
                idx = 1;
            for (int j = 0; j < i; j++) {
                if (abs(nums[ j ]) < abs(nums[ i ]) && dp[idx ^ 1][j] != -1) {
                    dp[idx][i] = max(dp[idx][i], dp[idx ^ 1][j] + 1);
                    res = max(res, dp[idx][i]);
                }
            }
        }

        cout << res << "\n";
    }

return 0;
}
