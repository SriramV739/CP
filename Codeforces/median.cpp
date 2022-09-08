#include <bits/stdc++.h>
using namespace std;

int lastTrue(int lo, int hi, function<bool(int)> f) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return lo;
}

int main() {
	int size;
	int maxOps;
	cin >> size >> maxOps;
	vector<int> arr(size);
	for (int& i: arr) {
		cin >> i;
	}
	
	sort(arr.begin(), arr.end());
	// Use 2e9 instead of INT32_MAX to avoid overflow
	cout << lastTrue(1, 2e9, [&] (int x) {
		// Returns true if the median can be raised to x
		long long opsNeeded = 0;
		for (int i = (size - 1) / 2; i < size; i++) {
			opsNeeded += max(0, x - arr[i]);
		}
		return opsNeeded <= maxOps;
	}) << endl;
}