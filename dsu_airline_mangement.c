#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

struct DSUAirline {
    char passport[6];
    char name[15];
    char destination[15];
    int seat_num;
    char email[30];
    struct DSUAirline *next;
};

struct DSUAirline *head = NULL, *current = NULL, *temp = NULL;

void reserve(int seatNo);
void cancel();
void display();
void saveToFile();
void inputDetails();

int main() {
    int choice;
    int seatCount = 1;

    do {
        printf("\n\n\t\t********************************************************************");
        printf("\n\t\t                  Welcome to DSU Airline System                     ");
        printf("\n\t\t********************************************************************");
        printf("\n\n\t\tPlease enter your choice (1-4):");
        printf("\n\n\t\t1. Reservation");
        printf("\n\t\t2. Cancel");
        printf("\n\t\t3. Display Records");
        printf("\n\t\t4. Exit");
        printf("\n\n\t\tEnter your choice: ");

        scanf("%d", &choice);
        fflush(stdin);
        system("cls");

        switch (choice) {
            case 1:
                reserve(seatCount);
                seatCount++;
                break;
            case 2:
                cancel();
                break;
            case 3:
                display();
                break;
            case 4:
                saveToFile();
                printf("\n\n\tThank you for using DSU Airline System!");
                break;
            default:
                printf("\n\n\tInvalid choice! Please choose between 1-4.");
        }

        getch();
    } while (choice != 4);

    return 0;
}

void inputDetails() {
    printf("\n\tEnter your passport number: ");
    gets(current->passport); fflush(stdin);

    printf("\n\tEnter your name: ");
    gets(current->name); fflush(stdin);

    printf("\n\tEnter your email address: ");
    gets(current->email); fflush(stdin);

    printf("\n\tEnter your destination: ");
    gets(current->destination); fflush(stdin);
}

void reserve(int seatNo) {
    if (seatNo > 15) {
        printf("\n\tSorry, all seats are full!");
        return;
    }

    if (head == NULL) {
        head = current = (struct DSUAirline*) malloc(sizeof(struct DSUAirline));
    } else {
        current = head;
        while (current->next != NULL)
            current = current->next;

        current->next = (struct DSUAirline*) malloc(sizeof(struct DSUAirline));
        current = current->next;
    }

    inputDetails();
    current->seat_num = seatNo;
    current->next = NULL;

    printf("\n\tSeat booking successful!");
    printf("\n\tYour seat number is: A-%d", seatNo);
}

void cancel() {
    char passport[6];
    struct DSUAirline *prev = NULL;

    printf("\n\nEnter passport number to delete booking: ");
    gets(passport); fflush(stdin);

    current = head;
    while (current != NULL) {
        if (strcmp(current->passport, passport) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("\n\tBooking has been deleted successfully.");
            Sleep(800);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\n\tInvalid passport number! Please check again.");
}

void display() {
    current = head;
    if (current == NULL) {
        printf("\n\tNo records found!");
        return;
    }

    while (current != NULL) {
        printf("\n\nPassport Number: %-6s", current->passport);
        printf("\nName: %-15s", current->name);
        printf("\nEmail: %-25s", current->email);
        printf("\nSeat Number: A-%d", current->seat_num);
        printf("\nDestination: %-15s", current->destination);
        printf("\n-------------------------------------------------------------");
        current = current->next;
    }
}

void saveToFile() {
    FILE *fp = fopen("DSU_Airline_Records.txt", "w");
    if (!fp) {
        printf("\nError opening file!");
        Sleep(800);
        return;
    }

    current = head;
    while (current != NULL) {
        fprintf(fp, "%-6s %-15s %-25s %-15s\n",
                current->passport,
                current->name,
                current->email,
                current->destination);
        current = current->next;
    }

    printf("\n\n\tDetails have been saved to 'DSU_Airline_Records.txt'.");
    fclose(fp);
}