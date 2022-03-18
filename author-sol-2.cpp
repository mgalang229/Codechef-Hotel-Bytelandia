#include <bits/stdc++.h>
using namespace std;

struct Guest {
	int time;
	int type;
	Guest(int time, int type) {
		this->time = time;
		this->type = type;
	}
};

void perform_test() {
	int n;
	cin >> n;
	// store the time of all the guests in one vector (both arrival & departure)
	// denote its type as 1 if it's arrival time and type 0 for departure time
	Guest person(-1, -1);
	vector<Guest> vec;
	for(int i = 0; i < n; i++) {
		int arrival_time;
		cin >> arrival_time;
		person = Guest(arrival_time, 1);
		vec.push_back(person);
	}
	for(int i = 0; i < n; i++) {
		int departure_time;
		cin >> departure_time;
		person = Guest(departure_time, 0);
		vec.push_back(person);
	}
	// sort the sequence based on the arrival time (least to greatest)
	// note: if the arrival times are equal, then compare its type (departure)
	sort(vec.begin(), vec.end(), [](const Guest& a, const Guest& b) {
		if(a.time == b.time) {
			return a.type < b.type;
		}
		return a.time < b.time;
	});
	// increment the counter for every arrival of a guest
	// decrement the counter for every departure of a guest
	// note: in each iteration, store the maximum no. of guests that are present
	int ans = 0, cnt = 0;
	for(Guest g : vec) {
		if(g.type == 1) {
			cnt++;
		} else {
			cnt--;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
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

