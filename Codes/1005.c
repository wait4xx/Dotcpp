//
// Created by XX on 2024/12/21.
//

# include <stdio.h>

int main(){
  float f;
  scanf("%f", &f);
  float c = 5 * (f - 32) / 9;
  printf("c=%.2f", c);
  return 0;
}