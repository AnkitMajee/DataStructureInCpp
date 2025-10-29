🏥 Use Case: Hospital Management System

The hospital has:

Doctors, Patients, Appointments, Departments, and Billing System.

Each patient can book an appointment with a doctor.

Each doctor belongs to a department.

Bills are generated based on services.

The system should handle invalid appointments, duplicate entries, and overbooking (edge cases).

🧩 OOP Concepts Applied
Concept	Example in this System
Encapsulation	Private fields for Doctor, Patient, etc. with getters/setters
Inheritance	Person → Doctor, Patient
Polymorphism	generateBill() behaves differently for in-patient and out-patient
Abstraction	Abstract class Person defines common features
Composition	Hospital has List<Doctor>, List<Patient> etc.

      🧠 Class Diagram (simplified)
      Person (abstract)
      │
      ├── Doctor
      │
      └── Patient
              │
              └── Appointment → Billing
