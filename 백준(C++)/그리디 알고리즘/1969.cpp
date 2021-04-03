//1969 DNA
#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
char DNA[1000][50];  //뉴클레오티드 쌍
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	//첫 번째 수가 같다면
	if (a.first == b.first)
		return a.second < b.second; //두 번째 수로 오름차순
	return a.first > b.first; //첫 번째 수가 더 작은 수가 앞으로 내림차순
}

int main() {
	int N, M;
	char s[50];
	int sum = 0;
	vector <pair<int, char>> dna; //뉴클레오티드 하나
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> DNA[i];
	}

	int check_dna = 0; 
	for (int i = 0; i < M; i++) {
		dna.clear();
		for (int j = 0; j < N; j++) {
			check_dna = 0;
			for (int k = 0; k < dna.size(); k++) {
				if (dna[k].second == DNA[j][i]) {
					dna[k].first++; //size 증가
					check_dna = 1;
					break;
				}
			}
			if (check_dna == 0) {
				dna.push_back(make_pair(1, DNA[j][i])); // dna를 하나 생성하여 저장
			}
		}

		if (dna.size() == 1) {
			s[i] = dna[0].second; // 한종류의 dna만 존재할 때
			continue;
		}

		sort(dna.begin(), dna.end(), compare); //내림차순으로 정렬

		s[i] = dna[0].second;
		sum += (N - dna[0].first);
	}

	for (int i = 0; i < M; i++) {
		cout << s[i];
	}

	cout << endl << sum << endl;

	return 0;
}