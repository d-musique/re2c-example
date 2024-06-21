#include "ParseYMD.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int year, month, day;

    if (argc < 2)
    {
        printf("Usage: ParseYMD <YYYY-MM-DD>\n");
        return 0;
    }

    if (argc != 2)
    {
        fprintf(stderr, "Invalid arguments.\n");
        return 1;
    }

    if (!ParseYMD(argv[1], &year, &month, &day))
    {
        fprintf(stderr, "Could not parse text.\n");
        return 1;
    }

    printf("Year: %d\nMonth: %d\nDay: %d\n", year, month, day);

    return 0;
}
