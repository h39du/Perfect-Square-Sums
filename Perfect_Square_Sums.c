#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  
  int num_elem = 0;
  // set array to max length 400
  int a[400] = {0};
  // read in numbers and set array
  int i = 0;
  while (true) {
    ++num_elem;
    int read_in = 0;
    scanf("%d", &read_in);
    a[i] = read_in;
    ++i;
    if (read_in == 0) {
      break;
    }
  }
  
  int n = sqrt(num_elem);
  
  // print the array
  for (int b = 0; b <= num_elem - 2; b += n) {
    int k = b;
    for (; k <= b + n - 1; ++k) {
      printf("%3d", a[k]);  
    }
    printf("\n");
  }
  printf("\n");
  // calculate row sums
  printf("Row sums: ");
  int upper = n - 1;
  int start = 0;
  for (int i = 0; i <= n - 1; ++i) {
    int rowsum = 0;
    for (; start <= upper; ++start) {
      rowsum += a[start];
    }
    upper += n;
    printf("%d ", rowsum);
  }
  printf("\n");
  // calculate column sums
  printf("Column sums: ");
  int upper1 = num_elem - n + 1;
  int i1 = 0;
  for (; i1 <= n - 1; ++i1) {
    int colsum = 0;
    int start = i1;
    for (; start <= upper1; start += n) {
      colsum += a[start];
    }
    upper1 += 1;
    printf("%d ", colsum);
  }
  printf("\n");
  int diasum1 = 0;
  for (int d = 0; d <= num_elem - 1; d += (n + 1)) {
    diasum1 += a[d];
  }
  int diasum2 = 0;
  for (int d = n - 1; d <= num_elem - n; d += (n - 1)) {
    diasum2 += a[d];
  }
  printf("Diagonal sums: %d %d\n", diasum1, diasum2);
}
