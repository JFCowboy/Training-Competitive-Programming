/**
  * LONGPALIN using manacher
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

string lps;

string transformS(string s) {
    string t = "";
    t.PB('@');
    for (int i = 0; i < LEN(s); i++) {
        t.PB('#');
        t.PB(s[i]);
    }
    t.PB('#');
    t.PB('$');
    return t;
}

void LPS_Manacher(string s) {
    string t = transformS(s);
    VI p(t.size(), 0);

    int center = 0, right = 0, mxLength = 0, mxCenter = 0;

    for (int i = 1; i < LEN(t) - 1; i++) {
        int mirror = 2 * center - i;

        if(i < right){
            p[i] = min(right - i, p[mirror]);
        }

        while (t[i + (1 + p[i])] == t[i - (1 + p[i])]) {
            p[i]++;
        }

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (mxLength < p[i]) {
            mxLength = p[i];
            mxCenter = center;
        }
    }
    lps = s.substr((mxCenter - 1 - mxLength) / 2, mxLength);
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
        LPS_Manacher(str);
        cout << lps.size() << "\n" << lps << "\n";
    }

return 0;
}
