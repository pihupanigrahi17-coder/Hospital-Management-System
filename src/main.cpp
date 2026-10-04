#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// ============================================================
// DATA STRUCTURES
// ============================================================

struct Patient
{
    int id;
    string name;
    int age;
    string gender;
    string bloodGroup;
    string phone;
    string disease;
};

struct Doctor
{
    int id;
    string name;
    string specialization;
    string department;
    int experience;
    string phone;
};

struct Appointment
{
    int id;
    int patientId;
    int doctorId;
    string date;
    string time;
    string status;
};

struct MedicalRecord
{
    int id;
    int patientId;
    int doctorId;
    string diagnosis;
    string prescription;
    string notes;
};

struct Medicine
{
    int id;
    string name;
    int quantity;
    double price;
    string expiryDate;
};

// ============================================================
// GLOBAL STORAGE
// ============================================================

vector<Patient> patients;
vector<Doctor> doctors;
vector<Appointment> appointments;
vector<MedicalRecord> medicalRecords;
vector<Medicine> medicines;

// ============================================================
// UTILITY FUNCTIONS
// ============================================================

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool patientExists(int id)
{
    for (const auto& patient : patients)
    {
        if (patient.id == id)
        {
            return true;
        }
    }

    return false;
}

bool doctorExists(int id)
{
    for (const auto& doctor : doctors)
    {
        if (doctor.id == id)
        {
            return true;
        }
    }

    return false;
}

// ============================================================
// PATIENT MANAGEMENT
// ============================================================

void addPatient()
{
    Patient patient;

    cout << "\n========== ADD PATIENT ==========\n";

    cout << "Enter Patient ID: ";
    cin >> patient.id;

    if (patientExists(patient.id))
    {
        cout << "Patient ID already exists.\n";
        clearInput();
        return;
    }

    clearInput();

    cout << "Enter Name: ";
    getline(cin, patient.name);

    cout << "Enter Age: ";
    cin >> patient.age;
    clearInput();

    cout << "Enter Gender: ";
    getline(cin, patient.gender);

    cout << "Enter Blood Group: ";
    getline(cin, patient.bloodGroup);

    cout << "Enter Phone Number: ";
    getline(cin, patient.phone);

    cout << "Enter Disease/Problem: ";
    getline(cin, patient.disease);

    patients.push_back(patient);

    cout << "\nPatient added successfully.\n";
}

void viewPatients()
{
    cout << "\n========== PATIENT LIST ==========\n";

    if (patients.empty())
    {
        cout << "No patients available.\n";
        return;
    }

    for (const auto& patient : patients)
    {
        cout << "\nPatient ID    : " << patient.id;
        cout << "\nName          : " << patient.name;
        cout << "\nAge           : " << patient.age;
        cout << "\nGender        : " << patient.gender;
        cout << "\nBlood Group   : " << patient.bloodGroup;
        cout << "\nPhone         : " << patient.phone;
        cout << "\nDisease       : " << patient.disease;
        cout << "\n----------------------------------";
    }

    cout << endl;
}

void searchPatient()
{
    int id;

    cout << "\nEnter Patient ID to search: ";
    cin >> id;

    for (const auto& patient : patients)
    {
        if (patient.id == id)
        {
            cout << "\nPatient Found!\n";
            cout << "ID          : " << patient.id << endl;
            cout << "Name        : " << patient.name << endl;
            cout << "Age         : " << patient.age << endl;
            cout << "Gender      : " << patient.gender << endl;
            cout << "Blood Group : " << patient.bloodGroup << endl;
            cout << "Phone       : " << patient.phone << endl;
            cout << "Disease     : " << patient.disease << endl;

            return;
        }
    }

    cout << "Patient not found.\n";
}

void deletePatient()
{
    int id;

    cout << "\nEnter Patient ID to delete: ";
    cin >> id;

    for (auto it = patients.begin(); it != patients.end(); ++it)
    {
        if (it->id == id)
        {
            patients.erase(it);
            cout << "Patient deleted successfully.\n";
            return;
        }
    }

    cout << "Patient not found.\n";
}

void patientMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "        PATIENT MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Delete Patient\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                viewPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                deletePatient();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// DOCTOR MANAGEMENT
// ============================================================

