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
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string ori, que;
    int n;

    while(cin >> ori) {
        vector<pair<char, int>> /*cnt,*/ cntQ, cntCp;
        vector<VPII> posCant(300);
        char ch = ori[0];
        int ct = 1;
        for (int i = 1; i < ori.size(); i++) {
            if (ori[i] != ch) {
                // cout << ch << " -o- " << ct << "\n";
                posCant[ch].push_back({i - ct, ct});
                // cnt.push_back({ch, ct});
                ct = 0;
            }
            ch = ori[i];
            ct++;
        }
        
        posCant[ch].push_back({ori.size() - ct, ct});
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> que;
            cntQ.clear();
            VI idxO(300, 0);

            ch = que[0];
            ct = 1;
            for (int j = 1; j < que.size(); j++) {
                if (que[j] != ch) {
                    cntQ.push_back({ch, ct});
                    ct = 0;
                }
                ch = que[j];
                ct++;
            }
            
            cntQ.push_back({ch, ct});

            int ini = -1, fin = 0;

            int idxQ;

            for (idxQ = 0; idxQ < cntQ.size();) {
                ch = cntQ[idxQ].first;
                ct = cntQ[idxQ].second;
                
                while (idxO[ch] < posCant[ch].size()) {
                    if(posCant[ch][idxO[ch]].first >= fin) {
                        break;
                    }
                    idxO[ch]++;
                }

                if (idxO[ch] >= posCant[ch].size()) {
                    break;
                }
                if (ini == -1) {
                    ini = posCant[ch][idxO[ch]].first;
                }
                fin = posCant[ch][idxO[ch]].first;
                
                if (posCant[ch][idxO[ch]].second >= cntQ[idxQ].second) {
                    fin += cntQ[idxQ].second;
                    idxQ++;
                } else {
                    cntQ[idxQ].second -= posCant[ch][idxO[ch]].second;
                }
                idxO[ch]++;
            }

            if (idxQ != cntQ.size()) {
                cout << "Not matched\n";
            } else {
                cout << "Matched " << ini << " " << fin - 1<< "\n";
            }
        }
    }

return 0;
} 