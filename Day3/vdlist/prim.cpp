#include <stdio.h>

int isprim(long i) {
	if ((i % 2) == 0 || i < 3) return -1;

	int op = 0;
	int t;
	int u = i / t;
	for (t = 3; t < u + 1; t = t + 2, u = (i / t) + 1) {
		op++;
		if ((i % t) == 0) {
			op = -1;
			break;
		}
	}
	return op;
}
void printout(long prim, int counter, int op) {
	if ((counter % 100) != 0) return;
	double prozent = (double)counter * 100 / prim;
	printf("%10ld Anzahl: %-10d Op: %-5d Prozent: %lf\n", prim, counter, op,
	       prozent);
}
int main(void) {
	int counter = 1;
	long zahl = 2;
	int op = 0;
	printout(zahl, counter, op);

	for (zahl = 3; zahl < 1000000; zahl += 2, op = 0) {
		op = isprim(zahl);
		if (op >= 0) {
			printout(zahl, ++counter, op);
		}
	}
	return 0;
}