void addDoctor()
{
    Doctor doctor;

    cout << "\n========== ADD DOCTOR ==========\n";

    cout << "Enter Doctor ID: ";
    cin >> doctor.id;

    if (doctorExists(doctor.id))
    {
        cout << "Doctor ID already exists.\n";
        clearInput();
        return;
    }

    clearInput();

    cout << "Enter Name: ";
    getline(cin, doctor.name);

    cout << "Enter Specialization: ";
    getline(cin, doctor.specialization);

    cout << "Enter Department: ";
    getline(cin, doctor.department);

    cout << "Enter Years of Experience: ";
    cin >> doctor.experience;
    clearInput();

    cout << "Enter Phone Number: ";
    getline(cin, doctor.phone);

    doctors.push_back(doctor);

    cout << "\nDoctor added successfully.\n";
}

void viewDoctors()
{
    cout << "\n========== DOCTOR LIST ==========\n";

    if (doctors.empty())
    {
        cout << "No doctors available.\n";
        return;
    }

    for (const auto& doctor : doctors)
    {
        cout << "\nDoctor ID       : " << doctor.id;
        cout << "\nName            : " << doctor.name;
        cout << "\nSpecialization  : " << doctor.specialization;
        cout << "\nDepartment      : " << doctor.department;
        cout << "\nExperience      : " << doctor.experience << " years";
        cout << "\nPhone           : " << doctor.phone;
        cout << "\n----------------------------------";
    }

    cout << endl;
}

void searchDoctor()
{
    int id;

    cout << "\nEnter Doctor ID to search: ";
    cin >> id;

    for (const auto& doctor : doctors)
    {
        if (doctor.id == id)
        {
            cout << "\nDoctor Found!\n";
            cout << "ID             : " << doctor.id << endl;
            cout << "Name           : " << doctor.name << endl;
            cout << "Specialization : " << doctor.specialization << endl;
            cout << "Department     : " << doctor.department << endl;
            cout << "Experience     : " << doctor.experience << " years" << endl;
            cout << "Phone          : " << doctor.phone << endl;

            return;
        }
    }

    cout << "Doctor not found.\n";
}

void deleteDoctor()
{
    int id;

    cout << "\nEnter Doctor ID to delete: ";
    cin >> id;

    for (auto it = doctors.begin(); it != doctors.end(); ++it)
    {
        if (it->id == id)
        {
            doctors.erase(it);
            cout << "Doctor deleted successfully.\n";
            return;
        }
    }

    cout << "Doctor not found.\n";
}

void doctorMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "         DOCTOR MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Add Doctor\n";
        cout << "2. View Doctors\n";
        cout << "3. Search Doctor\n";
        cout << "4. Delete Doctor\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addDoctor();
                break;

            case 2:
                viewDoctors();
                break;

            case 3:
                searchDoctor();
                break;

            case 4:
                deleteDoctor();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// APPOINTMENT MANAGEMENT
// ============================================================

