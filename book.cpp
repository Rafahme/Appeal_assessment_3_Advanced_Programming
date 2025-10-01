#include "book.h"
#include <iostream>

Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), dateAdded("01/08/2025") {}

void Book::setBookDetails(const std::string& t, const std::string& a, const std::string& i) {
    title = t;
    author = a;
    isbn = i;
    isAvailable = true;
    // dateAdded stays as the default for this exercise
}

void Book::displayBookDetails() const {
    std::cout << "Title: " << title << '\n';
    std::cout << "Author: " << author << '\n';
    std::cout << "ISBN: " << isbn << '\n';
    std::cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << '\n';
    std::cout << "Date Added: " << dateAdded << "\n\n";
}

const std::string& Book::getISBN() const { return isbn; }
bool Book::getAvailability() const { return isAvailable; }

void Book::borrowBook() {
    isAvailable = false;
    std::cout << "Book successfully borrowed.\n";
}

void Book::returnBook() {
    isAvailable = true;
    std::cout << "Book successfully returned.\n";
}

bool Book::compareISBN(const Book& a, const Book& b) {
    return a.getISBN() < b.getISBN();
}
