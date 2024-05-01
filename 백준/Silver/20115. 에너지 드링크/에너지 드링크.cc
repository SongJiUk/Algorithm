#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;	// 에너지드링크 수 
	double energy_drink[100000];	// 에너지 드링크의 양
	double max;	// 합쳐진 에너지 드링크의 최대 양

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> energy_drink[i];
	}

	// 주어진 에너지 드링크들 중
	// 양이 제일 많은 드링크를 찾기 위해 정렬
	sort(energy_drink, energy_drink + N);

	// 정렬된 값중 마지막 값이 제일 양이 많은 드링크
	// 이 값을 기준으로 나머지 드링크들을 여기에 붓는다.
	max = energy_drink[N - 1];

	for (int i = 0; i < N - 1; i++) {
		// 가장 큰 값에 다른 작은 값의 드링크들을 모두 붓는다.
		// 단, 붓는 과정에서 절반씩 흘린다고 했으므로, / 2
		max += (energy_drink[i] / 2);
	}

	cout << max;

	return 0;
}