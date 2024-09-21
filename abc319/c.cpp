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
    vector<int> num(9);
    rep(i, 0, 9) cin >> num.at(i);

    vector<tuple<int, int, int>> row {{0, 1, 2}, 
                                      {3, 4, 5},
                                      {6, 7, 8},
                                      {0, 3, 6},
                                      {1, 4, 7},
                                      {2, 5, 8},
                                      {0, 4, 8},
                                      {2, 4, 6}};

    vector<int> order(9);
    rep(i, 0, 9) order.at(i) = i;

    int all = 0, fail = 0;
    do {
        all++;
        bool fail_flag = false;
        for (auto [a, b, c] : row) {
            if (num.at(a) == num.at(b) && order.at(a) < order.at(c) && order.at(b) < order.at(c)) 
                fail_flag = true;
            else if (num.at(b) == num.at(c) && order.at(b) < order.at(a) && order.at(c) < order.at(a)) 
                fail_flag = true;
            else if (num.at(c) == num.at(a) && order.at(c) < order.at(b) && order.at(a) < order.at(b))
                fail_flag = true;
            
            if (fail_flag) break;
        }

        if (fail_flag) fail++;
    } while (next_permutation(order.begin(), order.end()));

    double prob = (double) (all - fail) / all;
    printf("%.12lf\n", prob);
    return 0;
}