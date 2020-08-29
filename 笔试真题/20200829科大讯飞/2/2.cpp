/*
#include <iostream>
#include <vector>
using namespace std;
long  TotalCount(int n) {
	if (n < 1) {
		return 0;
	}
	if (n == 1) {
		return 3;
	}
	vector<long> dp(n + 1, 0);
	dp[1] = 3;
	dp[2] = 9;
	for (int i = 3; i <= n; ++i) {
		dp[i] = 2 * dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

int main() {
	int n = 0;
	cin >> n;
	int res = TotalCount(n+1);
	cout << res << endl;
	return 0;
}

*/