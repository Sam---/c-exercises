#include <stdio.h>

#define MAX 90

main()
{
    int star = 0, dia = 0, dot = 0;

    for (star = 0; star < MAX; star++) {
        for (dot = 0; dot < MAX; dot++) {
            for (dia = 0; dia < MAX; dia++) {
                if (star * 2 + dia + dot == 63 &&
                        dot * 2 + star + dia == 78 &&
                        dia * 3 + star == 72 &&
                        (star + dot) * 2 == 66 &&
                        (dot + dia) * 2 == 90 &&
                        star * 3 + dia == 48) {
                    printf(".%d <>%d *%d", dot, dia, star);
                    return 0;
                }
            }
        }
    }
    return -1;
}

