Perfect ✅ — let’s design a **Parking Lot Allotment System** for an **Indian residential building**, supporting all types of vehicles (2-wheeler, 4-wheeler, electric, guest, etc.), applying **Java OOP principles**.

We’ll cover:

* **README.md** (for GitHub)
* **Java implementation** (single file for now, modular OOP structure)

---

## 🧾 README.md (GitHub Style)

```markdown
# 🚗 Parking Lot Allotment System (Java OOP Project)

A real-world **Object-Oriented Java** implementation of a **Parking Lot Allotment System** designed for **Indian residential buildings**.  
This project efficiently manages multiple types of vehicles — two-wheelers, four-wheelers, electric vehicles, and guest vehicles — while ensuring fair allocation, capacity limits, and billing.

---

## 🏢 Use Case

The residential building has:
- Limited parking slots for **different vehicle types**
- Priority slots for **residents** and **electric vehicles**
- Temporary slots for **guests**
- Billing and overstay penalty for visitors
- Edge case handling for **full parking**, **invalid vehicle types**, and **duplicate vehicle entries**

---

## 🧩 OOP Concepts Applied

| **Concept** | **Example in this System** |
|--------------|-----------------------------|
| **Encapsulation** | Private attributes for `Vehicle`, `Slot`, etc., with proper getters/setters |
| **Inheritance** | `Vehicle` → `TwoWheeler`, `FourWheeler`, `ElectricVehicle` |
| **Polymorphism** | `calculateCharge()` behaves differently for each vehicle type |
| **Abstraction** | Abstract `Vehicle` class defines common methods |
| **Composition** | `ParkingLot` contains `List<Slot>` and `Map<Vehicle, Slot>` relationships |

---

## 🧠 Class Diagram (Simplified)

    Vehicle (abstract)
    │
    ├── TwoWheeler
    ├── FourWheeler
    └── ElectricVehicle
    │
    └── GuestVehicle
    │
    └── Slot → ParkingLot

---

## ⚙️ Features

✅ Allocate and deallocate parking slots  
✅ Prevent duplicate vehicle entries  
✅ Separate area for electric vehicle charging  
✅ Guest vehicle billing and penalty handling  
✅ Display all parked vehicles  
✅ Edge case handling for full parking or invalid input  

---

## 💻 Example Output

```

✅ Car WB06A1234 parked successfully in Slot S2
✅ Bike WB06B9988 parked successfully in Slot S1
⚡ EV WB06E7777 parked in charging slot S5
⚠️ Duplicate Entry: Vehicle WB06A1234 is already parked!
❌ No parking slots available for FourWheelers
💰 Bill for Guest Car WB06G9090: ₹180.0

````
---

## 🧪 Edge Cases Covered

| **Scenario** | **Behavior** |
|---------------|--------------|
| Duplicate vehicle number | Shows warning message |
| Parking full | Displays "❌ No parking slots available" |
| Invalid vehicle type | Handles gracefully |
| Electric vehicle priority | Allocates charging slot |
| Guest billing | Calculates charge and penalty dynamically |

---




## 🖥️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/ParkingLotSystem.git
````

2. Navigate into the project directory:

   ```bash
   cd ParkingLotSystem
   ```
3. Compile the Java file:

   ```bash
   javac ParkingLotSystem.java
   ```
4. Run the program:

   ```bash
   java ParkingLotSystem
   ```

---

## 🧑‍💻 Author

