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
        VLL nums(n);
        VLL sumF(n, -INF), sumB(n, -INF);

        for (auto& val : nums)
            cin >> val;

        k--;
        sumF[k] = 0;
        for (int i = k + 1; i < n; i++) {
            sumF[i] = sumF[i - 1];
            if (i - 2 >= 0)
                sumF[i] = max(sumF[i], sumF[i - 2]);
            sumF[i] += nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            sumB[i] = sumF[i];
            if (i + 1 < n) {
                sumB[i] = max(sumB[i], sumB[i + 1] + nums[i]);
            }
            if (i + 2 < n) {
                sumB[i] = max(sumB[i], sumB[i + 2] + nums[i]);
            }
        }

        cout << sumB[0] << "\n";
    }

return 0;
}
