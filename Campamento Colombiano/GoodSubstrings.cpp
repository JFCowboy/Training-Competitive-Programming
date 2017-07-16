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

LL base2 = 33;
LL primeMod2 = 1000000007ll;
LL base1 = 71;
LL primeMod1 = 34369934ll;

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
        set<pair<LL, LL> > setCnt;
        VLL hash1(n + 1), pot1(n + 1);
        VLL hash2(n + 1), pot2(n + 1);
        LL auxHash1, auxHash2;

        VI cnt(n + 1);
        hash1[0] = 0;
        pot1[0] = 1;
        hash2[0] = 0;
        pot2[0] = 1;
        cnt[0] = 0;

        for (int i = 0; i < n; i++) {
            idx = str[i] - 'a' + 1;
            hash1[i + 1] = (hash1[i] * base1 + idx);
            pot1[i + 1] = (pot1[i] * base1);

            hash2[i + 1] = (hash2[i] * base2 + idx);
            pot2[i + 1] = (pot2[i] * base2);

            hash2[i + 1] %= primeMod2;
            pot2[i + 1] %= primeMod2;

            hash1[i + 1] %= primeMod1;
            pot1[i + 1] %= primeMod1;

            cnt[i + 1] = cnt[i] + (val[idx - 1] == '0');
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (cnt[j] - cnt[i - 1] > k) {
                    break;
                }
                auxHash1 = (hash1[j] - ((hash1[i - 1] * pot1[j - i + 1]) % primeMod1) + primeMod1) % primeMod1;
                LL auxMen = (hash2[i - 1] * pot2[j - i + 1]);
                auxMen %= primeMod2;
                auxHash2 = (hash2[j] -  auxMen + primeMod2) % primeMod2;
                //cout << i << ", " << j << " h1: " << auxHash << " < " << str.substr(i - 1, j - i + 1) << " cnt:" << cnt[j] - cnt[i - 1]<< "\n";
                //cout << i << ", " << j << " h2: " << auxHash2 << " < " << str.substr(i - 1, j - i + 1) << " cnt:" << cnt[j] - cnt[i - 1]<< "\n";
                setCnt.insert(MP(auxHash1, auxHash2));
            }
        }

        cout << setCnt.size() << "\n";
    }

return 0;
}
