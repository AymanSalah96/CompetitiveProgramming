/*
Author: Ayman Salah

Category: Dynamic Programming

Idea:
-Count all possible valid messages with DP
-Take care of overflow. You don't need the actual number of differant valid messages.
-Then if it's a unique message then construct it using the DP taple.
-Else if there are more than one valid message output "AMBIGUOUS!"
-Else if there are no valid messages at all output "IMPOSSIBLE!"
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

using namespace std;

typedef long long ll;

class MessageMess {
public:

	vector<string> dic;
	string mess;
	ll dp[55];
	ll solve(int i) {
		if (i == mess.size()) return dp[i] = 1;
		ll &ret = dp[i];
		if (ret != -1) return ret;
		ret = 0;
		string cur = mess;
		cur.erase(0, i);
		for (int j = 0; j < dic.size(); j++) {
			string substr = cur.substr(0, dic[j].size());
			if (substr == dic[j]) {
				ret += solve(i + substr.size());
				if (ret > 1) return ret = 2;
			}
		}
		return ret;
	}

	string restore(vector <string> dictionary, string message) {
		memset(dp, -1, sizeof dp);
		mess = message;
		dic = dictionary;
		ll cnt = solve(0);
		if (cnt == 0) return "IMPOSSIBLE!";
		if (cnt > 1) return "AMBIGUOUS!";
		string ret = "";
		int prev = 0;
		for (int i = 0; i <= message.size(); i++) {
			if (dp[i] == 1) {
				int sz = i - prev;
				if (!sz) continue;
				ret += mess.substr(0, sz);
				ret += " ";
				mess.erase(0, sz);
				prev = i;
			}
		}
		if (ret.back() == ' ') ret.pop_back();
		return ret;
	}
};
