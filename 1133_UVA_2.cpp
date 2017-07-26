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

    for (int n, cas = 0; cin >> n; cas ++) {
        vector< pair<int, PII> > order(n);
        pair<int, PII> _this, _other;
        string aux;

        for (auto& ord : order) {
            cin >> aux >> ord.FS >> ord.SC.FS >> ord.SC.SC;
        }

        sort(ALL(order));

        vector<int> dp(n);
        int res = 0;

        for (int i = 0; i < n; i++) {
            _this = order[i];
            dp[i] = _this.SC.SC;
            for (int j = 0; j < i; j++) {
                _other = order[j];
                if (_other.FS + _other.SC.FS <= _this.FS) {
                    dp[i] = max(dp[i], dp[j] + _this.SC.SC);
                    res = max(res, dp[i]);
                }
            }
        }

        if(cas > 0)
            cout << "\n";
        cout << res << "\n";
    }

return 0;
}
