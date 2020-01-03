#pragma once
#include <string>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "myOrder.h"
#include <iostream>
using namespace std;
typedef long long LL;


/* MIN, MAX etc. */
#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

/******************************************************************************/
/* Macros                                                                     */
/******************************************************************************/
/* Simple makros */
/* Errorcodes    */

#define E_LINT_OK     0        /* Everything O.K.                            */
#define E_LINT_DBZ   -1        /* Division by zero                           */
#define E_LINT_OFL   -2        /* Overflow                                   */
#define E_LINT_UFL   -3        /* Underflow                                  */

#define E_LINT_MAL   -4        /* Error in memory allocation                 */
#define E_LINT_NOR   -5        /* Register not present                       */
#define E_LINT_BOR   -6        /* Base in str2lint_l() not valid            */
#define E_LINT_MOD   -7        /* Modulus even in ?mexp?m_l()                */
#define E_LINT_NPT   -8        /* Null-Pointer received                      */

#define E_VCHECK_OK    0        /* LINT-format O.K.                          */
#define E_VCHECK_LDZ   1        /* vcheck_l-Warning: Leading zeros            */
#define E_VCHECK_MEM  -1        /* vcheck_l-Error: Null-Pointer               */
#define E_VCHECK_OFL  -2        /* vcheck_l-Error: Overflow                   */

/**************************************************************/
/* Constants referring to the internal LINT-representation   */
/**************************************************************/
#define BASE            0x10000UL
#define BITPERDGT       16UL
#define BASEMINONE      0xffffU
#define BASEMINONEL     0xffffUL
#define DBASEMINONE     0xffffffffUL
#define BASEDIV2        0x8000U

/*******************************************************/
/* Number of digits of LINT-ojects to base 0x10000    */
#define LINTMAXDIGIT   512U
/*******************************************************/

#define LINTMAXSHORT   (LINTMAXDIGIT + 1)		//-- 256 + 1	//-- LINT 最大长度，其中每单位长度有16bit
#define LINTMAXBIT     (LINTMAXDIGIT << 4)		//-- 4096		//-- 可处理最大位数
#define LINTMAXBYTE    (LINTMAXSHORT << 1)
#define LDBITPERDGT     4U
/***********************************************************/
/* Typedefs                                                */
/***********************************************************/
#ifndef UCHAR
typedef unsigned char  UCHAR;	//-- 8bit
#endif  /* UCHAR */
#ifndef USHORT
typedef unsigned short USHORT;	//-- 16bit
#endif  /* USHORT */
#ifndef ULONG
typedef unsigned long  ULONG;
#endif  /* ULONG */

typedef USHORT lint;				//-- 16bit

/* Read the number of digits of a LINT-variable */
//-- nl为数组名（同时为数组首元素地址） *nl == nl[0] ,再将改值强制转换为 USHORT 类型值
#define DIGITS_L(n_l) ((unsigned short)*(n_l))

/* Pointer to the most significant digit of a LINT variable */
#define MSDPTR_L(n_l) ((n_l) + DIGITS_L (n_l))

/* Pointer to the least significant digit of a LINT variable */
#define LSDPTR_L(n_l) ((n_l) + 1)

/* Set the number of digits of a LINT-variable */
#define SETDIGITS_L(n_l, l) (*(n_l) = (unsigned short)(l))

/* Increment the number of digits of a LINT-variable */
#define INCDIGITS_L(n_l) (++*(n_l))

/* Decrement the number of digits of a LINT-variable */
#define DECDIGITS_L(n_l)\
    if(DIGITS_L (n_l) > 0)\
    (--*(n_l))

/* ReMoveLeaDingZeRoS from LINT-variables */
#define RMLDZRS_L(n_l) \
    while ((DIGITS_L (n_l) > 0) && (*MSDPTR_L (n_l) == 0)) {DECDIGITS_L (n_l);}

/* Reduction modulo Nmax + 1 */
#define ANDMAX_L(a_l)\
    SETDIGITS_L ((a_l), MIN (DIGITS_L (a_l), (USHORT)LINTMAXDIGIT));\
    RMLDZRS_L ((a_l))

/* Comparisons, setting, testing for evenness and oddness */
#define LT_L(a_l,b_l) \
    (Cmp((a_l), (b_l)) == -1)			/* a_l < b_l  */

#define EQZ_L(a_l) \
    (Equ ((a_l), nul_l) == 1)			/* a_l == 0   */

#define EQONE_L(a_l) \
    (Equ ((a_l), one_l) == 1)         /* a_l == 1   */

#define EQTWO_L(a_l) \
    (Equ ((a_l), two_l) == 1)         /* a_l == 1         */

