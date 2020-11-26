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



void remove_i_j(double **arr1,double **arr2, int i1, int j1, int n){
  //double** arr2 = (double**)malloc(sizeof(double*) * (n-1));
  for (int i = 0; i < n; i++){
    //arr2[i] = (double*)malloc(sizeof(double) * n);
    for (int j = 0; j < n; j++){
      if((i!=i1)&&(j!=j1)){
        arr2[i >= i1 ? i - 1 : i][j >= j1 ? j - 1 : j] = arr1[i][j];
      }
      }
    }
  }


void transpose_matrix(double **arr1, double **arr2, int n){
  double **arrPtr1 = arr1;
  double **arrPtr2 = arr2;
  int i, j;
 
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      arrPtr2[j][i] = arrPtr1[i][j];
  }
}

void copymat(double** mas,double** mas1, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mas1[i][j]=mas[i][j];
			}
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


void smulti(double **m, int n, double a){
    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++){
            m[row][col] *= a;
        }
}

int main(void){
   int n;
   printf("Enter n:\n");
   scanf("%d", &n);
   double** str = (double**)malloc(sizeof(double*) * n);
   double** str_c = (double**)malloc(sizeof(double*) * n);
   double** tr = (double**)malloc(sizeof(double*) * n);
   double** minor = (double**)malloc(sizeof(double*) * n);
   double** str_n = (double**)malloc(sizeof(double*) * (n-1));

   for (int i = 0; i < n; i++){
      str[i] = (double*)malloc(sizeof(double) * n);
      str_c[i] = (double*)malloc(sizeof(double) * n);
      minor[i] = (double*)malloc(sizeof(double) * n);
      tr[i] = (double*)malloc(sizeof(double) * n);
      for (int j = 0; j < n; j++){
         scanf("%lf", &str[i][j]);
        //printf("%lf", str[i][j]);
         tr[i][j]=0;
         str_c[i][j]=0;
         minor[i][j]=0;
         }
        // printf("\n");
   }

   for (int i = 0; i < n-1; i++){
     str_n[i] = (double*)malloc(sizeof(double) * (n-1));
     for (int j = 0; j < n-1; j++){
       str_n[i][j]=0;
     }
   } 
    copymat(str, str_c, n);
   gauss(str, n, n, 0, 0);
  
   double d = det(str, n);
  if (d==0){
    printf("no way to find inverse matrix");
  }
  else{
    
    //gauss_wo(str, n, n, 0, 0, i_r, j_r);
    copymat(str_c, tr, n);
    //printmat(str_c, n);
    remove_i_j(str_c, str_n, 0, 0, n);
    //printmat(str_n,n-1);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        copymat(str_c, tr, n);
        remove_i_j(str_c, str_n, i, j, n);

        gauss(str_n, n-1, n-1, 0, 0);
        minor[i][j]=pow(-1,i+j)*det(str_n,n-1);
      }

    }
    transpose_matrix(minor, tr, n);
    smulti(tr, n, 1/d);
    printf("Inverse matrix:\n");
    printmat(tr,n);

  }
  //printf("determinant: %lf", d);
   
   for (int i = 0; i < n; i++)
      free(str[i]);
   free(str);
}
