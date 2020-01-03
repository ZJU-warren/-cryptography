#include "stdafx.h"
#include "LINT.h"
using namespace std;

/* LINT-Constant Values */
lint nul_l[] = { 0, 0, 0, 0, 0 };
lint one_l[] = { 1, 1, 0, 0, 0 };
lint two_l[] = { 1, 2, 0, 0, 0 };

LINT::LINT(int SIZE) {
	size = SIZE * LINTMAXSHORT;
	val = new lint[size]{};
	//TEST(printf("LINT 1  %X\n",this);)
}
LINT::LINT(lint* arr, int SIZE) {
	//TEST(printf("LINT 2  %X\n", this);)
	if (arr == NULL) {
		printf("this is a empty lint*");
	}
	else {
		size = SIZE * LINTMAXSHORT;
		val = new lint[size]{};
		Fin(i, 0, MIN(size - 1, arr[0]))
			val[i] = arr[i];
	}
	ClearZero();
}
LINT::LINT(const LINT& a)                    //拷贝构造函数
{
	//TEST(printf("LINT 3  %X\n", this);)
	size = a.size;
	val = new lint[size]; //深拷贝
	Fin(i, 0, MIN(size - 1, a.val[0]))
		val[i] = a.val[i];
	ClearZero();
}
LINT::~LINT() {
	//TEST(printf("~LINT  %X\n", this);)
	if (val != NULL)
		delete val;
}
LINT& LINT::operator =(const LINT& a){
	//TEST(printf("LINT 4  %X\n", this);)
	if (this == &a)	
		return *this;
	delete[] val;
	val = new lint[MAX(size,a.size)];
	Fin(i, 0, MIN(size - 1, a.val[0]))
		val[i] = a.val[i];
	return *this;
}
LINT& LINT::operator =(const USHORT& a) {
	val[0] = 1;
	val[1] = a;
	return *this;
}
void LINT::KeyIn(const char *p,int len) {
	memset(val, 0, sizeof val);
	int rem = len % 4, unit = len / 4;
	val[0] = unit + (rem != 0);
	if (!val[0])
		return;

	char temp[6];
	if (rem) {
		Fin(i, 0, rem-1)
			temp[i] = p[i];
		temp[rem+1] = 0;
		sscanf(temp, "%hx", &val[val[0]]);
	}
	
	Fin(i, 0, unit-1) {
		Fin(j, 0, 3)
			temp[j] = p[rem + i*4 + j];
		temp[4] = 0;
		sscanf(temp,"%hx", &val[unit-i]);
	}
}
void LINT::Display(char *p) {
	int len = 0;
	if (!val[0]) {
		p[len] = '0';
	}
	else {
		Fde(i, val[0], 1) {
			sprintf(p + len,"%04hx", val[i]);
			len += 4;
		}
	}
	p[len + 1] = 0;
}
void LINT::Decode(char *p) {
	int len = 0;
	if (!val[0]) {
		p[len] = '-';
	}
	else {
		Fde(i, val[0], 1) {
			sprintf(p + len, "%c", val[i]);
			len += 1;
		}
	}
	p[len + 1] = 0;
}

void LINT::ClearZero() {
	Fde(i, val[0], 1) {
		if (!val[i])
			--val[0];
		else
			break;
	}
}
void LINT::IncOne() {
	ClearZero();
	lint *msdptra_l, *aptr_l = LSDPTR_L(val);
	ULONG carry = BASE;
	msdptra_l = MSDPTR_L(val);
	while ((aptr_l <= msdptra_l) && (carry & BASE)) {
		*aptr_l = (USHORT)(carry = 1UL + (ULONG)(*aptr_l));
		aptr_l++;
	}
	if ((aptr_l > msdptra_l) && (carry & BASE))
	{
		*aptr_l = 1;
		INCDIGITS_L(val);
		if (DIGITS_L(val) > (USHORT)LINTMAXDIGIT)    /* Overflow ? */
			SETZERO_L(val);              /* Reduction modulo Nmax+1 */
	}
}
void LINT::DecOne()
{
	ClearZero();
	lint *msdptra_l, *aptr_l = LSDPTR_L(val);
	ULONG carry = DBASEMINONE;

	if (DIGITS_L(val) == 0)                     /* Underflow ? */
		this->SetMax();            /* Reduction modulo Nmax+1 */

	msdptra_l = MSDPTR_L(val);
	while ((aptr_l <= msdptra_l) && (carry & (BASEMINONEL << BITPERDGT)))
	{
		*aptr_l = (USHORT)(carry = (ULONG)*aptr_l - 1L);
		aptr_l++;
	}
	RMLDZRS_L(val);
	ClearZero();
}
LINT& LINT:: operator ++() {
	this->IncOne();
	return *this;
}
LINT  LINT:: operator ++(int) {
	LINT tmp(*this);
	this->IncOne();
	return tmp;
}
LINT& LINT:: operator --() {
	this->DecOne();
	return *this;
}
LINT  LINT:: operator --(int) {
	LINT tmp(*this);
	this->DecOne();
	return tmp;
}
void LINT::SetMax()
{
	lint *aptr_l = val;
	lint *msdptra_l = val + LINTMAXDIGIT;

	while (++aptr_l <= msdptra_l) {
		*aptr_l = BASEMINONE;
	}
	SETDIGITS_L(val, LINTMAXDIGIT);
}

