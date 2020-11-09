#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <limits>

int main() {
	std::cout << "Begin" << std::endl;

	double T[14] = { 0,10,12,15,18,22,27,33,39,47,56,68,82, 100 };
	
	int n = 14, k = 8;
	int q;
	int* P = new int[k];
	for (int i = 0; i < k; i++) {
		P[i] = 0;
	}
	int R0 = 271;

	do {


			int RAB = 0;

			for (int i = 0; i < 8; i += 2) {
				double a = T[P[i]], b = T[P[i+1]];
				if (a == 0) {
					a = 1;
				}
				else if (a == 100) {
					a = 0;
				}
				else {
					a = 1 / a;
				}
				if (b == 0) {
					b = 1;
				}
				else if (b == 100) {
					b = 0;
				}
				else {
					b = 1 / b;
				}
				if (a + b == 0)
					a = std::numeric_limits<double>::max();
				RAB += (int) 1/(a + b);
				
			}
			if (abs(R0 - RAB) == 0)
			{
				for (int i = 0; i < k; i++) {
					std::cout << T[P[i]] << ", ";
				}
				std::cout << std::endl;
			}
		
		q = k - 1;
		while (q >= 0) {
			P[q]++;
			if (P[q] == n) {
				P[q] = 0;
				q--;
			}
			else {
				break;
			}
		}
	} while (q >= 0);
	delete[] P;

	return 0;
}