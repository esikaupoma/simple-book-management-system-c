#include <stdio.h>
#include <string.h>

struct BookShop {
    char book_title[51];
    char author[31];
    float price;
    int copies;
};



int main() {
    int max_book = 1000;
    int bookCounter = 0;
    struct BookShop book[max_book];
    int choice;

    showWelcomeMessage();
    showMenuOptions();

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            showMenuOptions();
            break;
        case 2:
            showBooks(book, bookCounter);
            break;
        case 3:
            addBook(book, &bookCounter, max_book);
            break;
        case 4:
            searchBook(book, bookCounter);
            break;
        case 5:
            showNumberOfBooks(book, bookCounter);
            break;
        case 6:
            showGoodByeMessage();
            break;
        default:
            printf("Invalid choice. Enter the choice between 1 to 6.\n");
        }
    } while (choice != 6);

    return 0;
}

void showWelcomeMessage() {
    printf("-----------------------------------------------\n");
    printf("Hello! Enjoy the Simple Book Management System. \n");
    printf("-----------------------------------------------\n");
}

void showGoodByeMessage() {
    printf("-------------------------------------------------------------\n");
    printf("Goodbye for now! We look forward to assisting you again soon.\n");
    printf("-------------------------------------------------------------\n");
}

void showMenuOptions() {
    printf("\nPlease select a menu option number:\n");
    printf("1. Display this menu.\n");
    printf("2. Show all available books.\n");
    printf("3. Add a book to the book shop.\n");
    printf("4. Search a book by title.\n");
    printf("5. Display the total number of books.\n");
    printf("6. Exit\n");
}

void showBooks(struct BookShop book[], int bookCounter) {
    if (bookCounter == 0) {
        printf("\nSorry! No Books Available!\n");
        return;
    }
    printf("\n---------List of books---------\n");
    for (int i = 0; i < bookCounter; i++) {
        printf("-------------------------------\n");
        printf("Book No %d :\n", i + 1);
        printf("Book Title : %s\n", book[i].book_title);
        printf("Book Author : %s\n", book[i].author);
        printf("Book Price : %.2f\n", book[i].price);
        printf("Number of copies : %d\n", book[i].copies);
    }
}

void addBook(struct BookShop book[], int *bookCounter, int max_book) {
    if (*bookCounter >= max_book) {
        printf("Storage full! Cannot add more books!\n");
        return;
    }
    printf("\nEnter book title : ");
    scanf(" %[^\n]s", book[*bookCounter].book_title);
    printf("Enter book author : ");
    scanf(" %[^\n]s", book[*bookCounter].author);
    printf("Enter book price : ");
    scanf("%f", &book[*bookCounter].price);
    printf("Enter number of copies : ");
    scanf("%d", &book[*bookCounter].copies);
    (*bookCounter)++;
    printf("Book added successfully!\n");
}

void searchBook(struct BookShop book[], int bookCounter)
{
    char title[51];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCounter; i++)
    {
        if (!strcmp(book[i].book_title, title))
        {
            printf("--------Book found--------\n");
            printf("Title: %s\n", book[i].book_title);
            printf("Author: %s\n", book[i].author);
            printf("Price: %.2f\n", book[i].price);
            printf("Copies: %d\n", book[i].copies);
            return;
        }
    }
    printf("\nBook not found.\n");
}
void showNumberOfBooks(struct BookShop book[], int bookCounter) {
    int totalBooks = 0;
    for (int i = 0; i < bookCounter; i++) {
        totalBooks += book[i].copies;
    }
    printf("\nTotal number of books in the shop: %d\n", totalBooks);
}

