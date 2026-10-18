#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>
#define Q0 500.0
#define SMAX 1000.0
#define WARN 700.0
#define X_MAX 100000
int main()
{
    int n, i;
    int k;
    double x, q;
    double s;
    setlocale(LC_ALL, "RUS");
    k = 0;
    printf("Q0 = %.2f, Smax = %.2f, порог предупреждения = %.2f\n", Q0, SMAX, WARN);
    printf("Сколько показаний датчика будете вводить?: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("X%d = ", i);
        scanf("%lf", &x);
        if (x < 0 || x > X_MAX)
        {
            printf("Ошибка: X должен быть от 0 до %d\n", X_MAX);
            continue;
        }
        if (x < 200)
        {
            q = 2 * x + 20;
        }
        else if (x < 400)
        {
            q = 1.2 * x + 180;
        }
        else
        {
            q = 0.7 * x + 380;
        }
        k = k + 1;
        s = fabs(q - Q0);
        printf("X = %.2f  Q = %.2f  отклонение = %.2f  ", x, q, s);
        if (s > SMAX)
        {
            printf("ТРЕВОГА отклонение превысило Smax\n");
        }
        else if (s > WARN)
        {
            printf("ПРЕДУПРЕЖДЕНИЕ отклонение приближается к Smax\n");
        }
        else
        {
            printf("НОРМА отклонение в допустимых пределах\n");
        }
    }
}
