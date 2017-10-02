#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    int m,l,p,q,r;
    double x[1024],y[1024];
    int i,j,k;
    double t1,t2,a,e,c,s;
    
    printf("Enter the points in 2 power n for the fft\n");
    scanf("%d",&n);
    
    for(i = 0; i < n; i++)
    {
        x[i] = i;
        y[i] = i;
    }
    
    l = n;
    m = 0;
    while(l/2 != 0)
    {
        m++;
        l /= 2;
    }
    
    printf("Radix 2 points are %d\n",m);
    printf("Original data\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }

    for(i = 0; i < n; i++)
    {
        p = i;
        q = 0;
        for(j = m-1; j >= 0; j--)
        {
            for(k = 0,r = 1; k < j; k++)
            {
                r *= 2;
            }
            q += (p%2)*r;
            p /= 2;
        }
        if(q > i)
        {
             t1 = x[q];
             t2 = y[q];
             x[q] = x[i];
             y[q] = y[i];
             x[i] = t1;
             y[i] = t2;
        }
    }
        
    printf("Bit reversed data\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }
    
    l = 0;
    p = 1;
    for(i = 0; i < m; i++)
    {
        l = p;
        p *= 2;
        e = -6.283185307179586/p;
        a = 0.0;
        
        for(j = 0; j < l; j++)
        {
            c = cos(a);
            s = sin(a);
            a = a + e;
            
            for(k = j; k < n; k = k+p)
            {
                t1 = c*x[k+l] - s*y[k+l];
                t2 = s*x[k+l] + c*y[k+l];
                x[k+l] = x[k] - t1;
                y[k+l] = y[k] - t2;
                x[k] = x[k] + t1;
                y[k] = y[k] + t2;
            }
        }
    }
    
    printf("Data in the Fourier domain\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }

    return;
}
