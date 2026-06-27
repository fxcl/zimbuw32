/*
 * Generated from Zimbu file testdir/progs/exeName.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <sys/time.h>

/*
 * TYPEDEFS
 */
#define ZINT_FORMAT "%lld"
#define ZNAT_FORMAT "%llu"
#define ZINT_XFORMAT "%llx"
#define ZFLOAT_FORMAT "%g"
typedef long long Ti; /* int */
typedef short Ti16; /* int16 */
typedef int Ti32; /* int32 */
typedef unsigned long long Tu; /* nat */
typedef unsigned char Tc; /* byte */
typedef unsigned short Tu16; /* nat16 */
typedef unsigned int Tu32; /* nat32 */
typedef double Tf; /* float */
typedef float Tf32; /* float32 */
typedef __INTPTR_TYPE__ Tip; /* int for pointer */
typedef long long Tbb; /* big BITS */

typedef int Tbs; /* small BITS */
typedef int Tb; /* bool */
typedef int Ts; /* status */
typedef int Te; /* enum */
typedef struct Zref__S Tr; /* object ref */
typedef struct Zobj__S To; /* object description */
typedef union {
 Ti ival;
 Tf fval;
 void *ptr;
} Tz; /* dyn value */
typedef struct Ztype__S Tt; /* type */
typedef struct Ztypeo__S Tto; /* type with To pointer */
typedef struct Zoh__S Zoh; /* allocated memory header */
struct Zoh__S {
 Zoh *np;
};
#define ZOH_OFF sizeof(Zoh)
Zoh Zstatic;
Zoh Znoalloc;
Zoh Zlast;
typedef struct {
 void *var;
 Tt   *type;
} Zop;
#define GC_BLOCK_SIZE 1022
typedef struct Zgcb__S Zgcb;
struct Zgcb__S {
 Zgcb *next;
 int used;
 Zop items[GC_BLOCK_SIZE];
};
typedef struct {
 Zgcb *todo;
 Zgcb *empty;
} Zgcs;
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
typedef struct YzSI__S YzSI; /* MEModule.DivideByZero */
typedef struct YXKl__S YXKl; /* MEModule.IOError */
typedef struct YuDC__S YuDC; /* MEModule.WrongType */
typedef struct YrHq__S YrHq; /* MEModule.Internal */
/* EModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/*
 * STRUCTS
 */
/* IO.eof */
#define Y3QJ EOF


typedef struct {
 int line;
 int col;
} Tcpos;
typedef struct {
 Ti offset;
 Tc *fileName;
 Tc *methodName;
 Tcpos *table;
} Tcode;

void *Za(size_t size);
void *ZaNm(size_t size);
void *ZaNmi(size_t size);
void *Zran(void *op, size_t osize, size_t nsize);
void *ZranNm(void *op, size_t osize, size_t nsize);
void ZthrowOutOfMemory(Ti size);
char *emergencyAlloc = NULL;
size_t emergencyAllocUsed = 0;
void ZthrowDeadly(int nr);
Tc *ZnewString(Tc *p, Ti len);
void ZthrowCstringNil(char *text);
void ZthrowCstringBadValue(char *msg);
void ZthrowInternal(Tc *t);
char *ZgetCstring(Tc *s);
struct ZforList__S {
 Zoh *np;
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);

struct Zref__S {
 void *ptr;
 Tc **table;
 int  type;
};
Tr trZero = {NULL,NULL,0};
struct Zobj__S {
 int off;
 Tt *type;
};

struct Ztype__S {
 int nr;
 Tc *name;
 void *ToString;
};
struct Ztypeo__S {
 int nr;
 Tc *name;
 void *ToString;
 To *to;
};
extern Tt bool__T;
extern Tt byte__T;
extern Tt byteString__T;
extern Tt float128__T;
extern Tt float32__T;
extern Tt float80__T;
extern Tt float__T;
extern Tt int16__T;
extern Tt int32__T;
extern Tt int8__T;
extern Tt int__T;
extern Tt nat16__T;
extern Tt nat32__T;
extern Tt nat__T;
extern Tt status__T;
extern Tt string__T;
extern Tt type__T;
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt iobj__T;

struct CArray__S {
 Zoh *np;
 void *ptr;
 void *alloced;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);
struct CListHead__S {
 Zoh *np;
 Tt *itemType;
 void **items;
 void *alloced;
 Ti empty;
 Ti space;
 Ti itemCount;
 int itemSize;
 int tosNr;
};
Tl *ZLa(Tl *head, Ti after, Tz val);
Tl *ZnewList(Tt *itemType, Ti size);
Tl *ZLap(Tl *head, Tz val);
void *ZListGetPtr(Tl *head, Ti idx);
#define HT_INIT_SIZE 16
#define PERTURB_SHIFT 5

#define DTYPE_ORDERED 1 /* dict with list to keep order of items */

#define CDI_FLAG_USED 1
#define CDI_FLAG_DEL 2
struct CDictItem__S {
 Zhashtype hash;
 union {
  Tz key;
  Tr iokey;
 };
 union {
  Tz item;
  Tr ioitem;
 };
 CDictItem *lnext;
 CDictItem *lprev;
 int flags;
};

struct CDictHead__S {
 Zoh *np;

