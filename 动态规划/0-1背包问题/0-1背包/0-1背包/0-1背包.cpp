/*
#include <iostream>
#include <algorithm>

using namespace std;



//origin
int dp[35][205];
int w[35],c[35];

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> c[i];

	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {//递推从后往前推
			if (j < w[i]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;

	}
	return 0;
}


int w[35], c[35],dp[205];

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i] >> c[i];

	}
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >=1 ; --j) {//递推从后往前推
			if (j >= w[i]) {
			
				dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
			}
		}
		
	}
	cout << dp[m];

	return 0;
}

*/
/*
10 4
2 1
3 3
4 5
7 9


*/