/*
Author: Ayman Salah

Category: Dynamic Programming, Bitmask
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

using namespace std;


class PowerPlants {
public:


	int getCost(char ch) {
		if (ch >= '0' && ch <= '9') return ch - '0';
		return (ch - 'A') + 10;
	}

	int minCost(vector <string> connectionCost, string plantList, int numPlants) {
		int n = (int)connectionCost.size();
		int cost[16][16];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cost[i][j] = getCost(connectionCost[i][j]);
		int dp[1 << 16];
		for (int i = 0; i < 1 << 16; i++)
			dp[i] = 1e4;
		int msk = 0;
		for (int i = 0; i < plantList.size(); i++)
			if (plantList[i] == 'Y')
				msk |= (1 << i);
		dp[msk] = 0;
		int ret = 1e4;
		for (int i = 1; i < (1 << n); i++) {
			int tmp = i, cnt = 0;
			while (tmp) {
				tmp = tmp & (tmp - 1);
				cnt++;
			}
			if (cnt >= numPlants) {
				ret = min(ret, dp[i]);
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (!(i & (1 << j))) {
					int mnCost = 1e4;
					for (int k = 0; k < n; k++)
						if (i & (1 << k))
							mnCost = min(mnCost, cost[k][j]);
					dp[i | (1 << j)] = min(dp[i | (1 << j)], mnCost + dp[i]);

				}
 			}
		}
		return ret;
	}
};
