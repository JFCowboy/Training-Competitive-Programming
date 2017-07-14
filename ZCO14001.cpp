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
        freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n, maxH, ope; cin >> n >> maxH; ) {
        vector<LL> piles(n);

        for (auto& val : piles) {
            cin >> val;
        }
        int idx = 0, crab = 0;
        while (cin >> ope && ope != 0) {
            if (ope == 1) {
                idx--;
                idx = max(idx, 0);
            }
            if (ope == 2) {
                idx++;
                idx = min(idx, n - 1);
            }
            if (ope == 3) {
                if (!crab && piles[idx] > 0) {
                    crab = 1;
                    piles[idx]--;
                }
            }
            if (ope == 4) {
                if (crab && piles[idx] < maxH) {
                    crab = 0;
                    piles[idx]++;
                }
            }
        }

        cout << piles[0];
        for (int i = 1; i < n; i++){
            cout << " " << piles[i];
        }
        cout << "\n";
    }

return 0;
}
