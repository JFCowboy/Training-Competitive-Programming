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

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout << "aca\n" ;
    for (int n; cin >> n;) {
        vector<LL>a(n), b(n);

        for (auto& v : a)
            cin >> v;
        for (auto& v : b)
            cin >> v;

        vector<LL> pre(n), diff(n), diff2(n);

        pre[0] = b[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + b[i];
        }

        diff[0] = a[0] - pre[0];
        diff2[0] = a[0];
        for (int i = 1; i < n; i++) {
            diff[i] = max(diff[i - 1], a[i] - pre[i]);
            diff2[i] = max(diff2[i - 1], a[i] + pre[i - 1]);
        }

        LL res = a[0];
        for (int i = 1; i < n; i++) {
            res = max(res, max(a[i] + pre[n - 1] - pre[i] + diff2[i - 1]
                      , a[i] + pre[i - 1] + diff[i - 1]) );
//            cout << i << ", " << a[i] + pre[n - 1] - pre[i] + diff2[i - 1] << ":\n";
//            cout << i << ", " << a[i] + pre[i - 1] + diff[i - 1] << "\n";
        }

        cout << res << "\n";
    }

return 0;
}
