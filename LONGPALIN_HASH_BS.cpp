/**
 * LONGPALIN using Hash + BS
 * in this approach I do BS on the length of the palindrome with special case of odd and even length
 * Other possible approach is:
 * Choose position x and then find with bin_search the maximal palindrome with the middle in x!And we can compare two strings with the hashes in o(1)!
 */
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
LL base2 = 34369934;
LL primeMod2 = 9584612342;

VLL hash1, hashRev1;
VLL hash2, hashRev2;
VLL pot1;
VLL pot2;

void preprocess(string s) {
    int n = LEN(s);
    string sRev = s;
    reverse(ALL(sRev));
    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);

    hashRev1.assign(n + 1, 0);
    hashRev2.assign(n + 1, 0);

    pot1.assign(n + 1, 0);
    pot2.assign(n + 1, 0);

    hash1[0] = 0;
    hash2[0] = 0;
    hashRev1[0] = 0;
    hashRev2[0] = 0;
    pot1[0] = 1;
    pot2[0] = 1;
    for (int i = 0; i < n; i++) {
        hash1[i + 1] = ((hash1[i] * base1) % primeMod1 + (s[i] - 'a' + 1)) % primeMod1;
        hash2[i + 1] = ((hash2[i] * base2) % primeMod2 + (s[i] - 'a' + 1)) % primeMod2;

        hashRev1[i + 1] = ((hashRev1[i] * base1) % primeMod1 + (sRev[i] - 'a' + 1)) % primeMod1;
        hashRev2[i + 1] = ((hashRev2[i] * base2) % primeMod2 + (sRev[i] - 'a' + 1)) % primeMod2;

        pot1[i + 1] = (pot1[i] * base1) % primeMod1;
        pot2[i + 1] = (pot2[i] * base2) % primeMod2;
    }
}

int palOfSizeK(int k, int n) {
    LL h1, h2;
    for (int i = 0; 0 < k && i + k<= n; i++) {
        h1 = (hash1[i + k] - hash1[i] * pot1[k]) % primeMod1;
        h1 = (h1 + primeMod1) % primeMod1;

        h2 = (hashRev1[n - i] - hashRev1[n - i - k] * pot1[k]) % primeMod1;
        h2 = (h2 + primeMod1) % primeMod1;

        if (h1 == h2) {
            return i;
        }
    }

    return -1;
}

string solve(string s){
    int n = LEN(s);

    preprocess(s);

    int inf = 0, cnt = (LEN(s) + 1) / 2, step, mid, auxPar, auxImpar, mxLength, mxIdx;
    int cnt_0 = 0; // auxiliar para analizar un caso mas debido q 0 + 1 es un caso valido
    while (cnt_0 < 2) {
        step = cnt >> 1;
        mid = inf + step;
        auxPar = palOfSizeK(2 * mid, n);
        auxImpar = palOfSizeK(2 * mid + 1, n);

        if (auxPar > -1 or auxImpar > -1) { // existe
            if(auxImpar > -1) {
                mxLength = 2 * mid + 1;
                mxIdx = auxImpar;
            } else {
                mxLength = 2 * mid;
                mxIdx = auxPar;
            }
            inf = mid + 1;
            cnt -= step + 1;
        } else {
            cnt = step;
        }

        if (cnt <= 0)
            cnt_0++;
    }

    return s.substr(mxIdx, mxLength);
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    for(int n; cin >> n; ) {
        cin >> str;
        string lps = solve(str);
        cout << lps.size() << "\n" << lps << "\n";
    }

return 0;
}
