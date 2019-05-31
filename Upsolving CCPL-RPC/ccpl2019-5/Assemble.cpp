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

set<string> types;
map<string, VPII> components;

bool check(int qua, int cost) {
    for (auto type : types) {
        VPII arr = components[type];
        int idx;
        for (idx = 0; idx < arr.size(); idx++) {
            if (arr[idx].FS >= qua) {
                // cout << type << ": " << idx << " " << arr[idx].FS << " , " << arr[idx].SC << " -> " << cost << "\n";
                cost -= arr[idx].SC;
                break;
            }
        }
        
        if (cost < 0 || idx == arr.size()) {
            return false;
        }
    }

    return true;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, b, price, quality;
    string type, name;
    cin >> t;

    for (int cas = 0; cas < t; cas++) {
        cin >> n >> b;
        
        components.clear();
        types.clear();
        for (int i = 0; i < n; i++) {
            cin >> type >> name >> price >> quality;
            components[type].push_back({quality, price});
            types.insert(type);
        }

        for (auto val : types) {
            sort(ALL(components[val]));
            for (int idx = components[val].size() - 2; idx >=0; idx--) {
                components[val][idx].SC = min(components[val][idx].SC, components[val][idx + 1].SC);
            }
        }
        // cout << "QUA:" << check(1, b) << "\n";
        int tam = 1e9;
        int iniPos = 0;
        for (int step = tam/2; step >= 1; step/=2) {
            while (iniPos + step <= tam && check(iniPos + step, b) ) {
                iniPos += step;
            }
        }

        cout << iniPos << "\n";
    }    

return 0;
}