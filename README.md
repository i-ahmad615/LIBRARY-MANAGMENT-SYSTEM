# Library Management System (LMS)
The Library Management System is a C++ program designed to facilitate the management of books and user details in a library. It employs object-oriented programming principles to create a structured and efficient system for handling various library operations. Users can interact with the system through a command-line interface, making it accessible and straightforward.

## Features of the Library Management System (LMS)
1. **Add Books**: Input and store details for new books in the library.
2. **Display Books**: Show a list of all books with their details.
3. **Borrow Books**: Allow users to borrow books and record borrower information.
4. **Return Books**: Enable users to return borrowed books and update their status.
5. **Search Books**: Locate books by ISBN or title.
6. **Error Handling**: Provide feedback for invalid operations (e.g., borrowing non-existent books).
7. **Dynamic Management**: Support up to 100 books, ensuring efficient resource management.
8. **User Interaction**: Menu-driven interface for easy navigation and command execution.

## Working of the Library Management System
1. **Class Structure**:
    **Person Class**: Manages personal information (name, ID, contact details) of individuals borrowing books.
    **Book Class**: Inherits from `Person` and includes additional attributes such as title, author, ISBN, and borrowing status.
    **Library Class**: Manages an array of `Book` objects, enabling operations like adding, displaying, borrowing, and returning books.

2. **User Interaction**:
    The system presents a menu-driven interface, allowing users to choose actions such as adding books or viewing details.

3. **Adding Books**:
    Users can input details for new books, which are then stored in the library's collection.

4. **Displaying Books**:
    Users can view a list of all books along with their details, including borrowing status.

5. **Borrowing and Returning**:
    Users can borrow books by providing their details, which updates the book's status to indicate it is checked out. Returning books resets the status.

6. **Error Handling**:
    The system provides feedback for invalid actions, such as attempting to borrow a book that is already checked out or adding more than the maximum allowed books.

7. **Dynamic Management**:
    The library can handle up to 100 books, ensuring efficient management of resources.

8. **Customization**:
    Users can navigate through the menu options to perform various operations, allowing for a customized experience based on their needs. 

This system provides a simple yet effective solution for managing library operations, making it easy for users to interact with and maintain the library's resources.
