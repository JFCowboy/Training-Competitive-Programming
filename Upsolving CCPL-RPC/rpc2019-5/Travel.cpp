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

vector<VPII> trains;
unordered_map<int, VPII> G;

void timeToString(int num) {
    int mm = num % 60;
    int hh = num / 60;
    cout << setfill('0') << setw(2);
    cout << hh << setfill('0') << setw(2) << mm;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int c, t, n, time; cin >> c && c; ) {
        trains.clear();
        G.clear();
        map<string, int> names;
        map<string, int> nodes;
        // map<int, string> inv;
        int node, cntNode;
        string name, h, start, end, iniT;
        for (int i = 0; i < c; i++) {
            cin >> name;
            names[name] = i;
        }
        trains.assign(c, VPII());

        cin >> t;
        
        cntNode = 0;
        for (int i = 0; i < t; i++) {   
            cin >> n;
            int prev = -1, pTime;
            for (int j = 0; j < n; j++) {
                cin >> h >> name;
                time = ((h[0] - '0') * 10 + h[1] - '0') * 60 + ((h[2] - '0')*10 + h[3] - '0');
                
                if (nodes.count(name + h) == 0) {
                    nodes[name + h] = cntNode;
                    // inv[cntNode] = name + h;
                    G[cntNode] = VPII();
                    cntNode++;
                }
                
                node = nodes[name + h];
                trains[names[name]].push_back({time, node});
                
                if (prev > -1) {
                    G[prev].push_back({node, time - pTime});
                }
                prev = node;
                pTime = time;
            }
        }

        for (auto nm : names) {
            sort(ALL(trains[nm.second]));
            VPII aux = trains[nm.second];
            
            for (int i = 1; i < aux.size(); i++) {
                G[aux[i - 1].second].push_back({aux[i].second, aux[i].first - aux[i - 1].first});
            }
        }

        cin >> iniT >> start >> end;
        //Check the graph
        // for (auto val : G) {
        //     cout << inv[val.FS]<< "(" << val.first << "): ";
        //     for (auto u : val.second) {
        //         cout << inv[u.FS]<<"("<< u.FS << ") - " << u.SC << ", ";
        //     }
        //     cout << "\n";
        // }
        time = ((iniT[0] - '0') * 10 + iniT[1] - '0') * 60 + ((iniT[2] - '0')*10 + iniT[3] - '0');

        priority_queue<PII, VPII, greater<PII>> pq;
        VI dist(G.size(), INF / 2);
        for (auto nu : trains[names[start]]) {
            
            if (time <= nu.first){
                pq.push({0, nu.second});
                dist[nu.second] = 0;
            }
        }

        while (!pq.empty()) {
            PII aux = pq.top(); pq.pop();

            if (dist[aux.second] < aux.first) {
                continue;
            }

            for (auto vec : G[aux.second]) {
                if (dist[vec.first] > dist[aux.second] + vec.second) {
                    dist[vec.first] = dist[aux.second] + vec.second;
                    pq.push({dist[vec.first], vec.first});
                }
            }
        }
        // cout << dist.size() << "<<<\n";
        // for (int i = 0; i < dist.size(); i++) {
        //     cout << inv[i] << "(" << i << "):" << dist[i] << "\n";
        // }
        // cout << "--------\n";

        int res = 0;
        for (auto nu : trains[names[end]]) {
            if (dist[nu.second] < 60 * 60 * 60) {
                res = 1;
                timeToString(nu.first - dist[nu.second]);
                cout << " ";
                timeToString(nu.first) ;
                cout << "\n";
                break;
            }
        }

        if (!res) {
            cout << "No connection\n";
        }
    }
    
    
return 0;
}