 Zhashtype mask;
 Zhashtype used;
 Zhashtype extra;
 Zhashtype filled;
 int tosNr;
 int type;
 CDictItem *array;
 CDictItem smallArray[HT_INIT_SIZE];
 void *alloced;
 Tt *keyType;
 Tt *itemType;
 int (*eqfunc)(void *i, Tz *v);
 CDictItem *first;
 CDictItem *last;
};
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 Zoh *np;
 char text[5];
} Zs5;
/* including EModule structs */
typedef struct {
 Zoh *np;
 char text[4];
} Zs4;
typedef struct {
 Zoh *np;
 char text[13];
} Zs13;
typedef struct {
 Zoh *np;
 char text[11];
} Zs11;
typedef struct {
 Zoh *np;
 char text[39];
} Zs39;
typedef struct {
 Zoh *np;
 char text[12];
} Zs12;
typedef struct {
 Zoh *np;
 char text[3];
} Zs3;
struct Ytlm__S {
 Zoh *np;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 Zoh *np;
 char text[7];
} Zs7;
struct YEro__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 Zoh *np;
 char text[6];
} Zs6;
typedef struct {
 Zoh *np;
 char text[28];
} Zs28;
typedef struct {
 Zoh *np;
 char text[9];
} Zs9;
struct YKhn__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 Zoh *np;
 char text[14];
} Zs14;
struct YVNj__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct Yalz__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 Zoh *np;
 char text[10];
} Zs10;
struct Yw3O__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 Zoh *np;
 char text[17];
} Zs17;
typedef struct {
 Zoh *np;
 char text[18];
} Zs18;
struct YX0i__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 Zoh *np;
 char text[22];
} Zs22;
typedef struct {
 Zoh *np;
 char text[23];
} Zs23;
struct YzSI__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 Zoh *np;
 char text[15];
} Zs15;
struct YuDC__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including ZModule structs */
typedef struct {
 Zoh *np;
 char text[16];
} Zs16;
typedef struct {
 Zoh *np;
 char text[8];
} Zs8;
struct YkxB__S {
 Zoh *np;
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
struct Yw8L__S {
 Zoh *np;
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
typedef struct {
 Zoh *np;
 char text[2];
} Zs2;
typedef struct {
 Zoh *np;
 char text[53];
} Zs53;
struct YjUM__S {
 Zoh *np;
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
/* IOModule done */
/* including ARGModule structs */
struct YnU5__S {
 Zoh *np;
};
extern Tto YnU5__T;
typedef struct {
 Zoh *np;
 char text[56];
} Zs56;
typedef struct {
 Zoh *np;
 char text[20];
} Zs20;
typedef struct {
 Zoh *np;
 char text[29];
} Zs29;
typedef struct {
 Zoh *np;
 char text[31];
} Zs31;
typedef struct {
 Zoh *np;
 char text[43];
} Zs43;
typedef struct {
 Zoh *np;
 char text[19];
} Zs19;
typedef struct {
 Zoh *np;
 char text[21];
} Zs21;
typedef struct {
 Zoh *np;
 char text[24];
} Zs24;
struct YuMQ__S {
 Zoh *np;
 Tc *Vtext;
};
extern Tto YuMQ__T;
struct Y86c__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tb Vcurrent;
 Tb Vdefault;
};
extern Tto Y86c__T;
struct YJQu__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Ti Vcurrent;
 Ti Vdefault;
 Tl *VtheValueList;
};
extern Tto YJQu__T;
struct YzqH__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tc *Vcurrent;
 Tc *Vdefault;
 Tl *VtheValueList;
};
extern Tto YzqH__T;
struct Y_SI__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tl *Vcurrent;
 Tl *Vdefault;
};
extern Tto Y_SI__T;
/* ARGModule done */
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {&Zstatic, "\003NIL\000"};
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
/* TIMEModule done */
/* including EModule declarations */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {&Zstatic, "\002: \000"};
Zs13 YHbP = {&Zstatic, "\013Exception: \000"};
Zs11 YDGe = {&Zstatic, "\011Exception\000"};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {&Zstatic, "\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {&Zstatic, "\012\n(unknown)\000"};
Zs3 Yk = {&Zstatic, "\001\n\000"};
To ToYtlm[4];
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Zs7 YxJ1 = {&Zstatic, "\005EXIT \000"};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
To ToYEro[4];
Zs6 YJMo = {&Zstatic, "\004Exit\000"};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {&Zstatic, "\032Out of memory (allocating \000"};
Zs9 YDSH = {&Zstatic, "\007 bytes)\000"};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
Zs13 Y9Fv = {&Zstatic, "\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
Zs11 Y4wO = {&Zstatic, "\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
Zs14 Y4QW = {&Zstatic, "\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {&Zstatic, "\013signal SEGV\000"};
Zs12 YoEx = {&Zstatic, "\012signal FPE\000"};
Zs12 YQNH = {&Zstatic, "\012signal BUS\000"};
Zs9 YpCZ = {&Zstatic, "\007signal \000"};
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
Zs6 Ysqt = {&Zstatic, "\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
Zs10 YEZq = {&Zstatic, "\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
Zs12 YFK2 = {&Zstatic, "\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
Zs13 YRiW = {&Zstatic, "\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {&Zstatic, "\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {&Zstatic, "\020Key not found: \"\000"};
Zs3 YI = {&Zstatic, "\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
Zs11 Y9_h = {&Zstatic, "\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {&Zstatic, "\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {&Zstatic, "\025Key already exists: \"\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
Zs14 YxFl = {&Zstatic, "\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
Zs9 YTj3 = {&Zstatic, "\007IOError\000"};
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {&Zstatic, "\015Type mismatch\000"};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
Zs11 YCoZ = {&Zstatic, "\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
Zs10 YVki = {&Zstatic, "\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including SYSModule declarations */
Tc *Yhy5(Tc *Aname); /* MSYSModule.getEnv */
Zs9 YVbO = {&Zstatic, "\007IOFlags\000"};
Tt MSYSModule__BIOFlags__T = {25, ((Tc*)&YVbO), 0};
/* SYSModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {&Zstatic, "\016[unknown file]\000"};
Zs8 YBpY = {&Zstatic, "\006 line \000"};
Zs7 Y8ES = {&Zstatic, "\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {&Zstatic, "\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato); /* MSTRINGModule.replaceAll */
/* STRINGModule done */
/* including IOModule declarations */
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Zs18 YQe8 = {&Zstatic, "\020File is not open\000"};
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
Zs6 YtTU = {&Zstatic, "\004File\000"};
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Zs2 Ya = {&Zstatic, "\000\000"};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {&Zstatic, "\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Tc *YjUM__YdXi_imt[3];
To ToYjUM[3];
Zs14 YE4c = {&Zstatic, "\014StringWriter\000"};
Tb Y_3K(Tc *Aname); /* MIOModule.isExecutable */
Tc *Ycmi(Tc *AexeName); /* MIOModule.findExe */
Zs3 YV = {&Zstatic, "\001/\000"};
Zs4 YFka = {&Zstatic, "\002./\000"};
Zs5 Y0y2 = {&Zstatic, "\003../\000"};
Zs6 Yykt = {&Zstatic, "\004PATH\000"};
Zs3 Y6 = {&Zstatic, "\001;\000"};
Zs3 Y5 = {&Zstatic, "\001:\000"};
Zs6 YpPR = {&Zstatic, "\004.exe\000"};
Tc *YDop(Tc *AexeName, Tl *Adirs); /* MIOModule.findExeInDirList */
Tc *Yq8a(Tc *Afirst, Tc *Asecond); /* MIOModule.concatPath */
Tc *YPjH(Tc *Afname); /* MIOModule.resolve */
Ti Yr30(Tc *Afname); /* MIOModule.tailIndex */
Ti YEpA(Tc *Afname); /* MIOModule.pastHeadIndex */
Tb Yhu2(Ti Ac); /* MIOModule.isPathSep */
Ti Y26N(Tc *Afname, Ti Aidx); /* MIOModule.nextPartIndex */
int JIOModule(int round);
/* IOModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
Tc *Y2R7 = NULL; /* MARGModule.exeName */
Tl *Y1p3 = NULL; /* MARGModule.rawArgs */
Tl *Y6fX = NULL; /* MARGModule.cleanArgs */
Tb YQpY = 0; /* MARGModule.stopFlag */
Tb YUBd = 0; /* MARGModule.disabled */
Tb YhUP = 0; /* MARGModule.disableGiveHelp */
Tb Y_kI = 0; /* MARGModule.disableCompactVal */
Ti YMLU = 1 /* MARGModule.exitVal */;
YuMQ *Yun4 = 0; /* MARGModule.theUsage */
int Ytu___r = 0; /* MARGModule.Ready */
Ts Ytu_(); /* MARGModule.Init */
To ToYnU5[1];
Zs8 Yr32 = {&Zstatic, "\006Status\000"};
void YQtK(); /* MARGModule.initExeName */
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {&Zstatic, "\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {&Zstatic, "\001-\000"};
Zs4 Y1ia = {&Zstatic, "\002--\000"};
Zs6 YqzQ = {&Zstatic, "\004help\000"};
Zs10 Y3vi = {&Zstatic, "\010morehelp\000"};
Zs10 Yll7 = {&Zstatic, "\010helpmore\000"};
Zs4 YhZb = {&Zstatic, "\002no\000"};
Zs20 YcW8 = {&Zstatic, "\022Invalid argument: \000"};
Zs29 Y2hB = {&Zstatic, "\033Unknown command line flag: \000"};
Zs31 YcLH = {&Zstatic, "\035Duplicate command line flag: \000"};
Zs5 YjK7 = {&Zstatic, "\003yes\000"};
Zs6 YsfP = {&Zstatic, "\004true\000"};
Zs7 YvpX = {&Zstatic, "\005false\000"};
Zs43 YHSJ = {&Zstatic, "\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {&Zstatic, "\021Unexpected = in: \000"};
Zs28 Y_ju = {&Zstatic, "\032Missing argument for flag \000"};
Zs29 YjTs = {&Zstatic, "\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {&Zstatic, "\024To list flags use: '\000"};
Zs10 Y15F = {&Zstatic, "\010 --help'\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {&Zstatic, "\023Command line flags:\000"};
Zs13 YwXF = {&Zstatic, "\013--morehelp \000"};
Zs24 YEcf = {&Zstatic, "\026show more verbose help\000"};
Zs8 Yy2p = {&Zstatic, "\006number\000"};
Zs8 YanE = {&Zstatic, "\006string\000"};
Zs12 YDci = {&Zstatic, "\012string ...\000"};
Zs6 YulU = {&Zstatic, "\004 ...\000"};
Zs4 YVZ = {&Zstatic, "\002 [\000"};
Zs3 YEa = {&Zstatic, "\001]\000"};
Zs4 Yq_ = {&Zstatic, "\002 {\000"};
Zs3 Y9a = {&Zstatic, "\001}\000"};
Zs3 YG = {&Zstatic, "\001 \000"};
Zs5 Y_y2 = {&Zstatic, "\003...\000"};
Zs6 Y2yA = {&Zstatic, "\004... \000"};
Zs13 Ym4c = {&Zstatic, "\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {&Zstatic, "\003%0%\000"};
To ToYuMQ[2];
Zs7 Y6qT = {&Zstatic, "\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
To ToY86c[6];
Zs6 YZ1F = {&Zstatic, "\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
To ToYJQu[7];
Zs5 YzBa = {&Zstatic, "\003Int\000"};
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
To ToYzqH[9];
Zs8 YDAE = {&Zstatic, "\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[8];
Zs12 Ygf5 = {&Zstatic, "\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */


Zop ZglobalVars[] = {
{&Y59X,(Tt*)&iobj__T},
{&Yb0q,(Tt*)&iobj__T},
{&YeNQ,(Tt*)&iobj__T},
{&YzvW,(Tt*)&string__T},
{&Y2R7,(Tt*)&string__T},
{&Y1p3,(Tt*)&list__T},
{&Y6fX,(Tt*)&list__T},
{&Yun4,(Tt*)&YuMQ__T},
{&Y7be,(Tt*)&dict__T},
{&YBQy,(Tt*)&dict__T},
{0,0},
};

Tt bool__T  = {21, 0, 0};
Tt byte__T  = {11, 0, 0};
Tt byteString__T = {201, 0, 0};
Tt float128__T  = {83, 0, 0};
Tt float32__T  = {81, 0, 0};
Tt float80__T  = {82, 0, 0};
Tt float__T  = {80, 0, 0};
Tt int16__T  = {2, 0, 0};
Tt int32__T  = {3, 0, 0};
Tt int8__T  = {1, 0, 0};
Tt int__T  = {0, 0, 0};
Tt nat16__T  = {12, 0, 0};
Tt nat32__T  = {13, 0, 0};
Tt nat__T  = {10, 0, 0};
Tt status__T  = {22, 0, 0};
Tt string__T = {200, 0, 0};
Tt type__T  = {101, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt iobj__T = {391, 0, 0};
int ZglobInit(int round);

typedef struct Zfo__S {
 int off;
 Tt  *type;
} Zfo;
typedef struct Zsf__S {
 volatile int pos;
 struct Zsf__S *prev;
 Zfo *frof;
} Zsf;
#define POS_MASK 0x3fffffff
typedef struct Senv__S {
 int tosNr;
} Tn; /* per-thread environemnt */

Zoh *firstUsed = &Zlast;
Zgcs gcStatus;
Zsf *topFrame = NULL;
int inZa = 0;
int ZaEntered = 0;

Tn Zenv = {0};

void ZthreadGC();
void ZgcRun();
void beforeExit() {
 ZgcRun();
 firstUsed = &Zlast;
}

Ti ZgcUseCount = 0;
Ti ZgcStwTime = 0;
Ti ZgcMarkTime = 0;
Ti ZgcFinishTime = 0;
Ti ZgcFreeTime = 0;
Ti ZgcFreeCount = 0;


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

void ZreportUnsafe() {
 static int rec = 0;
 if (rec == 0) {
  rec = 1;
  ZthrowInternal(Zstr("Allocating memory without UNSAFE set!"));
  rec = 0;
 }
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 if (topFrame != NULL && (topFrame->pos & 0x40000000) == 0)
  ZreportUnsafe();
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 ((Zoh *)p)->np = (Zoh*)firstUsed;
 firstUsed = p;
 ++ZgcUseCount;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 if (topFrame != NULL && (topFrame->pos & 0x40000000) == 0)
  ZreportUnsafe();
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (topFrame != NULL && (topFrame->pos & 0x40000000) == 0)
  ZreportUnsafe();
 p = Za(nsize);
 if (op)
  memmove(p + ZOH_OFF, op + ZOH_OFF, nsize > osize ? osize - ZOH_OFF : nsize - ZOH_OFF);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void *ZranNm(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (topFrame != NULL && (topFrame->pos & 0x40000000) == 0)
  ZreportUnsafe();
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
   ++ZaEntered;
   ZthrowOutOfMemory(nsize);
  }
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = ZaNm(nsize);
 if (op) memmove(p, op, nsize > osize ? osize : nsize);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

int newMark = 1;

void ZgcGetBlock(Zgcs *gcs) {
 Zgcb *b = malloc(sizeof(Zgcb));
 if (b == NULL) {
  fputs("Out of memory (ZgcGetBlock)\n", stderr);
  fflush(stderr);
  exit(1);
 }
 b->next = gcs->todo;
 gcs->todo = b;
}

/* Mark used memory on stack frames and try context for one thread.
 * When "doGlobal" is non-zero also mark global items. */
void ZgcMarkItems(Tn *e, int doGlobal, void *pArg, Tt *toArg) {
 Zgcs *gcs = &gcStatus;
 Zgcb *b = NULL;
 int used = GC_BLOCK_SIZE;
#define ADD_ITEM(ap, atype) \
  { if (ap) { \
   if (used == GC_BLOCK_SIZE) { \
    if (b) b->used = GC_BLOCK_SIZE; \
    ZgcGetBlock(gcs); \
    b = gcs->todo; \
    used = 0; \
   } \
   b->items[used].var = (ap); \
   b->items[used].type = (atype); \
   ++used; \
  }}

 Zsf *frame = topFrame;
 Zfo *fo = frame == NULL ? NULL : frame->frof;
 int ti = 0;
 int gi = 0;
 int ni = 0;
 void *p = NULL;
 Tt *to;
 int what = 0;
 while (what <= 5) {
  switch (what) {
   case 0:
    if (pArg) {
     what = 99;
     p = pArg;
     to = toArg;
     break;
    }
    if (frame == NULL) ++what;
    else {
     if (!fo) {
      frame = frame->prev;
      if (frame) fo = frame->frof;
     } else {
      if (fo->type == &iobj__T) {
       p = (char *)frame - (fo->off & ~1);
       if (((Tr*)p)->ptr == NULL) p = NULL;
       else to = &iobj__T;
      } else if (fo->off & 1) {
       p = (char *)frame - (fo->off - 1);
       if (((Zoh*)p)->np == NULL) p = NULL;
       else to = fo->type;
      } else {
       p = *(char **)((char *)frame - fo->off);
       if (p) to = fo->type;
      }
      ++fo;
      if (!fo->off) {
       frame = frame->prev;
       if (frame) fo = frame->frof;
      }
     }
    }
    break;
   case 1: /* no TRY */
    what += 2;
    break;
   case 3:
    if (!doGlobal) what = 99;
    else {
     ++what;
    }
    break;
   case 4:
    if (!ZglobalVars[gi].var) {
     ++what;
    } else {
     to = ZglobalVars[gi].type;
     if (to == &iobj__T)
      p = ZglobalVars[gi].var;
     else
      p = *((char**)(ZglobalVars[gi].var));
     ++gi;
    }
    break;
   case 5:
    ++what;
    break;
  }

  while (p) {
   void *ip = NULL;
   Tt *ito = NULL;
   Zoh *np;
   while (to == &iobj__T) {
    if (((Tr*)p)->ptr == NULL) goto p_is_null;
    to = (Tt*)(((Tr*)p)->table[0]);
    p = ((Tr*)p)->ptr;
   }
   np = ((Zoh *)p)->np;
   if (((Tip)np & 3) != newMark && np != NULL) {
    ((Zoh *)p)->np = (Zoh *)(((Tip)np & ~3) | newMark);

    if (to != NULL && to->nr >= 300) {
     if (0) ;
      else if (to == &array__T) {
      Ta *head = (Ta*)p;
      if (head->ptr && head->ptr != head + 1) {
       ip = head->ptr - ZOH_OFF;
       /* ito = NULL; */
       if (head->itemType && head->itemType->nr >= 200) {
        Ti i;
        Ti d;
        i = head->size[0];
        for (d = 1; d < head->dim; ++d) i *= head->size[d];
        while (--i >= 0) {
         void *p;
         if (head->itemType == &iobj__T)
          p = (Tr*)head->ptr + i;
         else
          p = ((char **)(head->ptr))[i];
         ADD_ITEM(p, head->itemType)
        }
       }
      }
     } else if (to == &list__T) {
      Tl *head = (Tl*)p;
      if (head->itemType && head->itemType->nr >= 200) {
       if (head->items) {
        Ti n;
        Ti tot = head->empty + head->itemCount;
         for (n = head->empty; n < tot; ++n) {
          void *p;
         if (head->itemType == &iobj__T)
          p = (Tr*)head->items + n;
         else
           p = head->items[n];
          ADD_ITEM(p, head->itemType)
         }
       }
      }
      if (head->items && head->items != (void**)(head + 1)) {
       ip = (void*)head->items - ZOH_OFF;
       /* ito = NULL; */
      }
     } else if (to == &dict__T) {
      Td *head = (Td*)p;
      int dokey = (head->keyType && head->keyType->nr >= 200);
      int doitem = (head->itemType && head->itemType->nr >= 200);
      if (head->array != head->smallArray && head->array) {
       ip = (void*)head->array - ZOH_OFF;
       /* ito = NULL; */
      }
      if (dokey || doitem) {
       int todo;
       CDictItem *item;
       todo = (int)head->used;
       for (item = head->array; todo > 0; ++item) {
        if (item->flags & CDI_FLAG_USED) {
         if (dokey) {
          if (head->keyType == &iobj__T)
           ADD_ITEM(&item->iokey, &iobj__T)
          else
           ADD_ITEM(item->key.ptr, head->keyType)
         }
         if (doitem) {
          if (head->itemType == &iobj__T)
           ADD_ITEM(&item->ioitem, &iobj__T)
          else
           ADD_ITEM(item->item.ptr, head->itemType)
         }
         --todo;
        }
       }
      }
     } else {
      int i;
      To *tto = ((Tto*)to)->to;
      for (i = 1; i <= tto->off; ++i) {
       if (tto[i].type == &iobj__T) {
        void *pp = (char*)p + tto[i].off;
        ADD_ITEM(pp, tto[i].type)
       } else
       {
        void *pp = *(char**)((char*)p + tto[i].off);
        ADD_ITEM(pp, tto[i].type)
       }
      }
     }
    }
   }

p_is_null:
   if (ip) {
    p = ip;
    to = ito;
   } else if (b && used > 0) {
    --used;
    p = b->items[used].var;
    to = b->items[used].type;
   } else if (b) {
    gcs->todo = b->next;
    b->next = gcs->empty;
    gcs->empty = b;
    b = gcs->todo;
    if (b) {
     used = b->used - 1;
     p = b->items[used].var;
     to = b->items[used].type;
    } else {
     used = GC_BLOCK_SIZE;
     p = NULL;
    }
   } else p = NULL;
  }
 }

 while (gcs->empty) {
  b = gcs->empty->next;
  free(gcs->empty);
  gcs->empty = b;
 }
}
#undef ADD_ITEM
/* free unmarked memory */
Zoh *ZgcFree(Zoh *firstUsed) {
 Zoh *prev = NULL;
 Zoh *p = firstUsed;
 Zoh *newFirstUsed = firstUsed;
 Zoh *np;
 while (p != &Zlast) {
  np = p->np;
  if (((Tip)np & 3) != newMark) {
   np = (Zoh*)((Tip)np & ~3);
   newFirstUsed = np;
   ++ZgcFreeCount;
   free(p);
   p = np;
  } else {
   prev = p;
   p = (Zoh*)((Tip)np & ~3);
   break;
  }
 }
 while (p != &Zlast) {
  np = p->np;
  if (((Tip)np & 3) != newMark) {
   np = (Zoh*)((Tip)np & ~3);
   prev->np = np;
   ++ZgcFreeCount;
   free(p);
   p = np;
  } else {
   prev = p;
   p = (Zoh*)((Tip)np & ~3);
  }
 }
 return newFirstUsed;
}

void ZgcLinkedRun() {
 ZgcMarkTime = Y9Rj();
 newMark = newMark == 1 ? 2 : 1;
 ZgcMarkItems(&Zenv, 1, NULL, NULL);
 ZgcMarkTime = Y9Rj() - ZgcMarkTime;

 ZgcFreeCount = 0;
 ZgcFreeTime = Y9Rj();
 firstUsed = ZgcFree(firstUsed);
 ZgcFreeTime = Y9Rj() - ZgcFreeTime;
 ZgcUseCount -= ZgcFreeCount;
 ZgcStwTime = ZgcMarkTime + ZgcFreeTime;
}

Tc *ZnewStringInit(Ti len, Tc **pp) {
 Ti rlen = len;
 int i;
 int n = ZOH_OFF;
 Tc buf[20];
 Tc *res;
 buf[0] = (rlen & 127);
 rlen >>= 7;
 for (i = 1; rlen > 0; ++i)
 {
  buf[i] = (rlen & 127) + 128;
  rlen >>= 7;
 }
 res = Za(ZOH_OFF + len + i + 1);
 while (i > 0) res[n++] = buf[--i];
 *pp = res + n;
 return res;
}

Tc *ZnewString(Tc *p, Ti len) {
 Tc *pp;
 Tc *res = ZnewStringInit(len, &pp);
 memmove(pp, p, len);
 return res;
}
Tc YCG4[]="lib/ARGModule.zu";
Tc Yt1T[]="lib/EModule.zu";
Tc Yay0[]="lib/IOModule.zu";
Tc Yv00[]="lib/STRINGModule.zu";
Tc Y0dn[]="lib/SYSModule.zu";
Tc YyXk[]="lib/TIMEModule.zu";
Tc Y3zM[]="lib/ZModule.zu";
Tc Y6JX[]="testdir/progs/exeName.zu";
Tc YM2k[]="ARG.Bool.setToDefault/1()";
Tcpos ZcTbl38911[]={
{800,11},
{1,16},
};
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{865,11},
{1,16},
};
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
};
Tc YRbs[]="ARG.StringList.setToDefault/1()";
Tcpos ZcTbl64478[]={
{1046,11},
{1,16},
};
Tc YEFE[]="ARG.Usage.get()";
Tcpos ZcTbl43000[]={
{600,11},
{1,23},
{2,7},
{3,17},
{5,49},
};
Tc YzK9[]="ARG.displayHelp()";
Tcpos ZcTbl29560[]={
{461,5},
{1,7},
{3,5},
{6,35},
{7,5},
{8,19},
{9,7},
{10,33},
{7,5},
{17,5},
{18,7},
{19,9},
{20,9},
{23,7},
{24,21},
{26,26},
{28,9},
{29,11},
{30,21},
{32,21},
{34,15},
{35,21},
{36,11},
{37,21},
{39,21},
{41,15},
{42,21},
{43,11},
{44,21},
{46,21},
{48,15},
{50,9},
{51,11},
{52,21},
{54,21},
{58,23},
{59,9},
{60,16},
{62,9},
{63,11},
{65,13},
{66,15},
{67,22},
{69,15},
{71,18},
{73,16},
{76,9},
{77,16},
{80,9},
{81,11},
{82,13},
{83,13},
{85,13},
{87,11},
{88,13},
{89,13},
{92,11},
{93,24},
{95,11},
{96,24},
{23,7},
{17,5},
{103,10},
};
Tc Yza4[]="ARG.error()";
Tcpos ZcTbl85295[]={
{449,5},
{1,5},
{2,7},
{4,5},
{5,7},
{7,10},
};
Tc Yh2v[]="ARG.init()";
Tcpos ZcTbl82533[]={
{259,5},
{1,7},
{3,20},
{4,19},
{6,7},
{7,9},
{9,7},
{10,9},
{9,7},
{12,7},
{13,9},
{12,7},
{16,17},
{17,22},
{19,7},
{20,9},
{22,16},
{26,22},
{27,9},
{28,11},
{29,11},
{30,21},
{33,11},
{34,21},
{39,13},
{40,37},
{41,15},
{44,17},
{48,34},
{49,15},
{50,23},
{51,26},
{54,20},
{57,15},
{58,22},
{59,17},
{60,19},
{62,30},
{63,27},
{66,26},
{72,37},
{75,34},
{76,15},
{77,23},
{78,26},
{80,17},
{82,24},
{83,19},
{86,21},
{88,23},
{89,36},
{89,36},
{90,37},
{91,32},
{92,28},
{93,33},
{96,47},
{98,29},
{99,32},
{80,17},
{105,15},
{106,17},
{107,27},
{108,22},
{111,13},
{112,15},
{113,17},
{116,15},
{117,17},
{119,15},
{120,15},
{121,30},
{121,30},
{122,17},
{123,19},
{124,35},
{125,40},
{126,35},
{128,21},
{131,33},
{133,27},
{134,17},
{135,19},
{137,36},
{137,36},
{138,31},
{139,17},
{140,19},
{139,17},
{144,17},
{146,24},
{147,19},
{148,21},
{150,25},
{152,17},
{153,31},
{153,31},
{154,19},
{156,35},
{157,21},
};
Tcpos ZcTbl82534[]={
{422,40},
{1,35},
{2,21},
{4,29},
{5,34},
{5,34},
{6,19},
{8,35},
{9,21},
{11,35},
{12,21},
{15,19},
{-144,7},
};
Tc YTJ0[]="ARG.initExeName()";
Tcpos ZcTbl77164[]={
{238,13},
};
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y9VX[]="E.BadValue.writeTo__p2/4()";
Tcpos ZcTbl46171[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y4u_[]="E.BadValue.writeTo__p2/5()";
Tcpos ZcTbl56372[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y_Qs[]="E.DivideByZero.NEW__p3/3()";
Tcpos ZcTbl73471[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YG80[]="E.DivideByZero.writeTo__p3/6()";
Tcpos ZcTbl44130[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YLzZ[]="E.DivideByZero.writeTo__p3/7()";
Tcpos ZcTbl54331[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YgcH[]="E.Exception.writeTo()";
Tcpos ZcTbl49183[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YYT9[]="E.Exception.writeTo/1()";
Tcpos ZcTbl36491[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YTjU[]="E.Exit.writeTo/2()";
Tcpos ZcTbl92163[]={
{191,11},
{1,7},
{2,9},
{3,9},
{5,7},
{6,7},
{7,7},
{8,9},
{9,9},
};
Tc Y9aV[]="E.Exit.writeTo__p1/3()";
Tcpos ZcTbl42983[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y9Cv[]="E.IOError.NEW__p2/2()";
Tcpos ZcTbl48299[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y59h[]="E.IOError.writeTo__p2/4()";
Tcpos ZcTbl89685[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y0Jk[]="E.IOError.writeTo__p2/5()";
Tcpos ZcTbl99886[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YMF2[]="E.Init.writeTo__p2/4()";
Tcpos ZcTbl96107[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5_[]="E.Init.writeTo__p2/5()";
Tcpos ZcTbl6308[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YbzA[]="E.Internal.NEW__p2/2()";
Tcpos ZcTbl78082[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YxLq[]="E.Internal.writeTo__p2/4()";
Tcpos ZcTbl412[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YCbo[]="E.Internal.writeTo__p2/5()";
Tcpos ZcTbl10613[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ycb9[]="E.KeyExists.NEW__p3/3()";
Tcpos ZcTbl85000[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y4SL[]="E.KeyExists.writeTo__p3/6()";
Tcpos ZcTbl14715[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y9iJ[]="E.KeyExists.writeTo__p3/7()";
Tcpos ZcTbl24916[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YAVe[]="E.KeyNotFound.NEW__p3/3()";
Tcpos ZcTbl29585[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Ygil[]="E.KeyNotFound.writeTo__p3/6()";
Tcpos ZcTbl43124[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YlJi[]="E.KeyNotFound.writeTo__p3/7()";
Tcpos ZcTbl53325[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YF6S[]="E.MemoryAccess.NEW__p2/2()";
Tcpos ZcTbl73580[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y4vu[]="E.MemoryAccess.writeTo__p2/4()";
Tcpos ZcTbl25958[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y_4w[]="E.MemoryAccess.writeTo__p2/5()";
Tcpos ZcTbl36159[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y1As[]="E.NilAccess.NEW__p2/2()";
Tcpos ZcTbl32086[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YcIS[]="E.NilAccess.writeTo__p2/4()";
Tcpos ZcTbl35088[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y7gV[]="E.NilAccess.writeTo__p2/5()";
Tcpos ZcTbl45289[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YobA[]="E.OutOfMemory.NEW/3()";
Tcpos ZcTbl80644[]={
{262,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YoZS[]="E.OutOfMemory.writeTo__p2/4()";
Tcpos ZcTbl11217[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YtpQ[]="E.OutOfMemory.writeTo__p2/5()";
Tcpos ZcTbl21418[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y99g[]="E.OutOfRange.NEW__p3/3()";
Tcpos ZcTbl56381[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YqK0[]="E.OutOfRange.writeTo__p3/6()";
Tcpos ZcTbl52608[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ylj3[]="E.OutOfRange.writeTo__p3/7()";
Tcpos ZcTbl62809[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YlgI[]="E.WrongType.writeTo__p2/4()";
Tcpos ZcTbl86818[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YgQK[]="E.WrongType.writeTo__p2/5()";
Tcpos ZcTbl97019[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YEFs[]="E.unhandledException()";
Tcpos ZcTbl15718[]={
{609,23},
{0,23},
{0,23},
};
Tc YgcM[]="E.writeToStderr()";
Tcpos ZcTbl52386[]={
{629,5},
{1,5},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{2,5},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc Yxlj[]="IO.File.print__p1/15()";
Tcpos ZcTbl82618[]={
{230,11},
{1,15},
};
Tc YJ7z[]="IO.File.print__p1/8()";
Tcpos ZcTbl66188[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{483,11},
{3,9},
{4,11},
{6,4},
{31,14},
};
Tc YGQL[]="IO.File.write__p1/9()";
Tcpos ZcTbl59819[]={
{129,11},
{1,15},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc YCbR[]="IO.StringWriter.write/8()";
Tcpos ZcTbl89987[]={
{1359,11},
{1,37},
{3,9},
{4,14},
{5,11},
{6,17},
{8,11},
{10,13},
{12,11},
{13,17},
{24,14},
};
Tc Y1Ue[]="IO.StringWriter.writeChar__p1/1()";
Tcpos ZcTbl49285[]={
{175,11},
{1,7},
{2,9},
{4,15},
};
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
};
Tc Y0Nw[]="IO.concatPath()";
Tcpos ZcTbl68304[]={
{2077,5},
{1,7},
{2,22},
{4,20},
{6,5},
{7,20},
{9,25},
};
Tc YrlY[]="IO.findExe()";
Tcpos ZcTbl64970[]={
{1982,28},
{2,7},
{5,15},
{8,27},
{9,9},
{10,4},
{13,23},
{14,4},
{17,23},
{18,4},
{22,15},
{23,4},
{26,9},
{27,17},
{29,4},
{32,9},
{33,17},
{34,4},
{37,11},
{38,19},
{40,4},
{44,17},
{47,14},
};
Tc Y60W[]="IO.findExeInDirList()";
Tcpos ZcTbl86176[]={
{2038,5},
{1,22},
{2,7},
{3,16},
{0,5},
{6,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc Yuq9[]="IO.isExecutable()";
Tcpos ZcTbl73877[]={
{1729,4},
{8,14},
};
Tc Yofe[]="IO.isPathSep()";
Tcpos ZcTbl79136[]={
{2475,14},
};
Tc YaL5[]="IO.nextPartIndex()";
Tcpos ZcTbl36277[]={
{2481,5},
{1,7},
{2,18},
{0,5},
{5,13},
};
Tc YSYC[]="IO.pastHeadIndex()";
Tcpos ZcTbl11017[]={
{2456,4},
{3,7},
{4,11},
{6,4},
{10,5},
{11,7},
{10,5},
{13,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc YlPR[]="IO.resolve()";
Tcpos ZcTbl45331[]={
{2248,4},
{3,12},
{4,4},
{7,23},
{10,39},
{13,33},
{15,13},
{16,5},
{20,14},
{21,14},
{24,14},
{27,5},
{28,7},
{29,4},
{37,11},
{38,4},
{42,9},
{43,18},
{48,9},
{49,16},
{54,11},
{55,9},
{56,11},
{57,20},
{59,20},
{61,16},
{64,17},
{65,9},
{67,18},
{68,13},
{70,9},
{72,18},
{75,18},
{28,7},
{79,7},
{85,9},
{86,7},
{87,16},
{88,16},
{90,16},
{91,16},
{27,5},
{97,5},
{98,7},
{107,16},
{108,14},
{110,11},
{111,9},
{112,13},
{111,9},
{114,9},
{115,18},
{122,5},
{123,15},
{124,7},
{125,16},
{124,7},
{129,4},
{133,12},
};
Tc YU58[]="IO.tailIndex()";
Tcpos ZcTbl62213[]={
{2391,19},
{1,4},
{4,19},
{5,5},
{6,9},
{8,4},
{11,5},
{12,14},
{14,14},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1168,4},
{13,12},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{3,3},
{1,10},
};
Tc YuIh[]="STRING.replaceAll()";
Tcpos ZcTbl12035[]={
{669,5},
{1,14},
{3,18},
{4,5},
{6,27},
{7,7},
{8,9},
{9,11},
{11,9},
{12,18},
{13,11},
{7,7},
{15,7},
{16,16},
{18,12},
};
Tc YQ54[]="SYS.getEnv()";
Tcpos ZcTbl42323[]={
{56,4},
{4,12},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc Ym1t[]="Z.Pos.ToString()";
Tcpos ZcTbl18187[]={
{83,11},
{1,27},
{2,7},
{3,9},
{5,9},
{7,7},
{8,7},
{9,7},
{10,7},
{11,16},
};
Tcode ZcodeTable[]={
{412,Yt1T,YxLq,ZcTbl412},
{1872,Yay0,YNFk,ZcTbl1872},
{5270,Y6JX,Y9QD,ZcTbl5270},
{6308,Yt1T,YR5_,ZcTbl6308},
{7452,Yay0,Ys1a,ZcTbl7452},
{10613,Yt1T,YCbo,ZcTbl10613},
{11017,Yay0,YSYC,ZcTbl11017},
{11217,Yt1T,YoZS,ZcTbl11217},
{12035,Yv00,YuIh,ZcTbl12035},
{14715,Yt1T,Y4SL,ZcTbl14715},
{15718,Yt1T,YEFs,ZcTbl15718},
{16350,YCG4,Ygzb,ZcTbl16350},
{18187,Y3zM,Ym1t,ZcTbl18187},
{21418,Yt1T,YtpQ,ZcTbl21418},
{24916,Yt1T,Y9iJ,ZcTbl24916},
{25958,Yt1T,Y4vu,ZcTbl25958},
{29560,YCG4,YzK9,ZcTbl29560},
{29585,Yt1T,YAVe,ZcTbl29585},
{32086,Yt1T,Y1As,ZcTbl32086},
{35088,Yt1T,YcIS,ZcTbl35088},
{36159,Yt1T,Y_4w,ZcTbl36159},
{36277,Yay0,YaL5,ZcTbl36277},
{36491,Yt1T,YYT9,ZcTbl36491},
{38911,YCG4,YM2k,ZcTbl38911},
{42323,Y0dn,YQ54,ZcTbl42323},
{42983,Yt1T,Y9aV,ZcTbl42983},
{43000,YCG4,YEFE,ZcTbl43000},
{43124,Yt1T,Ygil,ZcTbl43124},
{44130,Yt1T,YG80,ZcTbl44130},
{45289,Yt1T,Y7gV,ZcTbl45289},
{45331,Yay0,YlPR,ZcTbl45331},
{46171,Yt1T,Y9VX,ZcTbl46171},
{46761,Yay0,YN2v,ZcTbl46761},
{48299,Yt1T,Y9Cv,ZcTbl48299},
{49183,Yt1T,YgcH,ZcTbl49183},
{49285,Yay0,Y1Ue,ZcTbl49285},
{50841,YyXk,YLwM,ZcTbl50841},
{52386,Yt1T,YgcM,ZcTbl52386},
{52608,Yt1T,YqK0,ZcTbl52608},
{53325,Yt1T,YlJi,ZcTbl53325},
{53377,Yt1T,Yp81,ZcTbl53377},
{54331,Yt1T,YLzZ,ZcTbl54331},
{56372,Yt1T,Y4u_,ZcTbl56372},
{56381,Yt1T,Y99g,ZcTbl56381},
{59819,Yay0,YGQL,ZcTbl59819},
{60593,Yt1T,Y5LR,ZcTbl60593},
{62213,Yay0,YU58,ZcTbl62213},
{62809,Yt1T,Ylj3,ZcTbl62809},
{64478,YCG4,YRbs,ZcTbl64478},
{64531,Yay0,YrJP,ZcTbl64531},
{64970,Yay0,YrlY,ZcTbl64970},
{66188,Yay0,YJ7z,ZcTbl66188},
{66501,YCG4,YPPv,ZcTbl66501},
{68304,Yay0,Y0Nw,ZcTbl68304},
{72007,Yay0,YzQB,ZcTbl72007},
{73471,Yt1T,Y_Qs,ZcTbl73471},
{73580,Yt1T,YF6S,ZcTbl73580},
{73877,Yay0,Yuq9,ZcTbl73877},
{77164,YCG4,YTJ0,ZcTbl77164},
{78082,Yt1T,YbzA,ZcTbl78082},
{79136,Yay0,Yofe,ZcTbl79136},
{80644,Yt1T,YobA,ZcTbl80644},
{81798,YCG4,YMnk,ZcTbl81798},
{82533,YCG4,Yh2v,ZcTbl82533},
{82534,YCG4,Yh2v,ZcTbl82534},
{82618,Yay0,Yxlj,ZcTbl82618},
{84870,Yay0,Y_pS,ZcTbl84870},
{85000,Yt1T,Ycb9,ZcTbl85000},
{85295,YCG4,Yza4,ZcTbl85295},
{86176,Yay0,Y60W,ZcTbl86176},
{86206,YCG4,YZNA,ZcTbl86206},
{86818,Yt1T,YlgI,ZcTbl86818},
{87235,Yt1T,YR5m,ZcTbl87235},
{89685,Yt1T,Y59h,ZcTbl89685},
{89987,Yay0,YCbR,ZcTbl89987},
{92163,Yt1T,YTjU,ZcTbl92163},
{94823,Yay0,Yj_J,ZcTbl94823},
{96107,Yt1T,YMF2,ZcTbl96107},
{97019,Yt1T,YgQK,ZcTbl97019},
{99886,Yt1T,Y0Jk,ZcTbl99886},
};

#ifdef SIGSEGV
void Zdeadly(int nr) {
 ZthrowDeadly(nr);
}
#endif

void ZthreadGC() {
}
Ti ZstringSizePtr(Tc *s, Tc **dp) {
 Tc *p;
 Ti len;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {  /* be quick for short string */
  *dp = p + 1;
  return *p;
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 *dp = p + 1;
 return (len << 7) + *p;
}

void ZgcRun() {
 ZgcLinkedRun();
}

void ZthrowCstringNil(char *text) {
 YvdV(NULL, Zstr(text));
}

void ZthrowThisNil() {
 YvdV(NULL, Zstr("THIS is NIL"));
}

void ZthrowCstringInit(char *text) {
 Y3w6(Zstr(text));
}

void ZthrowOutOfMemory(Ti size) {
 Y1KV(size);
}

void ZthrowCstringOutOfRange(Ti i, char *text) {
 Y6NT(i, Zstr(text));
}

void ZthrowCstringBadValue(char *msg) {
 Yaez(Zstr(msg));
}

void ZthrowDeadly(int nr) {
 YE93((Ti)nr);
}

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
}

Tc *ZintAsString(Ti n) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  Tc *p = Za(ZOH_OFF + 3);
  p[ZOH_OFF] = 1;
  p[ZOH_OFF + 1] = n;
  p[ZOH_OFF + 2] = 0;
  return p;
 }
 if (n <= 0x7ff) {
  Tc *p = Za(ZOH_OFF + 4);
  p[ZOH_OFF] = 2;
  p[ZOH_OFF + 1] = 0xc0 + ((unsigned)n >> 6);
  p[ZOH_OFF + 2] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 3] = 0;
  return p;
 }
 if (n <= 0xffff) {
  Tc *p = Za(ZOH_OFF + 5);
  p[ZOH_OFF] = 3;
  p[ZOH_OFF + 1] = 0xe0 + ((unsigned)n >> 12);
  p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  p[ZOH_OFF + 3] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 4] = 0;
  return p;
 }
 Tc *p = Za(ZOH_OFF + 6);
 p[ZOH_OFF] = 4;
 p[ZOH_OFF + 1] = 0xf0 + ((unsigned)n >> 18);
 p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 p[ZOH_OFF + 3] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 p[ZOH_OFF + 4] = 0x80 + (n & 0xef);
 p[ZOH_OFF + 5] = 0;
 return p;
}

int Zchar2stringBuf(Ti n, Tc *buf) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  buf[0] = n;
  buf[1] = 0;
  return 1;
 }
 if (n <= 0x7ff) {
  buf[0] = 0xc0 + ((unsigned)n >> 6);
  buf[1] = 0x80 + (n & 0x3f);
  buf[2] = 0;
  return 2;
 }
 if (n <= 0xffff) {
  buf[0] = 0xe0 + ((unsigned)n >> 12);
  buf[1] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  buf[2] = 0x80 + (n & 0x3f);
  buf[3] = 0;
  return 3;
 }
 buf[0] = 0xf0 + ((unsigned)n >> 18);
 buf[1] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 buf[2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 buf[3] = 0x80 + (n & 0xef);
 buf[4] = 0;
 return 4;
}

/* concat string */
Tc *ZcS(Tc *l, Tc *ri) {
 Tc *l_p;
 Ti l_len;
 Tc *r_p;
 Ti r_len;
 Ti len;
 Tc *pp;
 Tc *r;
 if (l == NULL) {l_len = 3; l_p = (Tc*)"NIL";}
 else l_len = ZstringSizePtr(l, &l_p);
 if (ri == NULL) {r_len = 3; r_p = (Tc*)"NIL";}
 else r_len = ZstringSizePtr(ri, &r_p);
 len = l_len + r_len;
 r = ZnewStringInit(len, &pp);
 memmove(pp, l_p, l_len);
 memmove(pp + l_len, r_p, r_len);
 return r;
}

/* concat string */
Tc *ZcS3(Tc *s1, Tc *s2, Tc *s3) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 len = len1 + len2 + len3;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 return r;
}

/* concat string */
Tc *ZcS5(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Tc *p4;
 Ti len4;
 Tc *p5;
 Ti len5;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 if (s4 == NULL) {len4 = 3; p4 = (Tc*)"NIL";}
 else len4 = ZstringSizePtr(s4, &p4);
 if (s5 == (Tc*)1) len5 = 0;
 else if (s5 == NULL) {len5 = 3; p5 = (Tc*)"NIL";}
 else len5 = ZstringSizePtr(s5, &p5);
 len = len1 + len2 + len3 + len4 + len5;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 memmove(pp + len1 + len2 + len3, p4, len4);
 if (s5 != (Tc*)1) memmove(pp + len1 + len2 + len3 + len4, p5, len5);
 return r;
}

Tr Zao(void *ptr, Tc **table, Ti type) {
 Tr tr;
 tr.ptr = ptr;
 tr.table = table;
 tr.type = type;
 return tr;
}

/* fill not-allocated object reference */
Tr *Znao(Tr *p, void *ptr, Tc **table, Ti type) {
 p->ptr = ptr;
 p->table = table;
 p->type = type;
 return p;
}

Tr ZconvertZioref(Tr orig, Tc ***table, int type, int maxType, Ti pos) {
 Tr p;
 if (orig.ptr == NULL) p.ptr = NULL;
 else {
  if (orig.type < type || orig.type >= maxType) YTuG(pos);
  p.ptr = orig.ptr;
  p.type = orig.type - type;
  p.table = table[p.type];
 }
 return p;
}

void *Zio(int type, Ti pos, Tr *p) {
 void *r;
 if (p == NULL || p->ptr == NULL) r = NULL;
 else {
  if (p->type != type) YTuG(pos);
  r = p->ptr;
 }
 return r;
}

void *Znio(int type, Ti pos, Tr tr) {
 void *r;
 if (tr.ptr == NULL) r = NULL;
 else {
  if (tr.type != type) YTuG(pos);
  r = tr.ptr;
 }
 return r;
}

void Zexit(YkxB *pos, Ti val) {
 beforeExit();
 exit((int)val);
}

Ti ZChar2ByteIdx(Tc *p, Ti len, Ti charIdx) {
 Ti idx = 0;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == len) break;
  ++idx;
  if ((p[idx - 1] & 0x80) != 0) {
    while ((p[idx] & 0xc0) == 0x80)
      ++idx;
  }
  ++count;
 }
 return idx;
}

Ti ZfromChar(Tc *p) {
 if (*p <= 0x7f)
  return *p;
 if ((*p & 0xe0) == 0xc0)
  return ((p[0] & 0x1f) << 6) + (p[1] & 0x3f);
 if  ((*p & 0xf0) == 0xe0)
  return ((p[0] & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
 return ((p[0] & 0x07) << 18) + ((p[1] & 0x3f) << 12) + ((p[2] & 0x3f) << 6) + (p[3] & 0x3f);
}

Ti ZstringGetChar(Tc *sv, Ti idx) {
 Ti i;
 Tc *p;
 Ti len;
 Ti r;
 if (sv == NULL) ZthrowCstringNil("using [] on NIL");
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 i = ZChar2ByteIdx(p, len, idx);
 if (i >= len) ZthrowCstringOutOfRange(idx, "index too big");
 r = ZfromChar(p + i);
 return r;
}

Ti Zutf8size(Tc *sp, Ti len) {
 Tc *p = (Tc*)sp;
 Tc *pend = p + len;
 Ti clen = 0;
 while (p < pend) {
  if ((*p & 0xc0) != 0x80) ++clen;
  ++p;
 }
 return clen;
}

Ti ZstringSize(Tc *s) {
 Tc *p;
 Ti r;
 Ti len;
 if (s == NULL) return 0;
 len = ZstringSizePtr(s, &p);
 r = Zutf8size(p, len);
 return r;
}

Ti ZbyteStringSize(Tc *s) {
 Tc *p;
 Ti len;
 if (s == NULL) return 0;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {
  return *p;  /* be quick for short string */
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 return (len << 7) + *p;
}

Tc *Zint2string(Ti n) {
 char buf[30];
 char *p;
 int len;
 sprintf(buf, ZINT_FORMAT, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

char *ZgetCstring(Tc *s) {
 Tc *p;
 if (s == NULL) return NULL;
 p = s + ZOH_OFF;
 while ((*p & 0x80) != 0) ++p;
 return (char *)p + 1;
}

Tc *ZstringToLowerAscii(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0)
  *d++ = tolower(*s++);
 *d = 0;
 return (Tc*)r;
}

Tc *ZstringToLower(Tc *ss) {
 return ZstringToLowerAscii(ss);
}

void ZforRangeNew(Ti start, Ti last, int until, Ti step, Tfr *s) {
 s->idx = start;
 if (until)
  s->last = last - (step > 0 ? 1 : -1);
 else
  s->last = last;
 s->step = step;
}
void ZforRangeGetInt(Tfr *s, Ti *p) {
 *p = s->idx;
}
int ZforRangeContInt(Tfr *s) {
 return s->step > 0 ? (s->idx <= s->last) : (s->idx >= s->last);
}
void ZforRangeNextInt(Tfr *s, Ti *p) {
 s->idx += s->step;
 ZforRangeGetInt(s, p);
}

void ZthrowIobject(Tr eo) {
 YxIS(eo);
}
int ZstringCmp(Tc *s1, Tc *s2) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 int r;
 if (s1 == NULL || s2 == NULL) {
  if (s1 == NULL && s2 == NULL) r = 0;
  else r = 1;
  goto end;
 }
 if (s1[ZOH_OFF] != s2[ZOH_OFF]) {
  r = 1;
  goto end;
 }
 len1 = ZstringSizePtr(s1, &p1);
 len2 = ZstringSizePtr(s2, &p2);
 if (len1 == len2) {
  r = memcmp(p1, p2, len1);
  goto end;
 }
 r = 1;
end:
 return r;
}

Ti ZChar2ByteIdxEnd(Tc *p, Ti len, Ti charIdx) {
 Ti idx = len;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == 0) return -1;
  --idx;
  while (idx > 0 && (p[idx] & 0xc0) == 0x80)
    --idx;
  ++count;
 }
 return idx;
}

Ti ZstringFindLen(Tc *big, Ti biglen, Tc *small, Ti smalllen) {
 Ti i;
 Ti ci = 0;
 for (i = 0; i <= biglen - smalllen; ++ci) {
  if (memcmp(big + i, small, smalllen) == 0)
   return ci;
  ++i;
  while ((big[i] & 0xc0) == 0x80 && i < biglen)
   ++i;
 }
 return -1;
}

Ti ZstringFind(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Ti r;
 if (big == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  if (small == NULL) ZthrowCstringNil("using find() with NIL argument");
  biglen = ZstringSizePtr(big, &bigp);
  smalllen = ZstringSizePtr(small, &smallp);
  r = ZstringFindLen(bigp, biglen, smallp, smalllen);
 }
 return r;
}

Ti ZptrFindChar2(Tc *s, Ti slen, Ti c, Ti low) {
 Tc *p = s;
 Ti idx = 0;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0 && idx >= low) {
   return idx;
  }
  p += charlen;
  ++idx;
 }
 return -1;
}

Ti ZstringFindChar2(Tc *s, Ti c, Ti low, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindChar2(p, len, c, low);
 }
 return r;
}

Ti ZstringFindChar(Tc *s, Ti c, int dn) {
 return ZstringFindChar2(s, c, 0, dn);
}

Tb ZstringStartsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using startsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using startsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp, smallp, smalllen) == 0;
end:
 return r;
}

Tb ZstringEndsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using endsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using endsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp + biglen - smalllen, smallp, smalllen) == 0;
end:
 return r;
}

Ti ZptrFindLastChar2(Tc *s, Ti slen, Ti c, Ti high) {
 Tc *p = s;
 Ti idx = 0;
 Ti best = -1;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0 && idx <= high; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0)
   best = idx;
  p += charlen;
  ++idx;
 }
 return best;
}

Ti ZstringFindLastChar(Tc *s, Ti c, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using findLast() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindLastChar2(p, len, c, len);
 }
 return r;
}

Tl *ZstringSplitLen(Tc *pss, Ti len, Tc *m) {
 Tl *head = ZnewList(&string__T, 0);
 if (len > 0) {
  Tc *mp;
  Ti mlen = ZstringSizePtr(m, &mp);
  Tc *ps;
  Tc *pe;

  for (ps = pss; ; ps = pe + mlen) {
   int nlen;
   /* TODO: handle NULL byteString */
   pe = (Tc*)strstr((char *)ps, (char *)mp);
   if (pe == NULL) {
    nlen = len - (ps - pss);
   } else {
    nlen = pe - ps;
   }
   ZLa(head, -1, (Tz)(void*)ZnewString(ps, nlen));
   if (pe == NULL) break;
  }
 }
 return head;
}

Tl *ZstringSplit(Tc *b, Tc *m, int dn) {
 Tc *p;
 Ti len;
 Tl *r;
 if (b == NULL) {
  if (!dn) ZthrowCstringNil("using split() on NIL");
  r = NULL;
 } else {
  if (m == NULL) ZthrowCstringNil("split() argument is NIL");
  len = ZstringSizePtr(b, &p);
  r = ZstringSplitLen(p, len, m);
 }
 return r;
}

Tc *ZstringSlice(Tc *sv, Ti start, Ti end, int dn) {
 Ti is;
 Ti ie;
 Tc *p;
 Ti len;
 Tc *r;
 if (sv == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("using slice() on NIL");
 }
 len = ZstringSizePtr(sv, &p);
 is = start < 0 ? ZChar2ByteIdxEnd(p, len, -start) : ZChar2ByteIdx(p, len, start);
 ie = end < 0 ? ZChar2ByteIdxEnd(p, len, -end - 1) - 1 : ZChar2ByteIdx(p, len, end + 1) - 1;
 if (is < 0)
  is = 0;
 if (ie < 0 || ie < is) r = ZnewString((Tc*)"", 0);
 else r = ZnewString(p + is,  ie - is + 1);
 return r;
}

Ti ZptrToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char*)s;
 if ((*p < '0' || *p > '9') && *p != '-') {
  if (t == 1) ZthrowCstringBadValue("toInt(): argument does not start with a digit or -");
  return def;
 }
 sscanf(p, ZINT_FORMAT, &r);
 return r;
}

Ti ZstringToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using toInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrToInt(s, t, def);
 return r;
}

int ZcopyItems(Tt *toType, int toSize, void *toPtr, Ti toOff, Tt *fromType, int fromSize, void *fromPtr, Ti fromOff, Ti len) {
 Ti i;
 if (toType == fromType || (toType->nr >= 100 && fromType->nr >= 100)) {
  memmove((char*)toPtr + toOff * toSize, (char*)fromPtr + fromOff * fromSize, len * toSize);
  return 1;
 }
 if (fromType->nr >= 100 || toType->nr >= 100) return 0;
 for (i = 0; i < len; ++i) {
  Ti iv;
  Tf fv;
  switch (fromType->nr) {
   case 0:
   case 24:
   case 25:
    iv = ((Ti*)fromPtr)[fromOff + i]; fv = iv; break;
   case 1:
    iv = ((char*)fromPtr)[fromOff + i]; fv = iv; break;
   case 2:
    iv = ((Ti16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 3:
    iv = ((Ti32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 10:
    iv = ((Tu*)fromPtr)[fromOff + i]; fv = iv; break;
   case 11:
    iv = ((Tc*)fromPtr)[fromOff + i]; fv = iv; break;
   case 12:
    iv = ((Tu16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 13:
    iv = ((Tu32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 21:
   case 22:
   case 23:
    iv = ((int*)fromPtr)[fromOff + i]; fv = iv; break;
   case 80:
   case 82:
   case 83:
    fv = ((Tf*)fromPtr)[fromOff + i]; iv = fv; break;
   case 81:
    fv = ((Tf32*)fromPtr)[fromOff + i]; iv = fv; break;
  }
  switch (toType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    ((Ti*)toPtr)[toOff + i] = iv; break;
   case 1:
   case 11:
    ((char*)toPtr)[toOff + i] = iv; break;
   case 2:
   case 12:
    ((Ti16*)toPtr)[toOff + i] = iv; break;
   case 3:
   case 13:
    ((Ti32*)toPtr)[toOff + i] = iv; break;
   case 21:
   case 22:
   case 23:
    ((int*)toPtr)[toOff + i] = iv; break;
   case 80:
   case 82:
   case 83:
    ((Tf*)toPtr)[toOff + i] = fv; break;
   case 81:
    ((Tf32*)toPtr)[toOff + i] = fv; break;
  }
 }
 return 1;
}
Ta *ZArrayInit(Ta *head, Tt *itemType, int itemSize, Ti size) {
 head->ptr = ZaOff(itemSize * size);
 head->alloced = head->ptr - ZOH_OFF;
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ta *ZnewArray(Tt *itemType, int itemSize, Ti size) {
 Ta *head;
 size_t extra = size * itemSize;
 if (extra > 100) extra = 0;
 head = Za(sizeof(Ta) + extra);
 if (extra == 0) {
  head->ptr = ZaOff(itemSize * size);
  head->alloced = head->ptr - ZOH_OFF;
 } else head->ptr = head + 1;
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ti ZArraySize(Ta *head) {
 Ti r;
 if (head == NULL) r = 0;
 else r = head->size[0];
 return r;
}

Ta *Zas(Ta *head, void *vals, int type, Ti offset) {
 int len;
 int i;
 if (head == NULL) ZthrowCstringNil("Invoking set() on NIL array");
 if (type == 0) {
  /* vals is a byteString */
  Tc *p;
  len = ZstringSizePtr(vals, &p);
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  if (head->itemSize == 1) {
   memmove(((Tc*)head->ptr) + offset, p, len);
  } else if (head->itemSize == sizeof(Te)) {
   for (i = 0; i < len; ++i) ((Te*)head->ptr)[i + offset] = p[i];
  } else {
   for (i = 0; i < len; ++i) ((Ti*)head->ptr)[i + offset] = p[i];
  }
 } else if (type == 1) {
  /* vals is an array */
  Ta *from = vals;
  len = from->size[0];
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->ptr, 0, len);

 } else {
  /* vals is a list */
  Tl *from = (Tl*)vals;
  Ti count = from->itemCount;
  if (count > offset + head->size[0]) count = offset + head->size[0];
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->items, from->empty, count);
 }
 return head;
}

Ta *ZarrayResize(Ta *head, int bytes, Ti size) {
 if (head == NULL) ZthrowCstringNil("Invoking resize() on NIL array");
 if (head->ptr == head + 1) {
  head->ptr = ZaOff(bytes * size);
  memmove(head->ptr, head + 1, size > head->size[0] ? bytes * head->size[0] : bytes * size);
 } else head->ptr = ZranOff(head->ptr, bytes * head->size[0], bytes * size);
 head->alloced = head->ptr - ZOH_OFF;
 head->size[0] = size;
 return head;
}

Ti ZListFindIdx(Tl *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("Accessing NIL list");
 if (idx < 0) {
  Ti n = head->itemCount + idx;
  if (n < 0) return n;
  return n + head->empty;
 }
 if (idx >= head->itemCount) return -1;
 return idx + head->empty;
}

void ZListSetType(Tl* head, Tt *itemType) {
 head->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating list without type");
 switch (itemType->nr) {
  case 0:
  case 10:
  case 80:
  case 82:
  case 83:
  case 24:
  case 25:
   head->itemSize = 8; break;
  case 1:
  case 11:
   head->itemSize = 1; break;
  case 12:
  case 2:
   head->itemSize = 2; break;
  case 3:
  case 13:
  case 81:
   head->itemSize = 4; break;
  case 21:
  case 22:
  case 23:
   head->itemSize = sizeof(int); break;
  case 391:
   head->itemSize = sizeof(Tr); break;
  default:
   head->itemSize = sizeof(void*); break;
 }
}

Tl *ZnewList(Tt *itemType, Ti size) {
 int alloc = size > ((itemType->nr == 1 || itemType->nr == 11) ? 64 : 8);
 int extraSize = itemType != NULL && itemType->nr == 391 ? 8 * sizeof(Tr) : 64;
 Tl *head = Za(sizeof(Tl) + (alloc ? 0 : extraSize));
 ZListSetType(head, itemType);
 if (alloc) {
  head->items = ZaOff(head->itemSize * size);
  head->alloced = (void*)head->items - ZOH_OFF;
  head->space = size;
 } else {
  head->items = (void**)(head + 1);
  head->space = extraSize / head->itemSize;
 }
 return head;
}
void ZListGrow(Tl *head, Ti count) {
 Ti newsize = head->empty + head->itemCount + count;
 if (newsize <= head->space) return;
 if (newsize < 100) {
  newsize += (newsize >> 2) + 7;
 } else {
  newsize += newsize >> 3;
 }
 if (head->items == (void**)(head + 1)) {
  head->items = ZaOff(head->itemSize * newsize);
  memmove(head->items, head + 1, head->itemSize * head->itemCount);
 } else {
  head->items = ZranOff(head->items, head->itemSize * head->space, head->itemSize * newsize);
 }
 head->alloced = (void*)head->items - ZOH_OFF;
 head->space = newsize;
}

Tl *ZLa(Tl *head, Ti after, Tz val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti*)head->items) + idx + 1, ((Ti*)head->items) + idx, head->itemSize * len);
   ((Ti*)head->items)[idx] = val.ival;
   break;
  case 1:
  case 11:
   if (len > 0 && idx >= head->empty)
    memmove(((char*)head->items) + idx + 1, ((char*)head->items) + idx, head->itemSize * len);
   ((char*)head->items)[idx] = val.ival;
   break;
  case 12:
  case 2:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti16*)head->items) + idx + 1, ((Ti16*)head->items) + idx, head->itemSize * len);
   ((Ti16*)head->items)[idx] = val.ival;
   break;
  case 3:
  case 13:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti32*)head->items) + idx + 1, ((Ti32*)head->items) + idx, head->itemSize * len);
   ((Ti32*)head->items)[idx] = val.ival;
   break;
  case 21:
  case 22:
  case 23:
   if (len > 0 && idx >= head->empty)
    memmove(((int*)head->items) + idx + 1, ((int*)head->items) + idx, head->itemSize * len);
   ((int*)head->items)[idx] = val.ival;
   break;
  case 80:
  case 82:
  case 83:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf*)head->items) + idx + 1, ((Tf*)head->items) + idx, head->itemSize * len);
   ((Tf*)head->items)[idx] = val.fval;
   break;
  case 81:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf32*)head->items) + idx + 1, ((Tf32*)head->items) + idx, head->itemSize * len);
   ((Tf32*)head->items)[idx] = val.fval;
   break;
  default:
   if (len > 0 && idx >= head->empty)
    memmove(head->items + idx + 1, head->items + idx, head->itemSize * len);
   head->items[idx] = val.ptr;
   break;
 }
 ++head->itemCount;
 return head;
}
Tl *ZLap(Tl *head, Tz val) {
 return ZLa(head, -1, val);
}

Tl *ZLaIobj(Tl *head, Ti after, Tr val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 if (len > 0 && idx >= head->empty)
  memmove((Tr*)head->items + idx + 1, (Tr*)head->items + idx, head->itemSize * len);
 ((Tr*)head->items)[idx] = val;
 ++head->itemCount;
 return head;
}
Tl *ZLapIobj(Tl *head, Tr val) {
 return ZLaIobj(head, -1, val);
}
Ti ZListSize(Tl *head) {
 if (head == NULL) return 0;
 return head->itemCount;
}

Ti ZListGetInt(Tl *head, Ti idx) {
 Ti r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 10:
    r = (Ti)((Tu*)head->items)[n]; break;
   case 1:
    r = ((char*)head->items)[n]; break;
   case 11:
    r = (Ti)((Tc*)head->items)[n]; break;
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 12:
    r = (Ti)((Tu16*)head->items)[n]; break;
   case 3:
    r = ((Ti32*)head->items)[n]; break;
   case 13:
    r = (Ti)((Tu32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

Tf ZListGetFloat(Tl *head, Ti idx) {
 Tf r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 80:
   case 82:
   case 83:
    r = ((Tf*)head->items)[n]; break;
   case 81:
    r = (Tf)((Tf32*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetPtr(Tl *head, Ti idx) {
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) return head->items[n];
 return NULL;
}

static int stringCmp(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p1p, p2p, len);
 if (r == 0) return len1 - len2;
 return r;
}
static int stringCmpR(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p2p, p1p, len);
 if (r == 0) return len2 - len1;
 return r;
}
Tl *ZstringListSort(Tl *head, int asc) {
 int i = 0;
 if (head == NULL) ZthrowCstringNil("Invoking sort() on NIL list");
 qsort(head->items + head->empty, head->itemCount, sizeof(Tc*), asc ? stringCmp : stringCmpR);
 return head;
}

int ZforListIntCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Ti*)tfl->valp = ZListGetInt(l, i);
 ++tfl->i;
 return 1;
}

int ZforListPtrCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(char**)tfl->valp = l->items[i + l->empty];
 ++tfl->i;
 return 1;
}

int ZDeqNr(Tz *l, Tz *r) {
 return l->ival == r->ival;
}
int ZDeqFloat(Tz *l, Tz *r) {
 return l->fval == r->fval;
}
int ZDeqStr(Tz *l, Tz *r) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 if (r->ptr != NULL) {
  len1 = ZstringSizePtr(l->ptr, &p1);
  len2 = ZstringSizePtr(r->ptr, &p2);
  if (len1 == len2) return memcmp(p1, p2, len1) == 0;
 }
 return 0;
}
int ZDeqRef(Tz *l, Tz *r) {
 return l->ptr == r->ptr;
}
int ZDeqIobj(Tr *l, Tz *r) {
 return l->ptr == ((Tr*)r->ptr)->ptr;
}

Td *ZDictHead(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 d->array = d->smallArray;
 d->mask = HT_INIT_SIZE - 1;
 d->keyType = keyType;
 d->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating dict without item type");
 if (keyType == NULL) ZthrowCstringNil("Creating dict without key type");
 if (ordered) d->type = DTYPE_ORDERED;
 if (keyType->nr < 80) d->eqfunc = (int (*)(void*, Tz*))ZDeqNr;
 else if (keyType->nr < 100) d->eqfunc = (int (*)(void*, Tz*))ZDeqFloat;
 else if (keyType == &iobj__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqIobj;
 else if (keyType == &string__T || keyType == &byteString__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqStr;
 else d->eqfunc = (int (*)(void*, Tz*))ZDeqRef;
 return d;
}
Td *ZDictInit(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 memset(d, 0, sizeof(Td));
 d->np = &Znoalloc;
 ZDictHead(d, keyType, itemType, ordered);
 return d;
}
Td *ZnewDict(Tt *keyType, Tt *itemType, Tb ordered) {
 return ZDictHead(Za(sizeof(Td)), keyType, itemType, ordered);
}

Zhashtype ZDictHash(Tt *keyType, Tz key) {
 Zhashtype hash;
 void *ptr;
 if (keyType->nr < 80) return (Zhashtype)key.ival;
 if (keyType->nr < 100) return (Zhashtype)key.fval;
 if (keyType == &iobj__T) {
  ptr = ((Tr*)key.ptr)->ptr;
 } else {
  ptr = key.ptr;
 }
 if (ptr == NULL) ZthrowCstringNil("dict key is NIL");
 if (keyType == &string__T || keyType == &byteString__T) {
  Tc *p;
  int l = ZstringSizePtr(key.ptr, &p);
  if (l == 0) {
   hash = 0;
  } else {
   hash = *p;
   while (--l > 0) {
    hash = hash * 101 + *++p;
   }
  }
 } else {
  Tip k = (Tip)ptr;
  int l = sizeof(Tc*);
  hash = k & 0xff;
  while (--l > 0) {
   k >>= 8;
   hash = hash * 101 + (k & 0xff);
  }
 }
 return hash;
}

void ZthrowIntKeyNotFound(Tz key, Tc *msg) {
  Yxmk(key.ival, msg);
}

void ZthrowStringKeyNotFound(Tz key, Tc *msg) {
  Y5LT(key.ptr, msg);
}

void ZthrowIntKeyExists(Tz key, Tc *msg) {
  YL9Z(key.ival, msg);
}
void ZthrowStringKeyExists(Tz key, Tc *msg) {
  YEeX(key.ptr, msg);
}

/* #define DICT_DEBUG 1 */

CDictItem *ZDictLookup(Td *d, Tz key, Zhashtype hash)
{
 Zhashtype  perturb;
 CDictItem  *freeitem;
 int        idx = (int)(hash & d->mask);
 CDictItem  *di = &d->array[idx];
 if (di->flags == 0) return di;
 if (di->flags == CDI_FLAG_DEL) freeitem = di;
 else if (di->hash == hash && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) {
  return di;
 } else {
  freeitem = NULL;
 }

 for (perturb = hash; ; perturb >>= PERTURB_SHIFT)
 {
  idx = (int)((idx << 2) + idx + perturb + 1);
  di = &d->array[idx & d->mask];
  if (di->flags == 0) return freeitem == NULL ? di : freeitem;
  if (di->hash == hash && di->flags != CDI_FLAG_DEL && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) return di;
  if (di->flags == CDI_FLAG_DEL && freeitem == NULL) freeitem = di;
 }
}

void ZDictResize(Td *d, int minitems) {
 CDictItem temparray[HT_INIT_SIZE];
 CDictItem *oldarray, *newarray;
 CDictItem *olditem, *newitem, *nextitem;
 int newi;
 int todo;
 Zhashtype oldsize, newsize;
 Zhashtype minsize;
 Zhashtype newmask;
 Zhashtype perturb;

#ifdef DICT_DEBUG
 printf("size: %lu, filled: %lu, used: %lu\n",
           d->mask + 1, d->filled, d->used);
#endif

 if (minitems == 0) {
  if (d->filled < HT_INIT_SIZE - 1 && d->array == d->smallArray) {
#ifdef DICT_DEBUG
   printf("small array not full\n");
#endif
   return;
  }
  oldsize = d->mask + 1;
  if (d->filled * 3 < oldsize * 2 && d->used > oldsize / 5) {
#ifdef DICT_DEBUG
   printf("size OK\n");
#endif
   return;
  }
  if (d->used > 1000) minsize = d->used * 2;
  else minsize = d->used * 4;
 } else {
  if ((Zhashtype)minitems < d->used) minitems = (int)d->used;
  minsize = minitems * 3 / 2;
 }

 newsize = HT_INIT_SIZE;
 while (newsize < minsize) {
  newsize <<= 1;
  if (newsize == 0) {
   ZthrowInternal(Zstr("ZDictResize"));
   return;
  }
 }

#ifdef DICT_DEBUG
 printf("resizing from %lu to %lu\n", d->mask + 1, newsize);
#endif

 if (newsize == HT_INIT_SIZE) {
  newarray = d->smallArray;
  if (d->array == newarray) {
   memmove(temparray, newarray, sizeof(temparray));
   oldarray = temparray;
  } else
   oldarray = d->array;
  memset(newarray, 0, (size_t)(sizeof(CDictItem) * newsize));
 } else {
  newarray = (CDictItem *)ZaOff((sizeof(CDictItem) * newsize));
  d->alloced = (void *)newarray - ZOH_OFF;
  oldarray = d->array;
 }

 newmask = newsize - 1;
 todo = (int)d->used;
 for (olditem = oldarray; todo > 0; ++olditem)
  if (olditem->flags & CDI_FLAG_USED) {
   newi = (int)(olditem->hash & newmask);
   newitem = &newarray[newi];
   if (newitem->flags != 0)
    for (perturb = olditem->hash; ; perturb >>= PERTURB_SHIFT) {
     newi = (int)((newi << 2) + newi + perturb + 1);
     newitem = &newarray[newi & newmask];
     if (newitem->flags == 0) break;
    }
   *newitem = *olditem;
   if (d->type & DTYPE_ORDERED) {
    olditem->lprev = newitem;
   }
   --todo;
  }
 if ((d->type & DTYPE_ORDERED) && d->first) {
  olditem = d->first;
  newitem = olditem->lprev;
  newitem->lprev = NULL;
  d->first = newitem;
  while (olditem->lnext) {
   olditem = olditem->lnext;
   nextitem = olditem->lprev;
   newitem->lnext = nextitem;
   newitem->lnext->lprev = newitem;
   newitem = nextitem;
  }
  newitem->lnext = NULL;
  d->last = newitem;
 }

 d->array = newarray;
 d->mask = newmask;
 d->filled = d->used;
}

/* "ow" is the overwrite flag.  When zero it's not allowed to overwrite an
 * existing entry. */
Td *ZDictAdd(int ow, Td *d, Tz key, Tz value) {
 Zhashtype hash = ZDictHash(d->keyType, key);
 CDictItem *di = ZDictLookup(d, key, hash);
#ifdef DICT_DEBUG
 if (d->keyType->nr >= 100)
   printf("Adding item %s\n", (Tc*)key.ptr);
 else
   printf("Adding item %lld\n", key.ival);
 if (key.ptr != NULL
     && (strcmp(key.ptr, "ENUM") == 0
         || strcmp(key.ptr, "Equal") == 0
         || strcmp(key.ptr, "EXIT") == 0))
   dumpdict(d);
#endif
 if (di->flags == 0 || di->flags == CDI_FLAG_DEL || ow) {
  if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
   ++d->used;
   if (di->flags == 0)
    ++d->filled;
  }
  di->hash = hash;
  if (d->keyType->nr == 391) {
   di->iokey = *(Tr*)key.ptr;
  } else if (d->keyType->nr >= 100) {
   if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
    di->key = key;
   }
  } else di->key = key;
  if (d->itemType->nr == 391)
   di->ioitem = *(Tr*)value.ptr;
  else
   di->item = value;
  di->flags = CDI_FLAG_USED;
  if (d->type & DTYPE_ORDERED) {
   di->lprev = d->last;
   if (d->last) d->last->lnext = di;
   else d->first = di;
   d->last = di;
   di->lnext = NULL;
  }

  ZDictResize(d, 0);
 } else {
  if (d->keyType->nr >= 100) ZthrowStringKeyExists(key, Zstr("dict.add(): "));
  ZthrowIntKeyExists(key, Zstr("dict.add(): "));
 }
 return d;
}
Td *ZDictAddIobjTz(int ow, Td *d, Tr key, Tz value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, value);
}
Td *ZDictAddTzIobj(int ow, Td *d, Tz key, Tr value) {
 return ZDictAdd(ow, d, key, (Tz)(void*)&value);
}
Td *ZDictAddIobjIobj(int ow, Td *d, Tr key, Tr value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, (Tz)(void*)&value);
}

#ifdef DICT_DEBUG
dumpdict(Td *d)
{
 int        todo = (int)d->used;
 CDictItem  *item;
 int        idx = 0;

 for (item = d->array; todo > 0; ++item) {
  if (item->flags & CDI_FLAG_USED) {
   printf("%2d: %s\n", idx, (Tc*)item->key.ptr);
   --todo;
  } else if (item->flags == 0) {
   printf("%2d: unused\n", idx);
  } else if (item->flags == CDI_FLAG_DEL) {
   printf("%2d: deleted\n", idx);
  } else {
   printf("%2d: invalid flags: %d\n", idx, item->flags);
  }
  ++idx;
 }
}
#endif


CDictItem *ZDictFind(Td *d, Tz key) {
 Zhashtype  hash = ZDictHash(d->keyType, key);
 CDictItem  *di = ZDictLookup(d, key, hash);
 if (di->flags & CDI_FLAG_USED) return di;
 return NULL;
}

Tr *ZDictGetIobjP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  static Tr dummy = {0, 0, 0};
  ZDictAdd(1, d, key, (Tz)(void*)&dummy);
  di = ZDictFind(d, key);
 }
 return &di->ioitem;
}

Tr ZDictGetIobj(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->ioitem;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return trZero;
}

Tr ZDictGetIobjDef(Td *d, Tz key, Tr def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->ioitem;
 return def;
}

Tl *ZDictKeys(Td *d, int dn) {
 Tl *l;
 int todo;
 CDictItem *di;
 if (d == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("Invoking keys() on NIL dict");
 }
 l = ZnewList(d->keyType, d->used);
 if (d->type & DTYPE_ORDERED) {
  if (d->keyType == &iobj__T)
   for (di = d->first; di; di = di->lnext) {
    ZLaIobj(l, -1, di->iokey);
   }
  else
   for (di = d->first; di; di = di->lnext) {
    ZLa(l, -1, di->key);
   }
 } else {
  todo = d->used;
  for (di = d->array; todo > 0; ++di) {
   if (di->flags & CDI_FLAG_USED) {
    --todo;
    if (d->keyType == &iobj__T)
     ZLaIobj(l, -1, di->iokey);
    else
     ZLa(l, -1, di->key);
   }
  }
 }
 return l;
}

Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
}

Tcode *ZtableIndex(Ti pos100) {
 Ti pos = pos100 / 100;
 int l = 0;
 int h = sizeof(ZcodeTable)/sizeof(Tcode) - 1;
 int m;
 while (l <= h) {
  m = (l + h) / 2;
  if (ZcodeTable[m].offset == pos) break;
  if (ZcodeTable[m].offset < pos) l = m + 1;
  else h = m - 1;
 }
 return &ZcodeTable[m];
}
YkxB *MZ__callerPos(void) {
 Tcode *p;
 Zsf *tf = topFrame;
 if (tf == NULL) return NULL;
 tf = tf->prev == NULL ? tf : tf->prev;
 while (1) {
  if (tf == NULL) return NULL;
  if (tf->pos & POS_MASK) {
   p = ZtableIndex(tf->pos & POS_MASK);
   if (p->fileName) {
    return MZ__posnr2pos(NULL, tf->pos & POS_MASK);
   }
  }
  tf = tf->prev;
 }
}

Tl *MZ__backtrace(Ti skip, Ti limit) {
 Tl *head = ZnewList((Tt*)&YkxB__T, 0);
 int done = 0;
 Zsf *tf = topFrame;
 if (skip > 0) {
  int i;
  for (i = 0; i < skip && tf != NULL; ++i) tf = tf->prev;
 }
 while (tf != NULL) {
  if (tf->pos & POS_MASK) {
   YkxB *item = Za(sizeof(YkxB));
   if (limit >= 0 && done >= limit) {
    item->Vfilename = Zstr("truncated");
    ZLa(head, -1, (Tz)(void*)item);
    break;
   }
   MZ__posnr2pos(item, tf->pos & POS_MASK);
   ZLa(head, -1, (Tz)(void*)item);
   ++done;
  }
  tf = tf->prev;
 }
 return head;
}

YkxB *MZ__posnr2pos(YkxB *t, Ti pos) {
 int i;
 Tcode *p;
 Tcpos *pp;
 if (t == NULL) t = Za(sizeof(YkxB));
 p = ZtableIndex(pos);
 i = pos - p->offset * 100;
 pp = &p->table[i];
 t->Vfilename = Zstr((char*)p->fileName);
 t->Vtext = Zstr((char*)p->methodName);
 t->Vlnum = pp->line;
 if (i) t->Vlnum += p->table[0].line;
 t->Vcol = pp->col;
 return t;
}
/*
 * FUNCTION BODIES
 */
/* including TIMEModule bodies */
Ti Y9Rj() {
 Ti Vusec;
 Zsf sf;
 Ti r = 0;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=1078825925;
 r = Vusec;
 topFrame = sf.prev;
 return r;
}
/* TIMEModule done */
/* including EModule bodies */
Zfo YxaJfo[3] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&iobj__T},{0,0}};
void YxaJ(Ytlm *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJfo[0].off = (void*)&sf - (void*)&t;
  YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078660124;
  ZthrowThisNil();
 }
 sf.pos=4918301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1078660126;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1078660127;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4918304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1078660129;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1078660130;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1078660131;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Zfo YxaJafo[5] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,0}};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJafo[0].off = (void*)&sf - (void*)&t;
  YxaJafo[1].off = (void*)&sf - (void*)&Zf2;
  YxaJafo[2].off = (void*)&sf - (void*)&Aw;
  YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1077390924;
  ZthrowThisNil();
 }
 sf.pos=1077390925;
 YxaJ(t, Aw);
 sf.pos=3649102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1077390927;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3649104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3649105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1077390930;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1077390931;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1077390932;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3649109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1077390934;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1077390935;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3649112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYtlm[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Ytlm__T = {390, (Tc*)&YDGe, 0, ToYtlm};
Zfo YXHSafo[3] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,0}};
void YXHSa(YEro *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXHSafo[0].off = (void*)&sf - (void*)&t;
  YXHSafo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXHSafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082958124;
  ZthrowThisNil();
 }
 sf.pos=9216301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1082958126;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1082958127;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1082958128;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YxJ1));
 sf.pos=1082958129;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Zint2string(t->Vvalue));
 sf.pos=9216306;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1082958131;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
  sf.pos=1082958132;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 topFrame = sf.prev;
 return;
}
Zfo YEro__YxaJafo[5] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEro__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YEro__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YEro__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YEro__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YEro__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078040124;
  ZthrowThisNil();
 }
 sf.pos=1078040125;
 YXHSa(t, Aw);
 sf.pos=4298302;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1078040127;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4298304;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4298305;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1078040130;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1078040131;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1078040132;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4298309;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1078040134;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1078040135;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4298312;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYEro[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YEro__T = {390, (Tc*)&YJMo, 0, ToYEro};
Zfo YDNobfo[2] = {{0,(Tt*)&YKhn__T},{0,0}};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDNobfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YDNobfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1081806224; t = Za(sizeof(YKhn));}
 sf.pos=1081806225;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=1081806226;
 t->Vpos = MZ__callerPos();
 sf.pos=1081806227;
 t->Vbacktrace = (sf.pos=1081806228, MZ__backtrace(1, Alimit));
 topFrame = sf.prev;
 return t;
}
Zfo YKhn__YwtA__YxaJafo[5] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YKhn__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YKhn__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YKhn__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1074863524;
  ZthrowThisNil();
 }
 sf.pos=1074863525;
 YKhn__YwtA__YxaJ(t, Aw);
 sf.pos=1121702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1074863527;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=1121704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1121705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1074863530;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1074863531;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1074863532;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=1121709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1074863534;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1074863535;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=1121712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YKhn__YwtA__YxaJfo[3] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,0}};
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YKhn__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1075883624;
  ZthrowThisNil();
 }
 sf.pos=2141801;
 if ((t->Vpos != NULL))
 {
  sf.pos=1075883626;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1075883627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=2141804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1075883629;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1075883630;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1075883631;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YKhn__Ytlm_I_imt[] = {
 (Tc*)&YKhn__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHRa */
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
 (Tc*)YKhn__YwtA__YxaJa, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJa */
 (Tc*)YKhn__YwtA__YxaJ, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YKhn__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YKhn__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - YKhn__YwtA__Y4bq */
 (Tc*)0, /* Init - YKhna */
};
To ToYKhn[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YKhn__T = {390, (Tc*)&Y9Fv, 0, ToYKhn};
Zfo Y1KVfo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void Y1KV(Ti Asize) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1KVfo[0].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1KVfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Zfo Y1uN__YwtA__YRHRfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&string__T},{0,0}};
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y1uN__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1076950424; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=1076950426;
 t->Vpos = MZ__callerPos();
 sf.pos=1076950427;
 t->Vbacktrace = (sf.pos=1076950428, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo Y1uN__YwtA__YxaJafo[5] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y1uN__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y1uN__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y1uN__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1077250624;
  ZthrowThisNil();
 }
 sf.pos=1077250625;
 Y1uN__YwtA__YxaJ(t, Aw);
 sf.pos=3508802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1077250627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3508804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3508805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1077250630;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1077250631;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1077250632;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3508809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1077250634;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1077250635;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3508812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo Y1uN__YwtA__YxaJfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y1uN__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078270724;
  ZthrowThisNil();
 }
 sf.pos=4528901;
 if ((t->Vpos != NULL))
 {
  sf.pos=1078270726;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1078270727;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4528904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1078270729;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1078270730;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1078270731;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Y1uN__Ytlm_I_imt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHRa */
 (Tc*)Y1uN__YwtA__YRHR, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHR */
 (Tc*)0, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
 (Tc*)Y1uN__YwtA__YxaJa, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJa */
 (Tc*)Y1uN__YwtA__YxaJ, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - Y1uN__YwtA__YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getPos - Y1uN__YwtA__YvCK */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y1uN__YwtA__Y4bq */
 (Tc*)0, /* Init - Y1uNa */
};
To ToY1uN[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y1uN__T = {390, (Tc*)&Y4wO, 0, ToY1uN};
Zfo YvdVfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&Y1uN__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&iobj__T},{0,0}};
void YvdV(YkxB *Apos, Tc *Atext) {
 Tr ex;
 Zsf sf;
 Y1uN *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvdVfo[0].off = (void*)&sf - (void*)&Atext;
  YvdVfo[1].off = (void*)&sf - (void*)&Ve;
  YvdVfo[2].off = (void*)&sf - (void*)&Apos;
  YvdVfo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YvdVfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Ve = Y1uN__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, Y1uN__Ytlm_I_imt, 5);
 ZthrowIobject(ex);
}
Zfo YAxe__YwtA__YRHRfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&string__T},{0,0}};
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YAxe__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1081099824; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=1081099826;
 t->Vpos = MZ__callerPos();
 sf.pos=1081099827;
 t->Vbacktrace = (sf.pos=1081099828, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YAxe__YwtA__YxaJafo[5] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YAxe__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YAxe__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YAxe__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1076337624;
  ZthrowThisNil();
 }
 sf.pos=1076337625;
 YAxe__YwtA__YxaJ(t, Aw);
 sf.pos=2595802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1076337627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2595804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2595805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1076337630;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1076337631;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1076337632;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2595809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1076337634;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1076337635;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2595812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YAxe__YwtA__YxaJfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,0}};
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YAxe__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1077357724;
  ZthrowThisNil();
 }
 sf.pos=3615901;
 if ((t->Vpos != NULL))
 {
  sf.pos=1077357726;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1077357727;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=3615904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1077357729;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1077357730;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1077357731;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YAxe__Ytlm_I_imt[] = {
 (Tc*)&YAxe__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHRa */
 (Tc*)YAxe__YwtA__YRHR, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHR */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
 (Tc*)YAxe__YwtA__YxaJa, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJa */
 (Tc*)YAxe__YwtA__YxaJ, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YAxe__YwtA__YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YAxe__YwtA__YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - YAxe__YwtA__Y4bq */
 (Tc*)0, /* Init - YAxea */
};
To ToYAxe[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YAxe__T = {390, (Tc*)&Y4QW, 0, ToYAxe};
Zfo YE93fo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void YE93(Ti Anr) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YE93fo[0].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YE93fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if ((Anr == 11))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YkfG)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 if ((Anr == 8))
 {
  Tr ex;
  *Znao(&ex, YzSI__Ylz1__YwtA__YRHR(NULL, ((Tc*)&YoEx)), YzSI__Ytlm_I_imt, 17);
  ZthrowIobject(ex);
 }
 if ((Anr == 7))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YQNH)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 *Znao(&ex, YAxe__YwtA__YRHR(NULL, ZcS(((Tc*)&YpCZ), Zint2string(Anr))), YAxe__Ytlm_I_imt, 6);
 ZthrowIobject(ex);
}
Zfo YVNj__YwtA__YRHRfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&string__T},{0,0}};
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YVNj__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1079079524; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=1079079526;
 t->Vpos = MZ__callerPos();
 sf.pos=1079079527;
 t->Vbacktrace = (sf.pos=1079079528, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YVNj__YwtA__YxaJafo[5] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YVNj__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YVNj__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YVNj__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1083352524;
  ZthrowThisNil();
 }
 sf.pos=1083352525;
 YVNj__YwtA__YxaJ(t, Aw);
 sf.pos=9610702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1083352527;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=9610704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=9610705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1083352530;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1083352531;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1083352532;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=9610709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1083352534;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1083352535;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=9610712;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YVNj__YwtA__YxaJfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YVNj__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1074372624;
  ZthrowThisNil();
 }
 sf.pos=630801;
 if ((t->Vpos != NULL))
 {
  sf.pos=1074372626;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1074372627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=630804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1074372629;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1074372630;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1074372631;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YVNj__Ytlm_I_imt[] = {
 (Tc*)&YVNj__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
 (Tc*)YVNj__YwtA__YxaJa, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJa */
 (Tc*)YVNj__YwtA__YxaJ, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YVNj__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInit.getPos - YVNj__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInit.getBacktrace - YVNj__YwtA__Y4bq */
 (Tc*)0, /* Init - YVNja */
};
To ToYVNj[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YVNj__T = {390, (Tc*)&Ysqt, 0, ToYVNj};
Zfo Y3w6fo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void Y3w6(Tc *Atext) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y3w6fo[0].off = (void*)&sf - (void*)&Atext;
  Y3w6fo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y3w6fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Zfo Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&string__T},{0,0}};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yalz__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1079801124; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=1079801126;
 t->Vpos = MZ__callerPos();
 sf.pos=1079801127;
 t->Vbacktrace = (sf.pos=1079801128, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yalz__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078358924;
  ZthrowThisNil();
 }
 sf.pos=1078358925;
 Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=4617102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1078358927;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4617104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4617105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1078358930;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1078358931;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1078358932;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4617109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1078358934;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1078358935;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4617112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,0}};
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yalz__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1079379024;
  ZthrowThisNil();
 }
 sf.pos=5637201;
 if ((t->Vpos != NULL))
 {
  sf.pos=1079379026;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1079379027;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5637204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1079379029;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1079379030;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1079379031;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *Yalz__Ytlm_I_imt[] = {
 (Tc*)&Yalz__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHRa */
 (Tc*)Yalz__YwtA__YRHR, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
 (Tc*)Yalz__YwtA__YxaJa, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJa */
 (Tc*)Yalz__YwtA__YxaJ, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CBadValue.getPos - Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yalza */
};
To ToYalz[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yalz__T = {390, (Tc*)&YEZq, 0, ToYalz};
Zfo Yaezfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void Yaez(Tc *Atext) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yaezfo[0].off = (void*)&sf - (void*)&Atext;
  Yaezfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yaezfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Zfo Yw3O__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&string__T},{0,0}};
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yw3O__Yalz__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1079379924; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=1079379926;
 t->Vpos = MZ__callerPos();
 sf.pos=1079379927;
 t->Vbacktrace = (sf.pos=1079379928, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo Yw3O__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1079002624;
  ZthrowThisNil();
 }
 sf.pos=5260801;
 if ((t->Vpos != NULL))
 {
  sf.pos=1079002626;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1079002627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5260804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1079002629;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1079002630;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1079002631;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Zfo Yw3O__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yw3O__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yw3O__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1080022724;
  ZthrowThisNil();
 }
 sf.pos=1080022725;
 Yw3O__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=6280902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1080022727;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=6280904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6280905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1080022730;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1080022731;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1080022732;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=6280909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1080022734;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1080022735;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=6280912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Yw3O__Ytlm_I_imt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHRa */
 (Tc*)Yw3O__Yalz__YwtA__YRHR, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfRange.ToString - Yw3O__Yalz__YwtA__YH0V */
 (Tc*)Yw3O__Yalz__YwtA__YxaJa, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJa */
 (Tc*)Yw3O__Yalz__YwtA__YxaJ, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - Yw3O__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getPos - Yw3O__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Yw3O__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
};
To ToYw3O[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Yw3O__T = {390, (Tc*)&YFK2, 0, ToYw3O};
Zfo Y6NTfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y6NTfo[0].off = (void*)&sf - (void*)&Amsg;
  Y6NTfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y6NTfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Zfo Y2EX__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&string__T},{0,0}};
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y2EX__Yalz__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1076700324; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=1076700326;
 t->Vpos = MZ__callerPos();
 sf.pos=1076700327;
 t->Vbacktrace = (sf.pos=1076700328, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo Y2EX__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078054224;
  ZthrowThisNil();
 }
 sf.pos=4312401;
 if ((t->Vpos != NULL))
 {
  sf.pos=1078054226;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1078054227;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4312404;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1078054229;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1078054230;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1078054231;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Zfo Y2EX__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y2EX__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y2EX__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1079074324;
  ZthrowThisNil();
 }
 sf.pos=1079074325;
 Y2EX__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=5332502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1079074327;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5332504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5332505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1079074330;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1079074331;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1079074332;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5332509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1079074334;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1079074335;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5332512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *Y2EX__Ytlm_I_imt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHRa */
 (Tc*)Y2EX__Yalz__YwtA__YRHR, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
 (Tc*)Y2EX__Yalz__YwtA__YxaJa, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJa */
 (Tc*)Y2EX__Yalz__YwtA__YxaJ, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - Y2EX__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - Y2EX__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y2EX__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Y2EXa */
};
To ToY2EX[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto Y2EX__T = {390, (Tc*)&YRiW, 0, ToY2EX};
Zfo Yxmkfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void Yxmk(Ti Akey, Tc *Amsg) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yxmkfo[0].off = (void*)&sf - (void*)&Amsg;
  Yxmkfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yxmkfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Ym6C), Zint2string(Akey))), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
