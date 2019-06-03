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

int main() {
    #ifdef LOCAL_JUDGE
        freopen("../input.txt", "rt", stdin);
        freopen("../output.txt", "wt", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> primes;
    primes.PB(2);
    for (int i = 3; primes.size() < 101; i += 2) {
        bool isPrime = true;

        for (auto prime : primes) {
            if ((i % prime) == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            primes.push_back(i);
        }
    }
    primes.push_front(1);

    int t, n, q;
    cin >> t;
    for (int cas = 0; cas < t; cas++) {
        cin >> n >> q;
        VI cnt(q + 1, INF);
        cnt[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int val = 0; val < q; val++) {
                if (cnt[val] < INF && val + primes[i] <= q)  {
                    cnt[val + primes[i]] = min(cnt[val + primes[i]], cnt[val] + 1);
                }
            }
        }

        cout << cnt[q] << "\n";
    }


return 0;
}