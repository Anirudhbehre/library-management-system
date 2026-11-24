#include <stdio.h>

struct Book {
    int id;
    char title[50];
    int available;
};

struct Book b[10] = {
    {101, "C Programming", 1},
    {102, "Data Structure", 1},
    {103, "Mathematics", 0},
    {104, "Computer Networks", 1},
    {105, "Operating System", 1},
    {106, "DBMS", 0},
    {107, "Java", 1},
    {108, "Python", 1},
    {109, "Digital Electronics", 1},
    {110, "Software Engineering", 1}
};

// Function to display all books
void display() {
    int i;

    printf("\nID\tTitle\t\t\tStatus\n");

    for(i = 0; i < 10; i++) {
        printf("%d\t%-25s", b[i].id, b[i].title);

        if(b[i].available == 1) {
            printf("Available\n");
        } else {
            printf("Issued\n");
        }
    }
}

// Function to search a book
void search() {
    int id, i, found = 0;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < 10; i++) {
        if(b[i].id == id) {
            printf("Book Found!\n");
            printf("ID: %d\n", b[i].id);
            printf("Title: %s\n", b[i].title);

            if(b[i].available == 1) {
                printf("Status: Available\n");
            } else {
                printf("Status: Issued\n");
            }

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Book Not Found!\n");
    }
}

// Function to issue a book
void issue() {
    int id, i, found = 0;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for(i = 0; i < 10; i++) {
        if(b[i].id == id) {
            found = 1;

            if(b[i].available == 1) {
                b[i].available = 0;
                printf("Book Issued Successfully!\n");
            } else {
                printf("Book is Already Issued!\n");
            }

            break;
        }
    }

    if(found == 0) {
        printf("Book Not Found!\n");
    }
}

// Function to return a book
void returnBook() {
    int id, i, found = 0;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for(i = 0; i < 10; i++) {
        if(b[i].id == id) {
            found = 1;

            if(b[i].available == 0) {
                b[i].available = 1;
                printf("Book Returned Successfully!\n");
            } else {
                printf("Book is Already Available!\n");
            }

            break;
        }
    }

    if(found == 0) {
        printf("Book Not Found!\n");
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n--- LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Display All Books\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            display();
        }
        else if(choice == 2) {
            search();
        }
        else if(choice == 3) {
            issue();
        }
        else if(choice == 4) {
            returnBook();
        }
        else if(choice == 5) {
            printf("Thank You!\n");
        }
        else {
            printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}
