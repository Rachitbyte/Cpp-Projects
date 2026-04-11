#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Donor {
    char name[25];
    int age;
    char group[5];
};

void mainmenu();
void addnewdonor();
void viewalldonor();
void searchdonor();
void deletedonor();

int main()
{
    mainmenu();
    return 0;
}

void mainmenu()
{
    int option;

    while(1)
    {
        system("cls");
        printf("******** BLOOD DONOR MANAGEMENT ********\n");
        printf("0. EXIT\n");
        printf("1. ADD NEW DONOR\n");
        printf("2. VIEW ALL DONORS\n");
        printf("3. SEARCH A DONOR\n");
        printf("4. DELETE A DONOR\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 0: exit(0);
            case 1: addnewdonor(); break;
            case 2: viewalldonor(); break;
            case 3: searchdonor(); break;
            case 4: deletedonor(); break;
            default: printf("Invalid choice!"); getch();
        }
    }
}

void addnewdonor()
{
    FILE *fp = fopen("donor.dat", "ab");
    struct Donor d;

    system("cls");

    if(fp == NULL)
    {
        printf("File error!");
        getch();
        return;
    }

    printf("Enter Name: ");
    getchar(); // clear buffer
    fgets(d.name, sizeof(d.name), stdin);
    d.name[strcspn(d.name, "\n")] = 0;

    printf("Enter Age: ");
    scanf("%d", &d.age);

    printf("Enter Blood Group: ");
    getchar();
    fgets(d.group, sizeof(d.group), stdin);
    d.group[strcspn(d.group, "\n")] = 0;

    fwrite(&d, sizeof(d), 1, fp);
    fclose(fp);

    printf("Donor added successfully!");
    getch();
}

void viewalldonor()
{
    FILE *fp = fopen("donor.dat", "rb");
    struct Donor d;

    system("cls");

    if(fp == NULL)
    {
        printf("No records found!");
        getch();
        return;
    }

    printf("\n--- DONOR LIST ---\n\n");

    while(fread(&d, sizeof(d), 1, fp))
    {
        printf("Name : %s\n", d.name);
        printf("Age  : %d\n", d.age);
        printf("Group: %s\n", d.group);
        printf("----------------------\n");
    }

    fclose(fp);
    getch();
}

void searchdonor()
{
    FILE *fp = fopen("donor.dat", "rb");
    struct Donor d;
    char name[25];
    int found = 0;

    system("cls");

    if(fp == NULL)
    {
        printf("No records found!");
        getch();
        return;
    }

    printf("Enter name to search: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while(fread(&d, sizeof(d), 1, fp))
    {
        if(strcmp(d.name, name) == 0)
        {
            printf("\nRecord Found:\n");
            printf("Name : %s\n", d.name);
            printf("Age  : %d\n", d.age);
            printf("Group: %s\n", d.group);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Donor not found!");

    fclose(fp);
    getch();
}

void deletedonor()
{
    FILE *fp = fopen("donor.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    struct Donor d;
    char name[25];
    int found = 0;

    system("cls");

    if(fp == NULL || temp == NULL)
    {
        printf("File error!");
        getch();
        return;
    }

    printf("Enter name to delete: ");
    getchar();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    while(fread(&d, sizeof(d), 1, fp))
    {
        if(strcmp(d.name, name) == 0)
        {
            found = 1;
        }
        else
        {
            fwrite(&d, sizeof(d), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("donor.dat");
    rename("temp.dat", "donor.dat");

    if(found)
        printf("Donor deleted successfully!");
    else
        printf("Donor not found!");

    getch();
}