void addAppointment()
{
    Appointment appointment;

    cout << "\n========== ADD APPOINTMENT ==========\n";

    cout << "Enter Appointment ID: ";
    cin >> appointment.id;

    cout << "Enter Patient ID: ";
    cin >> appointment.patientId;

    if (!patientExists(appointment.patientId))
    {
        cout << "Patient does not exist.\n";
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> appointment.doctorId;

    if (!doctorExists(appointment.doctorId))
    {
        cout << "Doctor does not exist.\n";
        return;
    }

    clearInput();

    cout << "Enter Date: ";
    getline(cin, appointment.date);

    cout << "Enter Time: ";
    getline(cin, appointment.time);

    appointment.status = "Scheduled";

    appointments.push_back(appointment);

    cout << "\nAppointment created successfully.\n";
}

void viewAppointments()
{
    cout << "\n========== APPOINTMENTS ==========\n";

    if (appointments.empty())
    {
        cout << "No appointments available.\n";
        return;
    }

    for (const auto& appointment : appointments)
    {
        cout << "\nAppointment ID : " << appointment.id;
        cout << "\nPatient ID     : " << appointment.patientId;
        cout << "\nDoctor ID      : " << appointment.doctorId;
        cout << "\nDate           : " << appointment.date;
        cout << "\nTime           : " << appointment.time;
        cout << "\nStatus         : " << appointment.status;
        cout << "\n----------------------------------";
    }

    cout << endl;
}

void appointmentMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "       APPOINTMENT MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Add Appointment\n";
        cout << "2. View Appointments\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addAppointment();
                break;

            case 2:
                viewAppointments();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// MEDICAL RECORD MANAGEMENT
// ============================================================

void addMedicalRecord()
{
    MedicalRecord record;

    cout << "\n========== ADD MEDICAL RECORD ==========\n";

    cout << "Enter Record ID: ";
    cin >> record.id;

    cout << "Enter Patient ID: ";
    cin >> record.patientId;

    if (!patientExists(record.patientId))
    {
        cout << "Patient does not exist.\n";
        return;
    }

    cout << "Enter Doctor ID: ";
    cin >> record.doctorId;

    if (!doctorExists(record.doctorId))
    {
        cout << "Doctor does not exist.\n";
        return;
    }

    clearInput();

    cout << "Enter Diagnosis: ";
    getline(cin, record.diagnosis);

    cout << "Enter Prescription: ";
    getline(cin, record.prescription);

    cout << "Enter Notes: ";
    getline(cin, record.notes);

    medicalRecords.push_back(record);

    cout << "\nMedical record added successfully.\n";
}

void viewMedicalRecords()
{
    cout << "\n========== MEDICAL RECORDS ==========\n";

    if (medicalRecords.empty())
    {
        cout << "No medical records available.\n";
        return;
    }

    for (const auto& record : medicalRecords)
    {
        cout << "\nRecord ID     : " << record.id;
        cout << "\nPatient ID    : " << record.patientId;
        cout << "\nDoctor ID     : " << record.doctorId;
        cout << "\nDiagnosis     : " << record.diagnosis;
        cout << "\nPrescription  : " << record.prescription;
        cout << "\nNotes         : " << record.notes;
        cout << "\n-------------------------------------";
    }

    cout << endl;
}

void medicalRecordMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "        MEDICAL RECORDS\n";
        cout << "====================================\n";
        cout << "1. Add Medical Record\n";
        cout << "2. View Medical Records\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addMedicalRecord();
                break;

            case 2:
                viewMedicalRecords();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// PHARMACY MANAGEMENT
// ============================================================

void addMedicine()
{
    Medicine medicine;

    cout << "\n========== ADD MEDICINE ==========\n";

    cout << "Enter Medicine ID: ";
    cin >> medicine.id;

    clearInput();

    cout << "Enter Medicine Name: ";
    getline(cin, medicine.name);

    cout << "Enter Quantity: ";
    cin >> medicine.quantity;

    cout << "Enter Price: ";
    cin >> medicine.price;

    clearInput();

    cout << "Enter Expiry Date: ";
    getline(cin, medicine.expiryDate);

    medicines.push_back(medicine);

    cout << "\nMedicine added successfully.\n";
}

void viewMedicines()
{
    cout << "\n========== PHARMACY STOCK ==========\n";

    if (medicines.empty())
    {
        cout << "No medicines available.\n";
        return;
    }

    cout << fixed << setprecision(2);

    for (const auto& medicine : medicines)
    {
        cout << "\nMedicine ID : " << medicine.id;
        cout << "\nName        : " << medicine.name;
        cout << "\nQuantity    : " << medicine.quantity;
        cout << "\nPrice       : Rs. " << medicine.price;
        cout << "\nExpiry Date : " << medicine.expiryDate;
        cout << "\n------------------------------------";
    }

    cout << endl;
}

void updateMedicineStock()
{
    int id;
    int quantity;

    cout << "\nEnter Medicine ID: ";
    cin >> id;

    for (auto& medicine : medicines)
    {
        if (medicine.id == id)
        {
            cout << "Current Quantity: " << medicine.quantity << endl;

            cout << "Enter new quantity: ";
            cin >> quantity;

            medicine.quantity = quantity;

            cout << "Stock updated successfully.\n";
            return;
        }
    }

    cout << "Medicine not found.\n";
}

void pharmacyMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "          PHARMACY MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Add Medicine\n";
        cout << "2. View Medicines\n";
        cout << "3. Update Stock\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addMedicine();
                break;

            case 2:
                viewMedicines();
                break;

            case 3:
                updateMedicineStock();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// BILLING
// ============================================================

void generateBill()
{
    int patientId;
    double consultationFee;
    double medicineCharge;
    double testCharge;
    double roomCharge;

    cout << "\n========== GENERATE BILL ==========\n";

    cout << "Enter Patient ID: ";
    cin >> patientId;

    if (!patientExists(patientId))
    {
        cout << "Patient does not exist.\n";
        return;
    }

    cout << "Consultation Fee: Rs. ";
    cin >> consultationFee;

    cout << "Medicine Charges: Rs. ";
    cin >> medicineCharge;

    cout << "Test Charges: Rs. ";
    cin >> testCharge;

    cout << "Room Charges: Rs. ";
    cin >> roomCharge;

    double total =
        consultationFee +
        medicineCharge +
        testCharge +
        roomCharge;

    cout << fixed << setprecision(2);

    cout << "\n====================================\n";
    cout << "              HOSPITAL BILL\n";
    cout << "====================================\n";
    cout << "Patient ID        : " << patientId << endl;
    cout << "Consultation      : Rs. " << consultationFee << endl;
    cout << "Medicine          : Rs. " << medicineCharge << endl;
    cout << "Tests             : Rs. " << testCharge << endl;
    cout << "Room              : Rs. " << roomCharge << endl;
    cout << "------------------------------------\n";
    cout << "TOTAL             : Rs. " << total << endl;
    cout << "====================================\n";
}

void billingMenu()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "             BILLING\n";
        cout << "====================================\n";
        cout << "1. Generate Bill\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                generateBill();
                break;

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}

