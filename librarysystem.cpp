#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a book
struct Book {
    string title;
    string author;
    string isbn;
    bool checkedOut;

    Book(const string& t, const string& a, const string& i) : title(t), author(a), isbn(i), checkedOut(false) {}
};

// Structure to represent a borrower
struct Borrower {
    string name;
    string email;

    Borrower(const string& n, const string& e) : name(n), email(e) {}
};

// Function to add a book to the library
void addBook(vector<Book>& books, const string& title, const string& author, const string& isbn) {
    books.push_back(Book(title, author, isbn));
    cout << "Book added successfully." << endl;
}

// Function to search for a book by title, author, or ISBN
void searchBook(const vector<Book>& books, const string& keyword) {
    bool found = false;
    for (const auto& book : books) {
        if (book.title.find(keyword) != string::npos || 
            book.author.find(keyword) != string::npos || 
            book.isbn.find(keyword) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << ", Status: " << (book.checkedOut ? "Checked Out" : "Available") << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found matching the search criteria." << endl;
    }
}

// Function to check out a book
void checkoutBook(vector<Book>& books, const string& isbn) {
    for (auto& book : books) {
        if (book.isbn == isbn) {
            if (!book.checkedOut) {
                book.checkedOut = true;
                cout << "Book checked out successfully." << endl;
            } else {
                cout << "This book is already checked out." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

// Function to return a book
void returnBook(vector<Book>& books, const string& isbn) {
    for (auto& book : books) {
        if (book.isbn == isbn) {
            if (book.checkedOut) {
                book.checkedOut = false;
                cout << "Book returned successfully." << endl;
            } else {
                cout << "This book is not checked out." << endl;
            }
            return;
        }
    }
    cout << "Book not found." << endl;
}

int main() {
    vector<Book> books;
    vector<Borrower> borrowers;

    // Adding some sample books
    addBook(books, "Book1", "Author1", "ISBN1");
    addBook(books, "Book2", "Author2", "ISBN2");
    addBook(books, "Book3", "Author3", "ISBN3");

    // Searching for a book
    searchBook(books, "Book2");

    // Checking out a book
    checkoutBook(books, "ISBN2");

    // Returning a book
    returnBook(books, "ISBN2");

    return 0;
}
