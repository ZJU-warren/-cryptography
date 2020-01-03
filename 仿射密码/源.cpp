#include <cstdio>
#include <cstring>
#include <cstdlib>

#define Fin(i,f,t) for(int i = f; i <= t; ++i)
#define MAXN 5000

char
	strZ[MAXN] = "计算机学院网络工程信息安全，我们热爱中华人民共和国。大家",
	strC[MAXN] = "和院程安我爱计";
int M[MAXN],C[MAXN];

int a, m, b, MOD = 28;
void Extgcd(int a, int b, int& d, int& x, int& y) {
	if (!b) { 
		d = a;
		x = 1;
		y = 0; 
	}
	else { 
		Extgcd(b, a%b, d, y, x); 
		y -= x*(a / b); 
	}
}
int Inv(int a, int n) {
	int d, x, y;
	Extgcd(a, n, d, x, y);
	return d == 1 ? (x + n) % n : -1;
}
void DeCode(int len) {
	// dk(c)=a^-1(c-b)mod MOD
	int aInv = Inv(a, MOD);
	Fin(i, 0, len-1)
		M[i] = ((aInv * (C[i] - b)) % MOD + MOD) % MOD;
}
int main(void) {
	//freopen("e:\\tsst.txt", "w", stdout);
	for (int i = 0; strC[i]; i += 2)
		for (int j = 0; strZ[j]; j += 2)
		if (strC[i] == strZ[j] && strC[i + 1] == strZ[j + 1])
			C[i / 2] = j / 2;
	int len = strlen(strC) / 2;
	
	Fin(i, 1, 27) {
		Fin(j, 0, 27) if (Inv(i, MOD) !=- 1) {
			a = i;
			b = j;
			DeCode(len);
			printf("[a = %2d, b = %2d] : ", a, b);
			Fin(i, 0, len - 1)
				printf("%c%c", strZ[M[i] * 2], strZ[M[i] * 2 + 1]);
			putchar('\n');
		}
	}
}
