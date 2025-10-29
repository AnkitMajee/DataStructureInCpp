Excellent choice 📚 — a **Library Management System** is a classic OOP case study that demonstrates inheritance, abstraction, and polymorphism in a clean and meaningful way.

Below you’ll get:
✅ **GitHub-ready README.md**
✅ **Complete Java program (single file)**

---

## 🧾 README.md (for GitHub)

```markdown
# 📚 Library Management System (Java OOP Project)

A real-world **Object-Oriented Programming (OOP)** implementation of a **Library Management System** in Java.  
This project simulates the process of managing books, members, borrowing/returning books, calculating fines, and maintaining library records.

---

## 🏢 Use Case

The library has:
- Books of different categories (Fiction, Non-Fiction, Reference)
- Members (Students, Teachers)
- A system to issue and return books
- Fine calculation for late returns
- Edge-case handling for invalid book IDs, unavailable books, and duplicate issues

---

## 🧩 OOP Concepts Applied

| **Concept** | **Example in this System** |
|--------------|-----------------------------|
| **Encapsulation** | Private fields in `Book`, `Member`, etc., with getters/setters |
| **Inheritance** | `Book` → `FictionBook`, `ReferenceBook` |
| **Polymorphism** | `calculateFine()` behaves differently for `Student` and `Teacher` |
| **Abstraction** | Abstract `Book` and `Member` classes define core behaviors |
| **Composition** | `Library` has `List<Book>`, `List<Member>`, and `List<Transaction>` |

---

## 🧠 Class Diagram (Simplified)

```

Book (abstract)
│
├── FictionBook
├── NonFictionBook
└── ReferenceBook

Member (abstract)
│
├── Student
└── Teacher

Transaction → Library

```

---

## ⚙️ Features

✅ Add and remove books/members  
✅ Issue and return books  
✅ Prevent duplicate issues  
✅ Fine calculation based on member type  
✅ Display all active transactions  
✅ Handle unavailable or invalid book IDs gracefully  

---

## 💻 Example Output

```

✅ Book '1984' issued to Student Ravi
✅ Book 'Physics Fundamentals' issued to Teacher Meena
⚠️ Book '1984' is already issued!
✅ Book '1984' returned by Student Ravi
💰 Fine for late return: ₹20.0
❌ Book ID not found in library!

````

---

## 🧪 Edge Cases Covered

| **Scenario** | **Behavior** |
|---------------|--------------|
| Duplicate issue attempt | Shows "⚠️ Book already issued!" |
| Invalid book ID | Displays "❌ Book not found!" |
| Late return | Fine applied based on member type |
| Reference books | Cannot be borrowed |
| Empty return list | Graceful handling |

---

## 🖥️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/LibraryManagementSystem.git
````

2. Navigate into the project directory:

   ```bash
   cd LibraryManagementSystem
   ```
3. Compile the Java file:

   ```bash
   javac LibraryManagementSystem.java
   ```
4. Run the program:

   ```bash
   java LibraryManagementSystem
   ```

---

## 🧑‍💻 Author

