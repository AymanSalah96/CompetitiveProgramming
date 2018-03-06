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

void PLAY() {
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX = (1 << 17);

int BIT[MAX];

int get(int idx) {
	idx++;
	int ret = 0;
	while (idx) {
		ret += BIT[idx - 1];
		idx -= (idx & -idx);
	}
	return ret;
}

void add(int idx, int val) {
	idx++;
	while (idx <= MAX) {
		BIT[idx - 1] += val;
		idx += (idx & -idx);
	}
}


int cnt[MAX];

int main() {
	PLAY();

	int n;
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		int a = get(l - 1), b = get(r - 1);
		cout << a + b - cnt[l - 1] - cnt[r - 1] << "\n";
		cnt[l] = a; cnt[r] = b;
		add(l, 1);
		add(r - 1, -1);
	}

	return 0;
}
