PROGRAM
#include <stdio.h>
int main() {
int a[12];
int n, i, k, r;
printf("Enter N (5 to 12): ");
scanf("%d", &n);
while (n < 5 || n > 12) {
printf("Invalid N. Enter N (5 to 12): ");
scanf("%d", &n);
}
for (i = 0; i < n; i++) {
printf("Enter reading %d (0 to 1000): ", i + 1);
scanf("%d", &a[i]);
while (a[i] < 0 || a[i] > 1000) {
printf("Invalid reading. Enter again (0 to 1000): ");
scanf("%d", &a[i]);
}
}
printf("\nOriginal readings: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
int sum = 0, min = a[0], max = a[0];
for (i = 0; i < n; i++) {
sum = sum + a[i];
if (a[i] < min) min = a[i];
if (a[i] > max) max = a[i];
}
printf("Sum = %d\n", sum);
printf("Average = %.2f\n", (float)sum / n);
printf("Minimum = %d\n", min);
printf("Maximum = %d\n", max);
int second = -1, found = 0;
for (i = 0; i < n; i++) {
if (a[i] != max) {
if (found == 0 || a[i] > second) {
second = a[i];
  GNU nano 8.7.1                                                              clg6.c
found = 1;
}
}
}
if (found)
printf("Second-largest distinct value = %d\n", second);
else
printf("No second-largest distinct value exists.\n");
int peaks = 0;
for (i = 1; i < n - 1; i++) {
if (a[i] > a[i - 1] && a[i] > a[i + 1])
peaks++;
}
printf("Local peaks = %d\n", peaks);
int cur = 1, longest = 1;
for (i = 1; i < n; i++) {
if (a[i] > a[i - 1])
cur++;
else
cur = 1;
if (cur > longest)
longest = cur;
}
printf("Longest increasing run = %d\n", longest);
printf("Enter K (positive = right, negative = left): ");
scanf("%d", &k);
int shifts = ((k % n) + n) % n;
int s, temp;
for (s = 0; s < shifts; s++) {
temp = a[n - 1];
for (i = n - 1; i > 0; i--)
a[i] = a[i - 1];
a[0] = temp;
}
printf("Rotated array: ");
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
printf("Enter last two digits of your registration number (R): ");
scanf("%d", &r);
int d = (r % 9) + 1;
int count = 0;
for (i = 0; i < n; i++) {
if (a[i] % d == 0)
count++;
}
printf("D = %d\n", d);
printf("Values divisible by D in rotated array = %d\n", count);
return 0;
}
