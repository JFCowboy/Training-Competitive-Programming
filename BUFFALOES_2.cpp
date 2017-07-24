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

    for (int n, k; cin >> n >> k ;) {
        VI nums(n + 1);

        nums[0] = INF / 2;
        for (int i = 1; i <= n; i++)
            cin >> nums[i];


        vector< VLL > dp(k / 2 + 1, VLL(n + 1, 0));



        for (int i = 1; i <= k /2; i ++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                for (int k = 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][k - 1] + nums[j] - nums[k]);
                }
            }
        }

        cout << dp[k / 2][n] << "\n";
    }

return 0;
}
