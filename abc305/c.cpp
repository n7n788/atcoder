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

    int a = h, b = -1, c = w, d = -1;
    rep(i, 0, h) rep(j, 0, w) {
        if (s.at(i).at(j) == '#') {
            chmin(a, i);
            chmax(b, i);
            chmin(c, j);
            chmax(d, j);
        }
    }

    erep(i, a, b) erep(j, c, d) {
        if (s.at(i).at(j) == '.') {
            cout << i + 1<< ' ' << j + 1<< endl;
        }
    }
    return 0;
}