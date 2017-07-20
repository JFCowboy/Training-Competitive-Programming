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

VPII parejas;
// Recurtion TLE / judge don't permit unorderedmap
// inside main
// memo.assign(n, map<int, int>())
// cout << abs(doDP(0, 0)) << "\n";

//AC Adding a LIMIT if acc if to small or to large, it don have in the answer
vector<map<int, int> > memo;
int LIM = 1000;

int doDP (int idx, int acc) {
    if (idx == parejas.size())
        return acc;

    if (acc > LIM || acc < -LIM)
        return INF / 2;

    if (memo[idx].count(acc) > 0)
        return memo[idx][acc];

    int dif = parejas[idx].FS - parejas[idx].SC;
    int res1 = doDP(idx + 1, acc + dif);
    int res2 = doDP(idx + 1, acc - dif);

    if (abs(res1) < abs(res2))
        return res1;

    return memo[idx][acc] = res2;
}
//

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    for (int n; cin >> n; ) {
        parejas.assign(n, PII());
        //int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> parejas[i].FS >> parejas[i].SC;
            //sum += abs(parejas[i].FS - parejas[i].SC);
        }

        memo.assign(n, map<int, int>());
        cout << abs(doDP(0, 0)) << "\n";
    }

return 0;
}
