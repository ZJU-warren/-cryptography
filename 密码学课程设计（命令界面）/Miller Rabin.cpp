#include "Miller Rabin.h"

USHORT MyRand()
{
	USHORT a = (USHORT)rand();
	a = (USHORT)(a * (USHORT)rand());
	return a;
}
bool MiLLer_Rabin(LINT n, int times, int bitLen) {
	//或者自己生成[2,N-1]以内的随机数rand（）%（n-2）+2
	LINT m = n - one_l;
	LINT inv = m;
	int k = 0;
	while (m.val[1] & 1) {
	//	m >>= 1;
		LINT::ShR1(m);
		++k;
	}
	LINT a, temp;
	for (int i = 0; i <= times; ++i) {
		//if (n == a[i]) return true;
		while (1) {
			a = GetOne(bitLen);
			a = a % n;
			if (a < n && a > one_l)
				break;
		}
		a = LINT::MQPower(a, m, n);
		if (a == one_l)
			return true;
		Fin(j, 0, k) {
			if (a == inv)
				return true;
			else
			{
				temp = a;
				LINT::MSqr(temp, a, n);
			}
		}
	}
	return false;
}
/*
bool Witness(LINT n, LINT a, LINT d)
{
	if (n == two_l) return true;
	if (n == a) return false;
	if (!(n.val[1] & 1)) return false;
	while (!(d.val[1] & 1))
		d >>= 1;
	LINT t = LINT::MQPower(a, d, n),temp;
	while (d != n - one_l && t != n - one_l && t != one_l) {
		temp = t;
		LINT::MSqr(temp, t, n);					//下面介绍防止溢出的办法，对应数据量为10^18次方；
		d <<= 1;
	}
	return t == n - one_l || (d.val[1] & 1) == 1;//要么t能变成n-1，要么一开始t就等于1
}
bool MiLLer_Rabin(LINT n, int times, int bitLen){
	//或者自己生成[2,N-1]以内的随机数rand（）%（n-2）+2
	for (int i = 0; i <= times; ++i) {
		//if (n == a[i]) return true;
		LINT t;
		while (1) {
			t = GetOne(bitLen);
			t = t % n;
			if (t < n && t > one_l)
				break;
		}
		if (!Witness(n, t, n - one_l))
			return false;
	}
	return true;
}
*/
LINT GetOne(int bitLen) {
	LINT x;
	int unitLen = bitLen / 16;
	int rem = bitLen % 16;
	x.val[0] = unitLen + (rem != 0);
	while (1) {
		Fin(i, 1, unitLen)
			x.val[i] = (USHORT)rand();
		if (rem) {
			x.val[unitLen + 1] = rand() % (1 << rem);
		}
		x.val[1] |= 0x0001U;
		x.ClearZero();
		//x.Display();
		if (x != one_l) {
			break;
		}
	}
	return x;
}
LINT Produce(int bitLen) {
	LINT x = GetOne(bitLen), temp;

	while (1) {
		
		bool flag = true;
 		Fin(i, 1, cnt) {
			temp = prime[i];
			if (x == temp)
				return x;
			if (x < temp)
				break;
			if (x % temp == nul_l) {
				flag = false;
				break;
			}
		}
		if (!flag || !MiLLer_Rabin(x, 10, bitLen)) {
			x = x + two_l;	
			continue;
		}
		return x;
	}
	return nul_l;
}
void Sieve() {
	for (int i = 2; i <= MAXN; ++i) if (!num[i]) {
		prime[++cnt] = i;
		//printf("su: %d\n", prime[0]);
		for (long long j = (long long)i * i; j <= MAXN; j += i)
			num[j] = true;
	}
	printf("%d\n", cnt);
}

bool num[MAXN] = {};
USHORT prime[MAXN] = {};
USHORT cnt = 0;