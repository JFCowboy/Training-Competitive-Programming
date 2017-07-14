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

VLL merge_bits(VLL& vecOri, VLL& vecDest) {
    VLL aux;
    int idxOri = 0, idxDest = 0;

    while (idxOri < vecOri.size() && idxDest < vecDest.size()) {
        if (vecOri[idxOri] / 2 >= vecDest[idxDest]) {
            aux.PB(vecOri[idxOri] / 2);
            idxOri++;
        } else {
            aux.PB(vecDest[idxDest]);
            idxDest++;
        }
    }

    while (idxOri < vecOri.size()) {
        aux.PB(vecOri[idxOri] / 2);
        idxOri++;
    }

    while (idxDest < vecDest.size()) {
        aux.PB(vecDest[idxDest]);
        idxDest++;
    }

    return aux;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int n, q; cin >> n >> q; ) {
        VLL sol;
        VLL nums(n);
        LL aux;

        vector<VLL> bucket(64);

        for (auto& v : nums) {
            cin >> v;
        }

        sort(ALL(nums), greater<LL>());

        for (auto& v : nums) {
            for (int bit = 63; bit >= 0; bit--){
                if(v & (1ll << bit)){
                    bucket[bit].PB(v);
                    break;
                }
            }
        }

        for (int bit = 63; bit >= 0; bit--) {
            for (auto v : bucket[bit]) {
                sol.PB(v);
            }

            if(bit > 0)
                bucket[bit - 1] = merge_bits(bucket[bit], bucket[bit - 1]);
        }

        for (int i = 0; i < q; i++) {
            cin >> aux;
            cout << sol[aux - 1] << "\n";
        }

    }

return 0;
}
