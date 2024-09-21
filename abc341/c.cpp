#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <atcoder/all>
#include <unordered_map>
#include <unordered_set>

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
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    map<char, P> d;
    int res = 0;
    rep(i, 0, h) cin >> s.at(i);
    d['L'] = P{0, -1};
    d['R'] = P{0, 1};
    d['U'] = P{-1, 0};
    d['D'] = P{1, 0};
    rep(i, 0, h) rep(j, 0, w) {
        int x = i;
        int y = j;
        if (s.at(x).at(y) == '#') continue;
        rep(k, 0, n) {
            int nx = x + d[t.at(k)].first;
            int ny = y + d[t.at(k)].second;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || s.at(nx).at(ny) == '#') 
                break;
            x = nx;
            y = ny;
            if (k == n - 1) res++;
        }
    }
    cout << res << "\n";
    return 0;
}