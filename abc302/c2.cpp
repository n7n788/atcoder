#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <atcoder/all>
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, 0, n) cin >> s.at(i);

    // next_premitationする前に、文字列の列をソート
    sort(s.begin(), s.end());
    do {
        bool ok = true;
        rep(i, 0, n - 1) {
            int d = 0;
            rep(j, 0, m) {
                if (s.at(i).at(j) != s.at(i + 1).at(j)) d++;
            }
            if (d != 1) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << "No" << endl;
    return 0;
}