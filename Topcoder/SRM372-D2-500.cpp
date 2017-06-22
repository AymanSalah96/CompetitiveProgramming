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


class RoadConstruction {
public:
	int getExitTime(vector <string> v) {
		int r = 0;
		int n = (int)v.size();
		int l = n - 1;
		vector<int> vis(n, 0);
		while (true) {
			for (int i = 0; i < n; i++) {
				if (!v[i].size()) continue;
				if (vis[i] >= l || i == l) {
					if (v[i][0] == 'D') return r;
					v[i] = v[i].substr(1);
					r++;
					vis[i] = 0;
					if (i == l)
						for (int j = 0; j < n; j++)
							if (v[j].size()) l = j;
					break;
				}
				else
					vis[i] = l;
			}
		}
		return r;
	}
};
