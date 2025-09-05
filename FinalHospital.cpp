#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

	void setColor(int color) 
	{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
//=======================================================================================================//	
void displayHospitalIntroduction() {

    setColor(3);
    cout<<"\n\n\t\t\t\t\t===================================";
    setColor(7);
	cout << "\n\t\t\t\t\t";setColor(3);cout<<"=->#";setColor(7);cout<<" Welcome to Royal Hospital ";setColor(3);cout<<"#<-=";
	setColor(3);
	cout<<"\n\t\t\t\t\t===================================";
    setColor(7);
	cout << "\n\tAt Royal Hospital, we are dedicated to providing the highest quality healthcare services to our community.\n";
    cout << "\tOur team of experienced professionals is committed to ensuring the well-being of our patients.\n";
    cout << "\tWe offer a wide range of medical services, including:\n";
    cout << "\t->. General Medicine\n";
    cout << "\t->. Surgery\n";
    cout << "\t->. Pediatrics\n";
    cout << "\t->. Cardiology\n";
    cout << "\t->. Neurology\n";
    cout << "\t->. Dermatology\n";
    cout << "\t->. gastroenterology\n";
    cout << "\t->. hematology\n";
    cout << "\t->. medical oncology\n";
    cout << "\t->. Emergency Services\n";
    cout << "\tThank you for choosing Royal Hospital, where your health is our priority.\n";
    cout << "\t\t\t================================================================\n";
    cin.get();
    system("cls");
}
//=======================================================================================================//	
void displayDoctors() {
    cout << "\n\t\t\t\t--- Doctor List ---\n";
    cout << "\n\t\t\t\t1. Dr. Smith (Cardiologist)\n";
    cout << "\n\t\t\t\t2. Dr. Johnson (Neurologist)\n";
    cout << "\n\t\t\t\t3. Dr. Davis (Dermatologist)\n";
    cout << "\n\t\t\t\t4. Dr. Kim (Surgery)\n";
    cout << "\n\t\t\t\t5. Dr. Charles (gastroenterology)\n";
    cout << "\n\t\t\t\t6. Dr. Mike (hematology)\n";


    system("pause"); 
    system("cls");
    
}
//=======================================================================================================//	
class Patient {
public:
    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;

    void inputPatientData() {
        cout << "\n\t\t\t\t->Enter patient's name: ";
        cin.ignore();  
        getline(cin, name);
        cout << "\n\t\t\t\t->Enter patient's age: ";
        cin >> age;
        cout << "\n\t\t\t\t->Enter patient's illness: ";
        cin.ignore();  
        getline(cin, illness);

        int doctorChoice;
        cout << "\n\t\t\t\t->Choose a doctor from the list below:\n";
        displayDoctors();  
        cout << "\n\t\t\t\t->Enter the number of the doctor you want to appoint: ";
        cin >> doctorChoice;

        switch (doctorChoice) {
            case 1:
                doctor = "->Dr. Smith (Cardiologist)";
                break;
            case 2:
                doctor = "->Dr. Johnson (Neurologist)";
                break;
            case 3:
                doctor = "->Dr. Davis (Dermatologist)";
                break;
            case 4:
                doctor = "->Dr. Kim (Surgery)";
                break;
            case 5:
                doctor = "->Dr. Charles (gastroenterology)";
                break;
            case 6:
                doctor = "->Dr. Mike (hematology)";
                break;
            default:
                cout << "->Invalid choice! Defaulting to 'Dr. Smith'.\n";
                doctor = "->Dr. Smith (Cardiologist)";
        }
		
		cout << "\t\t\t\t->Enter treatment cost: ";
        cin >> treatmentCost;        
    }
    //=======================================================================================================//	
    void displayPatientData() 
	{
        cout << left << setw(20) << "\t\t\t\t->Name: " << name << endl;
        cout << left << setw(20) << "\t\t\t\t->Age: " << age << endl;
        cout << left << setw(20) << "\t\t\t\t->Illness: " << illness << endl;
        cout << left << setw(20) << "\t\t\t\t->Doctor: " << doctor << endl;
        cout << left << setw(20) << "\t\t\t\t->Treatment Cost: $" << fixed << setprecision(2) << treatmentCost << endl;
    }
    //=======================================================================================================//	
};

void addPatient() {
    Patient patient;
    patient.inputPatientData();

    ofstream file("patients.txt", ios::app); 
    if (!file) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    file << patient.name << "\n" << patient.age << "\n" 
         << patient.illness << "\n" << patient.doctor << "\n" 
         << patient.treatmentCost << endl;
    file.close();

    cout << "\t\t\t\t->Patient data added successfully!\n";
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void displayPatients() {
    ifstream file("patients.txt");
    if (!file) {
        cerr << "\t\t\t\t->Error opening file for reading.\n";
        return;
    }

    cout << "\n\t\t\t\t --- Patient Data ---\n";
    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;

    while (getline(file, name)) {
        file >> age;
        file.ignore();  
        getline(file, illness);
        getline(file, doctor);
        file >> treatmentCost;
        file.ignore();  

        cout << "\n\t\t\t\t->=======Patient data====================" << endl;
        cout << "\t\t\t\t->Name: " << name << endl;
        cout << "\t\t\t\t->Age: " << age << endl; 
        cout << "\t\t\t\t->Illness: " << illness << endl; 
        cout << "\t\t\t\t->Doctor: " << doctor << endl; 
        cout << "\t\t\t\t->Treatment Cost: $" << fixed << setprecision(2) << treatmentCost << endl;
    }
    file.close();
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void deletePatientData() {
    string nameToDelete;
    cout << "\n\n\t\t\t\t->Enter the patient's name to delete: ";
    cin.ignore();  
    getline(cin, nameToDelete);

    ifstream file("patients.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file.\n";
        return;
    }

    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;
    bool found = false;

    while (getline(file, name)) {
        file >> age;
        file.ignore(); 
        getline(file, illness);
        getline(file, doctor);
        file >> treatmentCost;
        file.ignore();  

        if (name != nameToDelete) {
            tempFile << name << "\n" << age << "\n" 
                     << illness << "\n" << doctor << "\n" 
                     << treatmentCost << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found) {
        cout << "\n\t\t\t\tPatient data deleted successfully.\n";
    } else {
        cout << "\n\t\t\t\tPatient not found.\n";
    }
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void searchPatient() {
    string nameToSearch;
    cout << "\n\n\t\t\t\t->Enter the patient's name to search: ";
    cin.ignore(); 
    getline(cin, nameToSearch);

    ifstream file("patients.txt");
    if (!file) {
        cerr << "Error opening file for reading.\n";
        return;
    }

    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;
    bool found = false;

    while (getline(file, name)) {
        file >> age;
        file.ignore(); 
        getline(file, illness);
        getline(file, doctor);
        file >> treatmentCost;
        file.ignore();  

        if (name == nameToSearch) {
            cout << "\n\t\t\t\t--- Patient Found ---\n";
            cout << "\n\t\t\t\t->=======Patient data====================" << endl;
        cout << "\t\t\t\t->Name: " << name << endl;
        cout << "\t\t\t\t->Age: " << age << endl; 
        cout << "\t\t\t\t->Illness: " << illness << endl; 
        cout << "\t\t\t\t->Doctor: " << doctor << endl; 
        cout << "\t\t\t\t->Treatment Cost: $" << fixed << setprecision(2) << treatmentCost << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\t\t\t\t->Patient not found.\n";
    }

    file.close();
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void updatePatientData() {
    string nameToUpdate;
    cout << "\n\n\t\t\t\t->Enter the patient's name to update: ";
    cin.ignore();
    getline(cin, nameToUpdate);

    ifstream file("patients.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file.\n";
        return;
    }

    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;
    bool found = false;

    while (getline(file, name)) {
        file >> age;
        file.ignore();
        getline(file, illness);
        getline(file, doctor);
        file >> treatmentCost;
        file.ignore();

        if (name == nameToUpdate) {
            found = true;
            cout << "\n\t\t\t\t->Updating data for " << name << ":\n";
            cout << "\n\t\t\t\t->Enter new age: ";
            cin >> age;
            cin.ignore(); // Clear newline character
            cout << "\n\t\t\t\t->Enter new illness: ";
            getline(cin, illness);
            cout << "\n\t\t\t\t->Choose a new doctor from the list below:\n";
            displayDoctors();
            int doctorChoice;
            cout << "\n\t\t\t\t->Enter the number of the new doctor: ";
            cin >> doctorChoice;
            cin.ignore(); // Clear newline character

            switch (doctorChoice) {
                case 1:
                    doctor = "Dr. Smith (Cardiologist)";
                    break;
                case 2:
                    doctor = "Dr. Johnson (Neurologist)";
                    break;
                case 3:
                    doctor = "Dr. Davis (Dermatologist)";
                    break;
                default:
                    cout << "\n\t\t\t\t->Invalid choice! Keeping previous doctor.\n";
            }

            cout << "\n\t\t\t\t->Enter new treatment cost: ";
            cin >> treatmentCost;
            cin.ignore(); // Clear newline character
        }

        // Write each patient's data to temp file
        tempFile << name << "\n" << age << "\n" 
                 << illness << "\n" << doctor << "\n" 
                 << fixed << setprecision(2) << treatmentCost << endl;
    }

    file.close();
    tempFile.close();

    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found) {
        cout << "\n\t\t\t\tPatient data updated successfully.\n";
    } else {
        cout << "\n\t\t\t\tPatient not found.\n";
    }
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void generateReceipt(const string& patientName) {
    ifstream file("patients.txt");
    if (!file) {
        cerr << "Error opening patient file.\n";
        return;
    }

    string name;
    int age;
    string illness;
    string doctor;
    float treatmentCost;
    bool found = false;

    while (getline(file, name)) {
        file >> age;
        file.ignore();
        getline(file, illness);
        getline(file, doctor);
        file >> treatmentCost;
        file.ignore();

        if (name == patientName) 
		{
            found = true;
            cout << "\n\t\t\t\t============= Patient Receipt =============\n";
            cout << "\t\t\t\tName: " << name << endl;
            cout << "\t\t\t\tAge: " << age << endl;
            cout << "\t\t\t\tIllness: " << illness << endl;
            cout << "\t\t\t\tDoctor: " << doctor << endl;
            cout << "\t\t\t\tTreatment Cost: $" << fixed << setprecision(2) << treatmentCost << endl;
            cout << "\t\t\t\t===========================================\n";
            break;
        }
    }

    if (!found) 
	{
        cout << "Patient not found.\n";
    }

    file.close();
    system("pause"); 
    system("cls");
}
//=======================================================================================================//	
void printrcp(){
    string patientName;  
    cout << "\n\n\t\t\t\t->Enter patient name for receipt: ";
    cin.ignore();
    getline(cin, patientName);
    generateReceipt(patientName);             
    system("pause"); 
    system("cls");      
	}
//=======================================================================================================//	
int main() {
    int choice;
    displayHospitalIntroduction();
    do {
    	setColor(5);
        cout << "\n\t\t\t\t==========";setColor(6);cout<<" Hospital Management System ";setColor(5);cout<<"==========\n";
        setColor(7);cout << "\t\t\t\t1. Patient Appoint\n";
        setColor(7);cout << "\t\t\t\t2. Display Patient Data\n";
        setColor(7);cout << "\t\t\t\t3. Display Doctor List\n";
        setColor(7);cout << "\t\t\t\t4. Delete Patient Data\n";
        setColor(7);cout << "\t\t\t\t5. Search Patient\n";
        setColor(7);cout << "\t\t\t\t6. Update Patient Data\n";
        setColor(7);cout << "\t\t\t\t7. Generate Patient Receipt\n";
        setColor(4);cout << "\t\t\t\t8. Exit\n";
        setColor(7);cout << "\t\t\t\tEnter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
            	
                addPatient();
                
                
                break;
            case 2:
            
                displayPatients();
                
                break;
            case 3:
            
                displayDoctors();
                break;
            case 4:
            
                deletePatientData();
                break;
            case 5:
            
                searchPatient();
                break;
            case 6:
            
                updatePatientData();
                break;
            case 7: 
						
				printrcp();
				
            case 8:{ 
                cout << "Exiting...\n";
                break;
                	}
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}
