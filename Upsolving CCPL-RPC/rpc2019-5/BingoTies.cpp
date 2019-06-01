//run: g++ -std=c++14 -o run_sol.exe solution.cpp -DLOCAL_JUDGE
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

vector< vector<VI> > ties;

bool checkWon(set<int> prefix) {
    
    for (int t = 0; t < ties.size(); t++) {
        
        for (int i = 0; i < 5; i++) {
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if (prefix.count(ties[t][i][j])) {
                    cnt++;
                }
            }
            if (cnt == 5) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int n; cin >> n; ) {
        ties.assign(n, vector<VI>(5, VI(5, 0)) );
        map<int, VPII> posVal;
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cin >> ties[k][i][j];
                    posVal[ties[k][i][j]].push_back({k, i});
                }
            }
        }
        
        VPII empates;
        for (auto par : posVal) {
            int eq = par.FS;
            VPII vec = par.SC;

            for (int i = 0; i < vec.size(); i++) {
                int tie, row, tiej, rowj;
                tie = vec[i].FS;
                row = vec[i].SC;

                for (int j = i + 1; j < vec.size(); j++) {
                    set<int> inRow;
                    tiej = vec[j].FS;
                    rowj = vec[j].SC;
                    for (int k = 0; k < 5; k++) {
                        if (ties[tie][row][k] != eq){
                            inRow.insert(ties[tie][row][k]);
                        }

                        if (ties[tiej][rowj][k] != eq){
                            inRow.insert(ties[tiej][rowj][k]);
                        }
                    }

                    if (!checkWon(inRow)) {
                        empates.push_back({tie + 1, tiej + 1});
                        break;
                    }
                }
            }
        }
        
        if (empates.size() == 0) {
            cout << "no ties\n";
        } else {
            sort(ALL(empates));
            cout << empates[0].FS << " " << empates[0].SC << "\n";
        }
    }

return 0;
}