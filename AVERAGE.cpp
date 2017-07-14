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
        VLL nums(n);

        for (int i = 0; i < n; i++){
            cin >> nums[i];
        }

        sort(ALL(nums));

        int res = 0;
        for (int i = 0; i < n; i++) {
            int inf = 0, sup = n - 1;
            for (; inf < sup; inf++) {
                while (inf < sup && nums[i] * 2 < nums[inf] + nums[sup]) {
                    sup--;
                }
                if (inf < sup && nums[i] * 2 == nums[inf] + nums[sup]) {
                    res ++;
                    break;
                }
            }
        }

        cout << res << "\n";
    }

return 0;
}