void LINT::U2LINT(lint *num_l, USHORT u)
{
	*LSDPTR_L(num_l) = u;
	SETDIGITS_L(num_l, 1);
	RMLDZRS_L(num_l);
}
/*
void LINT::Copy(lint* dest_l, const LINT& src) {
LINT src_l = src;
lint *lastsrc_l = MSDPTR_L(src_l.val);
*dest_l = *src_l.val;
while ((*lastsrc_l == 0) && (*dest_l > 0)) {
--lastsrc_l;
--*dest_l;
}
while (src_l.val < lastsrc_l) {
*++dest_l = *++src_l.val;
}
}*/
int  LINT::Cmp(const LINT& a_l, const LINT& b_l)
{
	lint *msdptra_l, *msdptrb_l;
	int la = (int)DIGITS_L(a_l.val);
	int lb = (int)DIGITS_L(b_l.val);

	if (la == 0 && lb == 0)
		return 0;
	while (a_l.val[la] == 0 && la > 0)
		--la;
	while (b_l.val[lb] == 0 && lb > 0)
		--lb;
	if (la == 0 && lb == 0)
		return 0;
	if (la > lb)
		return 1;
	if (la < lb)
		return -1;

	msdptra_l = a_l.val + la;
	msdptrb_l = b_l.val + lb;
	while ((*msdptra_l == *msdptrb_l) && (msdptra_l > a_l.val)) {
		msdptra_l--;
		msdptrb_l--;
	}

	if (msdptra_l == a_l.val)
		return 0;
	if (*msdptra_l > *msdptrb_l)
		return 1;
	else
		return -1;
}
bool LINT::Equ(const LINT& a_l, const LINT& b_l)
{
	lint *msdptra_l, *msdptrb_l;
	int la = (int)DIGITS_L(a_l.val);
	int lb = (int)DIGITS_L(b_l.val);

	if (la == 0 && lb == 0)
		return 1;
	while (a_l.val[la] == 0 && la > 0)
		--la;

	while (b_l.val[lb] == 0 && lb > 0)
		--lb;

	if (la == 0 && lb == 0)
		return 1;

	if (la != lb)
		return 0;

	msdptra_l = a_l.val + la;
	msdptrb_l = b_l.val + lb;

	while ((*msdptra_l == *msdptrb_l) && (msdptra_l > a_l.val))
	{
		msdptra_l--;
		msdptrb_l--;
	}

	return (msdptra_l > a_l.val ? 0 : 1);
}
bool LINT::operator ==(const LINT& a) const {
	return Equ(*this, a);
}
bool LINT::operator !=(const LINT& a) const {
	return !Equ(*this, a);
}

