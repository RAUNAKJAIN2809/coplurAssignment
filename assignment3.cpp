#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Book {
    int bookID; string title, author; bool isAvailable;
public:
    Book(int id, string t, string a) : bookID(id), title(t), author(a), isAvailable(true) {}
    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool checkAvailability() const { return isAvailable; }
    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }
};

class LoggingInterface {
public: virtual void logAction(string message) = 0;
};

class ConsoleLogger : public LoggingInterface {
public: void logAction(string message) override { cout << "LOG: " << message << endl; }
};

class LibraryManagementSystem {
    unordered_map<int, Book> books; ConsoleLogger logger;
public:
    void addBook(int id, string title, string author) {
        if (title.empty() || books.find(id) != books.end()) {
            logger.logAction("Error: Invalid details or ID exists."); return;
        }
        books[id] = Book(id, title, author);
        logger.logAction("Book added: " + title + " by " + author);
    }

    void borrowBook(int id) {
        if (books.find(id) == books.end()) { logger.logAction("Error: Book ID not found."); return; }
        Book &book = books[id];
        if (!book.checkAvailability()) { logger.logAction("Error: Book '" + book.getTitle() + "' is borrowed."); return; }
        book.borrowBook(); logger.logAction("Book borrowed: " + book.getTitle() + " by " + book.getAuthor());
    }

    void returnBook(int id) {
        if (books.find(id) == books.end()) { logger.logAction("Error: Invalid Book ID."); return; }
        Book &book = books[id];
        if (book.checkAvailability()) { logger.logAction("Error: Book '" + book.getTitle() + "' was not borrowed."); return; }
        book.returnBook(); logger.logAction("Book returned: " + book.getTitle());
    }

    void viewAvailableBooks() {
        bool found = false;
        for (const auto &pair : books) {
            const Book &book = pair.second;
            if (book.checkAvailability()) {
                found = true;
                cout << "Book ID: " << book.getBookID() << ", Title: " << book.getTitle() << ", Author: " << book.getAuthor() << endl;
            }
        }
        if (!found) cout << "No available books at the moment." << endl;
    }
};

int main() {
    LibraryManagementSystem library;
    library.addBook(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook(2, "1984", "George Orwell");
    library.addBook(3, "To Kill a Mockingbird", "Harper Lee");
    library.viewAvailableBooks();
    library.borrowBook(1); library.borrowBook(1);
    library.viewAvailableBooks();
    library.returnBook(1); library.returnBook(2);
    library.viewAvailableBooks();
    library.addBook(1, "", "J.K. Rowling");
    return 0;
}
