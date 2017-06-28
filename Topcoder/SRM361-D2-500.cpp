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

class WhiteHats {
public:
	int whiteNumber(vector <int> count) {
		int n = sz(count);
		vector<int> freq(51, 0);
		for (int i = 0; i < sz(count); i++) 
			freq[count[i]]++;
		if (freq[0] == n) return 0;
		for (int i = 1; i < sz(freq); i++)
			if (freq[i - 1] == i && freq[i] == n - i)
				return i;
		return -1;
	}
};