int  LINT::SSub(const LINT& a_l, const int sign_a, const LINT& b_l, const int sign_b, LINT& c_l)
{
	int sign_c;

	if (!(sign_a == 1 || sign_a == -1)) exit(0);
	if (!(sign_b == 1 || sign_b == -1)) exit(0);

	if (1 == sign_a)
	{
		if (1 == sign_b)            /* a - b */
		{
			if (LT_L(a_l, b_l))
			{
				SubK(b_l, a_l, c_l);
				sign_c = -1;
			}
			else
			{
				SubK(a_l, b_l, c_l);
				sign_c = 1;
			}
		}
		else                        /* -1 == sign_b, a + b */
		{
			AddK(a_l, b_l, c_l);
			sign_c = 1;
		}
	}
	else                            /* -1 == sign_a */
	{
		if (1 == sign_b)            /* -(a + b) */
		{
			AddK(a_l, b_l, c_l);
			sign_c = -1;
		}
		else                        /* -1 == sign_b, b - a) */
		{
			if (LT_L(b_l, a_l))
			{
				SubK(a_l, b_l, c_l);
				sign_c = -1;
			}
			else
			{
				SubK(b_l, a_l, c_l);
				sign_c = 1;
			}
		}
	}

	return sign_c;
}
void LINT::AddK(const LINT& a_l, const LINT& b_l, LINT& s_l) {
	lint *msdptra_l, *msdptrb_l;
	lint *aptr_l, *bptr_l, *sptr_l = LSDPTR_L(s_l.val);
	ULONG carry = 0L;

	if (DIGITS_L(a_l.val) < DIGITS_L(b_l.val))
	{
		aptr_l = LSDPTR_L(b_l.val);
		bptr_l = LSDPTR_L(a_l.val);
		msdptra_l = MSDPTR_L(b_l.val);
		msdptrb_l = MSDPTR_L(a_l.val);
		SETDIGITS_L(s_l.val, DIGITS_L(b_l.val));
	}
	else
	{
		aptr_l = LSDPTR_L(a_l.val);
		bptr_l = LSDPTR_L(b_l.val);
		msdptra_l = MSDPTR_L(a_l.val);
		msdptrb_l = MSDPTR_L(b_l.val);
		SETDIGITS_L(s_l.val, DIGITS_L(a_l.val));
	}

	while (bptr_l <= msdptrb_l)
	{
		*sptr_l++ = (USHORT)(carry = (ULONG)*aptr_l++ + (ULONG)*bptr_l++
			+ (ULONG)(USHORT)(carry >> BITPERDGT));
	}
	while (aptr_l <= msdptra_l)
	{
		*sptr_l++ = (USHORT)(carry = (ULONG)*aptr_l++
			+ (ULONG)(USHORT)(carry >> BITPERDGT));
	}
	if (carry & BASE)
	{
		*sptr_l = 1;
		INCDIGITS_L(s_l.val);
	}
}
void LINT::SubK(const LINT& a_l, const LINT& b_l, LINT& d_l) {
	lint *msdptra_l, *msdptrb_l;
	lint *aptr_l = LSDPTR_L(a_l.val), *bptr_l = LSDPTR_L(b_l.val), *dptr_l = LSDPTR_L(d_l.val);
	ULONG carry = 0L;

	msdptra_l = MSDPTR_L(a_l.val);
	msdptrb_l = MSDPTR_L(b_l.val);

	SETDIGITS_L(d_l.val, DIGITS_L(a_l.val));

	while (bptr_l <= msdptrb_l)
	{
		*dptr_l++ = (USHORT)(carry = (ULONG)*aptr_l++ - (ULONG)*bptr_l++
			- ((carry & BASE) >> BITPERDGT));
	}

	while (aptr_l <= msdptra_l)
	{
		*dptr_l++ = (USHORT)(carry = (ULONG)*aptr_l++
			- ((carry & BASE) >> BITPERDGT));
	}

	RMLDZRS_L(d_l.val);
}
void LINT::MulK(const LINT& aa_l, const LINT& bb_l, LINT& p_l) /* Allow for double length result    */
{
	register lint *cptr_l, *bptr_l;
	lint *a_l, *b_l, *aptr_l, *csptr_l, *msdptra_l, *msdptrb_l;
	USHORT av;
	ULONG carry;

	if (EQZ_L(aa_l.val) || EQZ_L(bb_l.val))
	{
		SETZERO_L(p_l.val);
		return;
	}

	if (DIGITS_L(aa_l.val) < DIGITS_L(bb_l.val))
	{
		a_l = bb_l.val;
		b_l = aa_l.val;
	}
	else
	{
		a_l = aa_l.val;
		b_l = bb_l.val;
	}

	msdptra_l = MSDPTR_L(a_l);
	msdptrb_l = MSDPTR_L(b_l);

	carry = 0;
	av = *LSDPTR_L(a_l);
	for (bptr_l = LSDPTR_L(b_l), cptr_l = LSDPTR_L(p_l.val); bptr_l <= msdptrb_l; bptr_l++, cptr_l++)
	{
		*cptr_l = (USHORT)(carry = (ULONG)av * (ULONG)*bptr_l +
			(ULONG)(USHORT)(carry >> BITPERDGT));
	}
	*cptr_l = (USHORT)(carry >> BITPERDGT);

	for (csptr_l = LSDPTR_L(p_l.val) + 1, aptr_l = LSDPTR_L(a_l) + 1; aptr_l <= msdptra_l; csptr_l++, aptr_l++)
	{
		carry = 0;
		av = *aptr_l;
		for (bptr_l = LSDPTR_L(b_l), cptr_l = csptr_l; bptr_l <= msdptrb_l; bptr_l++, cptr_l++)
		{
			*cptr_l = (USHORT)(carry = (ULONG)av * (ULONG)*bptr_l +
				(ULONG)*cptr_l + (ULONG)(USHORT)(carry >> BITPERDGT));
		}
		*cptr_l = (USHORT)(carry >> BITPERDGT);
	}

	SETDIGITS_L(p_l.val, DIGITS_L(a_l) + DIGITS_L(b_l));
	RMLDZRS_L(p_l.val);
}
void LINT::SqrK(const LINT& a_l, LINT& p_l)              /* Allow for double length result     */
{
	register lint *cptr_l, *bptr_l;
	lint *aptr_l, *csptr_l, *msdptra_l, *msdptrb_l, *msdptrc_l;
	USHORT av;
	ULONG carry;

	if (EQZ_L(a_l))
	{
		SETZERO_L(p_l.val);
		return;
	}

	msdptrb_l = MSDPTR_L(a_l.val);
	msdptra_l = msdptrb_l - 1;
	*LSDPTR_L(p_l.val) = 0;
	carry = 0;
	av = *LSDPTR_L(a_l.val);
	for (bptr_l = LSDPTR_L(a_l.val) + 1, cptr_l = LSDPTR_L(p_l.val) + 1; bptr_l <= msdptrb_l; bptr_l++, cptr_l++)
	{
		*cptr_l = (USHORT)(carry = (ULONG)av * (ULONG)*bptr_l +
			(ULONG)(USHORT)(carry >> BITPERDGT));
	}
	*cptr_l = (USHORT)(carry >> BITPERDGT);

	for (aptr_l = LSDPTR_L(a_l.val) + 1, csptr_l = LSDPTR_L(p_l.val) + 3; aptr_l <= msdptra_l; aptr_l++, csptr_l += 2)
	{
		carry = 0;
		av = *aptr_l;
		for (bptr_l = aptr_l + 1, cptr_l = csptr_l; bptr_l <= msdptrb_l; bptr_l++, cptr_l++)
		{
			*cptr_l = (USHORT)(carry = (ULONG)av * (ULONG)*bptr_l +
				(ULONG)*cptr_l + (ULONG)(USHORT)(carry >> BITPERDGT));
		}
		*cptr_l = (USHORT)(carry >> BITPERDGT);
	}

	msdptrc_l = cptr_l;
	carry = 0;
	for (cptr_l = LSDPTR_L(p_l.val); cptr_l <= msdptrc_l; cptr_l++)
	{
		*cptr_l = (USHORT)(carry = (((ULONG)*cptr_l) << 1) +
			(ULONG)(USHORT)(carry >> BITPERDGT));
	}
	*cptr_l = (USHORT)(carry >> BITPERDGT);

	carry = 0;
	for (bptr_l = LSDPTR_L(a_l.val), cptr_l = LSDPTR_L(p_l.val); bptr_l <= msdptrb_l; bptr_l++, cptr_l++)
	{
		*cptr_l = (USHORT)(carry = (ULONG)*bptr_l * (ULONG)*bptr_l +
			(ULONG)*cptr_l + (ULONG)(USHORT)(carry >> BITPERDGT));
		cptr_l++;
		*cptr_l = (USHORT)(carry = (ULONG)*cptr_l + (carry >> BITPERDGT));
	}

	SETDIGITS_L(p_l.val, DIGITS_L(a_l.val) << 1);
	RMLDZRS_L(p_l.val);
}
int  LINT::Add(const LINT& a_l, const LINT& b_l, LINT& s_l) {
	LINT ss_l;
	int OFL = 0;
	AddK(a_l, b_l, ss_l);
	if (DIGITS_L(ss_l.val) > (USHORT)LINTMAXDIGIT)       /* Overflow ? */
	{
		ANDMAX_L(ss_l.val);                  /* Reduction modulo Nmax+1 */
		OFL = E_LINT_OFL;
	}
	s_l = ss_l;
	return OFL;
}
int  LINT::Sub(const LINT& aa_l, const LINT& bb_l, LINT& d_l)
{
	LINT b_l = bb_l;
	LINT a_l, t_l, tmp_l;
	int UFL = 0;

	if (LT_L(aa_l, b_l))            /* Underflow ? */
	{
		a_l.SetMax();              /* We calculate with Nmax             */
		t_l == aa_l;           /* aa_l will be needed once again, ...*/
		UFL = E_LINT_UFL;           /*  ... will be corrected at the end  */
	}
	else
	{
		a_l = aa_l;
	}

	SubK(a_l, b_l, tmp_l);

	if (UFL)
	{                             /* Underflow ? */
		Add(tmp_l, t_l, d_l);     /* Correction needed */
		d_l.IncOne();             /* One is missing */
	}
	else
	{
		d_l = tmp_l;
	}
	return UFL;
}
int  LINT::Mul(const LINT& f1_l, const LINT& f2_l, LINT& pp_l)
{
	LINT a_l = f1_l, b_l = f2_l;
	LINT p_l(2);
	int OFL = 0;
	MulK(a_l, b_l, p_l);
	if (DIGITS_L(p_l.val) > (USHORT)LINTMAXDIGIT)   /* Overflow ? */
	{
		ANDMAX_L(p_l.val);              /* Reduction modulo Nmax+1 */
		OFL = E_LINT_OFL;
	}
	pp_l = p_l;
	return OFL;
}
int  LINT::Sqr(const LINT& f_l, LINT& pp_l)
{
	LINT a_l;
	LINT p_l(2 * LINTMAXDIGIT + 1);
	int OFL = 0;
	a_l = f_l;
	SqrK(a_l, p_l);
	if (DIGITS_L(p_l.val) > (USHORT)LINTMAXDIGIT)   /* Overflow ? */
	{
		ANDMAX_L(p_l.val);              /* Reduction modulo Nmax+1 */
		OFL = E_LINT_OFL;
	}
	pp_l = p_l;
	return OFL;
}
int  LINT::Div(const LINT& d1_l, const LINT& d2_l, LINT& quot_l, LINT& rem_l)
{
	register lint *rptr_l, *bptr_l;
	LINT b_l, r_l(2);

	lint *qptr_l, *msdptrb_l, *msdptrr_l, *lsdptrr_l;
	USHORT bv, rv, qhat, ri, ri_1, ri_2, bn_1, bn_2;
	ULONG right, left, rhat, borrow, carry, sbitsminusd;
	unsigned int d = 0;
	int i;

	//Copy(r_l, d1_l);
	r_l = d1_l;
	b_l = d2_l;

	if (EQZ_L(b_l))
		return E_LINT_DBZ;          /* Division by Zero */


	if (EQZ_L(r_l))
	{
		SETZERO_L(quot_l.val);
		SETZERO_L(rem_l.val);
		return E_LINT_OK;
	}

	i = Cmp(r_l, b_l);

	if (i == -1)
	{
		rem_l = r_l;
		SETZERO_L(quot_l.val);
		return E_LINT_OK;
	}
	else if (i == 0)
	{
		SETONE_L(quot_l.val);
		SETZERO_L(rem_l.val);
		return E_LINT_OK;
	}

	if (DIGITS_L(b_l.val) == 1)
	{
		goto shortdiv;
	}

	/* Step 1 */
	msdptrb_l = MSDPTR_L(b_l.val);

	bn_1 = *msdptrb_l;
	while (bn_1 < BASEDIV2)
	{
		d++;
		bn_1 <<= 1;
	}

	sbitsminusd = (int)BITPERDGT - d;

	if (d > 0)
	{
		bn_1 += *(msdptrb_l - 1) >> sbitsminusd;

		if (DIGITS_L(b_l.val) > 2)
		{
			bn_2 = (USHORT)((*(msdptrb_l - 1) << d) + (*(msdptrb_l - 2) >> sbitsminusd));
		}
		else
		{
			bn_2 = (USHORT)(*(msdptrb_l - 1) << d);
		}
	}
	else
	{
		bn_2 = (USHORT)(*(msdptrb_l - 1));
	}

	/* Steps 2 and 3 */
	msdptrr_l = MSDPTR_L(r_l.val) + 1;
	lsdptrr_l = MSDPTR_L(r_l.val) - DIGITS_L(b_l.val) + 1;
	*msdptrr_l = 0;

	qptr_l = quot_l.val + DIGITS_L(r_l.val) - DIGITS_L(b_l.val) + 1;

	/* Step 4 */
	while (lsdptrr_l >= LSDPTR_L(r_l.val))
	{
		ri = (USHORT)((*msdptrr_l << d) + (*(msdptrr_l - 1) >> sbitsminusd));

		ri_1 = (USHORT)((*(msdptrr_l - 1) << d) + (*(msdptrr_l - 2) >> sbitsminusd));

		if (msdptrr_l - 3 > r_l.val)
		{
			ri_2 = (USHORT)((*(msdptrr_l - 2) << d) + (*(msdptrr_l - 3) >> sbitsminusd));
		}
		else
		{
			ri_2 = (USHORT)(*(msdptrr_l - 2) << d);
		}

		if (ri != bn_1)               /* almost always */
		{
			qhat = (USHORT)((rhat = ((ULONG)ri << BITPERDGT) + (ULONG)ri_1) / bn_1);
			right = ((rhat = (rhat - (ULONG)bn_1 * qhat)) << BITPERDGT) + ri_2;

			/* test qhat */

			if ((left = (ULONG)bn_2 * qhat) > right)
			{
				qhat--;
				if ((rhat + bn_1) < BASE)
					/* else bn_2 * qhat < rhat * b_l */
				{
					if ((left - bn_2) > (right + ((ULONG)bn_1 << BITPERDGT)))
					{
						qhat--;
					}
				}
			}
		}
		else                        /* ri == bn_1, almost never */
		{
			qhat = BASEMINONE;
			right = ((ULONG)(rhat = (ULONG)bn_1 + (ULONG)ri_1) << BITPERDGT) + ri_2;
			if (rhat < BASE)       /* else bn_2 * qhat < rhat * b_l */
			{
				/* test qhat */

				if ((left = (ULONG)bn_2 * qhat) > right)
				{
					qhat--;
					if ((rhat + bn_1) < BASE)
						/* else bn_2 * qhat < rhat * b_l */
					{
						if ((left - bn_2) > (right + ((ULONG)bn_1 << BITPERDGT)))
						{
							qhat--;
						}
					}
				}
			}
		}

		/* Step 5 */
		borrow = BASE;
		carry = 0;
		for (bptr_l = LSDPTR_L(b_l.val), rptr_l = lsdptrr_l; bptr_l <= msdptrb_l; bptr_l++, rptr_l++)
		{
			if (borrow >= BASE)
			{
				*rptr_l = (USHORT)(borrow = ((ULONG)(*rptr_l) + BASE -
					(ULONG)(USHORT)(carry = (ULONG)(*bptr_l) *
						qhat + (ULONG)(USHORT)(carry >> BITPERDGT))));
			}
			else
			{
				*rptr_l = (USHORT)(borrow = ((ULONG)(*rptr_l) + BASEMINONEL -
					(ULONG)(USHORT)(carry = (ULONG)(*bptr_l) *
						qhat + (ULONG)(USHORT)(carry >> BITPERDGT))));
			}
		}

		if (borrow >= BASE)
		{
			*rptr_l = (USHORT)(borrow = ((ULONG)(*rptr_l) + BASE -
				(ULONG)(USHORT)(carry >> BITPERDGT)));
		}
		else
		{
			*rptr_l = (USHORT)(borrow = ((ULONG)(*rptr_l) + BASEMINONEL -
				(ULONG)(USHORT)(carry >> BITPERDGT)));
		}

		/* Step 6 */
		*qptr_l = qhat;

		if (borrow < BASE)
		{
			carry = 0;
			for (bptr_l = LSDPTR_L(b_l.val), rptr_l = lsdptrr_l; bptr_l <= msdptrb_l; bptr_l++, rptr_l++)
			{
				*rptr_l = (USHORT)(carry = ((ULONG)(*rptr_l) + (ULONG)(*bptr_l) +
					(ULONG)(USHORT)(carry >> BITPERDGT)));
			}
			*rptr_l += (USHORT)(carry >> BITPERDGT);
			(*qptr_l)--;
		}

		/* Step 7 */
		msdptrr_l--;
		lsdptrr_l--;
		qptr_l--;
	}

	/* Step 8 */
	SETDIGITS_L(quot_l.val, DIGITS_L(r_l.val) - DIGITS_L(b_l.val) + 1);
	RMLDZRS_L(quot_l.val);

	SETDIGITS_L(r_l.val, DIGITS_L(b_l.val));
	rem_l = r_l;
	return E_LINT_OK;

	/* Division by divisor with one-digit */
shortdiv:

	rv = 0;
	bv = *LSDPTR_L(b_l.val);
	for (rptr_l = MSDPTR_L(r_l.val), qptr_l = quot_l.val + DIGITS_L(r_l.val); rptr_l >= LSDPTR_L(r_l.val); rptr_l--, qptr_l--)
	{
		*qptr_l = (USHORT)((rhat = ((((ULONG)rv) << BITPERDGT) +
			(ULONG)*rptr_l)) / bv);
		rv = (USHORT)(rhat - (ULONG)bv * (ULONG)*qptr_l);
	}

	SETDIGITS_L(quot_l.val, DIGITS_L(r_l.val));

	RMLDZRS_L(quot_l.val);
	U2LINT(rem_l.val, rv); // modif

	return E_LINT_OK;
}
int  LINT::Mod(const LINT& dv_l, const LINT& ds_l, LINT& r_l)
{
	LINT junk_l(2);
	int err = 0;
	err = Div(dv_l, ds_l, junk_l, r_l);
	return err;
}
int  LINT::MAdd(const LINT& aa_l, const LINT& bb_l, LINT& c_l, const LINT& m_l) {
	LINT a_l, b_l;
	LINT tmp_l;

	if (EQZ_L(m_l))
	{
		return E_LINT_DBZ;          /* Division by Zero */
	}

	a_l = aa_l;
	b_l = bb_l;

	if (GE_L(a_l, m_l) || GE_L(b_l, m_l))
	{
		AddK(a_l, b_l, tmp_l);
		Mod(tmp_l, m_l, c_l);
	}
	else
	{
		AddK(a_l, b_l, tmp_l);
		if (GE_L(tmp_l, m_l))
		{
			Sub(tmp_l, m_l, tmp_l);    /* Underflow prevented */
		}
		c_l = tmp_l;
	}
	return E_LINT_OK;
}
int  LINT::MSub(const LINT& aa_l, const LINT& bb_l, LINT& c_l, const LINT& m_l)
{
	LINT a_l, b_l, tmp_l;

	if (EQZ_L(m_l))
	{
		return E_LINT_DBZ;          /* Division by Zero */
	}

	a_l = aa_l;
	b_l = bb_l;

	if (GE_L(a_l, b_l))
	{
		SubK(a_l, b_l, tmp_l);
		Mod(tmp_l, m_l, c_l);
	}
	else
	{
		SubK(b_l, a_l, tmp_l);       /* Sign tmp_l = -1 */
		Mod(tmp_l, m_l, tmp_l);
		if (GTZ_L(tmp_l))
		{
			SubK(m_l, tmp_l, c_l);
		}
		else
		{
			SETZERO_L(c_l.val);
		}
	}
	return E_LINT_OK;
}
int  LINT::MMul(const LINT& aa_l, const LINT& bb_l, LINT& c_l, const LINT& m_l)
{
	LINT a_l, b_l;
	LINT tmp_l(2);

	if (EQZ_L(m_l))
	{
		return E_LINT_DBZ;          /* Division by Zero */
	}

	a_l = aa_l;
	b_l = bb_l;

	MulK(a_l, b_l, tmp_l);
	Mod(tmp_l, m_l, c_l);
	return E_LINT_OK;
}
int  LINT::MSqr(const LINT& aa_l, LINT& c_l, const LINT& m_l)
{
	LINT a_l;
	LINT tmp_l(2);
	if (EQZ_L(m_l))
		return E_LINT_DBZ;          /* Division by Zero */
	a_l = aa_l;
	SqrK(a_l, tmp_l);
	Mod(tmp_l, m_l, c_l);
	return E_LINT_OK;
}
int  LINT::MEqu(const LINT& a_l, const LINT& b_l, const LINT& m_l)
{
	LINT r_l;
	int res;
	if (EQZ_L(m_l))
		return E_LINT_DBZ;          /* Division by Zero? */
	MSub(a_l, b_l, r_l, m_l);
	res = (0 == DIGITS_L(r_l.val)) ? 1 : 0;
	return res;
}
LINT LINT::MQPower(const LINT& a_l, const LINT& n_l, const LINT& m_l) {
	LINT ans(one_l), a = a_l % m_l, n = n_l, m = m_l, temp;
	//n.Display();
	if (n == nul_l) {
		return ans;
	}

	if (a == nul_l) {
		//ans.Display();
		return nul_l;
	}


	while (n != nul_l) {
		if (n.val[1] & 1) {
			temp = ans;
			MMul(temp, a, ans, m);
		}
		temp = a;
		MSqr(temp, a, m);
		//a = (a * a) % m;
		ShR1(n);
	}
	return ans;
}
void LINT::GCD(const LINT& aa_l, const LINT& bb_l, LINT& cc_l) {
	LINT a = aa_l, b = bb_l, temp;
	while (b > nul_l) {
		a.ClearZero();
		b.ClearZero();
		temp = a % b;
		a = b;
		b = temp;
	}
	cc_l = a;
}
///******************************************************************************/
///*                                                                            */
///*  Function:  Extended Euclidean Algorithm                                   */
///*             Greatest Common Divisor d = GCD(a, b) and linear combination   */
///*             d = au + bv                                                    */
///*  Syntax:    void xgcd_l (LINT a_l, LINT b_l, LINT d_l, LINT u_l,       */
///*                                      int *sign_u, LINT v_l, int *sign_v); */
///*  Input:     a_l, b_l (Operands)                                            */
///*  Output:    d_l (GCD of a_l and b_l)                                       */
///*             u_l, v_l (Factors of the linear combination  d = au + bv       */
///*             with signs in sign_u and sign_v)                               */
///*  Returns:   -                                                              */
///*                                                                            */
///******************************************************************************/
void LINT::XGCD(const LINT& a_l, const LINT& b_l, LINT& d_l, LINT& u_l, int *sign_u, LINT& v_l, int *sign_v)
{
	LINT v1_l, v3_l, t1_l, t3_l, q_l;
	LINT tmp_l(2), tmpu_l(2), tmpv_l(2);
	int sign_v1, sign_t1;

	d_l = a_l;
	v3_l = b_l;

	if (EQZ_L(v3_l))                /* b_l == 0 ? */
	{
		SETONE_L(u_l.val);
		SETZERO_L(v_l.val);
		*sign_u = 1;
		*sign_v = 1;
		return;
	}

	SETONE_L(tmpu_l.val);
	*sign_u = 1;
	SETZERO_L(v1_l.val);
	sign_v1 = 1;

	while (GTZ_L(v3_l))
	{
		Div(d_l, v3_l, q_l, t3_l);
		Mul(v1_l, q_l, q_l);
		sign_t1 = SSub(tmpu_l, *sign_u, q_l, sign_v1, t1_l);
		tmpu_l = v1_l;
		*sign_u = sign_v1;
		d_l = v3_l;
		v1_l = t1_l;
		sign_v1 = sign_t1;
		v3_l = t3_l;
	}

	Mul(a_l, tmpu_l, tmp_l);
	*sign_v = SSub(d_l, 1, tmp_l, *sign_u, tmp_l);
	Div(tmp_l, b_l, tmpv_l, tmp_l);
	if (!EQZ_L(tmp_l))
		return;
	u_l = tmpu_l;
	v_l = tmpv_l;

	return;
}
///******************************************************************************/
///*                                                                            */
///*  Function:  Inverse of a modulo n                                          */
///*  Syntax:    void inv_l (LINT a_l, LINT n_l, LINT g_l, LINT i_l);       */
///*  Input:     a_l (Operand), n_l (Modulus)                                   */
///*  Output:    g_l (GCD of a_l and n_l),                                      */
///*             i_l (Inverse of a_l mod n_l)                                   */
///*             If gcd > 1 the inverse does not exist, i_l is set to zero then */
///*  Returns:   -                                                              */
///*                                                                            */
///******************************************************************************/
void LINT::Inv(const LINT& a_l, const LINT& n_l, LINT& g_l, LINT& i_l)
{
	LINT v1_l, v3_l, t1_l, t3_l, q_l;

	if (EQZ_L(a_l))
	{
		if (EQZ_L(n_l))
		{
			SETZERO_L(g_l.val);
			SETZERO_L(i_l.val);
			return;
		}
		else
		{
			g_l = n_l;
			SETZERO_L(i_l.val);
			g_l.ClearZero();
			return;
		}
	}
	else
	{
		if (EQZ_L(n_l))
		{
			g_l = a_l;
			SETZERO_L(i_l.val);
			g_l.ClearZero();
			return;
		}
	}
	g_l = a_l;
	g_l.ClearZero();
	v3_l = n_l;
	v3_l.ClearZero();
	SETZERO_L(v1_l.val);
	SETONE_L(t1_l.val);

	do
	{
		g_l.ClearZero();
		v3_l.ClearZero();
		Div(g_l, v3_l, q_l, t3_l);

		if (GTZ_L(t3_l))
		{
			v1_l.ClearZero();
			q_l.ClearZero();
			MMul(v1_l, q_l, q_l, n_l);
			MSub(t1_l, q_l, q_l, n_l);
			t1_l = v1_l;
			v1_l = q_l;
			g_l = v3_l;
			v3_l = t3_l;
		}
	} while (GTZ_L(t3_l));
	v3_l.ClearZero();
	g_l = v3_l;
	if (EQONE_L(g_l)) {
		i_l = v1_l;
		i_l.ClearZero();
	}

	else
		SETZERO_L(i_l.val);

}

