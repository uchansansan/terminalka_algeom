#define e 0.000000001
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double det(double** mas, int n){
   double d=1;
   for(int i=0;i<n;i++)
      d*=mas[i][i];
   return d;
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

void change_Column(double** mas, double* ans, int n, int m){
	for (int i = 0; i < n; i++){
      mas[i][m]=ans[i];
   }
}
void printmat(double** mas, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%lf ",mas[i][j]);
			}
		printf("\n");
		}
	
	}
	
void copymat(double** mas,double** mas1, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mas1[i][j]=mas[i][j];
			}
		}
	}
	
int main(void){
   int n;
   printf("Enter n\n");
   scanf("%d", &n);
   printf("Enter matrix\n");
   double** str = (double**)malloc(sizeof(double*) * n);
   double** str1 = (double**)malloc(sizeof(double*) * n);
   for (int i = 0; i < n; i++){
      str[i] = (double*)malloc(sizeof(double) * n);
      str1[i] = (double*)malloc(sizeof(double) * n);
      for (int j = 0; j < n; j++){
         scanf("%lf", &str[i][j]);
         str1[i][j]=0;
		}
   }
   printf("Enter answers\n");
   double* ans = (double*)malloc(sizeof(double*) * n);
   double* result = (double*)malloc(sizeof(double*) * n);
   for(int i=0;i<n;i++){
	   scanf("%lf",&ans[i]);
	   }
	 copymat(str,str1,n);  
   gauss(str1, n, n, 0, 0);
	double d = det(str1, n);
	//printf("%lf\n", d);
	
   for(int i=0; i<n; i++){
	   copymat(str,str1,n);
	   //printmat(str1,n);
	   //printf("*\n");
	   change_Column(str1,ans,n,i);
	   //printmat(str1,n);
	   //printf("\n");
	   gauss(str1, n, n, 0, 0);
	   double d1 = det(str1, n);
	   result[i]=d1/d;
		}
   
   printf("Solutions: \n");
   for (int i = 0; i < n; i++){
      //free(str[i]);
      printf("%lf\n", result[i]);
  }
   free(str);
  
}
