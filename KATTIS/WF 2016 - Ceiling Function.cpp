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
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

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
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void openfile() {
	cout << fixed << setprecision(15);
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int LCM(int a, int b) {
	int mx = max(a, b);
	while ((mx%a) || (mx%b)) mx++;
	return mx;
}
int GCD(int a, int b) {
	while (b != 0) {
		int x = a % b;
		a = b;
		b = x;
	}
	return a;
}

struct node {
	int x;
	node *left = NULL;
	node *right = NULL;
};

node *root;
void insert(int n) {
	node *temp = root;
	while (1) {
		if (n <= temp->x) {
			if (temp->left == NULL) {
				temp->left = new node;
				temp->left->x = n;
				return;
			}
			temp = temp->left;
		}
		else {
			if (temp->right == NULL) {
				temp->right = new node;
				temp->right->x = n;
				return;
			}
			temp = temp->right;
		}
	}
}

vector<int> pth;
void path(node *tmp) {
	if (tmp == NULL)
		return;
	pth.push_back(0);
	path(tmp->left);
	pth.push_back(1);
	path(tmp->right);
}

int main() {
	
	int n, k, a[25];
	sfi2(n, k);
	set<vector<int>> st;
	while(n--) {
		pth.clear();
		root = new node;
		sfi1(a[0]);
		root->x = a[0];
		for (int i = 1; i < k; i++) {
			sfi1(a[i]);
			insert(a[i]);
		}
		path(root);
		st.insert(pth);
	}
	cout << st.size() << endl;
	return 0;
}
