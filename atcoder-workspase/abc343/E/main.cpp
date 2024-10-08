#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
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
#include <regex>
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

const string YES = "Yes";
const string NO = "No";

struct P {
    int x, y, z;
    P(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {};
    void print() {
        printf("%d %d %d\n", x, y, z);
    };
};

void solve(std::vector<long long> V)
{
    auto f = [&](P p0, P p1, P p2) {
        int x = min({p0.x + 7, p1.x + 7, p2.x + 7}) - max({p0.x, p1.x, p2.x});
        int y = min({p0.y + 7, p1.y + 7, p2.y + 7}) - max({p0.y, p1.y, p2.y});
        int z = min({p0.z + 7, p1.z + 7, p2.z + 7}) - max({p0.z, p1.z, p2.z});
        return max(x, 0) * max(y, 0) * max(z, 0);
    };

    P p0 = {0, 0, 0};
    vector<P> cand;
    FOR(x, -7, 7) FOR(y, -7, 7) FOR(z, -7, 7) cand.emplace_back(P{x, y, z});
    for (auto p1: cand) for (auto p2: cand) {
        int s3 = f(p0, p1, p2);
        int s2 = f(p0, p1, p1) + f(p1, p2, p2) + f(p2, p0, p0) - 3 * s3;
        int s1 = 3 * 7 * 7 * 7 - 2 * s2 - 3 * s3;

        if (s3 == V.at(2) && s2 == V.at(1) && s1 == V.at(0)) {
            cout << "Yes\n";
            p0.print();
            p1.print();
            p2.print();
            return;
        }
    }

    cout << "No\n";
    return;
}

// Generated by 2.13.0 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
int main()
{
        std::vector<long long> V(3);
    for(int i = 0 ; i < 3 ; i++){
        std::scanf("%lld", &V[i]);
    }
        solve(std::move(V));
        return 0;
}
