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
    vector pos(m, vector<int>());
    rep(i, 0, n) {
        cin >> c.at(i);
        c.at(i)--;
        pos.at(c.at(i)).push_back(i);
    }

    rep(i, 0, m) {
        if (pos.at(i).size() == 1) continue;
        char tmp = s.at(pos.at(i).at(0));;
        rep(j, 0, pos.at(i).size()) {
            if (j == pos.at(i).size() - 1) s.at(pos.at(i).at(0)) = tmp;
            else {
                swap(s.at(pos.at(i).at(j + 1)), tmp);
            }
        }
    }

    cout << s << endl;
    return 0;
}