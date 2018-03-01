//The program counts the numbers of integers inputted as well as the sum of all of them
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_COUNT_MAX 100

size_t read_numbers(int numbers[], size_t n) {
  unsigned int i = 0;

  /* note that in Linux you can signal end of file/stream by key combination ctrl-d */
    //While i is less than 100 and the scanner hasn't reached EOF, continue incrementing i by 1 for each number inputted/counted
  while (i < n && scanf("%d", &numbers[i]) != EOF) {
    i++;
  }

  return i;
}

int main(int argc, char *argv[]) {
  int numbers[NUMBER_COUNT_MAX];
  size_t numberlen;
  int i, sum;

  numberlen = read_numbers(numbers, NUMBER_COUNT_MAX);
  for (sum = 0, i = 0; i < numberlen; sum += numbers[i], i++);
  printf("read %d integers, total: %d\n", numberlen, sum);

  return 0;
}
