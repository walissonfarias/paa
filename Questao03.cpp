#include <iostream>
#include <vector>

using namespace std;

template<
	class T,
	class Allocator = std::allocator<T>
> class vector;

int sequentialSearch(std::vector<int> vetor, int k) {
	int i = 0;
	while (i < vetor.size()) {
		i = i + 1;
		if (i < k) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	cout << "digite o tamanho do vetor" << endl;
	cin >> n;
	std::vector <int> v = { 7 , 5 , 16 , 8 };
	for (int i = 0; i < n; i++) {
		cout << "digite o tamanho a posicao" << i << " do vetor:" << endl;
		cin >> v[i];
	}
	int k;
	cout << "digite o numero a ser pesquisado:" << endl;
	cin >> k;
	if (sequentialSearch(v, k) == 1){
		cout << "o numero foi localizado no vetor";
	} else {
		cout << "o numero não foi localizado no vetor" << endl;
	}
}


