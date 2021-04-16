#include<stdio.h>
#include<math.h>

void area_triangle(double, double, double);
void isspecialtriangle(double, double, double);

int main()
{
    double dNum_1, dNum_2, dNum_3;
    printf("please input three numbers:\n");
    scanf("%f%f%f", &dNum_1, &dNum_2, &dNum_3);
    if ((dNum_1 + dNum_2) < dNum_3 && (dNum_1 + dNum_3) < dNum_2 && (dNum_2 + dNum_3) < dNum_1)
    {
        printf("They can form a triangle\n");
        isspecialtriangle(dNum_1, dNum_2, dNum_3);
        area_triangle(dNum_1, dNum_2, dNum_3);
    }
    else
        printf("They can't form a triangle\n");
    return 0;
}

void area_triangle(double dNum_1, double dNum_2, double dNum_3)
{
    double p, dArea;
    p = (dNum_1 + dNum_2 + dNum_3) / 2;
    dArea = sqrt(p * (p - dNum_1) * (p - dNum_2) * (p - dNum_3));
    printf("The area of this triangle is %.2f\n", dArea);
}
void isspecialtriangle(double dNum_1, double dNum_2, double dNum_3)
{
    if (dNum_1 * dNum_1 + dNum_2 * dNum_2 == dNum_3 * dNum_3 || dNum_2 * dNum_2 + dNum_3 * dNum_3 == dNum_1 * dNum_1 || dNum_3 * dNum_3 + dNum_1 * dNum_1 == dNum_2 * dNum_2)
        printf("This triangle is a right triangle\n");
    if (dNum_1 == dNum_2 || dNum_2 == dNum_3 || dNum_1 == dNum_3)
        printf("This triangle is an isosceles triangle\n");
    if (dNum_1 == dNum_2 == dNum_3)
        printf("This triangle is an equilateral triangle\n");
}