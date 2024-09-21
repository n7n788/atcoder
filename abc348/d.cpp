#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <iomanip>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

template <typename T>
inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h) cin >> a.at(i);
    int n;
    cin >> n;
    vector<int> r(n), c(n), e(n);
    REP(i, n) {
        cin >> r.at(i) >> c.at(i) >> e.at(i);
        r.at(i)--;
        c.at(i)--;
    }
    const int inf = 1<<30;
    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};
    vvvi distances(n, vvi(h, vi(w, inf)));
    auto bfs = [&](int i, vvi& dist) {
        queue<pii> q;
        q.emplace(r.at(i), c.at(i));
        dist.at(r.at(i)).at(c.at(i)) = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            REP(k, 4) {
                int nx = x + dx.at(k);
                int ny = y + dy.at(k);
                if (nx < 0 || nx >= h || ny < 0 || ny >= w || 
                    dist.at(nx).at(ny) != inf ||
                    a.at(nx).at(ny) == '#') continue;
                dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
                q.emplace(nx, ny);
            }
        }
    };

    REP(i, n) {
        bfs(i, distances.at(i));
        // cout << i << endl;
        // REP(j, h) {
        //     REP(k, w) cout << distances.at(i).at(j).at(k) << " ";
        //     cout << "\n";
        // }
        // cout << "\n";
    }

    int tx, ty, sx, sy;
    REP(i, h) REP(j, w) {
        if (a.at(i).at(j) == 'T') {
            tx = i;
            ty = j;
        } else if (a.at(i).at(j) == 'S') {
            sx = i;
            sy = j;
        }
    }
    int si = -1;
    REP(i, n) {
        if (r.at(i) == sx && c.at(i) == sy) si = i;
    }

    if (si == -1) {
        cout << "No\n";
        return 0;
    }
    vvi edges(n, vi());
    REP(i, n) REP(j, n) {
        if (i == j) continue;
        int d = distances.at(i).at(r.at(j)).at(c.at(j));
        // cout << i << ", " << j << ": " << d << "\n";
        if (e.at(i) >= d) edges.at(i).push_back(j);
    }
    REP(i, n) {
        int d = distances.at(i).at(tx).at(ty);
        if (e.at(i) >= d) edges.at(i).push_back(n);
    }

    vb visited(n + 1, false);
    auto dfs = [&](int v, auto dfs) -> bool {
        visited.at(v) = true;
        if (v == n) return true;
        bool flag = false;
        for (auto to: edges.at(v)) {
            if (visited.at(to)) continue;
            flag |= dfs(to, dfs);
        }
        return flag;
    };
    if (dfs(si, dfs)) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}