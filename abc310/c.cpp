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
    int n;
    cin >> n;
    set<string> st;
    rep(i, 0, n) {
        string t, t1;
        cin >> t;
        t1 = t;
        reverse(t1.begin(), t1.end());
        if (st.count(t) == 0 && st.count(t1) == 0) {
            st.insert(t);
        }
    }

    cout << st.size() << endl;
}