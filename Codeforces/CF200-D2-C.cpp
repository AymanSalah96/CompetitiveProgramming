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

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct team {
	string name;
	int points;
	int score;
	int miss;
	team() {
		name = "";
		points = score = miss = 0;
	}
	team(string n, int p, int s, int m) {
		name = n;
		points = p;
		score = s;
		miss = m;
	}
	bool operator<(const team &t) const {
		if (points == t.points) {
			int diff1 = score - miss;
			int diff2 = t.score - t.miss;
			if (diff1 == diff2) {
				if (score == t.score)
					return name < t.name;
				return score > t.score;
			}
			return diff1 > diff2;
		}
		return points > t.points;
	}
};

int main() {
	PLAY();


	map<string, team> mp;
	map<string, int> cnt;
	for (int i = 0; i < 5; i++) {
		string team1, team2;
		int score1, score2;
		char tmp;
		cin >> team1 >> team2;
		cin >> score1 >> tmp >> score2;
		cnt[team1]++;
		cnt[team2]++;
		int p1 = 0, p2 = 0;
		if (score1 == score2)
			p1 = p2 = 1;
		else if (score1 > score2) p1 = 3;
		else p2 = 3;
		if (mp.find(team1) == mp.end())
			mp[team1] = team(team1, p1, score1, score2);
		else {
			mp[team1].points += p1;
			mp[team1].score += score1;
			mp[team1].miss += score2;
		}
		if (mp.find(team2) == mp.end())
			mp[team2] = team(team2, p2, score2, score1);
		else {
			mp[team2].points += p2;
			mp[team2].score += score2;
			mp[team2].miss += score1;
		}
	}
	vector<team> v;
	team other;
	for (auto e : cnt)
		if (e.second == 2 && e.first != "BERLAND")
			other = mp[e.first];
	team berland;
	for (auto e : mp) {
		if (e.first == "BERLAND") berland = e.second;
		else if(e.first != other.name) v.push_back(e.second);
	}
	int mnx = 100, mny = 100;
	int mn = INT_MAX;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < i; j++) {
			vector<team> tmp = v;
			berland.points += 3;
			berland.score += i;
			berland.miss += j;
			other.score += j;
			other.miss += i;
			tmp.push_back(berland);
			tmp.push_back(other);
			sortva(tmp);
			if (tmp[0].name == "BERLAND" || tmp[1].name == "BERLAND") {
				int diff = i - j;
				if (diff <= mn) {
					if (diff == mn) {
						if (j < mny)
							mnx = i, mny = j;
					}
					else
						mnx = i, mny = j;
					mn = diff;

				}
			}
			berland.points -= 3;
			berland.score -= i;
			berland.miss -= j;
			other.score -= j;
			other.miss -= i;
		}
	}
	if (mn == INT_MAX)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << mnx << ":" << mny << endl;

	return 0;
}
