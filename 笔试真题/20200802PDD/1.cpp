#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const long long infl = 0x3f3f3f3f3f3f3f3fll;

int main() {
#ifdef __LOCAL_WONZY__
    freopen("input-1.txt", "r", stdin);
#endif // __LOCAL_WONZY__
    int k, n;
    cin >> k >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int cur = k;
    int back_cnt = 0;
    for(int i = 0; i < n; ++i) {
        cur -= arr[i];
        if(cur == 0) {
            break;
        } else if(cur < 0) {
            cur *= -1;
            back_cnt += 1;
        }
    }
    if(cur == 0 || k == 0) cout << "paradox" << endl;
    else {
        cout << cur << " " << back_cnt << endl;
    }
	return 0;
}