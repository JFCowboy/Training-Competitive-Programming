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

bool isUpper(char c) {
    return 'A' <= c && c <= 'Z';
}

int main() {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "rt", stdin);
        //freopen("output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string line, pal;
    int n;
    cin >> n;
//    cout << n << "...\n";
    cin.ignore();
    set<string> diffWords;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
//        cout << i << "= " << line << " <<\n";
        for (int j = 0; j < line.size(); j++) {
            if (!isalpha(line[j])) {
                line[j] = ' ';
            } else if (isUpper(line[j])) {
                line[j] = line[j] - 'A' + 'a';
            }
        }
//        cout << i << "= " << line << " << 2 <<\n";
        stringstream ss(line);
        while (ss >> pal) {
            diffWords.insert(pal);
        }
    }
    cout << diffWords.size() << "\n";
    set<string>::iterator it;
    for (it = diffWords.begin(); it != diffWords.end(); it++) {
        cout << *it << "\n";
    }

return 0;
}
