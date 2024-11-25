#include <stdio.h>

struct primlist
{
	long prim;
	primlist *next;
} *firstElement = NULL, *lastElement = NULL;
int isprimnew(long i)
{
	if (i == 2)
		return 1;
	if ((i % 2) == 0 || i < 3)
		return -1;
	if (firstElement == NULL)
		return -1;

	int op = 0;
	primlist *tempPrim = firstElement;
	long upper = i / tempPrim->prim;
	for (primlist *templist = firstElement; (upper + 1) > tempPrim->prim; tempPrim = tempPrim->next, upper = 1 / tempPrim->prim)
	{
		op++;
		if (i % tempPrim->prim == 0)
		{
			op = -1;
			break;
		}
		if (tempPrim->next == NULL)
			break;
	}
}
int isprim(long i)
{
	if ((i % 2) == 0 || i < 3)
		return -1;

	int op = 0;
	int t;
	int u = i / t;
	for (t = 3; t < u + 1; t = t + 2, u = (i / t) + 1)
	{
		op++;
		if ((i % t) == 0)
		{
			op = -1;
			break;
		}
	}
	return op;
}
void printout(long prim, int counter, int op)
{
	if ((counter % 100) != 0)
		return;
	double prozent = (double)counter * 100 / prim;
	printf("%10ld Anzahl: %-10d Op: %-5d Prozent: %lf\n", prim, counter, op,
		   prozent);
}
int main(void)
{
	int counter = 1;
	long zahl = 2;
	int op = 0;
	int op2 = 0;
	printout(zahl, counter, op);

	for (zahl = 3; zahl < 1000000; zahl += 2, op = 0)
	{
		op = isprim(zahl);
		if (op >= 0)
		{
			printout(zahl, ++counter, op);
		}
	}
	return 0;
}