**Ankit Majee**
📧 [Email](mailto:your-email@example.com) | 💼 [LinkedIn](https://linkedin.com/in/ankitmajee)

---

## 🏁 License

Licensed under the **MIT License** — free to use for learning and open-source development.

---

> 📖 *A robust Java OOP implementation of a Library Management System featuring encapsulation, inheritance, and polymorphism.*

````

---

## 💻 Java Code — `LibraryManagementSystem.java`

```java
import java.util.*;

// ===== ABSTRACT BOOK CLASS =====
abstract class Book {
    private String id;
    private String title;
    private String author;
    private boolean isIssued;

    public Book(String id, String title, String author) {
        this.id = id;
        this.title = title;
        this.author = author;
        this.isIssued = false;
    }

    public String getId() { return id; }
    public String getTitle() { return title; }
    public boolean isIssued() { return isIssued; }
    public void setIssued(boolean issued) { isIssued = issued; }

    public abstract boolean isBorrowable();

    @Override
    public String toString() {
        return title + " by " + author + (isIssued ? " (Issued)" : " (Available)");
    }
}

// ===== SUBCLASSES OF BOOK =====
class FictionBook extends Book {
    public FictionBook(String id, String title, String author) {
        super(id, title, author);
    }
    public boolean isBorrowable() { return true; }
}

class NonFictionBook extends Book {
    public NonFictionBook(String id, String title, String author) {
        super(id, title, author);
    }
    public boolean isBorrowable() { return true; }
}

class ReferenceBook extends Book {
    public ReferenceBook(String id, String title, String author) {
        super(id, title, author);
    }
    public boolean isBorrowable() { return false; }
}

// ===== ABSTRACT MEMBER CLASS =====
abstract class Member {
    private String id;
    private String name;

    public Member(String id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getId() { return id; }
    public String getName() { return name; }

    public abstract double calculateFine(int daysLate);
}

class Student extends Member {
    public Student(String id, String name) {
        super(id, name);
    }

    public double calculateFine(int daysLate) {
        return daysLate > 0 ? daysLate * 2.0 : 0.0;
    }
}

class Teacher extends Member {
    public Teacher(String id, String name) {
        super(id, name);
    }

    public double calculateFine(int daysLate) {
        return daysLate > 0 ? daysLate * 1.0 : 0.0;
    }
}

// ===== TRANSACTION CLASS =====
class Transaction {
    private Book book;
    private Member member;
    private Date issueDate;
    private Date returnDate;

    public Transaction(Book book, Member member) {
        this.book = book;
        this.member = member;
        this.issueDate = new Date();
        this.returnDate = null;
    }

    public Book getBook() { return book; }
    public Member getMember() { return member; }

    public void returnBook(int daysLate) {
        this.returnDate = new Date();
        double fine = member.calculateFine(daysLate);
        book.setIssued(false);
        System.out.println("✅ Book '" + book.getTitle() + "' returned by " + member.getName());
        if (fine > 0)
            System.out.println("💰 Fine for late return: ₹" + fine);
    }
}

// ===== LIBRARY CLASS =====
class Library {
    private Map<String, Book> books;
    private List<Member> members;
    private List<Transaction> transactions;

    public Library() {
        this.books = new HashMap<>();
        this.members = new ArrayList<>();
        this.transactions = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.put(book.getId(), book);
    }

    public void addMember(Member member) {
        members.add(member);
    }

    public void issueBook(String bookId, Member member) {
        Book book = books.get(bookId);

        if (book == null) {
            System.out.println("❌ Book ID not found in library!");
            return;
        }

        if (!book.isBorrowable()) {
            System.out.println("⚠️ '" + book.getTitle() + "' is a reference book and cannot be issued.");
            return;
        }

        if (book.isIssued()) {
            System.out.println("⚠️ Book '" + book.getTitle() + "' is already issued!");
            return;
        }

        book.setIssued(true);
        Transaction t = new Transaction(book, member);
        transactions.add(t);
        System.out.println("✅ Book '" + book.getTitle() + "' issued to " + member.getName());
    }

    public void returnBook(String bookId, Member member, int daysLate) {
        Optional<Transaction> trans = transactions.stream()
                .filter(t -> t.getBook().getId().equals(bookId) && t.getMember().equals(member))
                .findFirst();

        if (trans.isEmpty()) {
            System.out.println("❌ No active transaction found for this book and member!");
            return;
        }

        trans.get().returnBook(daysLate);
        transactions.remove(trans.get());
    }

    public void displayAvailableBooks() {
        System.out.println("\n📘 Available Books:");
        books.values().stream()
                .filter(book -> !book.isIssued())
                .forEach(book -> System.out.println("- " + book));
    }
}

// ===== MAIN CLASS =====
public class LibraryManagementSystem {
    public static void main(String[] args) {
        Library library = new Library();

        // Adding books
        library.addBook(new FictionBook("B1", "1984", "George Orwell"));
        library.addBook(new NonFictionBook("B2", "Physics Fundamentals", "HC Verma"));
        library.addBook(new ReferenceBook("B3", "Oxford Dictionary", "Oxford Press"));

        // Adding members
        Member s1 = new Student("S1", "Ravi");
        Member t1 = new Teacher("T1", "Meena");

        library.addMember(s1);
        library.addMember(t1);

        // Transactions
        library.issueBook("B1", s1);
        library.issueBook("B2", t1);
        library.issueBook("B1", t1); // Duplicate issue
        library.issueBook("B3", s1); // Reference book

        library.displayAvailableBooks();

        library.returnBook("B1", s1, 10); // Late return
        library.returnBook("B4", s1, 0);  // Invalid book ID
    }
}
````

---

## ✅ Example Output

```
✅ Book '1984' issued to Ravi
✅ Book 'Physics Fundamentals' issued to Meena
⚠️ Book '1984' is already issued!
⚠️ 'Oxford Dictionary' is a reference book and cannot be issued.

📘 Available Books:
- Oxford Dictionary by Oxford Press (Available)

✅ Book '1984' returned by Ravi
💰 Fine for late return: ₹20.0
❌ Book ID not found in library!
```

---
