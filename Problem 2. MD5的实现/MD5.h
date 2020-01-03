#pragma once
#include <cstdio>
#include <cstring>
typedef unsigned int UNIT32;
typedef unsigned long long UNIT64;
#define MAX_LEN 500000
#define Fin(i,f,t) for(int i =  (int)f; i <=  (int)t; ++i)
#define Fde(i,f,t) for(int i =  (int)f; i >=  (int)t; --i)

#define F(X, Y, Z)  ((X & Y) | ((~X) & Z))
#define G(X, Y, Z)  ((X & Z) | (Y & (~Z)))
#define H(X, Y, Z)  (X ^ Y ^ Z)
#define I(X, Y, Z)  (Y ^ (X | (~Z)))


#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n)))) 
#define FF(a, b, c, d, x, s, ac) { (a) += F ((b), (c), (d)) + (x) + (UNIT32)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define GG(a, b, c, d, x, s, ac) { (a) += G ((b), (c), (d)) + (x) + (UNIT32)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define HH(a, b, c, d, x, s, ac) { (a) += H ((b), (c), (d)) + (x) + (UNIT32)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 
#define II(a, b, c, d, x, s, ac) { (a) += I ((b), (c), (d)) + (x) + (UNIT32)(ac); (a) = ROTATE_LEFT ((a), (s)); (a) += (b); } 

extern const UNIT32 A;
extern const UNIT32 B;
extern const UNIT32 C;
extern const UNIT32 D;


struct DataGroup {
	UNIT32 m[16];
	void MD5();
};

extern DataGroup M[];
extern char strTemp[];
extern char p[], sp[];
extern UNIT32 a, b, c, d;

UNIT32 Trans32();
UNIT32 Reverse(UNIT32 x);
void Divide(char *p, int &size, UNIT64 &bitLen);
void Extend(char *p, int &size, UNIT64 &bitLen);
void Exchange();
