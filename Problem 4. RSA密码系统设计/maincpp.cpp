#include "LINT.h"
#include "Miller Rabin.h"

#define TEST(x) 



int main(void) {
	//freopen("e:\\test.txt", "r", stdin);
	int len = 100;
	srand((USHORT)time(0));
	LINT m , c;
	m = 0x22;
loop:

	LINT p;p =  Produce(len);
	LINT q;q =  Produce(len);
	if(p == q)	
		goto loop;
	LINT N = p * q;
	if (N <= m)
		goto loop;
	LINT phiN = (p - one_l)*(q - one_l);

inl:
	LINT d = Produce(len * 2);
	LINT e, gcd;
	LINT::Inv(d, phiN, gcd, e);
	if (gcd != one_l || d == e)
		goto inl;

	LINT temp = m;
	//m.Display();
	c = LINT::MQPower(m, e, N);
	//c.Display();
	m = LINT::MQPower(c, d, N);
	//m.Display();

	if (m != temp) {
		printf("___________________________\n");
	}
	else {
		printf("-----------\n");
		e.Display();
		d.Display();
		N.Display();
		c.Display();
	}
		//printf("-----------\n");

goto loop;
	return 0;
}
