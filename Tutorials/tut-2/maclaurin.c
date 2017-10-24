/*third tutorial*/
#include<stdio.h>
#include<math.h>

long factorial(long num){
	if (num < 2){
		return 1;
	}
	return num * factorial(num-1);
}

int main ()
{
	int terms;
	double theta, sin_theta, approx, difference, exponent;
	printf("\n\nMaclaurin's series");
	printf("\nWrite thera in radians: ");
	scanf("%lf", &theta);
	sin_theta = sin(theta);
	printf("\nSine theta is: %lf\n", sin_theta);
	approx = theta;
	difference = sin_theta - approx;
	printf("\nDifference after first: %lf", difference);
	terms = 1;
	exponent = 1;
	while (difference > 0.000001 || difference < -0.000001){
		exponent += 2;
		if (terms % 2 != 0){
			approx = approx - (pow(theta,exponent)/factorial(exponent));
		}
		else{
			approx = approx + (pow(theta,exponent)/factorial(exponent));
		}
		++terms;
		difference = sin_theta - approx;
		printf("\nApproximated value after %d iteration is %lf", terms, approx);
	}
	
	printf("\nNumber of required terms: %d\n\n", terms);
	return 0;
}
