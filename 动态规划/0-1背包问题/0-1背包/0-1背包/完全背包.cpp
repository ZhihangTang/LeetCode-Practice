#include <iostream>
#include <algorithm>

using namespace std;

int w[35], c[35], dp[205];

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> c[i];

	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= 1; --j) {//递推从后往前推
			for(int k=0;k<=j/w[i];++k)
				dp[j] = max(dp[j], dp[j - k*w[i]] + k*c[i]);

		}
		
	}
	cout << "max=" << dp[m];
	return 0;
}
/*
10 4
2 1
3 3
4 5
7 9


*/