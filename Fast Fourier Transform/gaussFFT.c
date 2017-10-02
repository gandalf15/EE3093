#include<stdio.h>
#include<math.h>
#define size 4096
#define Pi 3.141592653589793

int main()
{
    int n,n1;
    int m,l,p,q,r;
    double t[size]={0},f[size]={0};
    double x[size]={0},y[size]={0};
    double x0[size]={0},y0[size]={0};
    int i,j,k;
    double T0, A0, T, df, fmax, dt;
    double t1,t2,a,e,c,s;
    
    FILE *cPtr;
    
    printf("Enter the Gaussian pulse width\n");
    scanf("%lf",&T0);
    printf("Enter the Gaussian pulse peak amplitude\n");
    scanf("%lf",&A0);
    
    T = 20*T0;                /* calculation of timing window */
    df = 1/T;                 /* frequency sampling width */
    fmax = 160/(2*Pi*T0);    /* maximum frequency window size */
    dt = 1/(2*fmax);          /* time sampling width */
    
    /* calculation of 2 power m points for radix-2 fft */
    //N = (int)(T/dt);
    
    n = 2;
    do
    {
        n *= 2;
    }while(n*dt <= T);
       
    printf("Number of FFT points = %d\n",n);
    dt = (double)T/n;
    fmax = 1/(2.0*dt);
    n1 = n/2;
    
    //printf("T = %f\n",T);
    //printf("dt = %f\n",dt);
    //printf("N = %d\n",N);
    //printf("n = %d\n",n);
    
    //t[0] = -T/2;
    //df = (double)2*fmax/n;
    //f[0] = -fmax;

    for(i = 0; i < n; i++)
    {
        t[i] = (double)(-n1+i)*dt;
        f[i] = (double)(-n1+i)*df;
    }
        
    for(i = 0; i < n; i++)
    {
        x[i] = A0*exp(-(t[i]*t[i]/(T0*T0)));
        x0[i] = x[i];
        y0[i] = y[i];
    }
    
    l = n;
    m = 0;
    while(l/2 != 0)
    {
        m++;
        l /= 2;
    }
    /*
    printf("Radix 2 points are %d\n",m);
    printf("Original data\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }
    */
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
    /*   
    printf("Bit reversed data\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }
    */
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
    /*
    printf("Data in the Fourier domain\n");

    for(i = 0; i < n; i++)
    {
        printf("x[%d] = %.2f\n",i,x[i]);
        printf("y[%d] = %.2f\n",i,y[i]);
    }
    */
    if((cPtr = fopen("data.txt","w")) == NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            fprintf(cPtr,"%f\t%f\t%f\t%f\t%f\t%f\n",t[i],f[i],x0[i],y0[i],x[i],y[i]);
        }
    }
    
    return 0;
}
