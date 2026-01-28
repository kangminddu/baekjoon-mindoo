#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
  int n = 0, x = 0;
  scanf("%d %d", &n, &x);
  int arr[n];
  for (int i = 0; i < n ; i++){
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n ; i++){
    if (arr[i] < x){
      printf("%d ", arr[i]);
    }
  }



  return 0;
}