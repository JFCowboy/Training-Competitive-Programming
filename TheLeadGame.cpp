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

    for (int N; cin >> N;){
        int res, resLead, u, v, aux, score1, score2;
        res = 1;
        score1 = score2 = resLead = 0;

        for (int i = 0; i < N; i++) {
            cin >> u >> v;
            score1 += u;
            score2 += v;
            aux = abs(score1 - score2);
            if (resLead < aux) {
                resLead = aux;
                if (score1 > score2){
                    res = 1;
                } else {
                    res = 2;
                }
            }
        }

        cout << res << " " << resLead << "\n";
    }

return 0;
}
