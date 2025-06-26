#include <stdio.h>
#include <math.h>

double Verziera_Agnesi(double pi);
double Bernoullis_Lemniscate(double pi);
double Quadratic_Hyperbola(double pi);

int main()
{
    double pi_start = -M_PI;
    double pi_end = M_PI;
    int steps = 42;
    double step = ((pi_end - pi_start) / (steps - 1));

    for (int i = 0; i < steps; i++)
    {
        double pi = pi_start + i * step;
        double VA = Verziera_Agnesi(pi);
        double BL = Bernoullis_Lemniscate(pi);
        double QH = Quadratic_Hyperbola(pi);

        printf("%0.7lf | %0.7lf | ", pi, VA);

        if (isnan(BL))
        { // Проверка на NaN
            printf("- | ");
        }
        else
        {
            printf("%0.7lf | ", BL);
        }
        if (QH < 0)
        {
            printf("-\n");
        }
        else
        {
            printf("%0.7lf\n", QH);
        }
    }

    return 0;
}

double Verziera_Agnesi(double pi)
{
    return pow(1, 3) / (pow(1, 2) + pow(pi, 2));
}

double Bernoullis_Lemniscate(double pi)
{
    return sqrt(sqrt(1 + 4 * pow(pi, 2)) - pow(pi, 2) - 1);
}

double Quadratic_Hyperbola(double pi)
{
    return 1.0 / pow(pi, 2);
}