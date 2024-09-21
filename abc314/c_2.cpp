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

const int delta = 10;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i, 0, n) {
        cin >> c.at(i);
        c.at(i)--;
    }

    vector ps(m, vector<int>());
    rep(i, 0, n) {
        ps.at(c.at(i)).push_back(i);
    }

    string ans = s;
    rep(i, 0, m) {
        int l = ps.at(i).size();
        rep(j, 0, l) {
            ans.at(ps.at(i).at(j)) = s.at(ps.at(i).at((j - 1 + l) % l));
        }
    }

    cout << ans << endl;
    return 0;
}