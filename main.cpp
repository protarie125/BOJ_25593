#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using Table = map<string, ll>;

int n;
auto times = vi{ 4,6,4,10 };
Table tb;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	auto added = int{ 0 };
	for (auto i = 0; i < n; ++i) {
		for (const auto& t : times) {
			for (auto j = 0; j < 7; ++j) {
				string s;
				cin >> s;

				if ("-" != s) {
					++added;
					tb[s] += t;
				}
			}
		}
	}

	if (0 == added) {
		cout << "Yes";
		return 0;
	}

	auto min = numeric_limits<int>::max();
	auto max = numeric_limits<int>::min();
	for (const auto& [k, v] : tb) {
		if (v < min) {
			min = v;
		}

		if (max < v) {
			max = v;
		}
	}

	cout << (max - min <= 12 ? "Yes" : "No");

	return 0;
}