/* This approach:  every calling function will be passing the address of the variable to be manipulated.   */
#include <stdio.h>

void deduct_medical_insurance(float *, const float *);
void deduct_maternity_leave(float *, const float *);
void deduct_social_security(float *, const float *);
void deduct_tax(float *, const float *);

int main(void)
{
    void (*net_salary_funcs[4])(float *, const float *) = {deduct_tax, deduct_medical_insurance, deduct_maternity_leave, deduct_social_security};
    float gross = 0;
    float net = 0;

    printf("Enter Gross: ");
    scanf("%f", &gross);
    if (gross <= 0)
    {
        return 1;
    }

    net = gross; // initialize net

    // deduct from net
    for (int i = 0; i < 4; i++)
        net_salary_funcs[i](&net, &gross);

    printf("Net Salary: %.2f\n", net);
    return 0;
}

void deduct_medical_insurance(float *net, const float *gross)
{

    float insurance = (5.0 / 100.0) * *gross;
    *net -= insurance;
}

void deduct_maternity_leave(float *net, const float *gross)
{
    float m_leave = (0.3 / 100.0) * *gross;
    *net -= m_leave;
}

void deduct_social_security(float *net, const float *gross)
{
    float s_security = (3.0 / 100.0) * *gross;
    *net -= s_security;
}

void deduct_tax(float *net, const float *gross)
{
    float tax = 0;

    if (*gross <= 100)
        return;

    if (*gross <= 300)
    {
        tax = (20.0 / 100.0) * *gross;
        *net -= tax;
        return;
    }

    tax = (28.0 / 100) * *gross;
    *net -= tax;
}
