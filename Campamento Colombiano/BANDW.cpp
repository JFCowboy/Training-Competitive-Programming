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

    for (string strS, strT; cin >> strS >> strT; ){
        if (strS == strT and strS == "*")
            break;
        int res = 0, cnt = 0;
        int n = LEN(strS);

        for (int i = 0; i < n; i++) {
            if (strS[i] != strT[i]) {
                cnt++;
            } else if (cnt > 0){
                res++;
                cnt = 0;
            }
        }
        if (cnt > 0)
            res++;

        cout << res << "\n";
    }

return 0;
}
