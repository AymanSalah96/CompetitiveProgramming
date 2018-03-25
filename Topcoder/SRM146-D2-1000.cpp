#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <hash_map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define sz(v) (int)v.size()

int res, n;

void solve(vector<int> &time, vector<bool> passed, int cost) {
	
	int numberOfPassed = 0, last1 = -1, last2 = -1;
	for (int i = 0; i < n; i++) {
		if (passed[i]) numberOfPassed++;
		else if(last1 == -1) last1 = time[i];
		else last2 = time[i];
	}
	if (numberOfPassed == n - 1) {
		res = min(res, cost + last1);
		return;
	}
	if (numberOfPassed == n - 2) {
		res = min(res, cost + max(last1, last2));
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (passed[i] || passed[j]) continue;
				if (i != k && j != k && !passed[k]) continue;

				int cur_cost = max(time[i], time[j]) + time[k];

				if (i == k) {
					passed[j] = true;
					solve(time, passed, cost + cur_cost);
					passed[j] = false;
				}
				else if (j == k) {
					passed[i] = true;
					solve(time, passed, cost + cur_cost);
					passed[i] = false;
				}
				else {
					passed[i] = passed[j] = true;
					passed[k] = false;
					solve(time, passed, cost + cur_cost);
					passed[i] = passed[j] = false;
					passed[k] = true;
				}
			}
		}
	}
}

class BridgeCrossing {
public:

	int minTime(vector <int> times) {
		n = sz(times);
		res = INT_MAX;
		solve(times, vector<bool>(sz(times), false), 0);
		return res;
	}
};