int LINT::ShR1(LINT& a_l)
{
	lint *ap_l;
	USHORT help, carry = 0;

	if (DIGITS_L(a_l.val) == 0)
	{
		return E_LINT_UFL;          /* Underflow */
	}

	for (ap_l = MSDPTR_L(a_l.val); ap_l > a_l.val; ap_l--)
	{
		help = (USHORT)((USHORT)(*ap_l >> 1) | (USHORT)(carry << (BITPERDGT - 1)));
		carry = (USHORT)(*ap_l & 1U);
		*ap_l = help;
	}

	RMLDZRS_L(a_l.val);
	return E_LINT_OK;
}
int LINT::ShL1(LINT& a_l)
{
	lint *ap_l, *msdptra_l;
	ULONG carry = 0L;
	int error = E_LINT_OK;

	RMLDZRS_L(a_l.val);
	if (LD(a_l) >= (USHORT)LINTMAXBIT)
	{
		SETDIGITS_L(a_l.val, LINTMAXDIGIT);
		error = E_LINT_OFL;         /* Overflow */
	}

	msdptra_l = MSDPTR_L(a_l.val);
	for (ap_l = LSDPTR_L(a_l.val); ap_l <= msdptra_l; ap_l++)
	{
		*ap_l = (USHORT)(carry = ((ULONG)(*ap_l) << 1) | (carry >> BITPERDGT));
	}

	if (carry >> BITPERDGT)
	{
		if (DIGITS_L(a_l.val) < LINTMAXDIGIT)
		{
			*ap_l = 1;
			INCDIGITS_L(a_l.val);
			error = E_LINT_OK;
		}
		else
		{
			error = E_LINT_OFL;
		}
	}

	RMLDZRS_L(a_l.val);
	return error;
}
///******************************************************************************/
///*                                                                            */
///*  Function:  Calculate number of bits of a LINT operand                    */
///*             (Integral part of base-2-logarithm + 1)                        */
///*  Syntax:    unsigned int ld_l (n_l);                                       */
///*  Input:     n_l (Argument)                                                 */
///*  Output:    -                                                              */
///*  Returns:   Number of relevant binary digits of n_l                        */
///*                                                                            */
///******************************************************************************/
unsigned int LINT::LD(const LINT& n_l)
{
	unsigned int l;
	USHORT test;

	l = (unsigned int)DIGITS_L(n_l.val);
	while (n_l.val[l] == 0 && l > 0)
	{
		--l;
	}

	if (l == 0)
	{
		return 0;
	}

	test = n_l.val[l];
	l <<= LDBITPERDGT;

	while ((test & BASEDIV2) == 0)
	{
		test <<= 1;
		--l;
	}

	return l;
}
///******************************************************************************/
///*                                                                            */
///*  Function:  Binary left-/rightshift by n bits                              */
///*  Syntax:    int shift_l (LINT n_l, long int noofbits);                    */
///*  Input:     n_l (Operand)                                                  */
///*             noofbits (Number of places to be shifted)                      */
///*             negative sign: Shift right                                     */
///*             positive sign: Shift left                                      */
///*  Output:    a_l (Shifted value)                                            */
///*  Returns:   E_LINT_OK : Everything O.K.                                   */
///*             E_LINT_OFL: Overflow                                          */
///*             E_LINT_UFL: Underflow                                         */
///*                                                                            */
///******************************************************************************/
int  LINT::Shift(LINT& n_l, const long int noofbits)
{
	USHORT shorts = (USHORT)((ULONG)(noofbits < 0 ? -noofbits : noofbits) / BITPERDGT);
	USHORT bits = (USHORT)((ULONG)(noofbits < 0 ? -noofbits : noofbits) % BITPERDGT);
	long int resl;
	USHORT i;
	int error = E_LINT_OK;

	lint *nptr_l;
	lint *msdptrn_l;

	RMLDZRS_L(n_l.val);
	resl = LD(n_l) + noofbits;

	if (DIGITS_L(n_l.val) == 0)
	{
		shorts = bits = 0;
		return ((resl < 0) ? E_LINT_UFL : E_LINT_OK);
	}

	if (noofbits == 0)
	{
		return E_LINT_OK;
	}

	if ((resl < 0) || (resl >(long)LINTMAXBIT))
	{
		error = ((resl < 0) ? E_LINT_UFL : E_LINT_OFL);   /* Under-/Overflow */
	}

	SETDIGITS_L(n_l.val, MIN(DIGITS_L(n_l.val), LINTMAXDIGIT));

	if (noofbits < 0)
	{

		/* Shift Right */

		shorts = (USHORT)MIN(DIGITS_L(n_l.val), shorts);
		msdptrn_l = MSDPTR_L(n_l.val) - shorts;
		for (nptr_l = LSDPTR_L(n_l.val); nptr_l <= msdptrn_l; nptr_l++)
		{
			*nptr_l = *(nptr_l + shorts);
		}
		SETDIGITS_L(n_l.val, DIGITS_L(n_l.val) - shorts);

		for (i = 0; i < bits; i++)
			ShR1(n_l);
	}
	else
	{

		/* Shift Left   */

		if (shorts < LINTMAXDIGIT)
		{
			SETDIGITS_L(n_l.val, MIN((USHORT)(DIGITS_L(n_l.val) + shorts), LINTMAXDIGIT));
			nptr_l = n_l.val + DIGITS_L(n_l.val);
			msdptrn_l = n_l.val + shorts;
			while (nptr_l > msdptrn_l)
			{
				*nptr_l = *(nptr_l - shorts);
				--nptr_l;
			}

			while (nptr_l > n_l.val)
			{
				*nptr_l-- = 0;
			}

			RMLDZRS_L(n_l.val);
			for (i = 0; i < bits; i++)
			{
				ShL1(n_l);
			}
		}
		else
		{
			SETZERO_L(n_l.val);
		}
	}

	return error;
}


