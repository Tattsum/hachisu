#include <stdio.h>
#define NUM 5

struct st
{
  char name[20];
  int jpn;
  int eng;
  int math;
  int sum;
};

void score_add(struct st a[]){
  int i;
  for(i=0;i<NUM;i++){
    a[i].sum=a[i].jpn+a[i].eng+a[i].math;
  }
}

int max_score_jpn(struct st a[])
{
  int i;
  int max=0;
  for (i=1;i<NUM;i++){
    if (a[max].jpn<a[i].jpn){
      max=i;
    }
  }
  return max;
}

int max_score_eng(struct st a[])
{
  int i;
  int max=0;
  for (i=1;i<NUM;i++){
    if (a[max].eng<a[i].eng){
      max=i;
    }
  }
  return max;
}

int max_score_math(struct st a[])
{
  int i;
  int max=0;
  for (i=1;i<NUM;i++){
    if (a[max].math<a[i].math){
      max=i;
    }
  }
  return max;
}

int min_score_jpn(struct st a[])
{
  int i;
  int min=0;
  for (i=1;i<NUM;i++){
    if (a[min].jpn>a[i].jpn){
      min=i;
    }
  }
  return min;
}

int min_score_eng(struct st a[])
{
  int i;
  int min=0;
  for (i=1;i<NUM;i++){
    if (a[min].eng>a[i].eng){
      min=i;
    }
  }
  return min;
}

int min_score_math(struct st a[])
{
  int i;
  int min=0;
  for (i=1;i<NUM;i++){
    if (a[min].math>a[i].math){
      min=i;
    }
  }
  return min;
}

int main(void){
  struct st x [NUM];
  int i;

  for(i=0;i<NUM;i++){
    printf("student No. %d \n",i);

    printf("Name?");
    scanf("%s",x[i].name);

    printf("Japanese?");
    scanf("%d",&x[i].jpn);

    printf("English?");
    scanf("%d",&x[i].eng);

    printf("Math?");
    scanf("%d",&x[i].math);

    printf("\n");
  }
  score_add(x);
  printf(" 名前　国語　英語　数学　合計\n");
  printf("-----------------------------\n");
  for(i=0;i<NUM;i++){
    printf("%8s %3d %3d %3d %3d\n",x[i].name,x[i].jpn,x[i].eng,x[i].math,x[i].sum);
  }
  printf("-----------------------------\n");

  double ave_jpn=0,ave_eng=0,ave_math=0,ave_sum=0;
  for(i=0;i<=NUM;i++){
    ave_jpn += x[i].jpn;
    ave_eng += x[i].eng;
    ave_math += x[i].math;
    ave_sum += x[i].sum;
  }

  printf("平均点 %.1f %.1f %.1f %.1f\n",ave_jpn/NUM,ave_eng/NUM,ave_math/NUM,ave_sum/NUM);

  int max_jpn=max_score_jpn(x), max_eng=max_score_eng(x),max_math = max_score_math(x),min_jpn=min_score_jpn(x),min_eng=min_score_eng(x),min_math=min_score_math(x);

  printf("国語　最高点: %3d(%8s),最低点: %3d(%8s)\n",x[max_jpn].jpn,x[max_jpn].name,x[min_jpn].jpn,x[min_jpn].name);
  printf("英語　最高点: %3d(%8s),最低点: %3d(%8s)\n",x[max_eng].eng,x[max_eng].name,x[min_eng].eng,x[min_eng].name);
  printf("数学　最高点: %3d(%8s),最低点: %3d(%8s)\n",x[max_math].math, x[max_math].name, x[min_math].math, x[min_math].name);

  return 0;
}
