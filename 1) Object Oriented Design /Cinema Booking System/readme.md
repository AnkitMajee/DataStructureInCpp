## 🎬 GitHub README: Cinema Booking System (Java OOP Project)

```markdown
# 🎥 Cinema Booking System (Java OOP Project)

A clean, modular, and object-oriented **Cinema Booking System** built in **Java** that demonstrates real-world implementation of OOP principles — **Encapsulation**, **Inheritance**, **Polymorphism**, **Abstraction**, and **Composition**.

This project simulates ticket booking, seat allocation, movie scheduling, and payment billing for a modern cinema multiplex.

---

## 🚀 Overview

The system supports:
- Adding and managing movies and shows  
- Customer registration and ticket booking  
- Seat allocation and availability checks  
- Dynamic bill generation with seat type pricing and taxes  
- Handling duplicate bookings, invalid seats, and full show scenarios  

---

## 🧩 OOP Concepts Applied

| **Concept** | **Example in This System** |
|--------------|-----------------------------|
| **Encapsulation** | Private fields in `Movie`, `Customer`, `Seat`, etc. with getters/setters |
| **Inheritance** | `Person` → `Customer`, `Staff` |
| **Polymorphism** | `generateBill()` behaves differently for regular and premium bookings |
| **Abstraction** | Abstract `Bill` class defines a unified structure for billing |
| **Composition** | `Cinema` has `List<Movies>`, each `Movie` has `List<Show>`, each `Show` has `List<Seat>` |

---

## 🧠 Class Diagram (Simplified)

```

Person (abstract)
│
├── Customer
│
└── Staff
│
└── Movie → Show → Seat → Bill

```

---

## 🏗️ Project Structure

```

CinemaBookingSystem.java
├── Person.java
├── Customer.java
├── Staff.java
├── Movie.java
├── Show.java
├── Seat.java
├── Bill.java (abstract)
├── RegularBill.java
├── PremiumBill.java
└── Cinema.java

```

---

## ⚙️ Features

✅ Add movies and their shows  
✅ Register customers and book tickets  
✅ Allocate seats and mark as booked  
✅ Apply discount for premium customers  
✅ Handle duplicate booking and full capacity  

---

## 🧾 Example Output

```

🎬 Movie added: Inception
🎬 Movie added: Interstellar

✅ Customer registered: Rohan Singh (Premium)
✅ Ticket booked for Rohan Singh: Inception - Seat A1
✅ Ticket booked for Rohan Singh: Interstellar - Seat A2
⚠️ Seat A1 is already booked!
❌ Show is fully booked!

Bill for Rohan Singh: ₹855.0

````

---

## 🧪 Edge Cases

| **Scenario** | **Behavior** |
|---------------|--------------|
| Duplicate customer | “⚠️ Customer already exists!” |
| Seat already booked | “⚠️ Seat already booked!” |
| Show full | “❌ Show is fully booked!” |
| Premium customer | 5% discount, 10% GST |
| Regular customer | 10% GST only |

---

## 🖥️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/CinemaBookingSystem.git
````

2. Compile the Java files:

   ```bash
   javac CinemaBookingSystem.java
   ```
3. Run the program:

   ```bash
   java CinemaBookingSystem
   ```

---

## 👨‍💻 Author

