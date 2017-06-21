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


class MagicWords {
public:
	int count(vector <string> S, int K) {
		int n = (int)S.size();
		map<string, int> memo;
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		int ret = 0;
		do {
			string tmp = "";
			for (int i = 0; i < n; i++)
				tmp += S[p[i]];
			int &mem = memo[tmp];
			if (mem != 0) {
				if (mem == 2) ret++;
				continue;
			}
			mem = 1;
			int m = 0;
			for (int i = 0; i < (int)tmp.size(); i++) {
				bool good = true;
				for (int j = 0; j < (int)tmp.size() && good; j++)
					if (tmp[j] != tmp[(j + i) % ((int)tmp.size())])
						good = false;
				if (good) {
					m++; 
					if (m > K) break;
				}
			}
			if (m == K) ret++, mem = 2;
		} while (next_permutation(p.begin(), p.end()));
		return ret;
	}
};