Zfo Y5LTfo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void Y5LT(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y5LTfo[0].off = (void*)&sf - (void*)&Akey;
  Y5LTfo[1].off = (void*)&sf - (void*)&Amsg;
  Y5LTfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y5LTfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YJ3Y), Akey, ((Tc*)&YI), (Tc*)1)), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
Zfo YX0i__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&string__T},{0,0}};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YX0i__Yalz__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1082241824; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=1082241826;
 t->Vpos = MZ__callerPos();
 sf.pos=1082241827;
 t->Vbacktrace = (sf.pos=1082241828, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YX0i__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1075213324;
  ZthrowThisNil();
 }
 sf.pos=1471501;
 if ((t->Vpos != NULL))
 {
  sf.pos=1075213326;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1075213327;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1471504;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1075213329;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1075213330;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1075213331;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Zfo YX0i__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YX0i__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YX0i__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1076233424;
  ZthrowThisNil();
 }
 sf.pos=1076233425;
 YX0i__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2491602;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1076233427;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2491604;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2491605;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1076233430;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1076233431;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1076233432;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2491609;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1076233434;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1076233435;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2491612;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YX0i__Ytlm_I_imt[] = {
 (Tc*)&YX0i__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHRa */
 (Tc*)YX0i__Yalz__YwtA__YRHR, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
 (Tc*)YX0i__Yalz__YwtA__YxaJa, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJa */
 (Tc*)YX0i__Yalz__YwtA__YxaJ, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YX0i__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YX0i__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - YX0i__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YX0ia */
};
To ToYX0i[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YX0i__T = {390, (Tc*)&Y9_h, 0, ToYX0i};
Zfo YL9Zfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void YL9Z(Ti Akey, Tc *Amsg) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YL9Zfo[0].off = (void*)&sf - (void*)&Amsg;
  YL9Zfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YL9Zfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Y9qa), Zint2string(Akey))), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
