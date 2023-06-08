#Library System
  The Library System is a program written in C language that allows users to manage a collection of books using files. The program provides the following functionality:
1-Add new book
2-Delete an existing book
3-Search for a book by its ID
4-Search for a book by name
5-Display all books sorted by their name
6-Display all books unsorted as entered
Installation
To use the Library System, you will need to have a C compiler installed on your computer. You can use any C compiler that supports the C99 standard.

Once you have a C compiler installed, download the Library System files from the GitHub repository:(https://github.com/shadaashraf/Library-system-in-c-using-files)

#Usage
To run the Library System, open a terminal or command prompt and navigate to the directory where the program files are located. Then, compile the program using the following command:

Copy:
gcc -o library_system library_system.c
This will compile the program and create an executable file called library_system. To start the program, run the following command:

Copy:
./library_system
This will start the program and display a menu of options. To select an option, enter the corresponding number and press Enter.

-Functionality
Add new book
To add a new book to the collection, select option 1 from the main menu and follow the prompts to enter the book's name, ID, and any other relevant information. The program will write the book's information to a file called books.txt.

Delete an existing book
To delete an existing book from the collection, select option 2 from the main menu and enter the book's ID. The program will search for the book in the books.txt file and remove it if it exists.

Search for a book by its ID
To search for a book by its ID, select option 3 from the main menu and enter the book's ID. The program will search for the book in the books.txt file and display its information if it exists.

Search for a book by name
To search for a book by its name, select option 4 from the main menu and enter the book's name. The program will search for books that match the name in the books.txt file and display their information.

Display all books sorted by their name
To display all books in the collection sorted by their name, select option 5 from the main menu. The program will read the books from the books.txt file, sort them alphabetically by name, and display their information.

Display all books unsorted as entered
To display all books in the collection in the order they were entered, select option 6 from the main menu. The program will read the books from the books.txt file and display their information in the order they were added to the file.

Contributing
If you would like to contribute to the Library System, please fork the GitHub repository and submit a pull request with your changes. Before submitting a pull request, make sure to run the tests to ensure that your changes do not break existing functionality.

License
The Library System is released under the MIT License. See LICENSE file for more details.

Contact
If you have any questions or feedback about the Library System, please contact the author at your-email@example.com.
