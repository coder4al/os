#include <stdio.h>
struct process
{
    int size, flag, holeid;
} p[10];
struct hole
{
    int size, actual;
} h[10];
int main()
{
    int i, j, np, nh;
    printf("Enter no. of Holes : ");
    scanf("%d", &nh);
    for (i = 0; i < nh; i++)
    {
        printf("Enter size of H%d : ", i);
        scanf("%d", &h[i].size);
        h[i].actual = h[i].size;
    }
    printf("Enter no. of Process : ");
    scanf("%d", &np);
    for (i = 0; i < np; i++)
    {
        printf("Enter size of P%d : ", i);
        scanf("%d", &p[i].size);
        p[i].flag = 0;
    }
    for (i = 0; i < np; i++)
    {
        for (j = 0; j < nh; j++)
        {
            if (p[i].flag != 1)
            {
                if (p[i].size <= h[j].size)
                {
                    p[i].flag = 1;
                    p[i].holeid = j;
                    h[j].size -= p[i].size;
                }
            }
        }
    }
    printf("\nFirst Fit\n");
    printf("\nProcess\tPSize\tHole");
    for(i=0; i<np; i++){
        if(p[i].flag != 1) printf("\nP%d\t%d\tNot allocated", i, p[i].size);
        else printf("\nP%d\t%d\tH%d", i, p[i].size, p[i].holeid);
    }
    printf("\n\nHole\tActual\tAvailable");
    for(i=0; i<nh; i++){
        printf("\nH%d\t%d\t%d", i, h[i].actual, h[i].size);
    }
}
