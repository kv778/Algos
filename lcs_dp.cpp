#include <bits/stdc++.h>
using namespace std;

string LCSubStr(string X, string Y)
{
	int m = X.length();
	int n = Y.length();

	int result = 0;
	int end;

	int len[2][n];
	int currRow = 0;

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				len[currRow][j] = 0;
			}
			else if (X[i - 1] == Y[j - 1]) {
				len[currRow][j] = len[1 - currRow][j - 1] + 1;
				if (len[currRow][j] > result) {
					result = len[currRow][j];
					end = i - 1;
				}
			}
			else {
				len[currRow][j] = 0;
			}
		}
		currRow = 1 - currRow;
	}

	if (result == 0) {
		return "-1";
	}
	return X.substr(end - result + 1, result);
}

int main()
{
	string X = "arya";
	string Y = "aarya";
	cout << LCSubStr(X, Y);
	return 0;
}
