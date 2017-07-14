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
        VI nums(n);
        VLL sum(n);

        for (auto &val : nums) {
            cin >> val;
        }

        //base cases
        for (int i = 0; i < min(3, n); i++)
            sum[i] = nums[i];

        for (int i = 3; i < n; i++) {
            sum[i] = min(sum[i - 1], min(sum[i - 2], sum[i - 3])) + nums[i];
        }

        LL res = sum[n - 1];
        if (n - 2 >= 0)
            res = min(res, sum[n - 2]);
        if (n - 3 >= 0)
            res = min(res, sum[n - 3]);

        cout << res << "\n";
    }

return 0;
}