Zfo YEeXfo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
void YEeX(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEeXfo[0].off = (void*)&sf - (void*)&Akey;
  YEeXfo[1].off = (void*)&sf - (void*)&Amsg;
  YEeXfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YEeXfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YMKM), Akey, ((Tc*)&YI), (Tc*)1)), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
Zfo YzSI__Ylz1__YwtA__YRHRfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&string__T},{0,0}};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YzSI__Ylz1__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1081088924; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=1081088926;
 t->Vpos = MZ__callerPos();
 sf.pos=1081088927;
 t->Vbacktrace = (sf.pos=1081088928, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YzSI__Ylz1__YwtA__YxaJfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078154824;
  ZthrowThisNil();
 }
 sf.pos=4413001;
 if ((t->Vpos != NULL))
 {
  sf.pos=1078154826;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1078154827;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4413004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1078154829;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1078154830;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1078154831;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Zfo YzSI__Ylz1__YwtA__YxaJafo[5] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YzSI__Ylz1__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YzSI__Ylz1__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1079174924;
  ZthrowThisNil();
 }
 sf.pos=1079174925;
 YzSI__Ylz1__YwtA__YxaJ(t, Aw);
 sf.pos=5433102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1079174927;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5433104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5433105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1079174930;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1079174931;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1079174932;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5433109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1079174934;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1079174935;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5433112;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YzSI__Ytlm_I_imt[] = {
 (Tc*)&YzSI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHRa */
 (Tc*)YzSI__Ylz1__YwtA__YRHR, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHR */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
 (Tc*)YzSI__Ylz1__YwtA__YxaJa, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJa */
 (Tc*)YzSI__Ylz1__YwtA__YxaJ, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YzSI__Ylz1__YwtA__YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YzSI__Ylz1__YwtA__YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - YzSI__Ylz1__YwtA__Y4bq */
 (Tc*)0, /* Init - YzSIa */
};
To ToYzSI[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YzSI__T = {390, (Tc*)&YxFl, 0, ToYzSI};
Zfo YXKl__YwtA__YRHRfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&string__T},{0,0}};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YXKl__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1078571724; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=1078571726;
 t->Vpos = MZ__callerPos();
 sf.pos=1078571727;
 t->Vbacktrace = (sf.pos=1078571728, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YXKl__YwtA__YxaJafo[5] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YXKl__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YXKl__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YXKl__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082710324;
  ZthrowThisNil();
 }
 sf.pos=1082710325;
 YXKl__YwtA__YxaJ(t, Aw);
 sf.pos=8968502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1082710327;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8968504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8968505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1082710330;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1082710331;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1082710332;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8968509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1082710334;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1082710335;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8968512;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YXKl__YwtA__YxaJfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,0}};
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXKl__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1083730424;
  ZthrowThisNil();
 }
 sf.pos=9988601;
 if ((t->Vpos != NULL))
 {
  sf.pos=1083730426;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1083730427;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9988604;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1083730429;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1083730430;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1083730431;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YXKl__Ytlm_I_imt[] = {
 (Tc*)&YXKl__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHRa */
 (Tc*)YXKl__YwtA__YRHR, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHR */
 (Tc*)0, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
 (Tc*)YXKl__YwtA__YxaJa, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJa */
 (Tc*)YXKl__YwtA__YxaJ, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YXKl__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIOError.getPos - YXKl__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - YXKl__YwtA__Y4bq */
 (Tc*)0, /* Init - YXKla */
};
To ToYXKl[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YXKl__T = {390, (Tc*)&YTj3, 0, ToYXKl};
Zfo YdhHfo[2] = {{0,(Tt*)&YuDC__T},{0,0}};
YuDC *YdhH(YuDC *t) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YdhHfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YdhHfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1082465324; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=1082465326;
 t->Vpos = MZ__callerPos();
 sf.pos=1082465327;
 t->Vbacktrace = (sf.pos=1082465328, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YuDC__YwtA__YxaJafo[5] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YuDC__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YuDC__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YuDC__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082423624;
  ZthrowThisNil();
 }
 sf.pos=1082423625;
 YuDC__YwtA__YxaJ(t, Aw);
 sf.pos=8681802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1082423627;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8681804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8681805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1082423630;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1082423631;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1082423632;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8681809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1082423634;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1082423635;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8681812;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YuDC__YwtA__YxaJfo[3] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,0}};
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YuDC__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1083443724;
  ZthrowThisNil();
 }
 sf.pos=9701901;
 if ((t->Vpos != NULL))
 {
  sf.pos=1083443726;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1083443727;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9701904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1083443729;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1083443730;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1083443731;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YuDC__Ytlm_I_imt[] = {
 (Tc*)&YuDC__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHR */
 (Tc*)0, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
 (Tc*)YuDC__YwtA__YxaJa, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJa */
 (Tc*)YuDC__YwtA__YxaJ, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YuDC__YwtA__YCzX */
 (Tc*)0, /* MEModule__CWrongType.getPos - YuDC__YwtA__YvCK */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - YuDC__YwtA__Y4bq */
 (Tc*)0, /* Init - YuDCa */
};
To ToYuDC[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YuDC__T = {390, (Tc*)&YCoZ, 0, ToYuDC};
Zfo YTuGfo[3] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,0}};
void YTuG(Ti Apos) {
 Tr ex;
 Zsf sf;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTuGfo[0].off = (void*)&sf - (void*)&Ve;
  YTuGfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YTuGfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
Zfo YrHq__YwtA__YRHRfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&string__T},{0,0}};
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YrHq__YwtA__YRHRfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1081550024; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=1081550026;
 t->Vpos = MZ__callerPos();
 sf.pos=1081550027;
 t->Vbacktrace = (sf.pos=1081550028, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Zfo YrHq__YwtA__YxaJafo[5] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YrHq__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YrHq__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YrHq__YwtA__YxaJafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1073783024;
  ZthrowThisNil();
 }
 sf.pos=1073783025;
 YrHq__YwtA__YxaJ(t, Aw);
 sf.pos=41202;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1073783027;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=41204;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=41205;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1073783030;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1073783031;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1073783032;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=41209;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1073783034;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1073783035;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=41212;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YrHq__YwtA__YxaJfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,0}};
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YrHq__YwtA__YxaJfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1074803124;
  ZthrowThisNil();
 }
 sf.pos=1061301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1074803126;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1074803127;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1061304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1074803129;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1074803130;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1074803131;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YrHq__Ytlm_I_imt[] = {
 (Tc*)&YrHq__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHRa */
 (Tc*)YrHq__YwtA__YRHR, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
 (Tc*)YrHq__YwtA__YxaJa, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJa */
 (Tc*)YrHq__YwtA__YxaJ, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YrHq__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInternal.getPos - YrHq__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - YrHq__YwtA__Y4bq */
 (Tc*)0, /* Init - YrHqa */
};
To ToYrHq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YrHq__T = {390, (Tc*)&YVki, 0, ToYrHq};
Zfo YUSHfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&YrHq__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&iobj__T},{0,0}};
void YUSH(YkxB *Apos, Tc *Atext) {
 Tr ex;
 Zsf sf;
 YrHq *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YUSHfo[0].off = (void*)&sf - (void*)&Atext;
  YUSHfo[1].off = (void*)&sf - (void*)&Ve;
  YUSHfo[2].off = (void*)&sf - (void*)&Apos;
  YUSHfo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YUSHfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Ve = YrHq__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, YrHq__Ytlm_I_imt, 26);
 ZthrowIobject(ex);
}
Zfo YxISfo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void YxIS(Tr Ae) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxISfo[0].off = (void*)&sf - (void*)&Ae;
 }
 sf.frof = YxISfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
      static int entered = 0;
      int didEnter = entered;
      entered = 1;
 if ((Ae).type == 1)
 {
  Ti VexitVal;
  VexitVal = ((YEro *)Znio(1, 1571802, (Ae)))->Vvalue;
  if (!didEnter) beforeExit();
  exit(VexitVal);
 }
 else
 {
  YvL0(Ae);
  if (!didEnter) beforeExit();
  exit(1);
 }
 topFrame = sf.prev;
 return;
}
Zfo YvL0fo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void YvL0(Tr Ae) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvL0fo[0].off = (void*)&sf - (void*)&Ae;
 }
 sf.frof = YvL0fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1078980424;
 Ylxt();
 sf.pos=1078980425;
 YQar(Ae, 1, YeNQ);
 sf.pos=1078980440;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 topFrame = sf.prev;
 return;
}
void YQar(Tr A0, Tb A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("writeTo: object is NIL, cannot select method to invoke");
 if (A2.ptr == NULL) ZthrowCstringNil("writeTo: argument 2 is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238602)); return;
  case 1:
   YEro__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238603)); return;
  case 2:
   return;
  case 3:
   return;
  case 4:
   YKhn__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238604)); return;
  case 5:
   Y1uN__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238605)); return;
  case 6:
   YAxe__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238606)); return;
  case 7:
   YVNj__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238607)); return;
  case 8:
   return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 15:
   return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 27:
   return;
  case 28:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including SYSModule bodies */
