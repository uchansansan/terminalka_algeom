#define N 1000
#define Exp 0.00001

#include <stdio.h>
#include <math.h>

int rang(double* matr, int n, int k) {
  int rang = 0;
  for (int i=0;i<n;i++) {
    for (int j = 0;j < k;j++) {
      if (matr[j+i*k] == 0) {
        rang++;
        break;
      }
    }
  }
  return rang;
}

int main(void) {
    int n = 0, k = 0;
    double a[N][N] = {0}, c = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
        scanf("%lf", &a[i][j]);

    for (int сid = 0, rid = 0; сid < n && rid < k;) {
      int g = rid;
      for (int i = rid; i < k; ++i)
        if (fabs(a[i][сid]) - fabs(a[g][сid]) > 0)
          g=i;
      for (int i = сid; i < n; ++i) {
        double tmp = a[g][i];
          a[g][i] = a[rid][i];
          a[rid][i] = tmp;
      }

      for (int i = 0; i < k; ++i)
        if (i != rid & a[rid][сid] != 0)
          for (int j = сid; j < n; j++)
            a[i][j]=a[i][j]-(a[rid][j] * a[i][сid] / a[rid][сid]);
        rid++;сid++;
    }

    int tot = 0;
    int r = rang(*a,n,k);
    printf("Ранг системы: %d\n",r);

    for (int i = 0; i < k; i++)
      for (int j = 0; j < n; j++)
        if (fabs(a[i][j]) > Exp)
          tot++;
  
    if (k == tot)
    	printf("Линейно независимая система");
    else
    	printf("Линейно зависимая система");  
    return 0;  
}
