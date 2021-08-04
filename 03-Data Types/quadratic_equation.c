#include <stdio.h>
#include <math.h>

void
quadratic_equation_solution(double a, double b, double c) {
    double d  = b*b - 4.0*a*c;
    double sd = sqrt(d);
    double r1 = (-b+sd) / (2.0*a);
    double r2 = (-b-sd) / (2.0*a);
    printf("%f & %f\n", r1, r2);
}

int
main(int argc, char const *argv[]) {
    double a = +1.0;
    double b = -4.0;
    double c = +3.9999999;

    quadratic_equation_solution(a, b, c);

    return 0;
}
