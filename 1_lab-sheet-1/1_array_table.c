/*Write a program to find the average expenditure of a company for each month of each year,
 each year and average over the range of years specified.
 Use arrays to construct a table, display the table of expenditure and find the sum and average.*/
#include <stdio.h>

#define MAX_YEARS 5
#define MONTHS 12

int main() 
{
    int expenditure[MAX_YEARS][MONTHS]; // 2D ARRAYy
    int start_year, end_year;

    printf("Enter the starting year: ");
    scanf("%d", &start_year);
    printf("Enter the ending year: ");
    scanf("%d", &end_year);

    for (int year = start_year; year <= end_year; year++)
    {
        printf("Enter the expenditure for the year %d: ", year);
        for (int month = 0; month < MONTHS; month++)
        {
            printf("Enter the expenditure for the month %d: ", month + 1); // moths from 1-12, not 0-11
            scanf("%d", &expenditure[year - start_year][month]);
        }
    }

    // table for expenditure
    printf("\nTable of expenditure\n");
    for (int year = 0; year < end_year - start_year + 1; year++)
    {
        printf("Year %d: \t", start_year + year);
        for (int month = 0; month < MONTHS; ++month)
        {
            printf("%d\t",expenditure[year][month]);
        }
        printf("\n");
    }
        // Calculate and display the average expenditure for each month of each year
    printf("\nAverage Expenditure for Each Month:\n");
    for (int month = 0; month < MONTHS; ++month) {
        int monthSum = 0;
        for (int year = 0; year < end_year - start_year + 1; ++year) {
            monthSum += expenditure[year][month];
        }
        printf("Month %d: %.2f\n", month + 1, (float) monthSum / (end_year - start_year + 1));
    }

    // Calculate and display the average expenditure for each year
    printf("\nAverage Expenditure for Each Year:\n");
    for (int year = 0; year < end_year - start_year + 1; ++year) {
        int yearSum = 0;
        for (int month = 0; month < MONTHS; ++month) {
            yearSum += expenditure[year][month];
        }
        printf("Year %d: %.2f\n", start_year + year, (float) yearSum / MONTHS);
    }

    // Calculate and display the overall average expenditure
    int totalSum = 0;
    for (int year = 0; year < end_year - start_year + 1; ++year) {
        for (int month = 0; month < MONTHS; ++month) {
            totalSum += expenditure[year][month];
        }
    }
    printf("\nOverall Average Expenditure: %.2f\n", (float) totalSum / ((end_year - start_year + 1) * MONTHS));

    return 0;
}