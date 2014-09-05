#include <stdio.h>

main()
{
    int start = 0;
    int end = 150;
    int step = 10;

    float fahr, celc = start;
    
    printf(" °C     °F\n");

    while (celc <= end) {
        fahr = 32.0 + celc * (9.0/5.0);
        printf("%3.0f %6.0f\n", celc, fahr);
        celc += step;
    }
}
