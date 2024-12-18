#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int ID;
    string cntct_det;

public:
    Person() {}

    Person(string n, int id, string cntct) {
        name = n;
        ID = id;
        cntct_det = cntct;
    }

    void input_det() {
        cout << "Enter Name of Person: ";
        getline(cin, name);
        cout << "Enter ID of Person: ";
        cin >> ID;
        cin.ignore();
        cout << "Enter Contact Details of Person: ";
        getline(cin, cntct_det);
    }

    void display_det() const {
        cout << "\tName: " << name << endl;
        cout << "\tID: " << ID << endl;
        cout << "\tContact Details: " << cntct_det << endl;
    }

    string get_name() const { return name; }
    int get_id() const { return ID; }
    string get_cntct_det() const { return cntct_det; }
};

class Book : public Person {
private:
    string title;
    string author;
    string isbn;
    bool isBorrowed;
    Person borrower;
    string book_type;

public:
    Book() : Person(), isBorrowed(false) {}

    Book(string n, int id, string cntct, string t, string a, string i, string type) : Person(n, id, cntct) {
        title = t;
        author = a;
        isbn = i;
        isBorrowed = false;
        book_type = type;
    }

    void input_det() {
        Person::input_det();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        cout << "Enter Book Type (Fiction, Non-Fiction, Reference): ";
        getline(cin, book_type);
    }

    void display_det() const {
        Person::display_det();
        cout << "\tTitle: " << title << endl;
        cout << "\tAuthor: " << author << endl;
        cout << "\tISBN: " << isbn << endl;
        cout << "\tBook Type: " << book_type << endl;
        cout << "\tIs Borrowed: " << (isBorrowed ? "Yes" : "No") << endl;
        if (isBorrowed) {
            cout << "\tBorrower Details:" << endl;
            borrower.display_det();
        }
    }

    void borrow_book() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Enter borrower's details:" << endl;
            borrower.input_det();
            cout << "\tBook borrowed successfully." << endl;
        } else {
            cout << "\tBook is already borrowed." << endl;
        }
    }

    void return_book() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "\tBook returned successfully." << endl;
        } else {
            cout << "\tBook is not borrowed." << endl;
        }
    }
    string get_isbn() const { return isbn; }
    bool get_IsBorrowed() const { return isBorrowed; }
    string get_book_type() const { return book_type; }
};

class Library {
public:
    const int max_book = 100;
    Book books[30];
    int book_count = 0;

public:
    void add_book() {
        if (book_count < max_book) {
            Book newBook;
            newBook.input_det();
            books[book_count++] = newBook;
            cout << "\tBook added successfully." << endl;
        } else {
            cout << "\tLibrary is full. Cannot add more books." << endl;
        }
    }

    void display_book() const {
        cout << "Library Books:" << endl;
        for (int i = 0; i < book_count; i++) {
            cout << "Book " << i + 1 << ":" << endl;
            books[i].display_det();
            cout << endl;
        }
    }

    void borrow_book() {
        string isbn;
        cout << "Enter ISBN of the book to borrow: ";
        getline(cin, isbn);

        for (int i = 0; i < book_count; i++) {
            if (books[i].get_isbn() == isbn) {
                books[i].borrow_book();
                return;
            }
        }
        cout << "\tBook not found." << endl;
    }

    void return_book() {
        string isbn;
        cout << "Enter ISBN of the book to return: ";
        getline(cin, isbn);

        for (int i = 0; i < book_count; i++) {
            if (books[i].get_isbn() == isbn) {
                books[i].return_book();
                return;
            }
        }
        cout << "\tBook not found." << endl;
    }
};

int main() {
    Library library1;
    int choice;
    
    cout << "\n\t\t -------------------------";
    cout << "\n\t\t|Library Management System|";
    cout << "\n\t\t -------------------------\n";

    do {
        cout << "\nChoose an option:" << endl;
        cout << "\t1. Add a book" << endl;
        cout << "\t2. Display books" << endl;
        cout << "\t3. Borrow a book" << endl;
        cout << "\t4. Return a book" << endl;
        cout << "\t0. Exit" << endl;
        cout << "Enter your choice (1,2,3,4,0): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                library1.add_book();
                break;
            case 2:
                library1.display_book();
                break;
            case 3:
                library1.borrow_book();
                break;
            case 4:
                library1.return_book();
                break;
            case 0:
                cout << "\t... GOOD BYE !! EXITING PROGRAM ..." << endl;
                break;
            default:
                cout << "\tInvalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
