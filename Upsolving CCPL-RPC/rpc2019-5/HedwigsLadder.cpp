//run: g++ -std=c++14 -o run_sol.exe solution.cpp -DLOCAL_JUDGE
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

const int mod = 10007;

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    VI dp(1001, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < dp.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (i & 1) {
            dp[i]++;
        }
        dp[i] %= mod;
    }

    int t, k, n;
    cin >> t;
    for (int cas = 0; cas < t; cas++) {
        cin >> k >> n;
        cout << k << " " << dp[n] << "\n";
    }
return 0;
}