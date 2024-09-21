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
#define INF_ll 1001001001001001001ll
#define INF 1001001001
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
    vs s(h);
    REP(i, h) cin >> s.at(i);

    vi dx = {1, 0, -1, 0};
    vi dy = {0, 1, 0, -1};

    REP(i, h) REP(j, w) {
        if (s.at(i).at(j) == '#') {
            REP(k, 4) {
                int nx = i + dx.at(k);
                int ny = j + dy.at(k);
                if (nx < 0 || nx >= h || ny < 0 || ny >= w ||
                    s.at(nx).at(ny) == '#') continue;
                s.at(nx).at(ny) = '*';
            }
        }
    }

    vector visited(h, vi(w, -1));
    auto dfs = [&](auto dfs, int i, int j, int n) -> int {
        visited.at(i).at(j) = n;
        if (s.at(i).at(j) == '*') return 1;

        int ans = 0;
        REP(k, 4) {
            int nx = i + dx.at(k);
            int ny = j + dy.at(k);
            if (nx < 0 || nx >= h || ny < 0 || ny >= w ||
                visited.at(nx).at(ny) == n ||
                s.at(nx).at(ny) == '#') continue;
            ans += dfs(dfs, nx, ny, n);
        }

        return ans + 1;
    };

    int n = 0;
    int max = 1;
    REP(i, h) REP(j, w) {
        if (s.at(i).at(j) == '.' && visited.at(i).at(j) == -1) {
            chmax(max, dfs(dfs, i, j, n));
            n++;
            // REP(i, h) {
            //     REP(j, w) {
            //         cout << visited.at(i).at(j) << " ";
            //     }
            //     cout << "\n";
            //  }
        }
    }

    // REP(i, h) {
    //     REP(j, w) {
    //         cout << visited.at(i).at(j) << " ";
    //     }
    //     cout << "\n";
    // }
    cout << max << endl;
    return 0;
}