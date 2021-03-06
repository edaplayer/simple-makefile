#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	auto k = 0;

	int hash[255] = {0};
	int i = 0;
	int target = 0;
	string s;

	while (cin >> s) {
		cin >> k;
		int len = s.length();
		for (i = 0; i < len ; ++i) {
			if (!hash[s[i]]) {
				hash[s[i]] = i + 1;
			}
		}
		sort(s.begin(), s.end());

		if(k > len) {
			target = len -1;
		} else {
			target = k -1;
		}

		cout << hash[s[target]]  - 1 << endl << endl;
	}
	return 0;
}
