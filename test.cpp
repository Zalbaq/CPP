#include <iostream>
using namespace std;

bool can_defeat_all(int N, int M, int A[], int B[], int mid) {
	int current_skill = M;

	for (int i = 0; i < N; i++) {
		if (A[i] <= current_skill) {
			current_skill += B[i];
			if (current_skill > mid) {
				return false;
			}
		}
	}

	return true;
}

int find_max_skill(int N, int M, int A[], int B[]) {
	int left = M, right = M + 1000005;
	int max_skill = M;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (can_defeat_all(N, M, A, B, mid)) {
			max_skill = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return max_skill;
}

int main() {
	int N, M;
	cin >> N >> M;

	int A[N], B[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	int result = find_max_skill(N, M, A, B);
	cout << result << endl;

	return 0;
}
