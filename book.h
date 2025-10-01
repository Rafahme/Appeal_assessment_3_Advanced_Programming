#pragma once
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool isAvailable;
    std::string dateAdded; // kept as simple string to avoid time APIs

public:
    Book();

    void setBookDetails(const std::string& t, const std::string& a, const std::string& i);
    void displayBookDetails() const;

    const std::string& getISBN() const;
    bool getAvailability() const;

    void borrowBook();
    void returnBook();

    // For std::sort by ISBN
    static bool compareISBN(const Book& a, const Book& b);
};
