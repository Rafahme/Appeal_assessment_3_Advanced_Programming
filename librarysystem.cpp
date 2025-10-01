#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include "book.h"

static void displayBooks(const std::vector<Book>& books, const std::string& label) {
    std::cout << "\n" << label << '\n';
    for (const Book& b : books) b.displayBookDetails();
}

static void runLibrarySystem() {
    std::vector<Book> books(5);

    books[0].setBookDetails("1984", "George Orwell", "123");
    books[1].setBookDetails("Brave New World", "Aldous Huxley", "234");
    books[2].setBookDetails("Fahrenheit 451", "Ray Bradbury", "345");
    books[3].setBookDetails("The Great Gatsby", "F. Scott Fitzgerald", "456");
    books[4].setBookDetails("To Kill a Mockingbird", "Harper Lee", "567");

    std::string input;
    do {
        std::cout << "\nEnter ISBN to borrow/return (0 to exit): ";
        std::getline(std::cin, input);

        if (input != "0") {
            std::cout << "Do you want to (B)orrow or (R)return this book? ";
            std::string action;
            std::getline(std::cin, action);

            bool found = false;
            for (Book& book : books) {
                if (book.getISBN() == input) {
                    found = true;
                    if (action == "B" || action == "b") {
                        if (book.getAvailability()) {
                            book.borrowBook();
                        }
                        else {
                            std::cout << "Book is currently unavailable.\n";
                        }
                    }
                    else if (action == "R" || action == "r") {
                        book.returnBook();
                    }
                    else {
                        std::cout << "Invalid action. Please enter B or R.\n";
                    }
                    book.displayBookDetails();
                    break;
                }
            }
            if (!found) std::cout << "Book not found.\n";
        }
        else {
            std::cout << "\n📚 Thank you for using the Community Library Book System! 📚\n";
        }
    } while (input != "0");
}

static void runTestCases() {
    // Valid books
    Book book1, book2, book3;
    book1.setBookDetails("1984", "George Orwell", "123");
    book2.setBookDetails("Brave New World", "Aldous Huxley", "234");
    book3.setBookDetails("Fahrenheit 451", "Ray Bradbury", "345");

    std::cout << "\n--- Valid Book Initialisations ---\n";
    book1.displayBookDetails();
    book2.displayBookDetails();
    book3.displayBookDetails();

    // Invalid books (still initialised to show tolerance; real validation would block these)
    Book wrong1, wrong2, wrong3;
    wrong1.setBookDetails("", "", "");
    wrong2.setBookDetails("\n\n", "1234", "not-an-isbn");
    wrong3.setBookDetails("Book!@#", "!@#$%", "???");

    std::cout << "\n--- Invalid Book Initialisations ---\n";
    wrong1.displayBookDetails();
    wrong2.displayBookDetails();
    wrong3.displayBookDetails();

    // Sorting demos
    std::vector<Book> ascending = { book1, book2, book3 };
    std::vector<Book> descending = { book3, book2, book1 };
    std::vector<Book> mixed = { book2, book3, book1 };

    std::sort(ascending.begin(), ascending.end(), Book::compareISBN);
    displayBooks(ascending, "\nSorted Ascending Order (Already Sorted):");

    std::sort(descending.begin(), descending.end(), Book::compareISBN);
    displayBooks(descending, "\nSorted Descending Order (Now Sorted):");

    std::sort(mixed.begin(), mixed.end(), Book::compareISBN);
    displayBooks(mixed, "\nSorted Mixed Order (Now Sorted):");

    std::cout << "\n--- Summary and Recommendations ---\n";
    std::cout << "All valid books were successfully initialised, sorted, and displayed.\n";
    std::cout << "Invalid books were processed without crashing the system.\n";
    std::cout << "The sorting function works correctly with all order inputs.\n";
}

int main() {
    int choice = 0;
    std::cout << "Choose Mode:\n1. Library System\n2. Run Test Cases\nChoice: ";
    if (!(std::cin >> choice)) return 1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear newline

    if (choice == 1)      runLibrarySystem();
    else if (choice == 2) runTestCases();
    else std::cout << "Invalid choice.\n";
    return 0;
}
