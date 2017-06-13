/*
Author: Ayman Salah

Category: Brute Force, Geometry
*/

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
#include <cstring>
#include <climits>

using namespace std;

class CrouchingAmoebas {
public:
	int count(vector <int> x, vector <int> y, int A, int T) {
		int n = (int)x.size();
		int ret = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int dx = -T; dx <= T; ++dx) {
					for (int dy = -T; dy <= T; ++dy) {
						if (abs(dx) + abs(dy) <= T)
						{
							int left_x = dx + x[i];
							int down_y = dy + y[j];
							vector<int> vals;
							vals.clear();
							for (int k = 0; k < n; ++k)
							{
								int cur = 0;
								if (x[k]<left_x) 
									cur += left_x - x[k];
								else if (x[k]>left_x + A) 
									cur += x[k] - left_x - A;
								if (cur > T) continue;
								if (y[k]<down_y)
									cur += down_y - y[k];
								else if (y[k]>down_y + A) 
									cur += y[k] - down_y - A;
								if (cur > T) continue;
								vals.push_back(cur);
							}
							int cnt = 0, rem = T;
							sort(vals.begin(), vals.end());
							for (int k = 0; k < vals.size(); ++k) {
								if (rem - vals[k] < 0) break;
								rem -= vals[k];
								cnt++;
							}
							ret = max(ret, cnt);
						}
					}
				}
			}
		}
		return ret;
	}
};