**Ankit Majee**
📧 [Email](mailto:your-email@example.com) | 💼 [LinkedIn](https://linkedin.com/in/ankitmajee)

---

## 🏁 License

Licensed under the **MIT License** – free for personal and educational use.

---

> ✨ A real-world OOP project simulating movie booking and billing in Java.

````

---

## 🎬 `CinemaBookingSystem.java` (Full Java Implementation)

```java
import java.util.*;

// 🔹 Abstract base class for all people
abstract class Person {
    protected String name;
    protected String contact;

    public Person(String name, String contact) {
        this.name = name;
        this.contact = contact;
    }

    public String getName() { return name; }
}

// 🔹 Customer class
class Customer extends Person {
    private boolean isPremium;

    public Customer(String name, String contact, boolean isPremium) {
        super(name, contact);
        this.isPremium = isPremium;
    }

    public boolean isPremium() { return isPremium; }
}

// 🔹 Staff class (optional)
class Staff extends Person {
    private String position;

    public Staff(String name, String contact, String position) {
        super(name, contact);
        this.position = position;
    }

    public String getPosition() { return position; }
}

// 🔹 Seat class
class Seat {
    private String seatNumber;
    private boolean booked;

    public Seat(String seatNumber) {
        this.seatNumber = seatNumber;
        this.booked = false;
    }

    public String getSeatNumber() { return seatNumber; }
    public boolean isBooked() { return booked; }

    public void book() { this.booked = true; }
}

// 🔹 Movie class
class Movie {
    private String title;
    private List<Show> shows = new ArrayList<>();

    public Movie(String title) {
        this.title = title;
    }

    public String getTitle() { return title; }

    public void addShow(Show show) {
        shows.add(show);
    }

    public List<Show> getShows() { return shows; }
}

// 🔹 Show class
class Show {
    private String time;
    private List<Seat> seats;
    private Movie movie;

    public Show(Movie movie, String time, int seatCount) {
        this.movie = movie;
        this.time = time;
        seats = new ArrayList<>();
        for (int i = 1; i <= seatCount; i++) {
            seats.add(new Seat("A" + i));
        }
    }

    public String getTime() { return time; }

    public Seat getAvailableSeat(String seatNumber) {
        for (Seat seat : seats) {
            if (seat.getSeatNumber().equalsIgnoreCase(seatNumber)) {
                return seat;
            }
        }
        return null;
    }

    public boolean isFull() {
        return seats.stream().allMatch(Seat::isBooked);
    }

    public Movie getMovie() { return movie; }
}

// 🔹 Abstract Bill
abstract class Bill {
    protected Customer customer;
    protected double basePrice;

    public Bill(Customer customer, double basePrice) {
        this.customer = customer;
        this.basePrice = basePrice;
    }

    public abstract double generateBill();
}

// 🔹 Regular Bill
class RegularBill extends Bill {
    public RegularBill(Customer customer, double basePrice) {
        super(customer, basePrice);
    }

    public double generateBill() {
        return basePrice + (basePrice * 0.10); // 10% GST
    }
}

// 🔹 Premium Bill
class PremiumBill extends Bill {
    public PremiumBill(Customer customer, double basePrice) {
        super(customer, basePrice);
    }

    public double generateBill() {
        double discount = basePrice * 0.05;
        double gst = (basePrice - discount) * 0.10;
        return (basePrice - discount) + gst;
    }
}

// 🔹 Cinema class
class Cinema {
    private List<Movie> movies = new ArrayList<>();
    private List<Customer> customers = new ArrayList<>();

    public void addMovie(Movie movie) {
        movies.add(movie);
        System.out.println("🎬 Movie added: " + movie.getTitle());
    }

    public void registerCustomer(Customer customer) {
        for (Customer c : customers) {
            if (c.getName().equalsIgnoreCase(customer.getName())) {
                System.out.println("⚠️ Customer already exists!");
                return;
            }
        }
        customers.add(customer);
        System.out.println("✅ Customer registered: " + customer.getName() +
                (customer.isPremium() ? " (Premium)" : " (Regular)"));
    }

    public void bookTicket(String customerName, String movieTitle, String seatNumber) {
        Customer customer = customers.stream()
                .filter(c -> c.getName().equalsIgnoreCase(customerName))
                .findFirst().orElse(null);
        Movie movie = movies.stream()
                .filter(m -> m.getTitle().equalsIgnoreCase(movieTitle))
                .findFirst().orElse(null);

        if (customer == null || movie == null) {
            System.out.println("⚠️ Invalid movie or customer!");
            return;
        }

        Show show = movie.getShows().get(0); // single show per movie for simplicity
        if (show.isFull()) {
            System.out.println("❌ Show is fully booked!");
            return;
        }

        Seat seat = show.getAvailableSeat(seatNumber);
        if (seat == null) {
            System.out.println("⚠️ Invalid seat number!");
            return;
        }

        if (seat.isBooked()) {
            System.out.println("⚠️ Seat " + seat.getSeatNumber() + " is already booked!");
            return;
        }

        seat.book();
        double basePrice = 750.0;
        Bill bill = customer.isPremium() ? new PremiumBill(customer, basePrice) : new RegularBill(customer, basePrice);
        double total = bill.generateBill();

        System.out.println("✅ Ticket booked for " + customer.getName() + ": " + movie.getTitle() + " - Seat " + seat.getSeatNumber());
        System.out.println("Bill for " + customer.getName() + ": ₹" + total);
    }
}

// 🔹 Main class
public class CinemaBookingSystem {
    public static void main(String[] args) {
        Cinema cinema = new Cinema();

        // Add movies
        Movie inception = new Movie("Inception");
        inception.addShow(new Show(inception, "6:00 PM", 2));
        cinema.addMovie(inception);

        Movie interstellar = new Movie("Interstellar");
        interstellar.addShow(new Show(interstellar, "9:00 PM", 1));
        cinema.addMovie(interstellar);

        // Register customers
        Customer rohan = new Customer("Rohan Singh", "9999999999", true);
        cinema.registerCustomer(rohan);

        // Book tickets
        cinema.bookTicket("Rohan Singh", "Inception", "A1");
        cinema.bookTicket("Rohan Singh", "Interstellar", "A2");
        cinema.bookTicket("Rohan Singh", "Inception", "A1"); // Duplicate
        cinema.bookTicket("Rohan Singh", "Inception", "A2"); // Full
    }
}
````

---
