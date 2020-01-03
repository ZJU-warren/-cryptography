#include "stdafx.h"

const UNIT32 A = 0x67452301;
const UNIT32 B = 0xEFCDAB89;
const UNIT32 C = 0x98BADCFE;
const UNIT32 D = 0x10325476;
char strTemp[35] = {};
char p[MAX_LEN],sp[MAX_LEN];
DataGroup M[50];
UNIT32 a, b, c, d;
UNIT32 Trans32() {
	//puts(strTemp);
	UNIT32 res[4] = {};
	Fin(i, 0, 3) {
		Fin(j, 0, 7)
			res[i] = (res[i] << 1) + strTemp[i * 8 + j] - '0';
	}
	return (res[0]) | (res[1] << 8) | (res[2] << 16) | (res[3] << 24);
}
UNIT32 Reverse(UNIT32 x) {
	UNIT32 res[4] = {};
	Fde(i, 3, 0) {
		res[i] = x & 0xff;
		x >>= 8;
	}
	return (res[0]) | (res[1] << 8) | (res[2] << 16) | (res[3] << 24);
}
void Divide(char *p, int &size, UNIT64 &bitLen) {
	Fin(i, 0, size - 2) {
		Fin(j, 0, 15) {
			strncpy(strTemp, p + i * 512 + j * 32, 32);
			M[i].m[j] = Trans32();
		}
	}
	Fin(j, 0, 13) {
		strncpy(strTemp, p + (size - 1) * 512 + j * 32, 32);
		strTemp[32] = 0;
		M[size - 1].m[j] = Trans32();
	}
	M[size - 1].m[14] = bitLen & 0x00000000ffffffffL;
	M[size - 1].m[15] = (bitLen & 0xffffffff00000000L) >> 32;
}
void Extend(char *p, int &size, UNIT64 &bitLen) {
	for (bitLen = 0; p[bitLen]; ++bitLen);
	p[bitLen] = '1';
	size = (int)(bitLen + 1) / 512;
	UNIT32 rem = (bitLen + 1) % 512;
	UNIT32 add;
	if (rem > 448) {
		size += 2;
		add = 512 - rem + 448;
	}
	else {
		++size;
		add = 448 - rem;
	}
	Fin(i, 1, add)
		p[bitLen + i] = '0';
	p[bitLen + add + 1] = 0;
}
void DataGroup::MD5() {
	UNIT32 aa = a;
	UNIT32 bb = b;
	UNIT32 cc = c;
	UNIT32 dd = d;
	//��һ��
	FF(a, b, c, d, m[0], 7, 0xd76aa478)
		FF(d, a, b, c, m[1], 12, 0xe8c7b756)
		FF(c, d, a, b, m[2], 17, 0x242070db)
		FF(b, c, d, a, m[3], 22, 0xc1bdceee)

		FF(a, b, c, d, m[4], 7, 0xf57c0faf)
		FF(d, a, b, c, m[5], 12, 0x4787c62a)
		FF(c, d, a, b, m[6], 17, 0xa8304613)
		FF(b, c, d, a, m[7], 22, 0xfd469501)

		FF(a, b, c, d, m[8], 7, 0x698098d8)
		FF(d, a, b, c, m[9], 12, 0x8b44f7af)
		FF(c, d, a, b, m[10], 17, 0xffff5bb1)
		FF(b, c, d, a, m[11], 22, 0x895cd7be)

		FF(a, b, c, d, m[12], 7, 0x6b901122)
		FF(d, a, b, c, m[13], 12, 0xfd987193)
		FF(c, d, a, b, m[14], 17, 0xa679438e)
		FF(b, c, d, a, m[15], 22, 0x49b40821)

		//�ڶ���
		GG(a, b, c, d, m[1], 5, 0xf61e2562)
		GG(d, a, b, c, m[6], 9, 0xc040b340)
		GG(c, d, a, b, m[11], 14, 0x265e5a51)
		GG(b, c, d, a, m[0], 20, 0xe9b6c7aa)

		GG(a, b, c, d, m[5], 5, 0xd62f105d)
		GG(d, a, b, c, m[10], 9, 0x02441453)
		GG(c, d, a, b, m[15], 14, 0xd8a1e681)
		GG(b, c, d, a, m[4], 20, 0xe7d3fbc8)

		GG(a, b, c, d, m[9], 5, 0x21e1cde6)
		GG(d, a, b, c, m[14], 9, 0xc33707d6)
		GG(c, d, a, b, m[3], 14, 0xf4d50d87)
		GG(b, c, d, a, m[8], 20, 0x455a14ed)

		GG(a, b, c, d, m[13], 5, 0xa9e3e905)
		GG(d, a, b, c, m[2], 9, 0xfcefa3f8)
		GG(c, d, a, b, m[7], 14, 0x676f02d9)
		GG(b, c, d, a, m[12], 20, 0x8d2a4c8a)

		//������
		HH(a, b, c, d, m[5], 4, 0xfffa3942)
		HH(d, a, b, c, m[8], 11, 0x8771f681)
		HH(c, d, a, b, m[11], 16, 0x6d9d6122)
		HH(b, c, d, a, m[14], 23, 0xfde5380c)

		HH(a, b, c, d, m[1], 4, 0xa4beea44)
		HH(d, a, b, c, m[4], 11, 0x4bdecfa9)
		HH(c, d, a, b, m[7], 16, 0xf6bb4b60)
		HH(b, c, d, a, m[10], 23, 0xbebfbc70)

		HH(a, b, c, d, m[13], 4, 0x289b7ec6)
		HH(d, a, b, c, m[0], 11, 0xeaa127fa)
		HH(c, d, a, b, m[3], 16, 0xd4ef3085)
		HH(b, c, d, a, m[6], 23, 0x04881d05)

		HH(a, b, c, d, m[9], 4, 0xd9d4d039)
		HH(d, a, b, c, m[12], 11, 0xe6db99e5)
		HH(c, d, a, b, m[15], 16, 0x1fa27cf8)
		HH(b, c, d, a, m[2], 23, 0xc4ac5665)

		//������
		II(a, b, c, d, m[0], 6, 0xf4292244)
		II(d, a, b, c, m[7], 10, 0x432aff97)
		II(c, d, a, b, m[14], 15, 0xab9423a7)
		II(b, c, d, a, m[5], 21, 0xfc93a039)

		II(a, b, c, d, m[12], 6, 0x655b59c3)
		II(d, a, b, c, m[3], 10, 0x8f0ccc92)
		II(c, d, a, b, m[10], 15, 0xffeff47d)
		II(b, c, d, a, m[1], 21, 0x85845dd1)

		II(a, b, c, d, m[8], 6, 0x6fa87e4f)
		II(d, a, b, c, m[15], 10, 0xfe2ce6e0)
		II(c, d, a, b, m[6], 15, 0xa3014314)
		II(b, c, d, a, m[13], 21, 0x4e0811a1)

		II(a, b, c, d, m[4], 6, 0xf7537e82)
		II(d, a, b, c, m[11], 10, 0xbd3af235)
		II(c, d, a, b, m[2], 15, 0x2ad7d2bb)
		II(b, c, d, a, m[9], 21, 0xeb86d391)

		a = a + aa;
	b = b + bb;
	c = c + cc;
	d = d + dd;
}
void Exchange() {
	int len = strlen(sp);
	int cnt = 0;
	Fin(i, 0, len - 1) {
		Fde(j, 3, 0) {
			p[cnt + 4 + j] = (sp[i] & 1) + '0';
			sp[i] >>= 1;
		}
		Fde(j, 3, 0) {
			p[cnt + j] = (sp[i] & 1) + '0';
			sp[i] >>= 1;
		}
		cnt += 8;
	}
	p[cnt] = 0;
}