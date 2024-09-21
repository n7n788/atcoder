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
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x.at(i) >> y.at(i);

    //bfsで全探索
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    visited.at(0) = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        // cout << v << endl;
        rep(i, 0, n) {
            int dx = x.at(i) - x.at(v);
            int dy = y.at(i) - y.at(v);
            int dist = dx * dx + dy * dy;
            if (dist <= d * d && !visited.at(i)) {
                // cout << "  ->" << i << ", dist = " << dist << endl;
                q.push(i);
                visited.at(i) = true; //キューに入れるタイミングでvisitedを変化
            }
        }
    }

    rep(i, 0, n) {
        if (visited.at(i)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}