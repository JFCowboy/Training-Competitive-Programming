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

int cmp (pair<LL, int> p1, pair<LL, int> p2) {
    if(p1.FS != p2.FS)
        return p1.FS > p2.SC;
    return p1.SC < p2.SC;
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n, a , b, c; cin >> n; ) {
        priority_queue<pair<LL, int> > pq;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c;
            pq.push(MP(b + c, a));
        }

        LL res = 0, mxTime = 0;
        pair<LL, int> aux;
        while (!pq.empty()) {
            aux = pq.top(); pq.pop();
            res += aux.SC;
            mxTime = max(mxTime, res + aux.FS);
        }
        cout << mxTime << "\n";
    }

return 0;
}
