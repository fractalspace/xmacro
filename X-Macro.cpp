// X-Macro.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <tchar.h>

///////////////////////////////////////////////
// X-Macro Expansion - Enum

enum RC_CODES {
#define X(a) e##a,
#include "x-macro.h"
#undef X
};


///////////////////////////////////////////////
// X-Macro Expansion - String

static char *ErrString[] = {
#define X(a) #a,
#include "x-macro.h"
#undef X
};

/////////////////////////////////////////////////


#define ARRAY_SIZE(a) (sizeof(a)/sizeof(*a))

int _tmain(int argc, _TCHAR* argv[])
{
    int n = ARRAY_SIZE(ErrString);

    // print all enums
    for (int i = 0; i < n; i++)
    {
        printf("id %d, str \"%s\"\n", i, ErrString[i]);
    }

    // print individual enums
    printf(" eFailed is \"%s\"\n", ErrString[eFAILED]);

	return 0;
}

