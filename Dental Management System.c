#include <stdio.h>
#include <string.h>

struct Patient
{
    int id;
    char name[50];
    int age;
    char contact[15];
    char appointmentDate[20];
};

int main()
{
    struct Patient patients[100];
    int count = 0;
    int choice;

    do
    {
        printf("\n--- Dental Clinic Management System ---\n");
        printf("1. Register Patient\n");
        printf("2. Book Appointment\n");
        printf("3. Display All Patients\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n--- Register New Patient ---\n");
            printf("Enter Patient ID: ");
            scanf("%d", &patients[count].id);

            printf("Enter Name: ");
            scanf("%s", patients[count].name);

            printf("Enter Age: ");
            scanf("%d", &patients[count].age);

            printf("Enter Contact No: ");
            scanf("%s", patients[count].contact);

            strcpy(patients[count].appointmentDate, "Not Booked");

            count++;
            printf("Patient Registered Successfully!\n");
            break;

        case 2:
        {
            int searchId;
            int found = 0;

            printf("\nEnter Patient ID to book appointment: ");
            scanf("%d", &searchId);

            for (int i = 0; i < count; i++)
            {
                if (patients[i].id == searchId)
                {
                    printf("Enter Appointment Date (dd-mm-yyyy): ");
                    scanf("%s", patients[i].appointmentDate);

                    printf("Appointment Booked for %s on %s\n",
                           patients[i].name,
                           patients[i].appointmentDate);

                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Patient not found!\n");
            }
            break;
        }

        case 3:
            printf("\n--- Patient Records ---\n");

            if (count == 0)
            {
                printf("No records available!\n");
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    printf("ID: %d | Name: %s | Age: %d | Contact: %s | Appointment: %s\n",
                           patients[i].id,
                           patients[i].name,
                           patients[i].age,
                           patients[i].contact,
                           patients[i].appointmentDate);
                }
            }
            break;

        case 4:
            printf("Exiting Program...\n");
            break;

        default:
            printf("Invalid Choice! Try Again.\n");
        }

    } while (choice != 4);

    return 0;
}

