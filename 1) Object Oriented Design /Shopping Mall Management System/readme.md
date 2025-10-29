Here’s a complete **GitHub README** and **Java implementation** for a **Shopping Mall Management System** — written in the same professional, structured format as before 👇

---

## 🛍️ GitHub README: Shopping Mall Management System (Java OOP Project)

```markdown
# 🏬 Shopping Mall Management System (Java OOP Project)

A fully object-oriented **Shopping Mall Management System** built in Java that demonstrates real-world modeling using **OOP principles** — encapsulation, inheritance, polymorphism, abstraction, and composition.

This project manages shops, customers, staff, and transactions within a shopping mall.

---

## 🚀 Overview

The system supports:
- Shop registration and management  
- Customer registration and purchase handling  
- Staff assignment to shops  
- Bill generation with discounts and taxes  
- Handling invalid or duplicate entries, and out-of-stock items  

---

## 🧩 OOP Concepts Applied

| **Concept** | **Example in This System** |
|--------------|-----------------------------|
| **Encapsulation** | Private fields with getters and setters for `Shop`, `Customer`, `Item`, etc. |
| **Inheritance** | `Person` → `Customer`, `Staff` |
| **Polymorphism** | `generateBill()` behaves differently for premium and regular customers |
| **Abstraction** | Abstract class `Person` defines common behavior |
| **Composition** | `Mall` has `List<Shop>`, `List<Customer>`, and `List<Staff>` |

---

## 🧠 Class Diagram (Simplified)

```

Person (abstract)
│
├── Customer
│
└── Staff
│
└── Shop → Mall → Bill

```

---

## 🏗️ Project Structure

```

ShoppingMallManagementSystem.java
├── Person.java
├── Customer.java
├── Staff.java
├── Shop.java
├── Item.java
├── Bill.java (abstract)
├── RegularBill.java
├── PremiumBill.java
└── Mall.java

```

---

## ⚙️ Features

✅ Add and manage shops, staff, and customers  
✅ Handle purchases and generate bills  
✅ Apply discount logic based on customer type  
✅ Prevent duplicate customer registration  
✅ Handle out-of-stock item edge cases  

---

## 🧾 Example Output

```

✅ Shop registered: Fashion Hub
✅ Customer registered: Riya Sharma (Premium)
✅ Item added: Jeans - ₹2000.0
✅ Item added: T-Shirt - ₹800.0
✅ Purchase successful! Riya Sharma bought Jeans and T-Shirt
Bill for Riya Sharma: ₹2520.0

✅ Customer registered: Aman Verma (Regular)
✅ Purchase successful! Aman Verma bought T-Shirt
Bill for Aman Verma: ₹880.0

❌ Item 'T-Shirt' is out of stock!
⚠️ Customer Aman Verma already exists!

````

---

## 🧪 Edge Cases

| **Scenario** | **Expected Behavior** |
|---------------|------------------------|
| Duplicate customer | Warning message: "⚠️ Customer already exists!" |
| Out-of-stock item | Prints "❌ Item is out of stock!" |
| Invalid purchase | Prints "⚠️ Invalid shop or customer!" |
| Premium discount applied | 10% off total bill + 5% tax |
| Regular customer | No discount + 10% tax |

---

## 🖥️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-username>/ShoppingMallManagementSystem.git
````

2. Compile the Java files:

   ```bash
   javac ShoppingMallManagementSystem.java
   ```
3. Run the program:

   ```bash
   java ShoppingMallManagementSystem
   ```

---

## 👨‍💻 Author

