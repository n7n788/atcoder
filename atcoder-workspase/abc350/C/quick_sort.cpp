#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cassert>
#include <iomanip>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF_ll 1001001001001001001ll
#define INF 1001001001
#define fcout cout << fixed << setprecision(12)

using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvc = vector<vector<char>>;
using vvb = vector<vector<bool>>;
using vvvi = vector<vector<vector<int>>>;
using pii = pair<int, int>;

template <typename T>
inline bool chmax(T &a, T b) {
    return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
    return ((a > b) ? (a = b, true) : (false));
}

vector<pii> Swaps;

void print(vi a, int n) {
    REP(i, n) cout << a.at(i) << " ";
    cout << endl;
}

void bubble_sort(vi& a, int n) 
{
    REP(i, n - 1) {
        REV(j, n - 1, i + 1) {
            if (a.at(j - 1) > a.at(j)) {
                swap(a.at(j - 1), a.at(j));
                Swaps.emplace_back(j - 1, j);
                cout << "swap: " << j - 1 << " " << j << "\n";
                print(a, n);
            }
        }
    }
}

// void quick_sort(vi& a, int first, int last)
// {
//     int i, j, x, t;

//     //ビボットは要素の中央
//     x = a[(first + last) / 2];
//     // iをビボットの左領域のインデックス
//     // jはビボットの右領域のインデックス
//     i = first;
//     j = last;

//     cout << "pivot: " << x << ", first = " << first + 1<< ", last = " << last + 1 << "\n";
//     while (true) {
//         cout << "i = " << i + 1<< ", j = " << j + 1<< "\n";
//         // ビボット以上になるまで左領域を走査
//         while (a.at(i) < x) i++;
//         // ビボット以下になるまで右領域を走査
//         while (a.at(j) > x) j--;
//         cout << "    i = " << i + 1<< ", j = " << j + 1 << "\n";
//         // もし操作しているインデックスが交差したら終了
//         if (i >= j) break;

//         swap(a.at(i), a.at(j));
//         Swaps.emplace_back(i, j);
//         cout << "swap: " << i + 1 << " " << j + 1 << "\n";
//         FOR(i, first, last) cout << a.at(i) << " ";
//         cout << "\n";
//         // 次の要素から走査を開始
//         i++; j--;
//     }

//     // クイックソートを再帰的に呼び出し
//     if (first < i - 1) quick_sort(a, first, i - 1);
//     if (last > j + 1) quick_sort(a, j + 1, last);
// }

// void quick_sort(vi& a, int first, int last) 
// {
//     int i, j, x;
//     x = a.at((first + last) / 2);
//     i = first;
//     j = last;

//     while (true) {
//         while (a.at(i) < x) i++;
//         while (a.at(j) > x) j--;
//         if (i >= j) break;

//         swap(a.at(i), a.at(j));
//         Swaps.emplace_back(i, j);

//         i++, j--;
//     }

//     if (first < i - 1) quick_sort(a, first, i - 1);
//     if (last > j + 1) quick_sort(a, j + 1, last);
// }

// void quick_sort(vi&a, int first, int last)
// {
//     int i, j, x;
//     x = a.at((first + last) / 2);
//     i = first;
//     j = last;

//     while (true) {
//         while (a.at(i) < x) i++;
//         while (a.at(j) > x) j--;
//         if (i >= j) break;

//         swap(a.at(i), a.at(j));
//         Swaps.emplace_back(i, j);
//         i++, j--;
//     }

//     if (first < i - 1) quick_sort(a, first, i - 1);
//     if (last > j + 1) quick_sort(a, j + 1, last);
// }


void  quick_sort(vi& a, int first, int last)
{
    int i, j, x;
    x = a.at((first + last) / 2);
    i = first;
    j = last;

    while (true) {
        while (a.at(i) < x) i++;
        while (a.at(j) > x) j--;
        if (i >= j) break;

        swap(a.at(i), a.at(j));
        Swaps.emplace_back(i, j);
        i++, j--;
    }

    if (first < i - 1) quick_sort(a, first, i - 1);
    if (last > j + 1) quick_sort(a, j + 1, last);
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a.at(i);

    print(a, n);
    // bubble_sort(a, n);
    quick_sort(a, 0, n - 1);

    cout << "Swap count = " << Swaps.size() << endl;
    for (auto [i, j]: Swaps) {
        cout << i + 1 << " " << j + 1 << "\n";
    } 
    cout << "Sorted Array = ";
    REP(i, n) cout << a.at(i) << " ";
    cout << endl;
}