Zfo Yhy5fo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yhy5(Tc *Aname) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yhy5fo[0].off = (void*)&sf - (void*)&Aname;
  Yhy5fo[1].off = (void*)&sf - (void*)&Vres;
 }
 sf.frof = Yhy5fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1077974124;
 Vres = (Tc*)getenv(ZgetCstring(Aname));
 if (Vres != NULL) Vres = Zstr((char*)Vres);
 sf.pos=1077974125;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
/* SYSModule done */
/* including ZModule bodies */
Zfo Ypp_afo[3] = {{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,0}};
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ypp_afo[0].off = (void*)&sf - (void*)&t;
  Ypp_afo[1].off = (void*)&sf - (void*)&Afilename;
 }
 sf.frof = Ypp_afo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 topFrame = sf.prev;
 return t;
}
Zfo YpI_fo[3] = {{0,(Tt*)&YkxB__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YpI_(YkxB *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YpI_fo[0].off = (void*)&sf - (void*)&t;
  YpI_fo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YpI_fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1075560524;
  ZthrowThisNil();
 }
 sf.pos=1075560525;
 Vw = Za(sizeof(YjUM));
 sf.pos=1818702;
 if ((t->Vfilename == NULL))
 {
  sf.pos=1075560527;
  YJqza(Vw, ((Tc*)&YKo1));
 }
 else
 {
  sf.pos=1075560528;
  YJqza(Vw, t->Vfilename);
 }
 sf.pos=1075560529;
 YJqza(Vw, ((Tc*)&YBpY));
 sf.pos=1075560530;
 YjUM__YHhZb(Vw, t->Vlnum);
 sf.pos=1075560531;
 YJqza(Vw, ((Tc*)&Y8ES));
 sf.pos=1075560532;
 YjUM__YHhZb(Vw, t->Vcol);
 sf.pos=1075560533;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToYkxB[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&string__T}, /* text */
};
Tto YkxB__T = {390, (Tc*)&YBCs, 0, ToYkxB};
/* ZModule done */
/* including STRINGModule bodies */
Zfo Yvnffo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato) {
 Ti Vi;
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yvnffo[0].off = (void*)&sf - (void*)&Athis;
  Yvnffo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = Yvnffo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1203500;
 if (Athis == NULL)
 {
  sf.pos=1074945325;
  r = NULL;
  rt = 1;
  goto YIVu;
 }
 sf.pos=1074945326;
 Vi = ZstringFindChar(Athis, Afrom, 0);
 sf.pos=1203503;
 if ((Vi >= 0))
 {
  Ti VnextChar;
  VnextChar = 0;
  sf.pos=1074945328;
  Vw = Za(sizeof(YjUM));
  sf.pos=1203505;
  while ((Vi >= 0))
  {
   sf.pos=1203506;
   if ((Vi > VnextChar))
   {
    sf.pos=1074945331;
    YJqza(Vw, ZstringSlice(Athis, VnextChar, (Vi - 1), 0));
   }
   sf.pos=1074945332;
   YjUM__Ydti(Vw, Ato);
   sf.pos=1203509;
   VnextChar = (Vi + 1);
   sf.pos=1074945334;
   Vi = ZstringFindChar2(Athis, Afrom, VnextChar, 0);
  sf.pos=1203511;
  }
  sf.pos=1074945336;
  YJqza(Vw, ZstringSlice(Athis, VnextChar, -1, 0));
  sf.pos=1074945337;
  r = YbNW(Vw);
  rt = 1;
  goto YIVu;
 }
 sf.pos=1074945338;
 r = Athis;
YIVu:
 topFrame = sf.prev;
 return r;
}
/* STRINGModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stderr;
 r = Vfile;
 return r;
}
Tc **YdXi__imtt[] = {
  Yw8L__YdXi_imt,
    0,
  YjUM__YdXi_imt,
    0,
};
Zfo YwHoafo[4] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwHoafo[0].off = (void*)&sf - (void*)&t;
  YwHoafo[1].off = (void*)&sf - (void*)&Atext;
  YwHoafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YwHoafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1083224124;
  ZthrowThisNil();
 }
 Vret = 0;
 sf.pos=9482301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=1083224126;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 sf.pos=1083224127;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, t->Vfd) == 1)
   Vret = 1;
  else
   Vret = 0;
  }
 sf.pos=1083224128;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YHhZbfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YHhZbfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1079723724;
  ZthrowThisNil();
 }
 sf.pos=1079723725;
 r = YwHoa(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7fo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,0}};
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7fo[0].off = (void*)&sf - (void*)&t;
  Yw8L__YRt7fo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yw8L__YRt7fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1080360624;
  ZthrowThisNil();
 }
 sf.pos=1080360625;
 if (((YwHoa(t, Atext) == 1) && (YwHoa(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=1080360626;
  r = 1;
  rt = 1;
  goto Y7Vd;
 }
 sf.pos=1080360627;
 r = 0;
Y7Vd:
 topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7gfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YRt7g(Yw8L *t) {
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7gfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YRt7gfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082003624;
  ZthrowThisNil();
 }
 sf.pos=1082003625;
 r = YwHoa(t, ((Tc*)&Yk));
 topFrame = sf.prev;
 return r;
}
Tc *Yw8L__Yw8L_I_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)Yw8L__YHhZb, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)0, /* MIOModule__CFile.readChar - YAPp */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyuma */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyum */
 (Tc*)0, /* MIOModule__CFile.readAllBytes - YVfz */
 (Tc*)0, /* MIOModule__CFile.readLine - YaEh */
 (Tc*)0, /* MIOModule__CFile.readLineRaw - Yn2l */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1a */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1 */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWFa */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWF */
 (Tc*)0, /* MIOModule__CFile.writeAllLines - YZFx */
 (Tc*)0, /* MIOModule__CFile.flush - YGmp */
 (Tc*)0, /* MIOModule__CFile.close - YrF8 */
 (Tc*)0, /* MIOModule__CFile.Finish - YSo_ */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__YdXi_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, ToYw8L};
