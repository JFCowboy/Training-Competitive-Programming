//run: g++ -std=c++14 -o run_sol.exe solution.cpp -DLOCAL_JUDGE
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

#define MAX_N 1000010
string T, P; // T = text, P = pattern
int b[MAX_N], n, m; // b = back table, n = length of T, m = length of P

void kmpPreprocess() { // call this before calling kmpSearch()
    int i = 0, j = -1; b[0] = -1; // starting values
    while (i < m) { // pre-process the pattern string P
        while (j >= 0 && P[i] != P[j]) {
            j = b[j]; // if different, reset j using b
        }
        i++; j++; // if same, advance both pointers
        b[i] = j; // observe i = 8, 9, 10, 11, 12 with j = 0, 1, 2, 3, 4
    } 
}

int kmpSearch() { // this is similar as kmpPreprocess(), but on string T
    int i = 0, j = 0; // starting values
    int mxJ = 0;
    while (i < n) { // search through string T
        while (j >= 0 && T[i] != P[j]) {
            j = b[j];
        } // if different, reset j using b
        i++; j++; // if same, advance both pointers
        mxJ = max(mxJ, j);
        if (j == m) { // a match found when j == m
            j = b[j]; // prepare j for the next possible match
        }
    } 

    return mxJ;
}

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    
    cin >> t;
    for (int cas = 0; cas < t; cas++) {
        cin >> P;
        T = P;
        n = m = P.size();
        reverse(ALL(T));
        // cout << P << " " << T << "\n";
        kmpPreprocess();
        int sz = kmpSearch();
        string res = P.substr(0, sz);
        reverse(ALL(res));
        cout << res << "\n";
    }

return 0;
}