/*  DO NOT EDIT - automatically generated by msjavah  */
#include <native.h>
#pragma warning(disable:4510)
#pragma warning(disable:4512)
#pragma warning(disable:4610)

struct Classptc_Format;
#define Hptc_Format Classptc_Format
struct Classptc_Color;
#define Hptc_Color Classptc_Color

/*  Header for class ptc/rni/Clear  */

#ifndef _Included_ptc_rni_Clear
#define _Included_ptc_rni_Clear

#define Hptc_rni_Clear Classptc_rni_Clear
typedef struct Classptc_rni_Clear {
#include <pshpack4.h>
    long MSReserved;
    int64_t object;
#include <poppack.h>
} Classptc_rni_Clear;

typedef struct ClassArrayOfptc_rni_Clear {
    int32_t MSReserved;
    const unsigned long length;
    Hptc_rni_Clear * const body[1];
} ClassArrayOfptc_rni_Clear;
#define HArrayOfptc_rni_Clear ClassArrayOfptc_rni_Clear
#define ArrayOfptc_rni_Clear ClassArrayOfptc_rni_Clear

#ifdef __cplusplus
extern "C" {
#endif
__declspec(dllexport) int64_t __cdecl ptc_rni_Clear_create (struct Hptc_rni_Clear *);
__declspec(dllexport) void __cdecl ptc_rni_Clear_destroy (struct Hptc_rni_Clear *, int64_t);
__declspec(dllexport) void __cdecl ptc_rni_Clear_request (struct Hptc_rni_Clear *, int64_t, struct Hptc_Format *);
__declspec(dllexport) void __cdecl ptc_rni_Clear_clear (struct Hptc_rni_Clear *, int64_t, HObject *, long, long, long, long, long, struct Hptc_Color *);
#ifdef __cplusplus
}
#endif

#endif  /* _Included_ptc_rni_Clear */

#pragma warning(default:4510)
#pragma warning(default:4512)
#pragma warning(default:4610)
