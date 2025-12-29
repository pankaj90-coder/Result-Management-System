#include <stdio.h>
#include <string.h>

int n, s;
int roll[20];
char name[20][20];
int marks[20][10];
float total[20]; 
float percent[20];


void inputData();
void displayMarksheet();
void rankList();
void subjectTopper();

int main()
{
    int choice;

    do
    {
        printf("\n=== RESULT MANAGEMENT SYSTEM ===");
        printf("\n1. Enter Student Data");
        printf("\n2. Display Marksheet");
        printf("\n3. Rank List");
        printf("\n4. Subject Topper");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            inputData();
            break;
        case 2:
            displayMarksheet();
            break;
        case 3:
            rankList();
            break;
        case 4:
            subjectTopper();
            break;
        case 5:
            printf("\nThank you for using the Result Management System!");
            break;
        default:
            printf("\nInvalid choice! Please select a valid option.");
        }

    } while (choice != 5);

    return 0;
}


void inputData()
{
    int i, j;

   
    printf("\nEnter number of students: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Number of students must be greater than 0.\n");
        return;
    }

    printf("Enter number of subjects: ");
    scanf("%d", &s);
    if (s <= 0) {
        printf("Number of subjects must be greater than 0.\n");
        return;
    }

   
    for (i = 0; i < n; i++)
    {
        total[i] = 0;

        printf("\nStudent %d Roll No: ", i + 1);
        scanf("%d", &roll[i]);

       
        getchar(); 

        printf("Student Name: ");
        scanf("%[^\n]%*c", name[i]); 

       
        for (j = 0; j < s; j++)
        {
            do {
                printf("Marks of subject %d (0 to 100): ", j + 1);
                scanf("%d", &marks[i][j]);
                if (marks[i][j] < 0 || marks[i][j] > 100) {
                    printf("Invalid marks! Please enter marks between 0 and 100.\n");
                }
            } while (marks[i][j] < 0 || marks[i][j] > 100);

            total[i] = total[i] + marks[i][j];
        }

        percent[i] = total[i] / (float)s; 
    }

    printf("\nData entered successfully!\n");
}


void displayMarksheet()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        printf("\n---");
        printf("\nRoll No: %d", roll[i]);
        printf("\nName: %s", name[i]);

       
        for (j = 0; j < s; j++)
        {
            printf("\nSubject %d Marks: %d", j + 1, marks[i][j]);
        }

        printf("\nTotal Marks: %.2f", total[i]);
        printf("\nPercentage: %.2f%%", percent[i]);

       
        if (percent[i] >= 33)
            printf("\nResult: PASS");
        else
            printf("\nResult: FAIL");

        printf("\n---");
    }
}


void rankList()
{
    int i, j;
    int tempTotal, tempRoll;
    float tempPercent;
    char tempName[20];

   
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (total[i] < total[j])
            {
                tempTotal = total[i];
                total[i] = total[j];
                total[j] = tempTotal;

                tempPercent = percent[i];
                percent[i] = percent[j];
                percent[j] = tempPercent;

                tempRoll = roll[i];
                roll[i] = roll[j];
                roll[j] = tempRoll;

                
                strcpy(tempName, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tempName);
            }
        }
    }

  
    printf("\n=== RANK LIST ===");
    for (i = 0; i < n; i++)
    {
        printf("\nRank %d: %s (Total: %.2f, Percentage: %.2f%%)", i + 1, name[i], total[i], percent[i]);
    }
}


void subjectTopper()
{
    int i, j, max, topper;

    for (j = 0; j < s; j++)
    {
        max = marks[0][j];
        topper = 0;

       
        for (i = 1; i < n; i++)
        {
            if (marks[i][j] > max)
            {
                max = marks[i][j];
                topper = i;
            }
        }

       
        printf("\nSubject %d Topper: %s (Marks: %d)", j + 1, name[topper], max);
    }
}
