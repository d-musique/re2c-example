#include "ParseYMD.h"
#include <stdlib.h>
#include <string.h>

static int ToInt(const char *beg, const char *end);

int ParseYMD(const char *text, int *year, int *month, int *day)
{
    const char *YYCURSOR = text;
    const char *YYMARKER;
    const char *y1, *y2, *m1, *m2, *d1, *d2;
    /*!stags:re2c format = 'const char *@@;\n'; */

/*!re2c
  re2c:define:YYCTYPE = char;
  re2c:yyfill:enable = 0;
  re2c:flags:tags = 1;

@y1 [0-9]{4} @y2 "-" @m1 [0-9]{2} @m2 "-" @d1 [0-9]{2} @d2 [\x00]
{
    if (year) *year = ToInt(y1, y2);
    if (month) *month = ToInt(m1, m2);
    if (day) *day = ToInt(d1, d2);
    return 1;
}

.|"\n"
{
    return 0;
}
*/
}

static int ToInt(const char *beg, const char *end)
{
    char tmp[8] = {0};
    memcpy(tmp, beg, end - beg);
    return atoi(tmp);
}
