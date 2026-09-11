#include <iostream>
#include <vector>
#include <string>

using namespace std;

// كلاس يمثل الكتاب
class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

// كلاس إدارة المكتبة
class Library {
private:
    vector<Book> books;

public:
    // إضافة كتاب جديد
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); // لتنظيف البافير بعد إدخال الرقم
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book Added Successfully!\n";
    }

    // عرض جميع الكتب
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\n--- Library Books ---\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id 
                 << " | Title: " << book.title 
                 << " | Author: " << book.author 
                 << " | Status: " << (book.isIssued ? "Borrowed" : "Available") << "\n";
        }
    }

    // استعارة كتاب
    void issueBook() {
        int id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;
        for (auto& book : books) {
            if (book.id == id) {
                if (book.isIssued) {
                    cout << "Sorry, this book is already borrowed.\n";
                } else {
                    book.isIssued = true;
                    cout << "Book borrowed successfully!\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    // إعادة كتاب
    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (auto& book : books) {
            if (book.id == id) {
                if (!book.isIssued) {
                    cout << "This book was not borrowed.\n";
                } else {
                    book.isIssued = false;
                    cout << "Book returned successfully!\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.displayBooks(); break;
            case 3: lib.issueBook(); break;
            case 4: lib.returnBook(); break;
            case 5: cout << "Exiting system. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
