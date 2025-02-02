#include <stdio.h>

int tempConvert(int Fahrenheit) {
  int celsius = 0;
  celsius = (5.0 / 9.0) * (Fahrenheit-32);
  return celsius;
}



int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("Fahrenheit \t Celsius\n");
  fahr = upper;
  while(fahr >= lower) {
    celsius = tempConvert(fahr);
    printf("%7.0f     |  %6.1f\n", fahr, celsius);
    fahr = fahr - step;
  }
}