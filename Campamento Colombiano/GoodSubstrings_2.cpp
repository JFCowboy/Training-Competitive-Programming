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

LL base1 = 27;
LL primeMod1 = 1000000007;
LL base2 = 71;//34369934;
LL primeMod2 = 9584612342;
LL base3 = 33;//34369934;
LL primeMod3 = 1152921504606847009ll;

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    for (string str, val; cin >> str >> val >> k; ){
        int n = LEN(str), idx;
        //set<pair<LL, pair<LL, LL> > > setCnt;
        set<LL> setCnt;
        VI cnt(n + 1);
        LL hash1;

        for (int i = 0; i < n; i++) {
            idx = str[i] - 'a' + 1;
            cnt[i + 1] = cnt[i] + (val[idx - 1] == '0');
        }

        for (int i = 0; i < n; i++) {
            hash1 = 0;
            for (int j = i; j < n; j++) {
                if (cnt[j + 1] - cnt[i] > k) {
                    break;
                }
                idx = str[j] - 'a' + 1;
                hash1 = (hash1 * base3 + idx) % primeMod3;
                //cout << i << ", " << j << " h1: " << auxHash << " < " << str.substr(i - 1, j - i + 1) << " cnt:" << cnt[j] - cnt[i - 1]<< "\n";
                //cout << i << ", " << j << " h2: " << auxHash2 << " < " << str.substr(i - 1, j - i + 1) << " cnt:" << cnt[j] - cnt[i - 1]<< "\n";
                setCnt.insert(hash1);
            }
        }

        cout << setCnt.size() << "\n";
    }

return 0;
}
