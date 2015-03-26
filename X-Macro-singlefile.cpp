// X-Macro.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <tchar.h>

//////////////////////////////////////////////////////////////////////
// Multi purpose array

#define COLORS \
    X(First) \
    X(OK) \
    X(FAILED) \
    X(SERVER_NOT_FOUND) \
    X(FOOD_NOT_FOUND) \
    X(NOT_ENOUGH_MONEY)

#define X(a) e##a,
enum Colors {COLORS eLAST};
#undef X

#define X(a) #a,
static char *ErrString[] = { COLORS "Last" };
#undef X
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

