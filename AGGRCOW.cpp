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

VLL x;

int numCows(int sz) {
    int cnt, next;
    cnt = 1;
    next = x[0] + sz;

    for (int i = 1; i < x.size(); i++) {
        if (x[i] >= next) {
            cnt++;
            next = x[i] + sz;
        }
    }

    return cnt;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, c;
    cin >> T;
    for (int cas = 0; cas < T; cas++) {
        cin >> n >> c;
        x.assign(n, 0);

        for (auto& val : x) {
            cin >> val;
        }

        sort(ALL(x));

        LL inf, cnt, step, mid, res, aux;
        cnt = x[n - 1] + 1;
        inf = 0;

        while (cnt) {
            step = cnt >> 1;
            mid = inf + step;
            aux = numCows(mid);
            //cout << mid << " , " << aux << "\n";
            if (aux >= c) {
                res = mid;
                inf = mid + 1;
                cnt -= step + 1;
            } else {
                cnt = step;
            }
        }

        cout << res << "\n";
    }

return 0;
}