#define GE_L(a_l,b_l) \
    (Cmp((a_l), (b_l)) > -1)			/* a_l >= b_l */

#define GTZ_L(a_l) \
    (Cmp((a_l), nul_l) == 1)			/* a_l > 0    */

/* Set LINT-variables to values 0, 1, 2 resp. */
#define SETZERO_L(n_l)\
	(*(n_l) = 0)

#define SETONE_L(n_l)\
    (U2LINT ((n_l), 1U))

/* true: a_l is even   */
#define ISEVEN_L(a_l)\
    (DIGITS_L (a_l) == 0 || (DIGITS_L (a_l) > 0 && (*LSDPTR_L (a_l) & 1U) == 0))

struct LINT {
public:
	lint *val;
	int size;

	LINT(int SIZE = 1);
	LINT(lint*, int SIZE = 2);

	LINT(const LINT& a);				//拷贝构造函数
	~LINT();
	//static void Copy(lint*, const LINT&);
	LINT& operator =(const LINT& a);
	LINT& operator =(const USHORT&);
	static void U2LINT(lint*, USHORT);

	void KeyIn();
	void Display();
	void LINT::KeyIn(const char *p, int len) {
		memset(val, 0, sizeof val);
		int rem = len % 4, unit = len / 4;
		val[0] = unit + (rem != 0);
		if (!val[0])
			return;

		char temp[6];
		if (rem) {
			Fin(i, 0, rem - 1)
				temp[i] = p[i];
			temp[rem + 1] = 0;
			sscanf(temp, "%hx", &val[val[0]]);
		}

		Fin(i, 0, unit - 1) {
			Fin(j, 0, 3)
				temp[j] = p[rem + i * 4 + j];
			temp[4] = 0;
			sscanf(temp, "%hx", &val[unit - i]);
		}
	}
	static int Cmp(const LINT&, const LINT&);		//Returns:   -1 : a_l < b_l,   0: a_l == b_l,   1: a_l > b_l
	static bool Equ(const LINT&, const LINT&);	// Returns: 1 : a_l == b_l,	   0 : otherwise 
	bool operator ==(const LINT& a)const;
	bool operator !=(const LINT& a)const;
	bool operator <(const LINT& a)const;
	bool operator >(const LINT& a)const;
	bool operator <=(const LINT& a)const;
	bool operator >=(const LINT& a)const;
	void IncOne();
	void DecOne();
	void ClearZero();
	LINT& operator ++();
	LINT  operator ++(int);
	LINT& operator --();
	LINT  operator --(int);
	void SetMax();
	
	LINT operator +(const LINT& a)const;
	LINT operator -(const LINT& a)const;
	LINT operator *(const LINT& a)const;
	LINT operator /(const LINT& a)const;
	LINT operator %(const LINT& a)const;
	LINT operator >>(const long int)const;
	LINT operator << (const long int)const;
	static unsigned int LD(const LINT&);
	static int Shift(LINT&, const long int);
	static int ShR1(LINT& a_l);
	static int LINT::ShL1(LINT& a_l);
	LINT& operator >>= (const long int);
	LINT& operator <<= (const long int);

	static int  Add(const LINT&, const LINT&, LINT&);
	static int  Sub(const LINT&, const LINT&, LINT&);
	static int  Mul(const LINT&, const LINT&, LINT&);
	static int	Div(const LINT&, const LINT&, LINT&, LINT&);
	static int  Mod(const LINT&, const LINT&, LINT&);
	static int  Sqr(const LINT&, LINT&);
	static int  SSub(const LINT&, const int, const LINT&, const int, LINT&);
	static void  AddK(const LINT&, const LINT&, LINT&);
	static void  SubK(const LINT&, const LINT&, LINT&);
	static void  MulK(const LINT&, const LINT&, LINT&);
	static void  SqrK(const LINT&, LINT&);
	static int  MAdd(const LINT&, const  LINT&, LINT&, const LINT&);
	static int  MSub(const LINT&, const LINT&, LINT&, const LINT&);
	static int  MMul(const LINT&, const LINT&, LINT&, const LINT&);
	static int  MSqr(const LINT&, LINT&, const LINT&);
	static int  MEqu(const  LINT&, const  LINT&, const  LINT&);

	static void GCD(const LINT&, const LINT&, LINT&);
	static void XGCD(const LINT&, const LINT&, LINT&, LINT&, int *, LINT&, int *);
	//static void LINT::XGCD(const LINT& a, const LINT& b, LINT& d, LINT& x, LINT& y);
	static void Inv(const LINT&, const LINT&, LINT&, LINT&);
	static LINT MQPower(const LINT& a, const LINT& n, const LINT& m);
};
extern lint  nul_l[];
extern lint  one_l[];
extern lint  two_l[];
