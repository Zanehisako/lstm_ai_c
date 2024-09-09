#include <math.h>
#include <stdio.h>
#include <time.h>
double Sigmoid(double x) { return 1 / (1 + (pow(exp(1), -x))); }
double FastSigmoid(double x) { return 0.5 * ((x / (1 + fabs(x))) + 1); }
double FastTanh(double x) {
  const double a = 0.3333333333333333; // Approximate coefficients
  const double b = 0.6666666666666666;
  return x * (a + b * x * x) / (1.0 + a * x * x);
}
int main(int argc, char *argv[]) {
  clock_t start, end;
  double time_elapsed;
  start = clock();
  double s = Sigmoid(130328889002004);
  end = clock();
  time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
  printf("Sigmoid took : %lf ,result : %lf\n", time_elapsed, s);
  start = clock();
  double fs = Sigmoid(130328889002004);
  end = clock();
  time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
  printf("Fast Sigmoid took : %lf ,result : %lf\n", time_elapsed, fs);
  start = clock();
  double ft = Sigmoid(130328889002004);
  end = clock();
  time_elapsed = ((double)end - start) / CLOCKS_PER_SEC;
  printf("Fast Tanh took : %lf Fast Tanh took : %lf ,result : %lf\n",
         time_elapsed, ft);
  return 0;
}
