#include <stdio.h>
#include <stdlib.h>

/* functia lui Ackermann:
ack(m,n) = ack(m-1, ack(m, n-1));
ack(0,n) = n+1;
ack(m,0) = ack(m-1,1);
*/
int ackermann(int m, int n)
{
        if (!m) return n + 1;
        if (!n) return ackermann(m - 1, 1);
        return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
        int m, n;
        for (m = 0; m <= 4; m++) {
            for (n = 0; n < 6 - m; n++) {
                printf("A(%d, %d) = %d\n", m, n, ackermann(m, n));
            }
        }
        return 0;
}

