#include <iostream>
#include <vector>
using namespace std;
float min(float a, float b) {
	return a < b ? a : b;
}
void convolution(vector<float> &input1, vector<float> &input2, vector<float> & output) {
	int mm = input1.size();
	int nn = input2.size();
	vector<float> xx(mm + nn - 1, 0.0);
	vector<float> tempinput2(mm + nn - 1, 0.0);
	for (int i = 0; i < nn; ++i) {
		tempinput2[i] = input2[i];
	}
	for (int i = nn; i < mm+nn-1; ++i) {
		tempinput2[i] = 0.0;
	}
	for (int i = 0; i < mm+nn-1; ++i) {
		xx[i] = 0.0;
		int tem = (min(i, mm)) == mm ? mm - 1 : min(i, mm);
		for (int j = 0; j <= tem; ++j) {
			xx[i] += (input1[j] * tempinput2[i - j]);
		}
	}
	for (int i = 0; i < mm + nn - 1; ++i) {
		output.push_back(xx[i]);
	}
}


int main() {
	int n = 0;
	cin >> n;
	vector<float> a, b,c;
	for (int i = 0; i < n; ++i) {
		float tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		float tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	convolution(a, b, c);
	for (int i = 0; i < c.size(); ++i) {
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
	

}