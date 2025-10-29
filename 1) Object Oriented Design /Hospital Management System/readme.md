Here’s a clean and professional **GitHub README.md** version of your Hospital Management System 👇

---

```markdown
# 🏥 Hospital Management System (Java OOP Project)

A complete **Object-Oriented Programming (OOP)** implementation of a **Hospital Management System** in Java.  
This project demonstrates key OOP principles like **Encapsulation**, **Inheritance**, **Polymorphism**, **Abstraction**, and **Composition** through real-world hospital use cases.

---

## 🚀 Overview

This system allows:
- Doctors and Patients management  
- Appointment scheduling between patients and doctors  
- Department-based doctor organization  
- Automated bill generation for in-patients and out-patients  
- Handling of invalid appointments, duplicate entries, and overbooking scenarios  

---

## 🧩 OOP Concepts Applied

| **Concept** | **Implementation Example** |
|--------------|-----------------------------|
| **Encapsulation** | Private fields for `Doctor`, `Patient`, etc. with getters/setters |
| **Inheritance** | `Person` → `Doctor`, `Patient` |
| **Polymorphism** | `generateBill()` behaves differently for in-patient and out-patient |
| **Abstraction** | Abstract class `Person` defines common features |
| **Composition** | `Hospital` has `List<Doctor>`, `List<Patient>`, etc. |

---

## 🧠 Class Diagram (Simplified)

```

Person (abstract)
│
├── Doctor
│
└── Patient
│
└── Appointment → Billing

```

---

## 🏗️ Project Structure

```

HospitalManagementSystem.java
├── Person.java               (Abstract base class)
├── Doctor.java               (Extends Person)
├── Patient.java              (Extends Person)
├── Appointment.java          (Handles doctor-patient meetings)
├── Bill.java                 (Abstract base for billing)
├── InPatientBill.java        (Polymorphic implementation for admitted patients)
├── OutPatientBill.java       (Polymorphic implementation for visiting patients)
└── Hospital.java             (Central controller for doctors, patients, appointments)

```

---

## ⚙️ Features Implemented

✅ Add and manage doctors and patients  
✅ Book appointments and confirm availability  
✅ Handle duplicate and invalid booking scenarios  
✅ Generate bills with polymorphic behavior  
✅ Demonstrates all core OOP principles in one use case  

---

## 🧾 Example Output

```

✅ Appointment confirmed for Ravi Kumar with Dr. Arjun Singh
✅ Appointment confirmed for Neha Patel with Dr. Arjun Singh
❌ Doctor Arjun Singh is fully booked today!
✅ Appointment confirmed for Neha Patel with Dr. Priya Sharma
⚠️ Appointment already exists!
Bill for Ravi Kumar: ₹6500.0
Bill for Neha Patel: ₹1300.0

````

---

## 🧪 Edge Cases Covered

| **Scenario** | **Behavior** |
|---------------|--------------|
| Invalid doctor/patient ID | Prints “❌ Invalid Doctor or Patient ID!” |
| Duplicate appointment | Prints “⚠️ Appointment already exists!” |
| Overbooked doctor | Throws and handles “Doctor is fully booked today!” |
| Different billing types | In-patient and Out-patient bills calculated differently |

---

## 🖥️ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/HospitalManagementSystem.git
````

2. Navigate into the project directory:

   ```bash
   cd HospitalManagementSystem
   ```
3. Compile the Java files:

   ```bash
   javac HospitalManagementSystem.java
   ```
4. Run the program:

   ```bash
   java HospitalManagementSystem
   ```

---

## 🧑‍💻 Author

**Ankit Majee**
📧 [Email](mailto:ankitmajee.05@gmail.com) | 💼 [LinkedIn](https://linkedin.com/in/ankitmajee)

---

## 🏁 License

This project is licensed under the **MIT License** – feel free to use and modify it for educational purposes.
