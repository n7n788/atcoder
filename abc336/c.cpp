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
    ll n;
    cin >> n;
    vector<int> rem;
    n--;
    // 10進数を5進数に変換　桁の小さい方から順に配列に格納
    while (n > 0) {
        rem.push_back(n % 5);
        n /= 5;
    }
    if (rem.empty()) rem.push_back(0);
    for (auto it = rem.rbegin(); it != rem.rend(); it++) {
        cout << (*it) * 2;
    }
    cout << "\n";
    return 0;
}