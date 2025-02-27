#include <stdio.h>

void full_pyramid(){
  for(int i = 0 ; i<5; i++){
    for(int j = 0 ; j< 2*(5-i)-1 ; j++){
      printf(" ");
    }
    for(int k = 0; k<i*2 + 1; k++){
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");
}
void inverted_full_pyramid(){
  for(int i=0; i<5; i++){
    for(int j=0; j<i; j++){
       printf(" ");
    }
    for(int k=0;k<5-i;k++){
       printf("* ");
    }
    printf("\n");
  }
  printf("\n"); 
}
void rhombus(){
  for(int i=0; i<5; i++){
    for(int k=0; k<i; k++){
       printf(" ");
    }
    for(int j=0; j<5; j++){
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");
}
void diamond(){
  int n = 5;

  for(int i=0; i<2*n -1; i++){
    int cunt;
    if(i < n){
      cunt = 2*(n-i)-1;
    }
    else {
      cunt = 2*(i-n+1)+1;
    }
    for(int j=0; j<cunt; j++){
      printf(" ");
    }
    for(int k=0; k<2*(n)-cunt;k++){
      printf("* ");
    }
    printf("\n");
  }
  printf("\n");
}
void hourglass(){
 for(int i=0; i<9; i++){
  if(i<5){
    for(int j=0; j<i; j++){
      printf(" ");
    }
    for(int k=0; k<5-i; k++){
      printf("* ");
    }
  printf("\n");
  }
  else{
    for(int j=0; j<8-i; j++){
      printf(" ");
    }
    for(int k=0; k<i-3; k++){
      printf("* ");
    }
  printf("\n");
  }
 }
  printf("\n");
}
void hollow_square(){
  int n=5;
  for (int i=0; i<n; i++) {
    for(int j=0; j<n; j++){
      if(i==0||i==n-1||j==0||j==n-1){
        printf("* ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void hollow_pyramid(){
	int n = 5;
  for(int i=0; i<n; i++){
    for(int j=0; j<(n-i)-1; j++){
      printf("  ");
    }
    for(int k=0; k<2*i +1; k++){
      if(k==0||k==2*i||i==n-1){
        printf("* ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}
void hollow_inverted_pyramid(){
  int n=5;
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      printf("  ");
    }
    for(int k=0; k<2*(n-i)-1;k++){
      if(i==0||k==0||k==2*(n-i)-2){
        printf("* ");
      }
      else{
        printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}


int main() {
  full_pyramid();
  inverted_full_pyramid();
  rhombus();  
  diamond();
  hourglass();
  hollow_square();
  hollow_pyramid();
  hollow_inverted_pyramid();
  return 0;
}

