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
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    vector<P> x(m);
    rep(i, 0, m) cin >> x.at(i).first >> x.at(i).second;

    set<P> item;
    rep(i, 0, m) item.insert(x.at(i));

    int i = 0, j = 0;
    rep(ni, 0, n) {
        h--;
        switch (s.at(ni))
        {
        case 'R':
            i++;
            break;
        case 'L':
            i--;
            break;
        case 'U':
            j++;
            break;
        case 'D':
            j--;
            break;
        }

        // cout << "h: " << h << ", i:" << i << ", j: " << j << endl;
        if (h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (item.find(make_pair(i, j)) != item.end()) {
            if (h < k) {
                item.erase(make_pair(i, j));
                h = k;
            } 
        }

        
    }

    cout << "Yes" << endl;
    return 0;
}