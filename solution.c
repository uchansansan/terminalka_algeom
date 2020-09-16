#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main(void) {
	double a, b;
	int n;
	printf("Введите действительную часть числа:");
	scanf("%lf", &a);
	printf("Введите мнимую часть числа:");
	scanf("%lf", &b);
	printf("Введите натуральное число n:");
	scanf("%d", &n);
	double r = sqrt(a*a + b*b);//модуль
	double r1 = a*a + b*b;
  if(a>0)
	  printf("Тригонометрическая запись числа: %lf*(cos(%lf)+isin(%lf))\n",r,atan((double)b/a), atan((double)b/a));
  if((a<0)&&(b>0))
    printf("Тригонометрическая запись числа: %lf*(cos(%lf)+isin(%lf))\n",r,atan((double)b/a)+M_PI, atan((double)b/a)+M_PI);
  if((a<0)&&(b<0))
    printf("Тригонометрическая запись числа: %lf*(cos(%lf)+isin(%lf))\n",r,atan((double)b/a)-M_PI, atan((double)b/a)-M_PI);
	printf("Число обратное данному: %lf/%lf+i*%lf/%lf\n",a,r1,b,r1);

	printf("Число в степени n: %lf*(cos(%lf)+isin(%lf))\n",pow(r,(double)n), n*acos((double)a/r), n*asin((double)b/r));

	printf("Все корни n-ой степени из данного числа\n");
	for(int k=0;k<n;k++){
		printf("%lf*(cos(%lf+2pi*%lf)+isin(%lf+2pi*%lf))\n",pow(r,1/n),acos((double)a/r)/n, (double)k/n, acos((double)a/r)/n, (double)k/n);

	}
	return 0;
}
