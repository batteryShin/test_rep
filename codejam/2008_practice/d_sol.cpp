#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> stokens(string s, string sep = " \n\r\t") {
	vector<string> res;
	int start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}


class Store {
public:
Store() {}
Store(string s, int N, map<string, int> items) {
	price.resize(N, -1);
	vector<string> st = stokens(s, " :\n");
	x = atoi(st[0].c_str());
	y = atoi(st[1].c_str());
	for (int i = 2; i < st.size(); i += 2) {
		price[items[st[i]]] = atoi(st[i+1].c_str());
	}
}
double dist(int xp, int yp) const { return sqrt((x-xp)*(x-xp) + (y-yp)*(y-yp)); }
int x, y;
vector<int> price;
};

void doit(int cn, int gp, const vector<int> &per, const vector<Store> &sts) {
	int N = per.size(), S = sts.size();

	vector<vector<int> > shv(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < S; j++) if (sts[j].price[i] > 0) {
			shv[i].push_back(j);
		}
	}
	double bcost = 1e100;

	vector<int> ws(N, 0);
	do {
		double icost = 0.0;
		vector<int> tov, sper(S, 0);
		vector<vector<int> > tobuy(S);
		for (int i = 0; i < N; i++) {
			int s = shv[i][ws[i]];
			if (tobuy[shv[i][ws[i]]].empty()) tov.push_back(s);
			tobuy[s].push_back(i);
			icost += sts[s].price[i];
			if (per[i]) sper[s] = 1;
		}
/*	
printf("stores:");
for (int i = 0; i < N; i++) printf(" %d", shv[i][ws[i]]);
printf(", icost %d\n", (int)icost);
*/

		double bgcost = 1e100;
		sort(tov.begin(), tov.end());
		int T = tov.size();
		do {
			double gcost = 0.0;
			int x = 0, y = 0;
			for (int i = 0; i < T; i++) {
				int s = tov[i];
				gcost += sts[s].dist(x, y);
				if (sper[s]) {
					gcost += sts[s].dist(0, 0);
					x = 0, y = 0;
				} else {
					x = sts[s].x, y = sts[s].y;
				}
			}
			gcost += sqrt(x*x + y*y);
/*
printf(" order: ");
for (int i = 0; i < tov.size(); i++) printf(" %d", tov[i]);
printf(", gcost %g\n", gcost);
*/
			if (gcost < bgcost) bgcost = gcost;
		} while (next_permutation(tov.begin(), tov.end()));

		double tcost = icost + gp*bgcost;
		if (tcost < bcost) bcost = tcost;

		bool ok = false;
		for (int i = 0; i < N; i++) {
			ws[i]++;
			if (ws[i] == shv[i].size()) ws[i] = 0;
			else {
				ok = true;
				break;
			}
		}
		if (!ok) break;
	} while(true);

	printf("Case #%d: %.7lf\n", cn, bcost);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int ni, ns, pg;
		scanf(" %d %d %d ", &ni, &ns, &pg);
		map<string, int> items;
		vector<int> perish(ni, 0);
		vector<Store> sts(ns);
		char sz[10000];
		for (int j = 0; j < ni; j++) {
			scanf(" %9999s ", sz);
			string s(sz);
			if (s[s.size()-1] == '!') {
				perish[j] = 1;
				s.resize(s.size()-1);
			}
			items[s] = j;
		}

		for (int j = 0; j < ns; j++) {
			fgets(sz, 9999, stdin);
			sts[j] = Store(sz, ni, items);
		}

		doit(i+1, pg, perish, sts);
	}
	return 0;
}

