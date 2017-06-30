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

#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sz(v) (int)v.size()
typedef long long ll;

class ProgrammingDevice {
public:
	int minPackets(vector <int> offset, vector <int> size, int maxData) {
		int n = sz(offset);
		vector<ll> res(n, 0);
		vector<pair<ll, ll>> v(n);
		for (int i = 0; i < n; i++)
			v[i] = { offset[i], offset[i] + size[i] - 1 };
		sortva(v);
		for (int i = 0; i < n; i++) {
			ll size = v[i].second - v[0].first + 1;
			res[i] = size / maxData + bool(size % maxData);
			for (int j = 1; j <= i; j++) {
				size = v[i].second - v[j].first + 1;
				res[i] = min(res[i], res[j - 1] + (size / maxData + bool(size % maxData)));
			}
		}
		return res.back();
	}
};
