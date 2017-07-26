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

LL powerMod (LL a, LL x, LL mod) {
    if (x == 0)
        return 1;
    if (x == 1)
        return a;
    LL a2 = powerMod(a, x / 2, mod);
    LL res = (a2 * a2) % mod;
    if (x & 1) {
        res = (res * a) % mod;
    }

    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int MX_TAM = 200001;
    LL mod = 1e9 + 7;

    VLL fact(MX_TAM), invFact(MX_TAM);
    fact[0] = fact[1] = 1;
    invFact[0] = invFact[1] = 1;

    for (int i = 2; i < MX_TAM; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        invFact[i] = powerMod(fact[i], mod - 2, mod);
    }

    int t;
    cin >> t;

    int x[2];
    int y[2];
    int difX, difY;
    for (int cas = 0; cas < t; cas++) {

        for (int i = 0; i < 2; i++) {
            cin >> x[i] >> y[i];
        }
        difX = x[1] - x[0];
        difY = y[1] - y[0];

        LL res = 0;
        LL aux ;
        for (int i = 0; i <= min(difX, difY); i++) {
            aux = (((fact[difX + difY - i] * invFact[difX]) % mod) * invFact[difY - i]) % mod;
            aux *= (((fact[difX] * invFact[i])% mod) * invFact[difX - i]) % mod;
            res = (res + aux) % mod;
        }

        cout << "Case " << cas + 1 << ": " << res << "\n";
    }

return 0;
}
