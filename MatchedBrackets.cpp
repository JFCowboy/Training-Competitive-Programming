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

    for (int n; cin >> n; ) {
        int val, resDepth, resFDepth, resMax, resFMax;
        stack<int> q;
        resDepth = resMax = 0;

        for (int i = 0; i < n; i++) {
            cin >> val;
            if(val == 1) {
                q.push(i);
            } else {
                if ((i - q.top() + 1) > resMax) {
                    resMax = (i - q.top() + 1);
                    resFMax = q.top() + 1;
//                    cout << " esta " <<resMax << ", " << resFMax << "\n";
                }
                q.pop();
            }
//            cout << "TAM: " << q.size() << "\n";
            if(q.size() > resDepth) {
                resDepth = q.size();
                resFDepth = q.top() + 1;
            }
        }

        cout << resDepth << " " << resFDepth << " " << resMax << " " << resFMax << "\n";

    }

return 0;
}
