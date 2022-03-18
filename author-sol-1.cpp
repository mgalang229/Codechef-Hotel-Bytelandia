#include <bits/stdc++.h>
using namespace std;

struct Guest {
	int arrival;
	int departure;
};

void perform_test() {
	int n;
	cin >> n;
	vector<Guest> vec(n);
	for(int i = 0; i < n; i++) {
		cin >> vec[i].arrival;
	}
	for(int i = 0; i < n; i++) {
		cin >> vec[i].departure;
	}
	// brute-force approach:
	// from each time in 0 to 1000, count the no. of guest are present
	int mx = 0;
	for(int time = 0; time <= 1000; time++) {
		int cnt = 0;
		for(Guest g : vec) {
			if(time >= g.arrival && time < g.departure) {
				cnt++;
			}
		}
		mx = max(mx, cnt);
	}
	cout << mx << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		perform_test();
	}
	return 0;
}