Zfo Yvcufo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yvcufo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yvcufo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vret = 0;
 sf.pos=1082228824;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, stdout) == 1)
   Vret = 1;
  else
   Vret = 0;
 }
 sf.pos=1082228825;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Zfo Yl0kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yl0kfo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yl0kfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vret = 0;
 sf.pos=1073929024;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=187201;
 if ((Vlen == 0 || fwrite(ZgetCstring(Atext), (size_t)Vlen, 1, stdout) == 1) && fputc('\n', stdout) >= 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=1073929026;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=1078417925;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Zfo YJqzafo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJqzafo[0].off = (void*)&sf - (void*)&t;
  YJqzafo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = YJqzafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082740524;
  ZthrowThisNil();
 }
 sf.pos=1082740525;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=8998702;
 if ((t->Vs == NULL))
 {
  sf.pos=1082740527;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), (Vlen + 30));
  sf.pos=1082740528;
  Zas(t->Vs, Atext, 0, 0);
  sf.pos=8998705;
  t->VsLen = Vlen;
 }
 else
 {
  sf.pos=1082740530;
  if ((((t->VsLen + Vlen) + 1) >= ZArraySize(t->Vs)))
  {
   sf.pos=1082740531;
   ZarrayResize(t->Vs, sizeof(Tc), (((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + Vlen) + 50)) ;
  }
  sf.pos=1082740532;
  Zas(t->Vs, Atext, 0, t->VsLen);
  sf.pos=8998709;
  t->VsLen += Vlen;
 }
 sf.pos=1082740534;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Zfo YbNWfo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Tc *YbNW(YjUM *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YbNWfo[0].off = (void*)&sf - (void*)&t;
  YbNWfo[1].off = (void*)&sf - (void*)&Vr;
 }
 sf.frof = YbNWfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1080194924;
  ZthrowThisNil();
 }
 sf.pos=6453101;
 if ((t->Vs == NULL))
 {
  sf.pos=6453102;
  Vr = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=1080194927;
  Vr = ZnewString(t->Vs->ptr, t->VsLen);
 }
 sf.pos=1080194928;
 r = Vr;
 topFrame = sf.prev;
 return r;
}
Zfo YjUM__YHhZbfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjUM__YHhZbfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1080942524;
  ZthrowThisNil();
 }
 sf.pos=1080942525;
 r = YJqza(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Zfo YjUM__Ydtifo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YjUM__Ydti(YjUM *t, Ti Achar) {
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__Ydtifo[0].off = (void*)&sf - (void*)&t;
  YjUM__Ydtifo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YjUM__Ydtifo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078670324;
  ZthrowThisNil();
 }
 sf.pos=4928501;
 if (((Achar < 0) || (Achar > 1114111)))
 {
  Tr ex;
  sf.pos=1078670326;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&Yv8w), Zint2string(Achar))), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 sf.pos=1078670327;
 r = YJqza(t, ZintAsString(Achar));
 topFrame = sf.prev;
 return r;
}
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)0, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {2, 0},
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
Zfo Y_3Kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Tb Y_3K(Tc *Aname) {
 Ti Vv;
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y_3Kfo[0].off = (void*)&sf - (void*)&Aname;
 }
 sf.frof = Y_3Kfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vv = 0;
 sf.pos=7387700;
 Vv = access(ZgetCstring(Aname), X_OK);
 sf.pos=1081129525;
 r = (Vv == 0);
 topFrame = sf.prev;
 return r;
}
Zfo Ycmifo[6] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tc *Ycmi(Tc *AexeName) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vexe = NULL;
 Tc *Vfname = NULL;
 Tl *Vdirectories = NULL;
 Tc *Vpath = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ycmifo[0].off = (void*)&sf - (void*)&AexeName;
  Ycmifo[1].off = (void*)&sf - (void*)&Vexe;
  Ycmifo[2].off = (void*)&sf - (void*)&Vfname;
  Ycmifo[3].off = (void*)&sf - (void*)&Vdirectories;
  Ycmifo[4].off = (void*)&sf - (void*)&Vpath;
 }
 sf.frof = Ycmifo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1080238824;
 Vexe = Yvnf(AexeName, 92, 47);
 sf.pos=1080238825;
 if (((ZstringStartsWith(Vexe, ((Tc*)&YV), 0) || ZstringStartsWith(Vexe, ((Tc*)&YFka), 0)) || ZstringStartsWith(Vexe, ((Tc*)&Y0y2), 0)))
 {
  sf.pos=6497002;
  Vfname = Vexe;
 }
 else
 {
  sf.pos=1080238827;
  Vpath = Yhy5(((Tc*)&Yykt));
  sf.pos=6497004;
  if ((Vpath != NULL))
  {
   sf.pos=6497005;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=1080238830;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y6), 0);
   sf.pos=6497007;
#else
   sf.pos=1080238832;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y5), 0);
   sf.pos=6497009;
#endif
  }
  sf.pos=1080238834;
  Vfname = YDop(AexeName, Vdirectories);
  sf.pos=6497011;
#if defined(__MINGW32__) || defined(_MSC_VER)
  sf.pos=1080238836;
  if (((Vfname == NULL) && !(ZstringEndsWith(ZstringToLower(AexeName), ((Tc*)&YpPR), 0))))
  {
   sf.pos=1080238837;
   Vfname = YDop(ZcS(AexeName, ((Tc*)&YpPR)), Vdirectories);
  }
  sf.pos=6497014;
