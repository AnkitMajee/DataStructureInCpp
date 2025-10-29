import java.util.*;

// ===== ABSTRACT CLASS =====
abstract class Person {
    private String id;
    private String name;
    private int age;
    private String gender;

    public Person(String id, String name, int age, String gender) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public int getAge() { return age; }
    public String getGender() { return gender; }

    public abstract void displayInfo();
}

// ===== DOCTOR CLASS =====
class Doctor extends Person {
    private String specialization;
    private String department;
    private int maxAppointmentsPerDay;
    private List<Appointment> appointments;

    public Doctor(String id, String name, int age, String gender, 
                  String specialization, String department, int maxAppointmentsPerDay) {
        super(id, name, age, gender);
        this.specialization = specialization;
        this.department = department;
        this.maxAppointmentsPerDay = maxAppointmentsPerDay;
        this.appointments = new ArrayList<>();
    }

    public boolean isAvailable() {
        return appointments.size() < maxAppointmentsPerDay;
    }

    public void addAppointment(Appointment appointment) {
        if (isAvailable()) {
            appointments.add(appointment);
        } else {
            throw new IllegalStateException("Doctor " + getName() + " is fully booked today!");
        }
    }

    @Override
    public void displayInfo() {
        System.out.println("Dr. " + getName() + " (" + specialization + ", " + department + ")");
    }
}

// ===== PATIENT CLASS =====
class Patient extends Person {
    private String disease;
    private boolean isAdmitted;

    public Patient(String id, String name, int age, String gender, String disease, boolean isAdmitted) {
        super(id, name, age, gender);
        this.disease = disease;
        this.isAdmitted = isAdmitted;
    }

    public String getDisease() { return disease; }
    public boolean isAdmitted() { return isAdmitted; }

    @Override
    public void displayInfo() {
        System.out.println("Patient: " + getName() + " | Disease: " + disease + 
                           " | Admitted: " + (isAdmitted ? "Yes" : "No"));
    }
}

// ===== APPOINTMENT CLASS =====
class Appointment {
    private Doctor doctor;
    private Patient patient;
    private Date date;
    private boolean isConfirmed;

    public Appointment(Doctor doctor, Patient patient, Date date) {
        this.doctor = doctor;
        this.patient = patient;
        this.date = date;
        this.isConfirmed = false;
    }

    public void confirm() {
        if (doctor.isAvailable()) {
            doctor.addAppointment(this);
            isConfirmed = true;
            System.out.println("Appointment confirmed for " + patient.getName() + " with Dr. " + doctor.getName());
        } else {
            System.out.println("Doctor not available!");
        }
    }

    public boolean isConfirmed() { return isConfirmed; }
    public Doctor getDoctor() { return doctor; }
    public Patient getPatient() { return patient; }
}

// ===== BILLING SYSTEM =====
abstract class Bill {
    protected Patient patient;
    protected double baseAmount;

    public Bill(Patient patient, double baseAmount) {
        this.patient = patient;
        this.baseAmount = baseAmount;
    }

    public abstract double generateBill();

    public void printBill() {
        System.out.println("Bill for " + patient.getName() + ": ₹" + generateBill());
    }
}

// Polymorphism: Two types of bills
class InPatientBill extends Bill {
    private int daysAdmitted;
    private double roomChargePerDay;

    public InPatientBill(Patient patient, double baseAmount, int daysAdmitted, double roomChargePerDay) {
        super(patient, baseAmount);
        this.daysAdmitted = daysAdmitted;
        this.roomChargePerDay = roomChargePerDay;
    }

    @Override
    public double generateBill() {
        return baseAmount + (daysAdmitted * roomChargePerDay);
    }
}

class OutPatientBill extends Bill {
    private double consultationFee;

    public OutPatientBill(Patient patient, double baseAmount, double consultationFee) {
        super(patient, baseAmount);
        this.consultationFee = consultationFee;
    }

    @Override
    public double generateBill() {
        return baseAmount + consultationFee;
    }
}

// ===== HOSPITAL CLASS =====
class Hospital {
    private String name;
    private List<Doctor> doctors;
    private List<Patient> patients;
    private List<Appointment> appointments;

    public Hospital(String name) {
        this.name = name;
        this.doctors = new ArrayList<>();
        this.patients = new ArrayList<>();
        this.appointments = new ArrayList<>();
    }

    public void addDoctor(Doctor doctor) {
        doctors.add(doctor);
    }

    public void addPatient(Patient patient) {
        patients.add(patient);
    }

    public void bookAppointment(String doctorId, String patientId, Date date) {
        Doctor doctor = doctors.stream().filter(d -> d.getId().equals(doctorId)).findFirst().orElse(null);
        Patient patient = patients.stream().filter(p -> p.getId().equals(patientId)).findFirst().orElse(null);

        if (doctor == null || patient == null) {
            System.out.println("Invalid Doctor or Patient ID!");
            return;
        }

        // Prevent duplicate appointments
        boolean alreadyExists = appointments.stream()
                .anyMatch(a -> a.getDoctor().equals(doctor) && a.getPatient().equals(patient) && a.isConfirmed());
        if (alreadyExists) {
            System.out.println("Appointment already exists!");
            return;
        }

        Appointment appointment = new Appointment(doctor, patient, date);
        appointment.confirm();

        if (appointment.isConfirmed()) {
            appointments.add(appointment);
        }
    }
}

// ===== MAIN CLASS =====
public class HospitalManagementSystem {
    public static void main(String[] args) {
        Hospital hospital = new Hospital("City Care Hospital");

        Doctor d1 = new Doctor("D1", "Arjun Singh", 40, "Male", "Cardiologist", "Cardiology", 2);
        Doctor d2 = new Doctor("D2", "Priya Sharma", 35, "Female", "Dermatologist", "Skin", 3);

        Patient p1 = new Patient("P1", "Ravi Kumar", 28, "Male", "Chest Pain", true);
        Patient p2 = new Patient("P2", "Neha Patel", 22, "Female", "Rash", false);
        Patient p3 = new Patient("P3", "Amit Sharma", 30, "Male", "Headache", false);

        hospital.addDoctor(d1);
        hospital.addDoctor(d2);
        hospital.addPatient(p1);
        hospital.addPatient(p2);
        hospital.addPatient(p3);

        // Booking appointments (normal + edge cases)
        hospital.bookAppointment("D1", "P1", new Date());
        hospital.bookAppointment("D1", "P2", new Date());
        hospital.bookAppointment("D1", "P3", new Date()); // Edge case: overbooking doctor

        hospital.bookAppointment("D2", "P2", new Date());
        hospital.bookAppointment("D2", "P2", new Date()); // Edge case: duplicate appointment

        // Bills
        Bill inBill = new InPatientBill(p1, 2000, 3, 1500);
        Bill outBill = new OutPatientBill(p2, 500, 800);

        inBill.printBill();
        outBill.printBill();
    }
}
