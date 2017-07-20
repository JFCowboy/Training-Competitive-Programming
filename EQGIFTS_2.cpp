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
//
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    VPII parejas;
    for (int n; cin >> n; ) {
        parejas.assign(n, PII());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> parejas[i].FS >> parejas[i].SC;
            sum += abs(parejas[i].FS - parejas[i].SC);
        }

        int mx = sum, dif, idx;
        vector<vector<int> > dp(n, vector<int>(mx + 1, 0));
        dif = abs(parejas[0].FS - parejas[0].SC);
        dp[0][dif] = 1;
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= mx; j++) {
                dp[i][j] = dp[i - 1][j];
                dif = abs(parejas[i].FS - parejas[i].SC);
                if (j - dif >= 0) {
                    dp[i][j] |= dp[i - 1][j - dif];
                }
            }
        }
        int res;
        for (res = mx/2; res >= 0; res--) {
            if (dp[n - 1][res])
                break;
        }
        //cout << res << "<<<<\n";
        cout << abs(sum - 2 * res) << "\n";
    }

return 0;
}