// ============================================================
// SAMPLE DATA
// ============================================================

void loadSampleData()
{
    Patient p1 = {
        101,
        "Rahul Sharma",
        35,
        "Male",
        "O+",
        "9876543210",
        "Fever"
    };

    Patient p2 = {
        102,
        "Priya Das",
        28,
        "Female",
        "B+",
        "9876501234",
        "Migraine"
    };

    Doctor d1 = {
        201,
        "Dr. Amit Kumar",
        "Cardiologist",
        "Cardiology",
        12,
        "9123456789"
    };

    Doctor d2 = {
        202,
        "Dr. Neha Singh",
        "General Physician",
        "General Medicine",
        8,
        "9123456788"
    };

    Medicine m1 = {
        301,
        "Paracetamol",
        100,
        2.50,
        "12/2027"
    };

    Medicine m2 = {
        302,
        "Amoxicillin",
        50,
        8.00,
        "08/2027"
    };

    patients.push_back(p1);
    patients.push_back(p2);

    doctors.push_back(d1);
    doctors.push_back(d2);

    medicines.push_back(m1);
    medicines.push_back(m2);

    cout << "\nSample data loaded successfully.\n";
}

// ============================================================
// MAIN MENU
// ============================================================

void displayMainMenu()
{
    cout << "\n";
    cout << "============================================\n";
    cout << "       HOSPITAL MANAGEMENT SYSTEM\n";
    cout << "============================================\n";
    cout << "1. Patient Management\n";
    cout << "2. Doctor Management\n";
    cout << "3. Appointment Management\n";
    cout << "4. Medical Records\n";
    cout << "5. Pharmacy Management\n";
    cout << "6. Billing\n";
    cout << "7. Load Sample Data\n";
    cout << "0. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    int choice;

    cout << "\n";
    cout << "********************************************\n";
    cout << "*                                          *\n";
    cout << "*     HOSPITAL MANAGEMENT SYSTEM            *\n";
    cout << "*     Linux & C++ Project                  *\n";
    cout << "*                                          *\n";
    cout << "********************************************\n";

    do
    {
        displayMainMenu();

        cin >> choice;

        switch (choice)
        {
            case 1:
                patientMenu();
                break;

            case 2:
                doctorMenu();
                break;

            case 3:
                appointmentMenu();
                break;

            case 4:
                medicalRecordMenu();
                break;

            case 5:
                pharmacyMenu();
                break;

            case 6:
                billingMenu();
                break;

            case 7:
                loadSampleData();
                break;

            case 0:
                cout << "\nThank you for using the Hospital Management System.\n";
                cout << "Exiting program...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}