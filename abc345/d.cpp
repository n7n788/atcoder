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
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define erep(i, a, b) for (int i = (a); i <= (b); i++)
typedef pair<int, int> P;
template <typename T> bool chmin(T &a, const T& b) {if (a > b) {a = b; return true;} return false;}
template <typename T> bool chmax(T &a, const T& b) {if (a < b) {a = b; return true;} return false;}

typedef long long ll;
const int INF = 1 << 30;
const ll INF_ll = 1ll << 60;

int main()
{
    int n, h, w;
    cin >> n >> h >> w;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a.at(i) >> b.at(i);

    vector<int> perm(n);
    rep(i, 0, n) perm.at(i) = i;
    int m = 1 << n;

    do {
        rep(bit, 0, m) {
            int i = 0, j = 0;
            vector cnt(h, vector<int>(w, 0));
            bool ok = true;

            rep(i, 0, n) cout << perm.at(i) << " ";
            cout << "\n";
            cout << bit << "\n";

            rep(k, 0, n) {
                cout << i << ", " << j << "\n";
                int th = a.at(perm.at(k));
                int tw = b.at(perm.at(k));
                if (((bit >> k) & 1) == 1) {
                    // cout << "swap\n";
                    swap(th, tw);
                }
                cout << i << ", " << j << ": " << th << ", " << tw << "\n";
                if (i + th <= h && j + tw <= w) {
                    rep(ii, i, i + th) {
                        rep(jj, j, j + tw) {
                            if (cnt.at(ii).at(jj) == 0) {
                                cnt.at(ii).at(jj)++;
                            } else {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok) break;
                    }
                } else {
                    ok = false;
                    break;
                }
                // cout << cnt.at(0).at(3) << "\n";
                if (!ok) break;

                bool next = false;
                rep(ii, i, h) {
                    rep(jj, 0, w) {
                        if (ii == 0 && jj < j) continue;
                        if (cnt.at(ii).at(jj) == 0) {
                            i = ii;
                            j = jj;
                            next = true;
                            break;
                        }
                    }
                    if (next) break;
                }

                if (!next) {
                    cout << "Yes\n";
                    return 0;
                }
            }

            // if (ok) {
            //     bool ok2 = true;
            //     rep(i, 0, h) rep(j, 0, w) {
            //         if (cnt.at(i).at(j) != 1) {
            //             ok2 = false;
            //             break;
            //         }
            //     }
            //     if (ok2) {
            //         cout << "Yes\n";
            //         return 0;
            //     }
            // }
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << "No\n";
    return 0;
}