#endif
  sf.pos=6497015;
  if ((Vfname == NULL))
  {
   sf.pos=6497016;
   Vfname = Vexe;
   sf.pos=6497017;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=1080238842;
   if ((!(Y_3K(Vfname)) && Y_3K(ZcS(Vfname, ((Tc*)&YpPR)))))
   {
    sf.pos=1080238843;
    Vfname =  ZcS(Vfname, ((Tc*)&YpPR));
   }
   sf.pos=6497020;
#endif
  }
  else
  {
   sf.pos=1080238845;
   Vfname = Yvnf(Vfname, 92, 47);
  }
 }
 sf.pos=1080238846;
 r = YPjH(Vfname);
 topFrame = sf.prev;
 return r;
}
Zfo YDopfo[6] = {{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YDop(Tc *AexeName, Tl *Adirs) {
 Zsf sf;
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vdir = NULL;
 Tc *Vfname = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YDopfo[0].off = (void*)&sf - (void*)&Adirs;
  YDopfo[1].off = (void*)&sf - (void*)&AexeName;
  YDopfo[2].off = (void*)&sf - (void*)&Zf1;
  YDopfo[3].off = (void*)&sf - (void*)&Vdir;
  YDopfo[4].off = (void*)&sf - (void*)&Vfname;
 }
 sf.frof = YDopfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=8617600;
 {
  Tfl Zf1i;
  Zf1 = Adirs;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdir;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=1082359425;
  Vfname = Yq8a(Vdir, AexeName);
  sf.pos=1082359426;
  if (Y_3K(Vfname))
  {
   sf.pos=1082359427;
   r = Vfname;
   rt = 1;
   goto Ycsu;
  }
Ycsu:
  if (rt) goto YsLr;
  sf.pos=8617604;
  }
 }
 sf.pos=1082359429;
 r = NULL;
YsLr:
 topFrame = sf.prev;
 return r;
}
Zfo Yq8afo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yq8a(Tc *Afirst, Tc *Asecond) {
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yq8afo[0].off = (void*)&sf - (void*)&Afirst;
  Yq8afo[1].off = (void*)&sf - (void*)&Asecond;
 }
 sf.frof = Yq8afo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1080572224;
 if (ZstringEndsWith(Afirst, ((Tc*)&YV), 0))
 {
  sf.pos=1080572225;
  if (ZstringStartsWith(Asecond, ((Tc*)&YV), 0))
  {
   sf.pos=1080572226;
   r = ZcS(Afirst, ZstringSlice(Asecond, 1, -1, 0));
   rt = 1;
   goto YV1Y;
  }
  sf.pos=1080572227;
  r = ZcS(Afirst, Asecond);
YV1Y:
  ;
  rt = 1;
  goto YSGC;
 }
 sf.pos=1080572228;
 if (((ZbyteStringSize(Afirst) == 0) || ZstringStartsWith(Asecond, ((Tc*)&YV), 0)))
 {
  sf.pos=1080572229;
  r = ZcS(Afirst, Asecond);
  rt = 1;
  goto YSGC;
 }
 sf.pos=1080572230;
 r = ZcS3(Afirst, ((Tc*)&YV), Asecond);
YSGC:
 topFrame = sf.prev;
 return r;
}
Zfo YPjHfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YPjH(Tc *Afname) {
 Ti Vlimit;
 Tb VisRelative;
 Tb VhasTrailingSep;
 Ti Vi;
 Zsf sf;
 Tc *r = 0;
 Tc *Vresult = NULL;
 Tc *Vlink = NULL;
 Tc *Vremain = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YPjHfo[0].off = (void*)&sf - (void*)&Afname;
  YPjHfo[1].off = (void*)&sf - (void*)&Vresult;
  YPjHfo[2].off = (void*)&sf - (void*)&Vlink;
  YPjHfo[3].off = (void*)&sf - (void*)&Vremain;
 }
 sf.frof = YPjHfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=4533100;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=4533101;
 Vresult = Afname;
 sf.pos=4533102;
#else
 sf.pos=4533103;
 Vlimit = 100;
 sf.pos=1078274928;
 VisRelative = ((ZstringGetChar(Afname, 0) == 46) && ((Yhu2(ZstringGetChar(Afname, 1)) || (((ZstringGetChar(Afname, 1) == 46) && Yhu2(ZstringGetChar(Afname, 2)))))));
 sf.pos=1078274929;
 VhasTrailingSep = ZstringEndsWith(Afname, ((Tc*)&YV), 0);
 sf.pos=1078274930;
 Vi = Y26N(Afname, YEpA(Afname));
 sf.pos=4533107;
 if ((Vi > 1))
 {
  sf.pos=1078274932;
  Vresult = ZstringSlice(Afname, 0, (Vi - 2), 0);
  sf.pos=1078274933;
  Vremain = ZstringSlice(Afname, (Vi - 1), -1, 0);
 }
 else
 {
  sf.pos=4533110;
  Vresult = Afname;
 }
 sf.pos=4533111;
 while (1)
 {
  sf.pos=4533112;
  while (1)
  {
   Ti Vt;
   sf.pos=4533113;
   {
    int   len;
    char  buf[PATH_MAX + 1];
    len = readlink(ZgetCstring(Vresult), (char *)buf, PATH_MAX);
    if (len <= 0) break;  /* can't read, use as-is */
    buf[len] = 0;
   sf.pos=1078274938;
   Vlink = NULL;
   sf.pos=1078274939;
    Vlink = Zstr(buf);
   }
   sf.pos=4533116;
   if (((Vlimit)-- == 0))
   {
    sf.pos=1078274941;
    r = Afname;
    rt = 1;
    goto Yu7Z;
   }
   sf.pos=4533118;
   if (((Vremain == NULL) && VhasTrailingSep))
   {
    sf.pos=1078274943;
    Vlink =  ZcS(Vlink, ((Tc*)&YV));
   }
   sf.pos=1078274944;
   Vi = Y26N(Vlink, YEpA(Vlink));
   sf.pos=4533121;
   if ((Vi > 1))
   {
    sf.pos=4533122;
    if ((Vremain == NULL))
    {
     sf.pos=1078274947;
     Vremain = ZstringSlice(Vlink, (Vi - 1), -1, 0);
    }
    else
    {
     sf.pos=1078274948;
     Vremain = ZcS(ZstringSlice(Vlink, (Vi - 1), -1, 0), Vremain);
    }
    sf.pos=1078274949;
    Vlink = ZstringSlice(Vlink, 0, (Vi - 2), 0);
   }
   sf.pos=1078274950;
   Vt = Yr30(Vresult);
   sf.pos=1078274951;
   if (((Vt > 0) && (Vt == ZstringSize(Vresult))))
   {
    sf.pos=1078274952;
    Vresult = ZstringSlice(Vresult, 0, -2, 0);
    sf.pos=1078274953;
    Vt = Yr30(Vresult);
   }
   sf.pos=1078274954;
   if (((Vt > 0) && (YEpA(Vlink) == 0)))
   {
    sf.pos=1078274955;
    Vresult = ZcS(ZstringSlice(Vresult, 0, (Vt - 1), 0), Vlink);
   }
   else
   {
    sf.pos=1078274956;
    Vresult = ZcS(Vlink, ((Tc*)&Ya));
   }
Yu7Z:
   if (rt) goto YqPr;
  sf.pos=4533133;
  }
  sf.pos=4533134;
  if ((Vremain == NULL))
  {
   rt = 2;
   goto YqPr;
  }
  sf.pos=1078274959;
  Vi = Y26N(Vremain, 1);
  sf.pos=4533136;
  if ((Vi > 1))
  {
   sf.pos=1078274961;
   Vresult =  ZcS(Vresult, ZstringSlice(Vremain, 0, (Vi - 2), 0));
   sf.pos=1078274962;
   Vremain = ZstringSlice(Vremain, (Vi - 1), -1, 0);
  }
  else
  {
   sf.pos=1078274963;
   Vresult =  ZcS(Vresult, Vremain);
   sf.pos=1078274964;
   Vremain = NULL;
  }
YqPr:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YQMx;
 sf.pos=4533141;
 }
 sf.pos=1078274966;
 if (Yhu2(ZstringGetChar(Vresult, 0)))
 {
  sf.pos=1078274967;
  if (((VisRelative && (ZstringSize(Vresult) > 0)) && !((((ZstringGetChar(Vresult, 0) == 46) && ((((ZstringSize(Vresult) == 1) || Yhu2(ZstringGetChar(Vresult, 1))) || (((ZstringGetChar(Vresult, 1) == 46) && (((ZstringSize(Vresult) == 2) || Yhu2(ZstringGetChar(Vresult, 2)))))))))))))
  {
   sf.pos=1078274968;
   Vresult = ZcS(((Tc*)&YFka), Vresult);
  }
  else {
  sf.pos=1078274969;
 if (!(VisRelative))
  {
   sf.pos=4533146;
   Vi = 0;
   sf.pos=1078274971;
   while (((ZstringGetChar(Vresult, Vi) == 46) && Yhu2(ZstringGetChar(Vresult, (Vi + 1)))))
   {
    sf.pos=4533148;
    Vi += 2;
   sf.pos=1078274973;
   }
   sf.pos=4533150;
   if ((Vi > 0))
   {
    sf.pos=1078274975;
    Vresult = ZstringSlice(Vresult, Vi, -1, 0);
   }
  }
  }
 }
 sf.pos=4533152;
 if (!(VhasTrailingSep))
 {
  Ti Vm;
  sf.pos=1078274977;
  Vm = YEpA(Vresult);
  sf.pos=1078274978;
  while ((ZstringEndsWith(Vresult, ((Tc*)&YV), 0) && (ZstringSize(Vresult) > Vm)))
  {
   sf.pos=1078274979;
   Vresult = ZstringSlice(Vresult, 0, -2, 0);
  sf.pos=1078274980;
  }
 }
 sf.pos=4533157;
#endif
 sf.pos=1078274982;
 r = Vresult;
YQMx:
 topFrame = sf.prev;
 return r;
}
Zfo Yr30fo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Yr30(Tc *Afname) {
 Ti Vi;
 Ti Vj;
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yr30fo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Yr30fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1079963124;
 Vi = ZstringFindLastChar(Afname, 47, 0);
 sf.pos=6221301;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=1079963126;
 Vj = ZstringFindLastChar(Afname, 92, 0);
 sf.pos=6221303;
 if ((Vj > Vi))
 {
  sf.pos=6221304;
  Vi = Vj;
 }
 sf.pos=6221305;
#endif
 sf.pos=6221306;
 if ((Vi < 0))
 {
  sf.pos=1079963131;
  r = 0;
  rt = 1;
  goto YnSW;
 }
 sf.pos=1079963132;
 r = (Vi + 1);
YnSW:
 topFrame = sf.prev;
 return r;
}
Zfo YEpAfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti YEpA(Tc *Afname) {
 Ti Vi;
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEpAfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = YEpAfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 Vi = 0;
 sf.pos=1101700;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=1074843525;
 if ((isalpha(ZstringGetChar(Afname, 0)) && (ZstringGetChar(Afname, 1) == 58)))
 {
  sf.pos=1101702;
  Vi = 2;
 }
 sf.pos=1101703;
#endif
 sf.pos=1074843528;
 while (((Vi < ZstringSize(Afname)) && Yhu2(ZstringGetChar(Afname, Vi))))
 {
  sf.pos=1101705;
  ++(Vi);
 sf.pos=1074843530;
 }
 sf.pos=1074843531;
 r = Vi;
 topFrame = sf.prev;
 return r;
}
Tb Yhu2(Ti Ac) {
 Zsf sf;
 Tb r = 0;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1081655424;
 r = (Ac == 47);
 topFrame = sf.prev;
 return r;
}
Zfo Y26Nfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Y26N(Tc *Afname, Ti Aidx) {
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Y26Nfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Y26Nfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1077369524;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(Aidx, (ZstringSize(Afname) - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=1077369525;
  if (Yhu2(ZstringGetChar(Afname, Vi)))
  {
   sf.pos=1077369526;
   r = (Vi + 1);
   rt = 1;
   goto Ydy4;
  }
Ydy4:
  if (rt) goto Y3wQ;
  sf.pos=1077369527;
  }
 }
 sf.pos=1077369528;
 r = -1;
Y3wQ:
 topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0x40000000;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=1074487024;
   Y59X = Yd89();
   sf.pos=1074487025;
   Yb0q = Yvyt();
   sf.pos=1074487026;
   YeNQ = YsM3();
  }
  topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1080391924;
 r = (((Y6fX == NULL)) ? (0) : (1));
 topFrame = sf.prev;
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, ToYnU5};
void YQtK() {
 Zsf sf;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1081458224;
 Y2R7 = Ycmi(YzvW);
 topFrame = sf.prev;
 return;
}
Zfo YZH8fo[16] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y_SI__T},{0,(Tt*)&YJQu__T},{0,(Tt*)&YzqH__T},{0,(Tt*)&iobj__T},{0,0}};
void YZH8() {
 Zsf sf;
 Tc *Varg = NULL;
 Tc *Vvalue = NULL;
 Tc *Vflagname = NULL;
 Tc *Vflagname1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vk = NULL;
 Tl *Zf21 = NULL;
 Tc *Vk1 = NULL;
 Tr Vflag = {NULL};
 Y86c *Vbflag = 0;
 Y86c *Vbflag1 = 0;
 Y_SI *Vsflag = 0;
 YJQu *Viflag = 0;
 YzqH *Vsflag1 = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YZH8fo[0].off = (void*)&sf - (void*)&Varg;
  YZH8fo[1].off = (void*)&sf - (void*)&Vvalue;
  YZH8fo[2].off = (void*)&sf - (void*)&Vflagname;
  YZH8fo[3].off = (void*)&sf - (void*)&Vflagname1;
  YZH8fo[4].off = (void*)&sf - (void*)&Zf2;
  YZH8fo[5].off = (void*)&sf - (void*)&Vk;
  YZH8fo[6].off = (void*)&sf - (void*)&Zf21;
  YZH8fo[7].off = (void*)&sf - (void*)&Vk1;
  YZH8fo[8].off = (void*)&sf - (void*)&Vflag;
  YZH8fo[9].off = (void*)&sf - (void*)&Vbflag;
  YZH8fo[10].off = (void*)&sf - (void*)&Vbflag1;
  YZH8fo[11].off = (void*)&sf - (void*)&Vsflag;
  YZH8fo[12].off = (void*)&sf - (void*)&Viflag;
  YZH8fo[13].off = (void*)&sf - (void*)&Vsflag1;
  YZH8fo[14].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YZH8fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=8253300;
 if ((Y6fX == NULL))
 {
  Tb VdoFlags;
  Tb Vskip;
  sf.pos=8253301;
  if ((Y7be == NULL))
  {
   sf.pos=1081995126;
   Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
   sf.pos=1081995127;
   YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  }
  sf.pos=1081995128;
  if ((YUBd && (((ZDictSize(Y7be) > 0) || (ZDictSize(YBQy) > 0)))))
  {
   Tr ex;
   sf.pos=1081995129;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y7T_)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=1081995130;
  {
   Tfl Zf2i;
   Zf2 = ZDictKeys(Y7be, 0);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vk;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tr YXyJ = {NULL};
   sf.pos=1081995131;
   (YXyJ = ZDictGetIobj(Y7be, (Tz)(void*)Vk), ((void (*)(void*))(YXyJ.table[17]))(YXyJ.ptr));
   sf.pos=1081995132;
   }
  }
  sf.pos=1081995133;
  {
   Tfl Zf21i;
   Zf21 = ZDictKeys(YBQy, 0);
   Zf21i.l = Zf21;
   Zf21i.valp = (void*)&Vk1;
   Zf21i.i = 0;
   for (; ZforListPtrCont(&Zf21i); ) {
   Tr YWyJ = {NULL};
   sf.pos=1081995134;
   (YWyJ = ZDictGetIobj(YBQy, (Tz)(void*)Vk1), ((void (*)(void*))(YWyJ.table[17]))(YWyJ.ptr));
   sf.pos=1081995135;
   }
  }
  sf.pos=1081995136;
  Y6fX = ZnewList((Tt*)&string__T, 0);
  sf.pos=8253313;
  VdoFlags = !(YUBd);
  Vskip = 0;
  sf.pos=1081995138;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew(0, (ZListSize(Y1p3) - 1), 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=8253315;
   if (Vskip)
   {
    sf.pos=8253316;
    Vskip = 0;
    rt = 4;
    if (rt) goto YgsM;
   }
   sf.pos=1081995141;
   Varg = ((Tc *)ZListGetPtr(Y1p3, Vi));
   sf.pos=1081995142;
   if (((!(VdoFlags) || (ZstringGetChar(Varg, 0) != 45)) || (ZstringCmp(Varg, ((Tc*)&YT)) == 0)))
   {
    sf.pos=1081995143;
    ZLap((Tl*)Y6fX, (Tz)(void*)Varg);
    sf.pos=8253320;
    if (YQpY)
    {
     sf.pos=8253321;
     VdoFlags = 0;
    }
   }
   else
   {
    sf.pos=8253322;
    if ((ZstringCmp(Varg, ((Tc*)&Y1ia)) == 0))
    {
     sf.pos=8253323;
     VdoFlags = 0;
    }
    else
    {
     Vflag.ptr = NULL;
     Vvalue = NULL;
     sf.pos=1081995148;
     if ((ZstringCmp(ZstringSlice(Varg, 0, 1, 0), ((Tc*)&Y1ia)) == 0))
     {
      Ti Vidx;
      sf.pos=1081995149;
      Vflagname = ZstringSlice(Varg, 2, -1, 0);
      sf.pos=8253326;
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3vi)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
      {
       sf.pos=1081995151;
       Yfj5((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) != 0));
      }
      sf.pos=1081995152;
      Vidx = ZstringFindChar(Vflagname, 61, 0);
      sf.pos=8253329;
      if ((Vidx > 0))
      {
       sf.pos=1081995154;
       Vvalue = ZstringSlice(Vflagname, (Vidx + 1), -1, 0);
       sf.pos=1081995155;
       Vflagname = ZstringSlice(Vflagname, 0, (Vidx - 1), 0);
      }
      sf.pos=1081995156;
      Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)Vflagname, trZero);
      sf.pos=1081995157;
      if (((((Vflag).ptr) == NULL) && (ZstringCmp(ZstringSlice(Vflagname, 0, 1, 0), ((Tc*)&YhZb)) == 0)))
      {
       sf.pos=1081995158;
       Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)ZstringSlice(Vflagname, 2, -1, 0), trZero);
       sf.pos=8253335;
       if ((((Vflag).ptr) != NULL))
       {
        sf.pos=8253336;
        if ((Vflag).type == 0)
        {
         sf.pos=1081995161;
         Vflagname = ZstringSlice(Vflagname, 2, -1, 0);
         sf.pos=8253338;
         Vvalue = ((Tc*)&YhZb);
        }
        else
        {
         sf.pos=1081995163;
         Vflag = trZero;
        }
       }
      }
     }
     else
     {
      Ti Vidx;
      sf.pos=1081995164;
      Vflagname1 = ZstringSlice(Varg, 1, -1, 0);
      sf.pos=1081995165;
      Vidx = ZstringFindChar(Vflagname1, 61, 0);
      sf.pos=8253342;
      if ((Vidx > 0))
      {
       sf.pos=1081995167;
       Vvalue = ZstringSlice(Vflagname1, (Vidx + 1), -1, 0);
       sf.pos=1081995168;
       Vflagname1 = ZstringSlice(Vflagname1, 0, (Vidx - 1), 0);
      }
      else
      {
       sf.pos=1081995169;
       while ((ZstringSize(Vflagname1) > 1))
       {
        sf.pos=1081995170;
        Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)ZstringSlice(Vflagname1, 0, 0, 0), trZero);
        sf.pos=8253347;
        if ((((Vflag).ptr) == NULL))
        {
         rt = 2;
         goto Yy70;
        }
        else
        {
         sf.pos=8253348;
         if ((Vflag).type == 0)
         {
          sf.pos=8253349;
          ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
          sf.pos=1081995175;
          Vbflag = ((Y86c *)Znio(0, 8253350, (Vflag)));
          sf.pos=8253352;
          Vbflag->Vcurrent = !(Vbflag->Vdefault);
          sf.pos=1081995177;
          Vflagname1 = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=1081995178;
          Vflag = trZero;
         }
         else {
         sf.pos=8253355;
 if ((Vflag).type == 3)
         {
          rt = 2;
          goto YuBh;
         }
         else {
         sf.pos=8253356;
 if ((!(Y_kI) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[7])))))
         {
          sf.pos=1081995181;
          Vvalue = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=1081995182;
          Vflagname1 = ZstringSlice(Vflagname1, 0, 0, 0);
         }
         }}
