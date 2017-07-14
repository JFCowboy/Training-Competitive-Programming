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

int mod = 10000;
vector<VI> memo;

int do_DP(int n, int cas) {
    if(n == 0 && cas == 0)
        return 1;
    if(n < 0)
        return 0;
    //cout << n << ", " << cas << "\n";
    if (memo[cas][n] != -1)
        return memo[cas][n];
    int res = 0;

    if(cas == 0) {
        res = (do_DP(n - 1, 0) + do_DP(n - 2, 0)) % mod;
        res = (res + do_DP(n - 2, 1)) % mod;
        res = (res + do_DP(n - 2, 2)) % mod;
    }
    if(cas == 1) {
        res = do_DP(n - 1, 0);
        res = (res + do_DP(n - 1, 2)) % mod;
    }
    if(cas == 2) {
        res = do_DP(n - 1, 0);
        res = (res + do_DP(n - 1, 1)) % mod;
    }

    return memo[cas][n] = res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //vector<VI> aux(3, VI(1000000));
    for (int n; cin >> n; ) {
        //memo.assign(3, VI(n + 1, -1));
        //cout << do_DP(n, 0) << "\n";
        vector<VI> dp(3, VI(n + 1, 0));
        dp[0][0] = 1;


        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0){
                dp[0][i] += dp[0][i - 1];
                dp[0][i] %= mod;

                dp[1][i] += dp[0][i - 1] + dp[2][i - 1];
                dp[1][i] %= mod;

                dp[2][i] += dp[0][i - 1] + dp[1][i - 1];
                dp[2][i] %= mod;
            }
            if (i - 2 >= 0){
                dp[0][i] += dp[0][i - 2];
                dp[0][i] += dp[1][i - 2];
                dp[0][i] += dp[2][i - 2];
                dp[0][i] %= mod;
            }
        }

        cout << dp[0][n] << "\n";
    }

return 0;
}
