#include <stdio.h>
void initializeSeats(int seats[5][8]);
void displaySeats(int seats[5][8]);
int bookSeat(int seats[5][8], int row, int col);
int cancelSeat(int seats[5][8], int row, int col);
int reserveGroup(int seats[5][8], int groupSize);
void displayReport(int seats[5][8]);
int main()
{
int seats[5][8];
int choice, row, col, size;
initializeSeats(seats);
do
{
printf("\n--- SEATSMART MENU ---\n");
printf("1. Display seats\n");
printf("2. Book one seat\n");
printf("3. Cancel booking\n");
printf("4. Group reservation\n");
printf("5. Occupancy report\n");
printf("6. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);
if (choice == 1)
{
displaySeats(seats);
}
else if (choice == 2)
{
printf("Enter row (1-5) and seat (1-8): ");
scanf("%d %d", &row, &col);
if (bookSeat(seats, row, col) == 1)
{
printf("Seat booked!\n");
displaySeats(seats);
}
else
printf("Booking failed (invalid or already booked).\n");
}
else if (choice == 3)
{
printf("Enter row (1-5) and seat (1-8): ");
scanf("%d %d", &row, &col);
if (cancelSeat(seats, row, col) == 1)
{
printf("Booking cancelled!\n");
displaySeats(seats);
}
else
printf("Cancel failed (invalid or seat is not booked).\n");
}
else if (choice == 4)
{
printf("Enter group size (2-8): ");
scanf("%d", &size);
if (reserveGroup(seats, size) == 1)
displaySeats(seats);
else
printf("Reservation failed (invalid size or no block available).\n");
}
else if (choice == 5)
{
displayReport(seats);
}
else if (choice == 6)
{
printf("Thank you! Goodbye.\n");
}
else
{
printf("Invalid choice! Enter 1 to 6.\n");
}
} while (choice != 6);
return 0;
}
void initializeSeats(int seats[5][8])
{
int i, j;
for (i = 0; i < 5; i++)
for (j = 0; j < 8; j++)
seats[i][j] = 0;
}
void displaySeats(int seats[5][8])
{
int i, j;
printf("\n0 = Available, 1 = Booked\n");
printf("       S1 S2 S3 S4 S5 S6 S7 S8\n");
for (i = 0; i < 5; i++)
{
printf("Row %d  ", i + 1);
for (j = 0; j < 8; j++)
printf(" %d ", seats[i][j]);
printf("\n");
}
}
int bookSeat(int seats[5][8], int row, int col)
{
if (row < 1 || row > 5 || col < 1 || col > 8)
return 0;
row = row - 1;
col = col - 1;
if (seats[row][col] == 1)
return 0;
seats[row][col] = 1;
return 1;
}
int cancelSeat(int seats[5][8], int row, int col)
{
if (row < 1 || row > 5 || col < 1 || col > 8)
return 0;
row = row - 1;
col = col - 1;
if (seats[row][col] == 0)
return 0;
seats[row][col] = 0;
return 1;
}
int reserveGroup(int seats[5][8], int groupSize)
{
int i, j, k, free;
if (groupSize < 2 || groupSize > 8)
return 0;
for (i = 0; i < 5; i++)
{
for (j = 0; j <= 8 - groupSize; j++)
{
free = 1;
for (k = 0; k < groupSize; k++)
{
if (seats[i][j + k] == 1)
free = 0;
}
if (free == 1)
{
for (k = 0; k < groupSize; k++)
seats[i][j + k] = 1;
printf("Booked in Row %d from Seat %d.\n", i + 1, j + 1);
return 1;
}
}
}
return 0;
}
void displayReport(int seats[5][8])
{
int i, j, booked = 0, max = 0;
int count[5];
for (i = 0; i < 5; i++)
{
count[i] = 0;
for (j = 0; j < 8; j++)
{
if (seats[i][j] == 1)
count[i]++;
}
booked = booked + count[i];
if (count[i] > max)
max = count[i];
}
printf("\n--- OCCUPANCY REPORT ---\n");
printf("Booked seats    : %d\n", booked);
printf("Available seats : %d\n", 40 - booked);
printf("Occupancy       : %.2f%%\n", booked * 100.0 / 40);
if (max == 0)
printf("Busiest row(s)  : None\n");
else
{
printf("Busiest row(s)  : ");
for (i = 0; i < 5; i++)
{
if (count[i] == max)
printf("Row %d  ", i + 1);
}
printf("\n");
}
}
