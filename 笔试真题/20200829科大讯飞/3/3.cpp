
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	int N;
	cin >> N;
	map<pair<int, int>, pair<int, int>> features;
	int amounts;
	int x, y, ans = 1;
	vector<int> res;
	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		for (int j = 0; j < M; ++j) {
			cin >> amounts;

			for (int k = 0; k < amounts; ++k) {
				cin >> x >> y;
				if (features.find(make_pair(x, y)) == features.end()) {
					features.insert(make_pair(make_pair(x, y), make_pair(j, 1)));
				}
				else {
					auto iter = features.find(make_pair(x, y));
					if (j - iter->second.first == 1) {
						iter->second.first = j;
						iter->second.second += 1;
						ans = max(ans, iter->second.second);
					}
					else {
						iter->second.first = j;
						iter->second.second = 1;
					}
				}
			}
		}
		res.push_back(ans);
	}
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	return 0;
}

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool isInclude( vector<pair<int, int>> v, pair<int, int>p){
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == p) {
			return true;
		}
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> vv;
	//map<pair<int, int>, pair<int, int>> features;

	int x, y, res= 1;

	for (int i = 0; i < N; ++i) {
		int M;
		cin >> M;
		int max = 1;
		for (int j = 0; j < M; ++j) {
			
			int kk;
			cin >> kk;
			vector<pair<int, int>> single(kk);
			for (int k = 0; k < kk; ++k) {
				cin >> single[i].first>> single[i].second;
			}
			vv.push_back(single);
		}
		while (N--) {
			for (int i = 0; i < vv.size(); ++i) {
				for (int j = 0; j < vv[i].size(); ++j) {
					int tmp = 1;
					for (int m = i + 1; m < vv.size(); ++m) {
						if (isInclude(vv[m], vv[i][j])){
								tmp++;
								if (tmp > res) {
									res=tmp;
								}
						}
						else {
							tmp = 1;
						}
					}
				}
			}
		}
		
		
		
	}
	cout << res << endl;

	return 0;
}