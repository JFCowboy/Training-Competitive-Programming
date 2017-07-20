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

//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    for (int n; cin >> n; ) {
        string str, rev;
        cin >> str;
        rev = str;
        reverse(ALL(rev));

        vector<VI> dp(2, VI(n + 1, 0));

        for (int i = 0; i < n; i++) {
            int idxi = i % 2;
            int idxi_1 = (i + 1) % 2;
//            cout << str[i] << ": ";
            for (int j = 1; j <= n; j++) {
                dp[idxi][j] = max(dp[idxi_1][j - 1] + (str[i] == rev[j - 1]),
                               max(dp[idxi_1][j], dp[idxi][j - 1]));
//                cout << dp[idxi][j] << " ";
            }
//            cout << "\n";
        }
        cout << n - dp[(n - 1) % 2][n] << "\n";
    }

return 0;
}
