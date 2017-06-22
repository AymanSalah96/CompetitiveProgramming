#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class LotteryCheating {
public:
	int minimalChange(string ID) {
		int ret = 1e9;
		for (int i = 0; i < 1e5; i++) {
			int tmp = 0;
			long long cur = 1LL*i*i;
			for (int j = ID.size() - 1; j >= 0; j--) {
				if (char(cur % 10 + '0') != ID[j]) tmp++;
				cur /= 10;
			}
			if (!cur) ret = min(ret, tmp);
		}
		return ret;
	}
};
