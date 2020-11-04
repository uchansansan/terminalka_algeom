#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double exp = 0.000000001;

int rank(double** mas, int i, int j){
   int r = 0;
   double u;
   for (int t = 0; t < i; t++)
   {
      u = mas[t][j - 1];
      if (fabsl(u) < exp)
         break;
      r++;
   }
   return r;
}

void gauss(double** mas, int i, int j, int i0, int j0){
   if (i0 == (i - 1))
      return;
   else if (j0 == (j - 1)){
      if (fabsl(mas[i0][j0] - 0) < exp)
         for (int t = i0; t < i; t++)
         {
            if (fabsl(mas[t][j - 1] - 0) >= exp)
            {
               mas[i0][j0] = mas[t][j - 1];
               break;
            }

         }
      for (int t = i0 + 1; t < i; t++)
         mas[t][j - 1] = 0;
   }

   int flag = 0;
   int shift = i - 1;
   double* tm;
   while (flag == 0){
      for (int r = j0; r < j; r++)
         if (fabsl(mas[i0][r] - 0) >= exp){
            flag++;
            break;
         }
      if (flag == 0){
         if (i0==shift)
            return;
         tm = mas[i0];
         mas[i0] = mas[shift];
         mas[shift] = tm;
         shift--;
      }
   }

   while (fabsl(mas[i0][j0] - 0) < exp){
      if (i0 == shift){
         gauss(mas, i, j, i0, j0 + 1);
         return;
      }
      tm = mas[i0];
      mas[i0] = mas[shift];
      mas[shift] = tm;
      shift--;
   }
   double coef;
   for (int f = (i0 + 1); f < i; f++){
      if (mas[f][j0] == (double)0)
         continue;
      coef = -mas[f][j0] / mas[i0][j0];
      for (int t = j0; t < j; t++)
         mas[f][t] += mas[i0][t]*coef;
   }
   gauss(mas, i, j, i0+1, j0+1);
   return;
}

int main(void){
   int n;
   int k;
   printf("Enter n and k\n");
   scanf("%d %d", &n, &k);
   double** str = (double**)malloc(sizeof(double*) * k);
   for (int i = 0; i < k; i++){
      str[i] = (double*)malloc(sizeof(double) * n);
      for (int j = 0; j < n; j++)
         scanf("%lf", &str[i][j]);
   }
      
   gauss(str, k, n, 0, 0);
  
   int r = rank(str, k, n);
   if (r == k)
      printf("rank=%d, independent", r);
   else printf("rank=%d, dependent", r);

   for (int i = 0; i < k; i++)
      free(str[i]);
   free(str);
   return 0;
}
