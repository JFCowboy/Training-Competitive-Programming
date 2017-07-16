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

    int t;
    cin >> t;

    for (int cas = 0; cas < t; cas++) {
        string str;
        cin >> str;
        int n = LEN(str);

        vector<VI> dp(2, VI(n + 1, 0));
        int idxi, idxi1;
        for (int i = 0; i < n; i++) {
            idxi = i % 2;
            idxi1 = (i + 1) % 2;
            for (int j = 0; j < n; j++) {
                dp[idxi][j + 1] = max(dp[idxi][j], dp[idxi1][j + 1]);
                if (str[i] == str[n - 1 - j]) {
                    dp[idxi][j + 1] = max(dp[idxi][j + 1], dp[idxi1][j] + 1);
                }
            }
        }

        cout << n - dp[(n - 1) % 2][n] << "\n";
    }

return 0;
}
