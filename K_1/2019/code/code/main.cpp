#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <vector>
#include <list>
#include <stdlib.h>
#include <limits>

const unsigned long T[]{ 27257, 11737, 3417, 74732055, 7008769, 71198, 6970, 8602, 74787, 3485, 97291, 61981162, 1938, 8551, 8051, 65105553, 8228, 10217603, 23728483, 72114322, 4896, 85845, 6014, 84696329, 47142, 41039298, 2159, 5235466, 82838 };
//{
//	27257,		//1
//	11737,		//2
//	3417,		//3
//	74732055,	//4
//	7008769,	//5
//	71198,		//6
//	6970, //7
//	8602, // 8
//	74787, // 9
//	3485, //10
//	97291,		//11
//	61981162,		//12
//	1938,		//13
//	8551,		//14
//	8051,		//15
//	65105553,		//16
//	8228,		//17
//	10217603,		//18
//	23728483,		//19
//	72114322,		//20
//	4896,		//21
//	85845,		//22
//	6014,		//23
//	84696329,		//24
//	47142,		//25
//	41039298,		//26
//	2159,		//27
//	5235466,		//28
//	82838		//29
//};
const int size = 29;

int main() {
	unsigned long long total_sum = 0;
	for (int i = 0; i < size; i++) {
		total_sum += T[i];
	}
	
	int n = 29, k = 1;
	int i, j;
	bool b;
	int *P = new int[k];
	unsigned long long best_error = ULLONG_MAX;
	for (i = 0; i < k; i++)
		P[i] = i + 1;

	int count = 0;
	while (k != 15) {
		do {
			unsigned long long partial_sum = 0;
			for (int i = 0; i < k; i++) {
				partial_sum += T[P[i] - 1];
			}
			unsigned long long other_group_sum = total_sum - partial_sum;
			
			// Treba ovo napraviti da radi
			if (other_group_sum == partial_sum) {
				best_error = partial_sum;
				for (int i = 0; i < k; i++) {
					std::cout << P[i] << ", ";
				}
				std::cout << std::endl;
				std::cout << partial_sum << std::endl;
			}

			b = false;
			for (i = k - 1; i >= 0; i--) {
				if (P[i] < n - k + 1 + i) {
					P[i]++;
					for (j = i + 1; j < k; j++) {
						P[j] = P[j - 1] + 1;
					}

					b = true;
					break;
				}
			}
	
		} while (b);
		k++;
		P = new int[k];
		for (i = 0; i < k; i++)
			P[i] = i + 1;
	}
	for (int i = 0; i < k; i++) {
		std::cout << P[i] << ", ";
	}
	if (P != NULL)
		delete[] P;
	



	return 0;
}