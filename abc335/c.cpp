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
    int n, q;
    cin >> n >> q;
    deque<P> pos;
    map<char, P> d = {
        {'R', {1, 0}}, 
        {'L', {-1, 0}},
        {'U', {0, 1}},
        {'D', {0, -1}}
    };
    rep(i, 0, n) pos.emplace_back(i + 1, 0);
    rep(qi, 0, q) {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            char c;
            int nx, ny;
            cin >> c;
            // デキューへランダムアクセス
            nx = pos.at(0).first + d[c].first;
            ny = pos.at(0).second + d[c].second;
            pos.emplace_front(nx, ny);
            break;
        case 2:
            int p;
            int x, y;
            cin >> p;
            x = pos.at(p - 1).first;
            y = pos.at(p - 1).second;
            cout << x << " " << y << "\n";
            break;
        }
    }
    return 0;
}