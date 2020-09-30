#include <stdio.h>

int is_collinear(int vector1[], int vector2[]){
  int x1 = vector1[0];
  int x2 = vector2[0];
  int y1 = vector1[1];
  int y2 = vector2[1];
  int z1 = vector1[2];
  int z2 = vector2[2];
  if(y1*z2-y2*z1==0 && x1*z2-x2*z1==0 && x1*y2-x2*y1==0)
    return 1;
  return 0;
}

int is_complanar(int v[3][3]){
  if(v[0][0]*v[1][1]*v[2][2]+
  v[0][1]*v[1][2]*v[2][0]+
  v[0][2]*v[1][0]*v[2][1]-
  v[0][2]*v[1][1]*v[2][0]-
  v[0][0]*v[1][2]*v[2][1]-
  v[0][1]*v[1][0]*v[2][2]==0)
    return 1;
  return 0;
}
int main(void) {
  int vectors[3][3];
  int vector1[3],vector2[3],vector3[3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&vectors[i][j]);
      if (i==0)
        vector1[j]=vectors[i][j];
      if (i==1)
        vector2[j]=vectors[i][j];
      if (i==2)
        vector3[j]=vectors[i][j];
    }
  }
  //printf("%d",is_collinear(vector1,vector2));
  int flag=0;
  if(is_collinear(vector1,vector2)){
    printf("Вектор 1 коллинеарен вектору 2\n");
    flag++;}
  if(is_collinear(vector1,vector3)){
    printf("Вектор 1 коллинеарен вектору 3\n");
    flag++;}
  if(is_collinear(vector2,vector3)){
    printf("Вектор 2 коллинеарен вектору 3\n");
    flag++;}
  printf("Векторы компланарны:%s\n",is_complanar(vectors)==0 ? "да":"нет");
  if(flag==0){
    printf("Нет коллиниарных векторов\n");
  }
  return 0;
}
