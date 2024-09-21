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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    vector<char> ch(26);
    rep(i, 0, ch.size()) ch.at(i) = 'a' + i;
    cin >> q;
    rep(qi, 0, q) {
        char c, d;
        cin >> c >> d;
        rep(i, 0, ch.size()) {
            if (ch.at(i) == c) ch.at(i) = d;
        }
    }
    rep(i, 0, s.size()) {
        cout << ch.at(s.at(i) - 'a');
    }
    cout << "\n";
    return 0;
}