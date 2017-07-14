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

    for (int n, k; cin >> n >> k; ) {
        VI l1(n), l2(n);

        for (auto& nums : l1) {
            cin >> nums;
        }
        for (auto& nums : l2) {
            cin >> nums;
        }

        sort(ALL(l1));
        sort(ALL(l2));

        int idx, res = l1[n - 1] + l2[n - 1];
        for (idx = 0; idx < n - 1; idx++) {
            if (idx < k && l1[n - idx - 1] > l2[idx]) {
                res = min(res, max(l1[n - 1], l2[n - 1]) + max(l1[n - idx - 2], l2[idx]));
            } else {
                break;
            }
        }

        for (idx = 0; idx < n - 1; idx++) {
            if (idx < k && l2[n - idx - 1] > l1[idx]) {
                res = min(res, max(l2[n - 1], l1[n - 1]) + max(l2[n - idx - 2], l1[idx]));
            } else {
                break;
            }
        }

        cout << res << "\n";
    }

return 0;
}

