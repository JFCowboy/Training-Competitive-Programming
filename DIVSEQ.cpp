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

    for(int n; cin >> n; ) {
        VLL nums(n + 1);
        nums[0] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
        }

        VI dp(n + 1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[ i ] % nums[ j ]) == 0) {
                    dp[ i ] = max(dp[ i ], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }

        cout << res << "\n";
    }
return 0;
}
