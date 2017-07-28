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
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int n; cin >> n;) {
        int len = (int) sqrt (n + .0) + 1;
        VI nums(n);
        VI vsqrt(len, 0);
        VI update(len, 0);
        VI res;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            nums[i] += i + 1;
            vsqrt[i / len] = max(vsqrt[i / len], nums[i]);
        }

        int idx;
        for (int i = n - 1; i >= 0; i--) {
            int mx = -1;
            for(int j = 0; j < len; j++) {
                mx = max(mx, vsqrt[j] + update[j]);
                update[j] += 1;
            }
            res.PB(mx);

            idx = i / len;
            for (int j = idx * len; j < n && j <= (idx + 1) * len - 1; j++) {
                nums[j] += update[idx];
            }

            update[idx] = 0;
            vsqrt[idx] = 0;
            nums[i] -= n;

            for (int j = idx * len; j < n && j <= (idx + 1) * len - 1; j++) {
                vsqrt[idx] =  max(vsqrt[idx], nums[j]);
            }
        }

        cout << res[0];
        for (int i = 1; i < res.size(); i++) {
            cout << " " << res[i];
        }
        cout << "\n";

    }

return 0;
}
