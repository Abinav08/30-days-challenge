ALGORITHM:
1.START.
2.Read purchase amount, customer type, and delivery distance.
3.Calculate the discount using the customer type and purchase amount.
4.Subtract the discount from the purchase amount.
5.Calculate the delivery charge using the distance.
6.Add the amount after discount and delivery charge.
7.Display purchase amount, discount, amount after discount, delivery charge, and final payable amount.
8.STOP.

PROGRAM:
#include <stdio.h>
int main() {
float purchase, discount, afterDiscount;
float delivery, finalAmount, distance;
int type;
printf("Enter purchase amount: ");
scanf("%f", &purchase);
printf("Enter customer type (1=Student, 2=Regular): ");
scanf("%d", &type);
printf("Enter delivery distance in km: ");
scanf("%f", &distance);
if (type == 1 && purchase >= 2000) {
discount = purchase * 0.15;
}
else if (type == 1 && purchase < 2000) {
discount = purchase * 0.10;
}
else if (type == 2 && purchase >= 3000) {
discount = purchase * 0.08;
}
else{
discount = 0;
}
afterDiscount = purchase - discount;
if (distance <= 5) {
delivery = 40;
}
else if (distance <= 15) {
 delivery = 70;
}
else {
delivery = 100;
}
finalAmount = afterDiscount + delivery;
printf("\nPurchase Amount: Rs. %.2f\n", purchase);
printf("Discount Amount: Rs. %.2f\n", discount);
printf("Amount After Discount: Rs. %.2f\n", afterDiscount);
printf("Delivery Charge: Rs. %.2f\n", delivery);
printf("Final Payable Amount: Rs. %.2f\n", finalAmount);
return 0;
}
