//
// Created by XX on 2025/02/09.
//

#include <stdio.h>
#include <math.h>

double npv(int *cfs, int t, double irr);
double caculate_irr(int *cfs, int t);

int main()
{
    double result[26];
    int count = 0;
    
    while(1)
    {
        int t = 0;
        int cfs[11];
        scanf("%d", &t);
        if(t == 0)
        {
            break;
        }
        for (int i = 0; i <= t; i++)
        {
            scanf("%d", &cfs[i]);
        }
        result[count] = caculate_irr(cfs, t + 1);
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        if (result[i] == -9999) printf("No\n");
        else if (result[i] == 9999) printf("Too many\n");
        else printf("%.2lf\n", result[i]);
    }
    return 0;
}

double caculate_irr(int *cfs, int t)
{
    double irr = 0;
    double e = 0.001;
    double irr1 = -1;
    double irr2 = 10;
    int count = 0;
    double irr_temp = 0;
    for (int i = 0; i < 10000; i++)
    {
        irr = (irr1 + irr2) / 2;
        double sum = npv(cfs, t, irr);
        if (sum > 0)
        {
            irr1 = irr;
        }
        else
        {
            irr2 = irr;
        }
        if (irr2 - irr1 < e) break;
        if (fabs(sum) < e)
        {
            if (abs(irr - irr_temp) >= 0.1 && count > 1) 
            {
                count++;
                break;
            }
            count++;
            if (abs(irr - irr_temp) < 0.1 && count > 1) count--;
            irr_temp = irr;
        }
    }
    if (count > 1)
    {
        return 9999;
    }
    else if (count == 1)
    {
        return irr;
    }
    else
    {
        return -9999;
    }
}
double npv(int *cfs, int t, double irr)
{
    double sum = 0;
    for (int i = 0; i < t; i++)
    {
        sum += cfs[i] / pow(1 + irr, i);
    }
    return sum;
}

