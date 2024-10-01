#include <stdio.h>

// Exponentiation by squaring
// base ^ power can be written as:
// if power is even:
// base ^ power = base ^ (power / 2) * base ^ (power / 2)
// if power is odd: 
// base ^ power = base ^ (power / 2) * base ^ (power / 2) * base
long long exp_by_squaring(int base, int power) {
	if (power == 0) {
		return 1;
	}
	long long squaring = exp_by_squaring(base, power / 2);
	if (power % 2 == 0) {
		return squaring * squaring;
	} else {
		return base * squaring * squaring;
	}
}

int main() {
	int base, power;
	scanf("%d%d", &base, &power);
	long long result = exp_by_squaring(base, power);
	printf("%lld", result);
	return 0;
}