YuBh:
         if (rt) goto Yy70;
        }
Yy70:
        if (rt == 2) { rt &= 1; break; }
       sf.pos=1081995183;
       }
      }
      sf.pos=1081995184;
      if ((ZstringSize(Vflagname1) != 1))
      {
       sf.pos=1081995185;
       YSUO(ZcS(((Tc*)&YcW8), Varg));
      }
      else {
      sf.pos=1081995186;
 if ((((Vflag).ptr) == NULL))
      {
       sf.pos=1081995187;
       Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)Vflagname1, trZero);
      }
      }
     }
     sf.pos=8253364;
     if ((((Vflag).ptr) == NULL))
     {
      sf.pos=8253365;
      if (!(YUBd))
      {
       sf.pos=1081995190;
       YSUO(ZcS(((Tc*)&Y2hB), Varg));
      }
     }
     else
     {
      sf.pos=8253367;
      if ((((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])) > 0) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[6])))))
      {
       sf.pos=1081995192;
       YSUO(ZcS(((Tc*)&YcLH), Varg));
      }
      sf.pos=8253369;
      ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
      sf.pos=8253370;
      if ((Vflag).type == 0)
      {
       sf.pos=1081995196;
       Vbflag1 = ((Y86c *)Znio(0, 8253371, (Vflag)));
       sf.pos=8253373;
       if ((Vvalue != NULL))
       {
        sf.pos=8253374;
        if (((ZstringCmp(Vvalue, ((Tc*)&YjK7)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YsfP)) == 0)))
        {
         sf.pos=8253375;
         Vbflag1->Vcurrent = 1;
        }
        else {
        sf.pos=8253376;
 if (((ZstringCmp(Vvalue, ((Tc*)&YhZb)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YvpX)) == 0)))
        {
         sf.pos=8253377;
         Vbflag1->Vcurrent = 0;
        }
        else
        {
         sf.pos=1081995202;
         YSUO(ZcS(((Tc*)&YHSJ), Varg));
        }
        }
       }
       else
       {
        sf.pos=8253379;
        Vbflag1->Vcurrent = !(Vbflag1->Vdefault);
       }
      }
      else {
      sf.pos=8253380;
 if ((Vflag).type == 3)
      {
       sf.pos=8253381;
       if ((Vvalue != NULL))
       {
        sf.pos=1081995206;
        YSUO(ZcS(((Tc*)&Y6QK), Varg));
       }
       sf.pos=1081995208;
       Vsflag = ((Y_SI *)Znio(3, 8253383, (Vflag)));
       sf.pos=1081995209;
       Vsflag->Vcurrent = ZnewList((Tt*)&string__T, 0);
       sf.pos=1081995210;
       {
        Ti Vj;
        Tfr Zf7;
        ZforRangeNew((Vi + 1), (ZListSize(Y1p3) - 1), 0, 1, &Zf7);
        for (ZforRangeGetInt(&Zf7, &Vj); ZforRangeContInt(&Zf7); ZforRangeNextInt(&Zf7, &Vj)) {
        sf.pos=1081995211;
        ZLap((Tl*)Vsflag->Vcurrent, (Tz)(void*)((Tc *)ZListGetPtr(Y1p3, Vj)));
        sf.pos=1081995212;
        }
       }
       rt = 2;
       goto YxuQ;
      }
      else
      {
       sf.pos=8253389;
       if ((!((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[8]))) && (Vvalue == NULL)))
       {
        sf.pos=8253390;
        Vskip = 1;
        sf.pos=1081995215;
        if ((Vi == (ZListSize(Y1p3) - 1)))
        {
         sf.pos=1081995216;
         YSUO(ZcS(((Tc*)&Y_ju), Varg));
        }
        sf.pos=1081995217;
        Vvalue = ((Tc *)ZListGetPtr(Y1p3, (Vi + 1)));
       }
       sf.pos=8253394;
       if ((Vflag).type == 1)
       {
        sf.pos=1081995220;
        Viflag = ((YJQu *)Znio(1, 8253395, (Vflag)));
        sf.pos=8253397;
        if ((Vvalue == NULL))
        {
         sf.pos=8253398;
         Viflag->Vcurrent = Viflag->Vdefault;
         sf.pos=1081995223;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)Viflag->Vdefault);
        }
        else
        {
         Ti VintVal;
         sf.pos=1081995224;
         VintVal = ZstringToInt(Vvalue, 1, 0);
         sf.pos=8253401;
         Viflag->Vcurrent = VintVal;
         sf.pos=1081995226;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)VintVal);
        }
       }
       else {
       sf.pos=8253403;
 if ((Vflag).type == 2)
       {
        sf.pos=1081995229;
        Vsflag1 = ((YzqH *)Znio(2, 8253404, (Vflag)));
        sf.pos=8253406;
        if ((Vvalue == NULL))
        {
         sf.pos=8253407;
         Vsflag1->Vcurrent = Vsflag1->Vdefault;
         sf.pos=1081995232;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vsflag1->Vdefault);
        }
        else
        {
         sf.pos=8253409;
         Vsflag1->Vcurrent = Vvalue;
         sf.pos=1081995234;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vvalue);
        }
       }
       else
       {
        Tr ex;
        sf.pos=1081995235;
        *Znao(&ex, YrHq__YwtA__YRHR(NULL, ((Tc*)&YjTs)), YrHq__Ytlm_I_imt, 26);
        ZthrowIobject(ex);
       }
       }
      }
      }
YxuQ:
      if (rt) goto YdgD;
     }
YdgD:
     if (rt) goto YOd6;
    }
YOd6:
    if (rt) goto YgsM;
   }
YgsM:
   if (rt == 2) { rt &= 1; break; }
   if (rt == 4) { rt &= 1; continue; }
   sf.pos=1081995236;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YSUOfo[2] = {{0,(Tt*)&string__T},{0,0}};
void YSUO(Tc *Amsg) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSUOfo[0].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YSUOfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1082271324;
 ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, Amsg);
 sf.pos=8529501;
 if ((Yun4 != NULL))
 {
  sf.pos=1082271326;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=8529503;
 if (!(YhUP))
 {
  sf.pos=1082271328;
  ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, ZcS3(((Tc*)&YkFE), YzvW, ((Tc*)&Y15F)));
 }
 sf.pos=1082271329;
 Zexit(NULL, 1);
 topFrame = sf.prev;
 return;
}
Zfo Yfj5fo[12] = {{0,(Tt*)&dict__T},{0,(Tt*)&list__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,0}};
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
 Zsf sf;
 Td *VallFlags = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vkey = NULL;
 Tc *VargText = NULL;
 Tc *Vlead = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 Tr Vflag = {NULL};
 Tr Vflag1 = {NULL};
 Tl *t0 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yfj5fo[0].off = (void*)&sf - (void*)&VallFlags;
  Yfj5fo[1].off = (void*)&sf - (void*)&Zf1;
  Yfj5fo[2].off = (void*)&sf - (void*)&Zf2;
  Yfj5fo[3].off = (void*)&sf - (void*)&Vkey;
  Yfj5fo[4].off = (void*)&sf - (void*)&VargText;
  Yfj5fo[5].off = (void*)&sf - (void*)&Vlead;
  Yfj5fo[6].off = (void*)&sf - (void*)&Zf11;
  Yfj5fo[7].off = (void*)&sf - (void*)&Vkey1;
  Yfj5fo[8].off = (void*)&sf - (void*)&Vflag;
  Yfj5fo[9].off = (void*)&sf - (void*)&Vflag1;
  Yfj5fo[10].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yfj5fo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=2956000;
 if ((Yun4 != NULL))
 {
  sf.pos=1076697825;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=1076697826;
 Yl0k(((Tc*)&YaBy));
 sf.pos=2956003;
 VallFlags = Y7be;
 sf.pos=1076697828;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys(YBQy, 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=1076697829;
  Vflag = ZDictGetIobj(YBQy, (Tz)(void*)Vkey1);
  sf.pos=2956006;
  if (((*(Tc**)(Vflag.ptr + (size_t)Vflag.table[1])) == NULL))
  {
   sf.pos=1076697831;
   *ZDictGetIobjP(VallFlags, (Tz)(void*)(*(Tc**)(Vflag.ptr + (size_t)Vflag.table[2]))) = Vflag;
  }
  sf.pos=1076697832;
  }
 }
 VmaxLeadLen = 0;
 sf.pos=1076697833;
 {
  Ti Vdisplay;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdisplay;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=2956010;
  if (Vdisplay)
  {
   sf.pos=1076697835;
   YTlu(((Tc*)&YwXF), VmaxLeadLen);
   sf.pos=1076697836;
   Yl0k(((Tc*)&YEcf));
  }
  sf.pos=1076697837;
  {
   Tfl Zf2i;
   Zf2 = ZstringListSort(ZDictKeys(VallFlags, 0), 1);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vkey;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tb Vopt;
   sf.pos=1076697838;
   Vflag1 = ZDictGetIobj(VallFlags, (Tz)(void*)Vkey);
   sf.pos=2956015;
   VargText = ((Tc*)&Ya);
   Vopt = 0;
   sf.pos=2956016;
   if ((Vflag1).type == 1)
   {
    sf.pos=2956017;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956018;
     VargText = ((Tc*)&Yy2p);
    }
    else
    {
     sf.pos=2956019;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956020;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956021;
 if ((Vflag1).type == 2)
   {
    sf.pos=2956022;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956023;
     VargText = ((Tc*)&YanE);
    }
    else
    {
     sf.pos=2956024;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956025;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956026;
 if ((Vflag1).type == 3)
   {
    sf.pos=2956027;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956028;
     VargText = ((Tc*)&YDci);
    }
    else
    {
     sf.pos=1076697853;
     VargText = ZcS((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])), ((Tc*)&YulU));
    }
    sf.pos=2956030;
    Vopt = 1;
   }
   }}
   sf.pos=2956031;
   if ((ZbyteStringSize(VargText) != 0))
   {
    sf.pos=2956032;
    if (Vopt)
    {
     sf.pos=1076697857;
     VargText = ZcS3(((Tc*)&YVZ), VargText, ((Tc*)&YEa));
    }
    else
    {
     sf.pos=1076697858;
     VargText = ZcS3(((Tc*)&Yq_), VargText, ((Tc*)&Y9a));
    }
   }
   sf.pos=2956035;
   Vlead = ((Tc*)&Ya);
   sf.pos=2956036;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])) != NULL))
   {
    sf.pos=1076697861;
    Vlead = ZcS5(((Tc*)&YT), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])), VargText, ((Tc*)&YG), (Tc*)1);
   }
   sf.pos=2956038;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])) != NULL))
   {
    sf.pos=2956039;
    if (((ZbyteStringSize(Vlead) != 0) && (ZbyteStringSize(VargText) != 0)))
    {
     sf.pos=2956040;
     if (Vdisplay)
     {
      sf.pos=2956041;
      if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
      {
       sf.pos=1076697866;
       Vlead =  ZcS(Vlead, ((Tc*)&Y_y2));
      }
      sf.pos=1076697867;
      Yl0k(Vlead);
     }
     sf.pos=2956044;
     Vlead = ((Tc*)&Ya);
    }
    sf.pos=1076697869;
    Vlead =  ZcS(Vlead, ZcS5(((Tc*)&Y1ia), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])), VargText, ((Tc*)&YG), (Tc*)1));
   }
   sf.pos=2956046;
   if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
   {
    sf.pos=1076697871;
    Vlead =  ZcS(Vlead, ((Tc*)&Y2yA));
   }
   sf.pos=2956048;
   if (Vdisplay)
   {
    sf.pos=2956049;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])) != NULL))
    {
     sf.pos=1076697874;
     YTlu(Vlead, VmaxLeadLen);
     sf.pos=1076697875;
     Yl0k((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])));
    }
    else
    {
     sf.pos=1076697876;
     Yl0k(Vlead);
    }
    sf.pos=2956053;
    if (Averbose)
    {
     sf.pos=1076697878;
     YTlu(((Tc*)&Ya), VmaxLeadLen);
     sf.pos=1076697879;
     Yl0k(ZcS(((Tc*)&Ym4c), YpI_((*(YkxB**)(Vflag1.ptr + (size_t)Vflag1.table[9])))));
    }
   }
   else
   {
    sf.pos=1076697880;
    if ((VmaxLeadLen < ZstringSize(Vlead)))
    {
     sf.pos=1076697881;
     VmaxLeadLen = ZstringSize(Vlead);
    }
    sf.pos=2956058;
    if ((VmaxLeadLen > 30))
    {
     sf.pos=2956059;
     VmaxLeadLen = 30;
     rt = 2;
     goto YAEw;
    }
YAEw:
    if (rt) goto Yfan;
   }
Yfan:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=1076697884;
   }
  }
  sf.pos=1076697885;
  }
 }
 sf.pos=1076697886;
 Zexit(NULL, YMLU);
 topFrame = sf.prev;
 return;
}
Zfo YTlufo[2] = {{0,(Tt*)&string__T},{0,0}};
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTlufo[0].off = (void*)&sf - (void*)&Alead;
 }
 sf.frof = YTlufo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 sf.pos=1081921624;
 Yvcu(Alead);
 sf.pos=1081921625;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(ZstringSize(Alead), AmaxLeadLen, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=1081921626;
  Yvcu(((Tc*)&YG));
  sf.pos=1081921627;
  }
 }
 topFrame = sf.prev;
 return;
}
Zfo YAMWfo[4] = {{0,(Tt*)&YuMQ__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YAMWfo[0].off = (void*)&sf - (void*)&t;
  YAMWfo[1].off = (void*)&sf - (void*)&t0;
  YAMWfo[2].off = (void*)&sf - (void*)&t1;
 }
 sf.frof = YAMWfo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1078041824;
  ZthrowThisNil();
 }
 sf.pos=1078041825;
 Vidx = ZstringFind(t->Vtext, ((Tc*)&YMtG), 0);
 sf.pos=4300002;
 if ((Vidx < 0))
 {
  sf.pos=1078041827;
  r = t->Vtext;
  rt = 1;
  goto YZtK;
 }
 sf.pos=1078041828;
 r = ZcS3(ZstringSlice(t->Vtext, 0, (Vidx - 1), 0), YzvW, (t0 = ZstringSlice(t->Vtext, (Vidx + 3), -1, 0)));
YZtK:
 topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, ToYuMQ};
Zfo YEqoafo[2] = {{0,(Tt*)&Y86c__T},{0,0}};
void YEqoa(Y86c *t) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEqoafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YEqoafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1077632924;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToY86c[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, ToY86c};
Zfo Y49gafo[2] = {{0,(Tt*)&YJQu__T},{0,0}};
void Y49ga(YJQu *t) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y49gafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y49gafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1075376824;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYJQu[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, ToYJQu};
Zfo YJazafo[2] = {{0,(Tt*)&YzqH__T},{0,0}};
void YJaza(YzqH *t) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJazafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YJazafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1082362424;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYzqH[] = {
 {8, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, ToYzqH};
Zfo YSkKafo[2] = {{0,(Tt*)&Y_SI__T},{0,0}};
void YSkKa(Y_SI *t) {
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSkKafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YSkKafo;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1080189624;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToY_SI[] = {
 {7, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0x40000000;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  ToYEro[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YKhn *p = 0;
  YKhn__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YKhn__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YKhn__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYKhn[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYKhn[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYKhn[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y1uN *p = 0;
  Y1uN__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y1uN__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y1uN__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY1uN[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY1uN[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY1uN[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YAxe *p = 0;
  YAxe__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YAxe__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YAxe__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYAxe[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYAxe[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYAxe[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YVNj *p = 0;
  YVNj__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YVNj__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YVNj__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYVNj[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYVNj[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYVNj[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yalz *p = 0;
  Yalz__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yalz__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yalz__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYalz[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYalz[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYalz[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yw3O *p = 0;
  Yw3O__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yw3O__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yw3O__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYw3O[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYw3O[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYw3O[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y2EX *p = 0;
  Y2EX__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2EX__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2EX__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2EX[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2EX[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2EX[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YX0i *p = 0;
  YX0i__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YX0i__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YX0i__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYX0i[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYX0i[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYX0i[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YzSI *p = 0;
  YzSI__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YzSI__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzSI__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYzSI[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYzSI[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYzSI[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YXKl *p = 0;
  YXKl__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YXKl__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YXKl__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYXKl[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYXKl[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYXKl[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YuDC *p = 0;
  YuDC__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YuDC__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YuDC__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYuDC[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYuDC[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYuDC[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YrHq *p = 0;
  YrHq__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYrHq[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYrHq[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYrHq[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YkxB *p = 0;
  ToYkxB[1].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYkxB[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  YuMQ *p = 0;
  ToYuMQ[1].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Y86c *p = 0;
  ToY86c[1].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  ToYJQu[1].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 sf.frof = NULL;
 topFrame = &sf;
 done &= JIOModule(round);
 done &= JARGModule(round);
 if (round == 2001) {
 }
 topFrame = sf.prev;
 return done;
}

/*
 * MAIN
 */

#if defined(__MINGW32__) || defined(_MSC_VER)
# define CATCH_SIG(sig, func) signal(sig, func)
  typedef struct SEH_EXCEPTION_REGISTRATION_S SEH_EXCEPTION_REGISTRATION;
  struct SEH_EXCEPTION_REGISTRATION_S
  {
    SEH_EXCEPTION_REGISTRATION *prev;
    PEXCEPTION_HANDLER handler;
  };
  static EXCEPTION_DISPOSITION exception_handler(PEXCEPTION_RECORD pRecord, SEH_EXCEPTION_REGISTRATION *pReg, PCONTEXT pContext, PEXCEPTION_RECORD pRecord2) {
   Zdeadly(11);
   return ExceptionContinueSearch;
  }
#else
# define CATCH_SIG(sig, func) catch_sig(sig, func)
void catch_sig(int sig, void *func) {
 struct sigaction act;
 act.sa_handler = func;
 sigemptyset(&act.sa_mask);
 act.sa_flags = SA_NODEFER;
 sigaction(sig, &act, NULL);
}
#endif

int Fmain(void);
int main(int argc, char **argv) {
 int r = 0;
 int round = 0;
#if defined(__MINGW32__) || defined(_MSC_VER)
 SEH_EXCEPTION_REGISTRATION seh_er;
 seh_er.handler = (PEXCEPTION_HANDLER)(exception_handler);
 asm volatile ("movl %%fs:0, %0" : "=r" (seh_er.prev));
 asm volatile ("movl %0, %%fs:0" : : "r" (&seh_er));
#else
# ifdef SIGSEGV
 CATCH_SIG(SIGSEGV, Zdeadly);
# endif
# ifdef SIGBUS
 CATCH_SIG(SIGBUS, Zdeadly);
# endif
# ifdef SIGFPE
 CATCH_SIG(SIGFPE, Zdeadly);
# endif
#endif
#if defined(__MINGW32__) || defined(_MSC_VER)
# ifdef __MINGW32__
 _fmode = _O_BINARY;
# else
 _set_fmode(_O_BINARY);
# endif
 _setmode(_fileno(stdin), _O_BINARY);
 _setmode(_fileno(stdout), _O_BINARY);
 _setmode(_fileno(stderr), _O_BINARY);
#endif
 emergencyAlloc = malloc(16384);
 ZimtInit();
 ZglobInit(round++);
 YzvW = Zstr(argv[0]);
 YQtK();
 Y1p3 = ZnewList(&string__T, 0);
 {
  int i;
  for (i = 1; i < argc; ++i) {
   ZLa(Y1p3, -1, (Tz)(void*)Zstr(argv[i]));
  }
 }

 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 1002) ZthrowCstringInit("Early initialization not done within 1000 rounds");
 }
 YZH8();

 round = 2001;
 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 3002) ZthrowCstringInit("Initialization not done within 1000 rounds");
 }
 r = Fmain();
 beforeExit();
 if (topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}


int Fmain(void) {
 Zsf sf;
 Ti r = 0;
 sf.frof = NULL;
 sf.prev = topFrame;
 sf.pos = 0x40000000;
 topFrame = &sf;
 r = 0;
 sf.pos=1074268824;
 Yl0k(Y2R7);
 sf.pos=1074268825;
 r = 0;
 topFrame = sf.prev;
 return r;
}