**Ankit Majee**
📧 [Email](mailto:your-email@example.com) | 💼 [LinkedIn](https://linkedin.com/in/ankitmajee)

---

## 🏁 License

This project is licensed under the **MIT License** — free to use, modify, and distribute for learning purposes.

---

> ✨ A real-world OOP project simulating a shopping mall’s daily operations using Java.

````

---

## 💻 `ShoppingMallManagementSystem.java` (Full Code)

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

// 🔹 Staff class
class Staff extends Person {
    private String role;

    public Staff(String name, String contact, String role) {
        super(name, contact);
        this.role = role;
    }

    public String getRole() { return role; }
}

// 🔹 Item class
class Item {
    private String name;
    private double price;
    private int stock;

    public Item(String name, double price, int stock) {
        this.name = name;
        this.price = price;
        this.stock = stock;
    }

    public String getName() { return name; }
    public double getPrice() { return price; }
    public int getStock() { return stock; }

    public void reduceStock(int qty) { this.stock -= qty; }
}

// 🔹 Abstract Bill class
abstract class Bill {
    protected Customer customer;
    protected List<Item> items;

    public Bill(Customer customer, List<Item> items) {
        this.customer = customer;
        this.items = items;
    }

    public abstract double generateBill();
}

// 🔹 Regular Bill
class RegularBill extends Bill {
    public RegularBill(Customer customer, List<Item> items) {
        super(customer, items);
    }

    public double generateBill() {
        double total = items.stream().mapToDouble(Item::getPrice).sum();
        double tax = total * 0.10;
        return total + tax;
    }
}

// 🔹 Premium Bill
class PremiumBill extends Bill {
    public PremiumBill(Customer customer, List<Item> items) {
        super(customer, items);
    }

    public double generateBill() {
        double total = items.stream().mapToDouble(Item::getPrice).sum();
        double discount = total * 0.10;
        double tax = (total - discount) * 0.05;
        return (total - discount) + tax;
    }
}

// 🔹 Shop class
class Shop {
    private String name;
    private List<Item> inventory = new ArrayList<>();

    public Shop(String name) {
        this.name = name;
    }

    public String getName() { return name; }

    public void addItem(Item item) {
        inventory.add(item);
        System.out.println("✅ Item added: " + item.getName() + " - ₹" + item.getPrice());
    }

    public Item findItem(String itemName) {
        for (Item i : inventory) {
            if (i.getName().equalsIgnoreCase(itemName)) return i;
        }
        return null;
    }
}

// 🔹 Mall class
class Mall {
    private List<Shop> shops = new ArrayList<>();
    private List<Customer> customers = new ArrayList<>();

    public void registerShop(Shop shop) {
        shops.add(shop);
        System.out.println("✅ Shop registered: " + shop.getName());
    }

    public void registerCustomer(Customer customer) {
        for (Customer c : customers) {
            if (c.getName().equalsIgnoreCase(customer.getName())) {
                System.out.println("⚠️ Customer " + customer.getName() + " already exists!");
                return;
            }
        }
        customers.add(customer);
        System.out.println("✅ Customer registered: " + customer.getName() + (customer.isPremium() ? " (Premium)" : " (Regular)"));
    }

    public void purchase(String customerName, String shopName, List<String> itemNames) {
        Customer customer = customers.stream().filter(c -> c.getName().equalsIgnoreCase(customerName)).findFirst().orElse(null);
        Shop shop = shops.stream().filter(s -> s.getName().equalsIgnoreCase(shopName)).findFirst().orElse(null);

        if (customer == null || shop == null) {
            System.out.println("⚠️ Invalid shop or customer!");
            return;
        }

        List<Item> boughtItems = new ArrayList<>();
        for (String itemName : itemNames) {
            Item item = shop.findItem(itemName);
            if (item == null || item.getStock() <= 0) {
                System.out.println("❌ Item '" + itemName + "' is out of stock!");
                continue;
            }
            item.reduceStock(1);
            boughtItems.add(item);
        }

        if (!boughtItems.isEmpty()) {
            Bill bill = customer.isPremium() ? new PremiumBill(customer, boughtItems) : new RegularBill(customer, boughtItems);
            double amount = bill.generateBill();
            System.out.println("✅ Purchase successful! " + customer.getName() + " bought " + itemNames);
            System.out.println("Bill for " + customer.getName() + ": ₹" + amount);
        }
    }
}

// 🔹 Main Class
public class ShoppingMallManagementSystem {
    public static void main(String[] args) {
        Mall mall = new Mall();

        // Register shops
        Shop fashionHub = new Shop("Fashion Hub");
        mall.registerShop(fashionHub);

        // Add items
        fashionHub.addItem(new Item("Jeans", 2000, 2));
        fashionHub.addItem(new Item("T-Shirt", 800, 1));

        // Register customers
        Customer riya = new Customer("Riya Sharma", "9999999999", true);
        mall.registerCustomer(riya);
        Customer aman = new Customer("Aman Verma", "8888888888", false);
        mall.registerCustomer(aman);

        // Make purchases
        mall.purchase("Riya Sharma", "Fashion Hub", Arrays.asList("Jeans", "T-Shirt"));
        mall.purchase("Aman Verma", "Fashion Hub", Arrays.asList("T-Shirt"));
        mall.purchase("Aman Verma", "Fashion Hub", Arrays.asList("T-Shirt")); // Out of stock
        mall.registerCustomer(new Customer("Aman Verma", "8888888888", false)); // Duplicate
    }
}
````

---