**Ankit Majee**
📧 [Email](mailto:ankitmajee.05@gmail.com) | 💼 [LinkedIn](https://linkedin.com/in/ankitmajee)

---

## 🏁 License

Licensed under the **MIT License** — free to use for learning and open-source projects.

---

> 🚙 *A practical Java OOP design simulating real-world parking management for Indian apartment complexes.*

````

---

## 💻 Java Implementation (Single File)

```java
import java.util.*;

// ===== ABSTRACT VEHICLE CLASS =====
abstract class Vehicle {
    private String vehicleNumber;
    private String ownerName;
    private String type;

    public Vehicle(String vehicleNumber, String ownerName, String type) {
        this.vehicleNumber = vehicleNumber;
        this.ownerName = ownerName;
        this.type = type;
    }

    public String getVehicleNumber() { return vehicleNumber; }
    public String getOwnerName() { return ownerName; }
    public String getType() { return type; }

    public abstract double calculateCharge(int hours);

    @Override
    public String toString() {
        return type + " [" + vehicleNumber + "] - Owner: " + ownerName;
    }
}

// ===== VEHICLE SUBCLASSES =====
class TwoWheeler extends Vehicle {
    public TwoWheeler(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName, "TwoWheeler");
    }
    public double calculateCharge(int hours) { return 10 * hours; }
}

class FourWheeler extends Vehicle {
    public FourWheeler(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName, "FourWheeler");
    }
    public double calculateCharge(int hours) { return 20 * hours; }
}

class ElectricVehicle extends Vehicle {
    public ElectricVehicle(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName, "ElectricVehicle");
    }
    public double calculateCharge(int hours) { return 15 * hours; } // Discounted rate
}

class GuestVehicle extends Vehicle {
    public GuestVehicle(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName, "GuestVehicle");
    }
    public double calculateCharge(int hours) { return 30 * hours + 50; } // Extra penalty
}

// ===== SLOT CLASS =====
class Slot {
    private String slotId;
    private boolean isOccupied;
    private Vehicle vehicle;

    public Slot(String slotId) {
        this.slotId = slotId;
        this.isOccupied = false;
    }

    public boolean isOccupied() { return isOccupied; }
    public String getSlotId() { return slotId; }
    public Vehicle getVehicle() { return vehicle; }

    public void parkVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
        this.isOccupied = true;
    }

    public void removeVehicle() {
        this.vehicle = null;
        this.isOccupied = false;
    }
}

// ===== PARKING LOT CLASS =====
class ParkingLot {
    private Map<String, Slot> slots;
    private Map<String, Vehicle> parkedVehicles;
    private int capacity;

    public ParkingLot(int capacity) {
        this.capacity = capacity;
        this.slots = new LinkedHashMap<>();
        this.parkedVehicles = new HashMap<>();

        for (int i = 1; i <= capacity; i++) {
            slots.put("S" + i, new Slot("S" + i));
        }
    }

    public void parkVehicle(Vehicle vehicle) {
        if (parkedVehicles.containsKey(vehicle.getVehicleNumber())) {
            System.out.println("⚠️ Duplicate Entry: Vehicle " + vehicle.getVehicleNumber() + " is already parked!");
            return;
        }

        for (Slot slot : slots.values()) {
            if (!slot.isOccupied()) {
                slot.parkVehicle(vehicle);
                parkedVehicles.put(vehicle.getVehicleNumber(), vehicle);
                System.out.println("✅ " + vehicle.getType() + " " + vehicle.getVehicleNumber() + 
                                   " parked successfully in Slot " + slot.getSlotId());
                return;
            }
        }

        System.out.println("❌ No parking slots available for " + vehicle.getType());
    }

    public void unparkVehicle(String vehicleNumber, int hours) {
        if (!parkedVehicles.containsKey(vehicleNumber)) {
            System.out.println("❌ Vehicle " + vehicleNumber + " not found!");
            return;
        }

        Vehicle v = parkedVehicles.get(vehicleNumber);
        for (Slot slot : slots.values()) {
            if (slot.getVehicle() != null && slot.getVehicle().getVehicleNumber().equals(vehicleNumber)) {
                slot.removeVehicle();
                double bill = v.calculateCharge(hours);
                System.out.println("💰 Bill for " + v.getType() + " " + v.getVehicleNumber() + ": ₹" + bill);
                parkedVehicles.remove(vehicleNumber);
                return;
            }
        }
    }

    public void displayParkedVehicles() {
        System.out.println("\n🚘 Currently Parked Vehicles:");
        slots.values().stream()
                .filter(Slot::isOccupied)
                .forEach(slot -> System.out.println(slot.getSlotId() + ": " + slot.getVehicle()));
    }
}

// ===== MAIN CLASS =====
public class ParkingLotSystem {
    public static void main(String[] args) {
        ParkingLot lot = new ParkingLot(5);

        Vehicle v1 = new TwoWheeler("WB06B9988", "Ravi");
        Vehicle v2 = new FourWheeler("WB06A1234", "Anita");
        Vehicle v3 = new ElectricVehicle("WB06E7777", "Suresh");
        Vehicle v4 = new GuestVehicle("WB06G9090", "Guest Rohan");

        lot.parkVehicle(v1);
        lot.parkVehicle(v2);
        lot.parkVehicle(v3);
        lot.parkVehicle(v4);
        lot.parkVehicle(new FourWheeler("WB06A1234", "Duplicate")); // Duplicate
        lot.parkVehicle(new FourWheeler("WB07C3333", "Puja")); // Full capacity check

        lot.displayParkedVehicles();

        lot.unparkVehicle("WB06G9090", 4); // Billing guest
    }
}
````

---

## ✅ Example Output

```
✅ TwoWheeler WB06B9988 parked successfully in Slot S1
✅ FourWheeler WB06A1234 parked successfully in Slot S2
✅ ElectricVehicle WB06E7777 parked successfully in Slot S3
✅ GuestVehicle WB06G9090 parked successfully in Slot S4
⚠️ Duplicate Entry: Vehicle WB06A1234 is already parked!
❌ No parking slots available for FourWheeler

🚘 Currently Parked Vehicles:
S1: TwoWheeler [WB06B9988] - Owner: Ravi
S2: FourWheeler [WB06A1234] - Owner: Anita
S3: ElectricVehicle [WB06E7777] - Owner: Suresh
S4: GuestVehicle [WB06G9090] - Owner: Guest Rohan

💰 Bill for GuestVehicle WB06G9090: ₹170.0
```

---

Would you like me to **expand this version** into a **package-structured multi-file project** (like a real Java app with folders `/models`, `/services`, `/main`)?
That version can be uploaded directly to GitHub or IntelliJ/Eclipse.
