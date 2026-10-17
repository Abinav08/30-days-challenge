ALGORITHM:
1.	START the program.
2.	Display the menu with four choices.
3.	Read the user's choice.
4.	If choice 1, solve the linear equation.
5.	If choice 2, calculate the factorial using a loop.
6.	If choice 3, solve the quadratic equation and find the roots.
7.	If choice 4, display the exit message; otherwise, show an error for an invalid choice.
8.	Repeat the menu until the user selects Exit.
9.	STOP.
PROGRAM:
  #include <stdio.h>
int main(){
int ch, n, i, f;
float a, b, c, d, s, r1, r2;
do{
printf("\n1. Linear\n2. Factorial\n3. Quadratic\n4. Exit\n");
printf("Enter choice: ");
scanf("%d", &ch);
switch(ch) {
case 1:
printf("Enter a and b: ");
scanf("%f%f", &a, &b);
if(a != 0)
printf("x = %.2f", -b/a);
else if(b == 0)
printf("Infinite solutions");
else
printf("No solution");
break;
case 2:
printf("Enter n (0 to 12): ");
scanf("%d", &n);
if(n < 0 || n > 12)
printf("Invalid number");
else {
f = 1;
for(i = 1; i <= n; i++) {
f = f * i;
}
printf("Factorial = %d", f);
}
break;
case 3:
printf("Enter a, b and c: ");
scanf("%f%f%f", &a, &b, &c);
if(a == 0)
printf("Not quadratic");
else {
d = b*b - 4*a*c;
if(d < 0)
printf("No real roots");
else {
s = d;
for(i = 0; i < 20 && s > 0; i++)
s = (s + d/s) / 2;
if(d == 0)
printf("Equal root = %.2f", -b/(2*a));
else {
r1 = (-b+s)/(2*a);
r2 = (-b-s)/(2*a);
printf("Roots = %.2f %.2f", r1, r2);
}
}
}
break;
case 4:
printf("Program ended");
break;
default:
printf("Invalid choice");
}
} while(ch != 4);
return 0;
}

                                                      
