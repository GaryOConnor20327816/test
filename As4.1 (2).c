/* Gary O'Connor Assignment 4 Q1
 * write a program that finds integral of (a*x^alpha +b*x +c) from 1 to 8
 * program should read in alpha,a,b,c and find the corresponding integral above 
 * using both numerical and analytical approches and display integrals to screen
 * program should also find corresponding difference between the two approches
 */


#include <stdio.h>
#include <math.h>


double f(double ,double ,double,double,double);
double integral_f(double ,double ,double,double,double);


int main(void){
    
    double alpha;
    int i, steps;
    double a,b,c;
    double lower_limit,upper_limit,h,x;
    double simp,simp_exact;
    double lower_exact,upper_exact;
    double difference;
    int ans;
    
    ans=1;
    
    while(ans==1){
        
        printf("\n");
        
        printf("this program integrates a function a*pow(x,alpha) +b*x +c from 1 to 8\n");
        
        printf("\n");
        
        /*reading in value by user for the polynomial to be integrated and stepsize for simps rule*/
        
        printf("Please Enter a value for alpha: ");
        if(scanf("%lf",&alpha) !=1){
            printf("that wasnt a number rerun program to try again! \n");
            return 1;
        }
        
        printf("Please Enter a value for a: ");
        if(scanf("%lf",&a) !=1){
            printf("that wasnt a number rerun program to try again! \n");
            return 1;
        }
        
        printf("Please Enter a value for b: ");
        if(scanf("%lf",&b) !=1){
            printf("that wasnt a number rerun program to try again! \n");
            return 1;
        }
        
        printf("Please Enter a value for c: ");
        if(scanf("%lf",&c) !=1){
            printf("that wasnt a number rerun program to try again! \n");
            return 1;
        }
        
        printf("Please Enter a value for steps: ");
        if(scanf("%d",&steps) !=1){
            printf("that wasnt a number rerun program to try again! \n");
            return 1;
        }
        
        printf("\n");
        
        /*Numerical approach of integral of polynomial- simpsons rule algorithm*/
        
        
        lower_limit=1;
        upper_limit=8;
        
        h=(upper_limit-lower_limit)/steps;
        
        simp=-f(a,b,c,alpha,lower_limit);
    
        x = lower_limit;
        
        for (i = 0; i < steps; i += 2) {
            simp += 2.0*f(a,b,c,alpha,x)+4.0*f(a,b,c,alpha,x+h);
            x += 2*h;
        
        }
        
        simp += f(a,b,c,alpha,upper_limit);
        simp *= h/3.0;

    
        /*Analytical solution to integral of polynomial*/
        
        
        upper_exact =integral_f(a,b,c,alpha,upper_limit);
        lower_exact =integral_f(a,b,c,alpha,lower_limit);
        
        simp_exact= upper_exact - lower_exact;
        
        difference= simp - simp_exact;
        
        
        /*information being printed to screen*/
        
        
        printf("Analytical integral of %lg*x^(%lg) + %lg*x +%lg between 1 and 8 is %lg\n",a,alpha,b,c,simp_exact);
        
        printf("\n");
        
        printf("Numerical integral using simpsons rule approximation is %lf with %d steps\n",simp,steps);
        
        printf("\n");
        
        printf("the difference between Numerical and Analytical is %lf\n",fabs(difference));
        
        printf("\n");
        
        
        /*asking use if user would like to go again*/
        
        
        printf("Enter 1 to enter new values for integral or any other key to exit program!: ");
        
        if(scanf("%d",&ans) !=1){
            return 1;
        }
        
        
    printf("\n");
    
    }
    
    return 0;
}

double f(double a,double b,double c,double alpha,double x){    
    return  a*pow(x,alpha) + b*x + c;
}

double integral_f(double a,double b,double c,double alpha,double x){
    return (a/(alpha+1))*pow(x,alpha +1) +(b/2)*x*x +c*x;
}

/*when alpha is 0,1,2 or 3 the integral analytical and numberical are exactly the same even with small step sizes (e.g 10 steps) regardless of the choice for a b and c, once alpha = 4 or above there was a difference between the numerical and analyitical approach */