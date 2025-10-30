/* This approach: Each of the deductions is a standalone function that returns the calculated value */
#include <stdio.h>

float deduct_medical_insurance(const float *);
float deduct_maternity_leave(const float *);
float deduct_social_security(const float *);
float deduct_tax(const float *);
float net_salary_calculator(const float *);

int main(void)
{
    float gross = 0;
    float net = 0;

    printf("Enter Gross: ");
    scanf("%f", &gross);
    if (gross <= 0)
        return 1;

    // calculate net salary.
    net = net_salary_calculator(&gross);

    printf("Net Salary: %.2f\n", net);
    return 0;
}

float deduct_medical_insurance(const float *gross)
{

    float insurance = (5.0 / 100.0) * *gross;
    return insurance;
}

float deduct_maternity_leave(const float *gross)
{
    float m_leave = (0.3 / 100.0) * *gross;
    return m_leave;
}

float deduct_social_security(const float *gross)
{
    float s_security = (3.0 / 100.0) * *gross;
    return s_security;
}

float deduct_tax(const float *gross)
{
    float tax = 0;

    if (*gross > 100 && *gross <= 300)
        tax = (20.0 / 100.0) * *gross;

    if (*gross > 300)
        tax = (28.0 / 100.0) * *gross;

    return tax;
}

float net_salary_calculator(const float *gross)
{
    float (*deduction_funcs[4])(const float *) = {deduct_tax, deduct_maternity_leave, deduct_medical_insurance, deduct_social_security};
    float deductions = 0;
    float net = 0;

    for (int i = 0; i < 4; i++)
        deductions += deduction_funcs[i](gross);

    net = *gross - deductions;
    return net;
}