#include "LINT.h"
#include "Miller Rabin.h"

#define TEST(x) 



char strp[] = "94ee1a7eb3e4dcf5db880668fd7a5271833a30801ec5f00e86a0df4ed0c87fbed13a7c9c9bf21cfdabb2555f6aef1ab01053ae0196f0a94602b9b484ddb09633f326cbc6c56d6e1d101abe054ff454ec5d3b677292efa0abac30d7d8607dce1dfa8a85cd6511d9a9b889273b1b8b39c34e4469b21472d31932c0e17d89";
char strq[] = "9e457362ff32d61174557ece46cba4acdf6342df";
char stra[] = "2ac5c7414fe0a81437044d5054447b9a46376bd110ee5a9db837758a08fb6902db1be84e9b228fe050209631a0c5a24ace5a28b21bcb10ab825627486c542f757231d7b30a01a09731d8cbe5428c28a4b3f61605e18e483ade693954060b7e36c5c411b0b8bff2e909098d26af786bd89d13b1a1f3666c151101315070";

LINT p, q, a, x, y, r, gcd;

int main(void) {
	int len = 200;
	/*	p、q、a选定  t生成	*/
	srand(USHORT(time(0)));
	p.KeyIn(strp, strlen(strp));
	q.KeyIn(strq, strlen(strq));
	a.KeyIn(stra, strlen(stra));
	printf("p = ");
	p.Display();
	printf("q = ");
	q.Display();
	printf("a = ");
	a.Display();

	LINT p = Produce(len);

	LINT q;
	do {
		q = Produce(len);
	} while (q == p);

	LINT N = p * q;
	printf("N = ");
	N.Display();

	LINT d, gcd, e, phiN = (p - one_l) * (q - one_l), temp;

	do {
		d = Produce(len * 2);
		LINT::Inv(d, phiN, gcd, e);
	} while (gcd != one_l || d == e);
	printf("d = ");
	d.Display();
	printf("e = ");
	e.Display();
	//
	LINT::Inv(LINT::MQPower(a, x, p), p, gcd, y);
	int t = 200;
	LINT u;
	do {
		--t;
		u = LINT(one_l) << t;
	} while (u >= q);
	t = rand() % (t - 1) + 1;
	printf("t = %d\n", t);
	///*	r、x、y	生成		*/
	//r = (Produce(q.val[0] * 8) % (q - one_l) + one_l);
	//x = LINT::MQPower(a, r, p);	
	//LINT::Inv(LINT::MQPower(a, x, p), p, gcd, y);

	////x.Display();
	////y.Display();
	//

	///*	e	生成		*/
	//LINT e(one_l),et;
	//et = GetOne(t);
	//if (e < et)
	//	e = et;

	///*	s	生成		*/
	//LINT s = (r + x*e) % q;

	///*	验证		*/
	//LINT t1 = LINT::MQPower(a, s, p);
	//LINT t2 = LINT::MQPower(y, e, p);
	//LINT res = (t1 * t2) % p - x;
	////res.Display();
	return 0;
}
