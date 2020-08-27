
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  double n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  vector<double> equ(n);
  for (double i = 0; i < n; i++) {
    double temp;
    cin >> temp;
    equ[i] = temp;
  }
  sort(equ.begin(), equ.end());
  if (m == 0) {
    cout << equ[0] << endl;
  }
  else {
    double res = equ[0];
    for (double i = 0; i < n; i++) {
      equ[i] -= equ[0];
    }
    while (m) {
      double j;
      for (j = 0; j < n; j++) {
        if (m == 0) {
          break;
        }
        if (equ[j] == 0) {
          m--;
        }
        else {
          equ[j]--;
        }
      }
      if (j == n) {
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}