#pragma once
#include "LINT.h"
#define MAXN 60000
USHORT MyRand();
bool MiLLer_Rabin(LINT n, int times,int bitLen);
//bool Witness(LINT n, LINT a, LINT d);
LINT Produce(int bitLen);
void Sieve();

LINT GetOne(int bitLen);
extern bool num[];
extern USHORT prime[];
extern USHORT cnt;

