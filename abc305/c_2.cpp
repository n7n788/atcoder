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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s.at(i);

    vector<int> di = {1, 0, -1, 0};
    vector<int> dj = {0, 1, 0, -1};

    rep(i, 0, h)rep(j, 0, w) {
        if (s.at(i).at(j) == '#') continue;
        int cnt = 0;
        rep(k, 0, 4) {
            int ni = i + di.at(k), nj = j + dj.at(k);
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s.at(ni).at(nj) == '#') cnt++;
        }
        if (cnt >= 2) cout << i + 1 << ' ' << j + 1 << endl;
    }

    return 0;
}