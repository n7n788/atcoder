#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef pair<int, int> P;
typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int h, w;
    cin >> h >> w;
    vector c(h, vector<char>(w));
    rep(i, 0, h) rep(j, 0, w) cin >> c.at(i).at(j);

    int n = min(h, w);
    vector<int> sums(n + 1, 0);
    rep(si, 0, h) rep(sj, 0, w) {

        if (c.at(si).at(sj) != '#') continue;
        int cnt = 0;
        erep(d, 1, n) {
            if (si + d >  h - 1 || si - d < 0 || sj + d > w - 1 || sj - d < 0) break;
        
            if (c.at(si + d).at(sj + d) != '#' ||
                c.at(si + d).at(sj - d) != '#' ||
                c.at(si - d).at(sj + d) != '#' ||
                c.at(si - d).at(sj - d) != '#' ) break;
                
            cnt++;
        }
        if (cnt != 0) sums.at(cnt)++;
    }   

    erep(i, 1, n) cout << sums.at(i) << ' ';
    cout << endl;
    return 0;
}