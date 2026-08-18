# Scenario

# You have been asked to build a very small backend module for a library.
# Initially, the library only wants to keep track of books and whether they are available.
# Future features like members, librarians, due dates, and reservations will be added later, so design your class cleanly.

class Book:
    def __init__(self, book_id, title, author, price):
        self.book_id = book_id
        self.title = title
        self.author = author
        self.price = price
        self.is_available = True
    
    # methods
    def borrow_book(self):
        if self.is_available:
            self.is_available = False
            print(f'"{self.title}" borrowed successfully.\n')
        else:
            print(f'"{self.title}" is already borrowed.\n')

    def return_book(self):
        if self.is_available:
            print(f'"{self.title}" is already in the library.\n')
        else:
            self.is_available = True
            print(f'"{self.title}" returned successfully.\n')

    def display_details(self):
        status = "Available" if self.is_available else "Borrowed"

        print("-" * 40)
        print(f"Book ID      : {self.book_id}")
        print(f"Title        : {self.title}")
        print(f"Author       : {self.author}")
        print(f"Price        : ₹{self.price}")
        print(f"Availability : {status}")
        print("-" * 40)
        print()


# -------------------------
#making objects from book class----- Driver Code --
book1 = Book(101, "Atomic Habits", "James Clear", 499)
book2 = Book(102, "Clean Code", "Robert C. Martin", 699)
book3 = Book(103, "Deep Learning with Python", "Francois Chollet", 899)

# list of objects
books = [book1, book2, book3] 

print("Displaying all books:\n")
for book in books:
    book.display_details()

print("Borrow Book 1")
book1.borrow_book()

print("Borrow Book 1 Again")
book1.borrow_book()

print("Return Book 1")
book1.return_book()

print("Borrow Book 1 Again")
book1.borrow_book()

print("Final Details of Book 1")
book1.display_details()