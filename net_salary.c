#include <stdio.h>

void deduct_medical_insurance(float *, const float *);
void deduct_maternity_leave(float *, const float *);
void deduct_social_security(float *, const float *);
void deduct_tax(float *, const float *);

int main(void)
{
    float gross = 0;
    float net = 0;

    printf("Enter Gross: ");
    scanf("%f", &gross);

    net = gross;
    deduct_medical_insurance(&net, &gross);
    deduct_maternity_leave(&net, &gross);
    deduct_social_security(&net, &gross);
    deduct_tax(&net, &gross);

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
