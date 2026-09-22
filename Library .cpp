#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) : title(t), author(a), isBorrowed(false) {}
};

int main() {
    vector<Book> catalog;
    int choice;

    while (true) {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n2. Remove Book\n3. Borrow Book\n4. Return Book\n5. Search Book\n6. Display All Books\n7. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "Enter book title: "; cin.ignore(); getline(cin, title);
            cout << "Enter author: "; getline(cin, author);
            catalog.push_back(Book(title, author));
            cout << "Book \"" << title << "\" added.\n";
        }
        else if (choice == 3) {
            string title;
            cout << "Enter book title to borrow: "; cin.ignore(); getline(cin, title);
            bool found = false;
            for (auto &book : catalog) {
                if (book.title == title) {
                    if (book.isBorrowed) {
                        cout << "Book is already borrowed!\n";
                    } else {
                        book.isBorrowed = true;
                        cout << "\"" << title << "\" borrowed successfully.\n";
                    }
                    found = true; break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 6) {
            for (const auto &book : catalog) {
                cout << "Title: " << book.title << " | Author: " << book.author 
                     << " | Status: " << (book.isBorrowed ? "Borrowed" : "Available") << "\n";
            }
        }
        else if (choice == 7) {
            cout << "Goodbye!\n";
            break;
        }
    }
    return 0;
}
