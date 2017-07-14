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

    for (vector<int> ns(3), nreal(3, 0); cin >> ns[0] >> ns[1] >> ns[2];) {
        vector< vector<int> > listas(3);
        int val;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < ns[i]; j++) {
                cin >> val;
                if (listas[i].size() == 0){
                    listas[i].PB(val);
                    nreal[i]++;
                } else if (listas[i][nreal[i] - 1] != val) {
                    listas[i].PB(val);
                    nreal[i]++;
                }
            }
        }

        int mx = nreal[0] + nreal[1] + nreal[2];
        vector<int> idx(3, 0);
        int idxMen, men;
        vector<int>res;
        int cnt = 0;
        for (int i = 0; i < mx; i++) {
            for (int j = 0; j < 3; j++){
                if (idx[j] < nreal[j]){
                    idxMen = j;
                    men = listas[j][idx[j]];
                    break;
                }
            }
            for (int j = 0; j < 3; j++){
                if (idx[j] < nreal[j] && listas[j][idx[j]] < men) {
                    idxMen = j;
                    men = listas[j][idx[j]];
                }
            }
            idx[idxMen] ++;
            if(res.empty()) {
                res.PB(men);
                cnt = 0;
            } else {
                if (men == res[res.size() - 1]) {
                    cnt ++;
                } else {
                    if (cnt == 0) {
                        res[res.size() - 1] = men;
                    } else {
                        res.PB(men);
                    }
                    cnt = 0;
                }
            }
        }

        if (cnt == 0){
            res.pop_back();
        }

        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << "\n";
    }

return 0;
}
