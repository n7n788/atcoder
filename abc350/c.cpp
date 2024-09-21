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

using P = pair<int, int>;
vector<P> swaps = {};

// void quick_sort(int a[], int first, int last){
//   int i, j, x, t;

//   // 軸要素(ピボット)は要素の中央
//   x = a[(first + last) / 2];
//   // iを軸要素の左領域のインデックス
//   // jを軸要素の右領域のインデックス
//   i = first;
//   j = last;

//   while (true){
//     // 軸要素以上になるまで左領域を左端から走査する
//     while (a[i] < x) i++;
//     // 軸要素以下になるまで右領域を右端から走査する
//     while (a[j] > x) j--;
//     // もし操作しているインデックスが交差したら終了
//     if (i >= j) break;

//     // 以下の3行は両側を走査してヒットした要素同士を入れ替える操作
//     // 上のwhile文を全て抜けた場合にはヒットした要素が軸要素になっている
//     t = a[i];
//     a[i] = a[j];
//     a[j] = t;
//     swaps.emplace_back(i, j);
//     // 次の要素からまあ捜査を始める
//     i++; j--;
//   }

//   // クイックソートを再帰的に呼び出す
//   if (first < i - 1) quick_sort(a, first, i-1);
//   if (last > j + 1) quick_sort(a, j + 1, last);
// }

// ソート対象を格納する配列。10は適当な長さ。
int A[200100];
// ソート対象の長さ
int N;

void bubbleSort(int array[], int array_size) {
    int i, j, k;

    for (i = 0; i < (array_size - 1); i++) {
        for (j = (array_size - 1); j > i; j--) {
            if (array[j] < array[j - 1]) {
                k = array[j];
                array[j] = array[j - 1];
                array[j - 1] = k;
                swaps.emplace_back(j - 1, j);
            }
        }
    }
}

int main(){
  cin >> N;
  REP(i, N) cin >> A[i];
  REP(i, N) A[i]--;
  
  // vector<int> b(N);
  // REP(i, N) b.at(i) = A[i];

  // firstの初期値は一番左側の0
  // lastの初期値は一番右側のN-1
  // quick_sort(A, 0, N-1);
//   bubbleSort(A, N);

  // ソートされた数列を出力する
  //   REP(i, N) cout << A[i] << " ";

  REP(i, N) {
    if (i != A[i]) {
        swaps.emplace_back(i, A[i]);
        swap(i, A[i]);
    }
  }
  cout << swaps.size() << endl;
  for (auto [i, j]: swaps) {
    int x = min(i, j);
    int y = max(i, j);
    cout << x + 1 << " " << y + 1 << "\n";
    // swap(b.at(i), b.at(j));
  }
  // REP(i, N) cout << b.at(i) << " ";
  // cout << endl;
}