//LINT LINT:: operator --() {
//	*this = *this - one_l;
//	return *this;
//}
bool LINT::operator <(const LINT& a)const {
	return Cmp(*this, a) == -1;
}
bool LINT::operator <=(const LINT& a)const {
	return Cmp(*this, a) <= 0;
}
bool LINT::operator >(const LINT& a)const {
	return Cmp(*this, a) == 1;
}
bool LINT::operator >=(const LINT& a)const {
	return Cmp(*this, a) >= 0;
}

LINT LINT::operator +(const LINT& a)const {
	LINT temp;
	Add(*this, a, temp);
	return temp;
}
LINT LINT::operator -(const LINT& a)const {
	LINT temp;
	Sub(*this, a, temp);
	return temp;
}
LINT LINT::operator *(const LINT& a)const {
	LINT temp;
	Mul(*this, a, temp);
	return temp;
}
LINT LINT::operator /(const LINT& a)const {
	LINT temp1, temp2;
	Div(*this, a, temp1, temp2);
	return temp1;
}
LINT LINT::operator %(const LINT& a)const {
	LINT temp;
	Mod(*this, a, temp);
	return temp;
}
LINT LINT::operator >> (const long int noofbits)const {
	LINT temp = *this;
	Shift(temp, -noofbits);
	return temp;
	return *this;
}
LINT LINT::operator << (const long int noofbits)const {
	LINT temp = *this;
	Shift(temp, noofbits);
	return temp;
	return *this;
}
LINT& LINT::operator >>= (const long int noofbits) {
	Shift(*this, -noofbits);
	return *this;
}
LINT& LINT::operator <<= (const long int noofbits) {
	Shift(*this, noofbits);
	return *this;
}


