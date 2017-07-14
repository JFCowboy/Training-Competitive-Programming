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
typedef pair<LL, LL> PII;
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

    for (int n, x, y; cin >> n >> x >> y;) {
        VPII contests(n);
        VLL ini(x), fin(y);
        for (auto& par : contests) {
            cin >> par.FS >> par.SC;
        }

        for(auto& num : ini)
            cin >> num;

        for(auto& num : fin)
            cin >> num;

        sort(ALL(ini));
        sort(ALL(fin));

        LL mn, mx;
        LL res = INF;
        for (auto& par : contests) {
            mn = lower_bound(ALL(ini), par.FS) - ini.begin();
            mx = lower_bound(ALL(fin), par.SC) - fin.begin();

            if (mn >= 0 && ini[mn] > par.FS) {
                mn--;
            }

            if(mn >= 0 && mx < fin.size()) {
                res = min(res, fin[mx] - ini[mn] + 1);
            }
        }
        if(res == INF)
            res = 0;

        cout << res << "\n";
    }

return 0;
}
