#include <stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
typedef struct
{
	int numerator;
	int denominator;
}FRACTION;

void getFr (FRACTION* pFr);
void multFr (FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes2);
void printFr (FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes);

int main(void)
{
	FRACTION fr1;
	FRACTION fr2;
	FRACTION res;

	getFr (&fr1);
	getFr (&fr2);
	multFr (&fr1, &fr2, &res);
	printFr (&fr1, &fr2, &res);
	return 0;
}

void getFr(FRACTION* pFr)
{
	scanf("%d/%d", &pFr->numerator,&(*pFr).denominator);
	return ;
}

void multFr (FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes)
{
	pRes->numerator = pFr1 -> numerator * pFr2->numerator;
	pRes->denominator = pFr1->denominator * pFr2->denominator;
	return;
}

void printFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes)
{
    if ( pRes->denominator % pRes->numerator == 0 ) {
        pRes->denominator = pRes->denominator/pRes->numerator;
        pRes->numerator = 1;
    }
	printf("%d/%d\n",
		pRes->numerator, pRes->denominator);
	return;
}
