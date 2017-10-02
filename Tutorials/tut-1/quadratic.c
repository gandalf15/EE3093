/*second tutorial*/
#include<stdio.h>
#include<math.h>

int main()
{
  double num_a, num_b, num_c, root1, root2, tmp;
  int option;
  printf("\nCalculate roots of quadratic equation: ");
  printf("\nax2 + bx + c = 0");
  printf("\nwrite coefficients a, b & c of the quadratic equation");
  printf("\na = ");
  scanf("%lf", &num_a);
  printf("\nb = ");
  scanf("%lf", &num_b);
  printf("\nc = ");
  scanf("%lf", &num_c);
  //starart the calculation
  tmp = num_b*num_b - 4*num_a*num_c;
  if (tmp>=0){
    root1 = (-num_b + sqrt(tmp))/(2*num_a);
    root2 = (-num_b - sqrt(tmp))/(2*num_a);
    printf("\nFirst root is x = %lf", root1);
    printf("\nSecond root is x = %lf\n\n", root2);
  }
  else{
    root1 = (-1*num_b)/(2*num_a);
    root2 = (-1*num_b)/(2*num_a);
    tmp = sqrt(-tmp)/(2*num_a);
    printf("\nFirst root is x = %lf + %lfi", root1, tmp);
    printf("\nSecond root is x = %lf - %lfi\n\n", root2, tmp);
  }
  
  return 0;
}
