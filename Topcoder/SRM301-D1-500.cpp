/*
Author: Ayman Salah

Category: Graphs, Shortest Path, Floyd Warshall Algorithm
*/

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


class EscapingJail {
public:

	int getDistance(char ch) {
		if (ch >= '0' && ch <= '9') return ch - '0';
		if (ch >= 'a' && ch <= 'z') return (ch - 'a') + 10;
		return (ch - 'A') + 36;
	}
	int getMaxDistance(vector <string> chain) {
		int n = (int)chain.size();
		int cost[55][55];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cost[i][j] = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (chain[i][j] == ' ') continue;
				cost[i][j] = getDistance(chain[i][j]);
			}
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (cost[i][k] < INT_MAX && cost[k][j] < INT_MAX)
						cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
		int ret = INT_MIN;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret = max(ret, cost[i][j]);
		if (ret == INT_MAX) return -1;
		return ret;
	}
};
