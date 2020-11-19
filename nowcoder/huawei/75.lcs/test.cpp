// 公共子串计算
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	auto result = 0;
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	int len1 = s1.length() + 1;
	int len2 = s2.length() + 1;

	vector<vector<int>> dp(len2, vector<int>(len1, 0));

	// 形式1
	for (int i = 0; i < len2 - 1; ++i) {
		for(int j = 0; j < len1 - 1; j++) {
			if (s2[i] == s1[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
				result = max (result, dp[i + 1][j + 1]);
			}
		}
	}

	for (int i = 0; i < len2; ++i) {
		for(int j = 0; j < len1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "max = " << result << endl << endl;

	// 形式2
	int i = 1, j = 1;
	for (i = 1; i < len2; ++i) {
		for(j = 1; j < len1; j++) {
			if (s2[i - 1] == s1[j - 1])
			{
				dp[i][j] = dp[i -1][j - 1] + 1;
				result = max (result, dp[i][j]);
			}
		}
	}

	for (int i = 0; i < len2; ++i) {
		for(int j = 0; j < len1; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "max = " << result << endl;

	return 0;
}
