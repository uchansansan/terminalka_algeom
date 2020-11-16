#define e 0.000000001
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rank(double** mas, int i, int j){
   int r = 0;
   double u=0;
   
   for(int n=0;n<i;n++){
	   for(int m=0;m<j;m++){
		   u+=fabsl(mas[n][m]);
		 }
		if (u==0)
			r++;
		u=0;
	}
   return i-r;
}

void gauss(double** mas, int i, int j, int i0, int j0){
   if (i0 == (i - 1))
      return;
   else if (j0 == (j - 1)){
      if (fabsl(mas[i0][j0] - 0) < e)
         for (int t = i0; t < i; t++)
         {
            if (fabsl(mas[t][j - 1] - 0) >= e)
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
         if (fabsl(mas[i0][r] - 0)>=e){
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

   while (fabsl(mas[i0][j0] - 0) < e){
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

void printmat(double** mas, int n, int k){
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			printf("%lf ",mas[i][j]);
			}
		printf("\n");
		}
	
	}

int main(void){
   int n;
   int k;
   printf("Enter n and k\n");
   scanf("%d %d", &n, &k);
   double** str = (double**)malloc(sizeof(double*) * n);
   for (int i = 0; i < n; i++){
      str[i] = (double*)malloc(sizeof(double) * k);
      for (int j = 0; j < k; j++)
         scanf("%lf", &str[i][j]);
   }
   //printmat(str,n,k);
   //printf("\n");   
   gauss(str, n, k, 0, 0);
//printmat(str,n,k);
   int r = rank(str, n, k);
   if (r == n)
      printf("rank=%d, independent", r);
   else printf("rank=%d, dependent", r);

   for (int i = 0; i < n; i++)
      free(str[i]);
   free(str);
}
