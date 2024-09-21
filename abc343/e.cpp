//#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "atcoder/all"
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
// typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

struct P {
    int x, y, z;
    P(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}; 
};

int main()
{
    int v1, v2, v3;
    cin >> v1 >> v2 >> v3;
    vector<P> cand;
    P p1;
    // p1, p2, p3の作る立方体の全てに含まれた体積を返す
    auto getV = [](P p1, P p2, P p3) -> int {
        P l, r;
        int ans;
        l.x = min({p1.x, p2.x, p3.x});
        l.y = min({p1.y, p2.y, p3.y});
        l.z = min({p1.z, p2.z, p3.z});
        r.x = max({p1.x, p2.x, p3.x});
        r.y = max({p1.y, p2.y, p3.y});
        r.z = max({p1.z, p2.z, p3.z});
        ans = 1;
        ans *= max(l.x + 7 - r.x, 0);
        ans *= max(l.y + 7 - r.y, 0);
        ans *= max(l.z + 7 - r.z, 0);
        return ans;
    };

    auto printP = [](P p) {
        cout << p.x << " " << p.y << " " << p.z << "\n";
    };
    erep(x, -7, 7) erep(y, -7, 7) erep(z, -7, 7) cand.emplace_back(P{x, y, z});
    
    for (auto p2: cand) for (auto p3: cand) {
        int s1, s2, s3;
        s3 = getV(p1, p2, p3);
        s2 = getV(p1, p2, p2) + getV(p2, p3, p3) + getV(p3, p1, p1) - 3 * s3;
        s1 = 7 * 7 * 7 * 3 - 2 * s2 - 3 * s3;
        if (s1 == v1 && s2 == v2 && s3 == v3) {
            cout << "Yes" << "\n";
            printP(p1);
            printP(p2);
            printP(p3);
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}