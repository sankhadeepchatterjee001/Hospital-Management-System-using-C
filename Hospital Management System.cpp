#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// PATIENT STRUCT
struct patient
{
 int id;
 char name[30];
 char disease[30];
 int age;
 char doctor[30];
 float bill;
}pat;

// DOCTOR STRUCT
struct doctor
{
 int did;
 char name[30];
 char specialization[30];
}doc;

// APPOINTMENT STRUCT
struct booking
{
 int pid;
 int did;
 char date[20];
}book;

// ADD PATIENT
void insertPatient()
{
 FILE *fp = fopen("PatientRecord", "a");
 printf("Enter Patient ID: "); scanf("%d", &pat.id);
 printf("Enter Name: "); scanf("%s", pat.name);
 printf("Enter Disease: "); scanf("%s", pat.disease);
 printf("Enter Age: "); scanf("%d", &pat.age);
 printf("Enter Doctor Name: "); scanf("%s", pat.doctor);
 printf("Enter Bill: "); scanf("%f", &pat.bill);
 fwrite(&pat, sizeof(pat), 1, fp);
 fclose(fp);
}

// DISPLAY PATIENT
void displayPatient()
{
 FILE *fp = fopen("PatientRecord", "r");
 printf("\nID\tName\tDisease\tAge\tDoctor\tBill\n");
 while (fread(&pat, sizeof(pat), 1, fp))
 printf("%d\t%s\t%s\t%d\t%s\t%.2f\n", pat.id, pat.name, pat.disease, pat.age, pat.doctor, pat.bill);
 fclose(fp);
}

// ADD DOCTOR
void addDoctor()
{
 FILE *fp = fopen("DoctorRecord", "a");
 printf("Enter Doctor ID: "); scanf("%d", &doc.did);
 printf("Enter Name: "); scanf("%s", doc.name);
 printf("Enter Specialization: "); scanf("%s", doc.specialization);
 fwrite(&doc, sizeof(doc), 1, fp);
 fclose(fp);
}

// DISPLAY DOCTOR
void displayDoctor()
{
 FILE *fp = fopen("DoctorRecord", "r");
 printf("\nDoctorID\tName\tSpecialization\n");
 while (fread(&doc, sizeof(doc), 1, fp))
 printf("%d\t%s\t%s\n", doc.did, doc.name, doc.specialization);
 fclose(fp);
}

// BOOK APPOINTMENT
void bookAppointment()
{
 FILE *fp = fopen("BookingRecord", "a");
 printf("Enter Patient ID: "); scanf("%d", &book.pid);
 printf("Enter Doctor ID: "); scanf("%d", &book.did);
 printf("Enter Date (dd-mm-yyyy): "); scanf("%s", book.date);
 fwrite(&book, sizeof(book), 1, fp);
 fclose(fp);
 printf("Appointment Booked Successfully!\n");
}

// DISPLAY BOOKINGS
void displayBooking()
{
 FILE *fp = fopen("BookingRecord", "r");
 printf("\nPatientID\tDoctorID\tDate\n");
 while (fread(&book, sizeof(book), 1, fp))
 printf("%d\t\t%d\t\t%s\n", book.pid, book.did, book.date);
 fclose(fp);
}

// MAIN FUNCTION
int main()
{
 int choice;
 do
 {
  printf("\n--- Hospital Management System ---\n");
  printf("1. Add Patient\n");
  printf("2. Display Patients\n");
  printf("3. Add Doctor\n");
  printf("4. Display Doctors\n");
  printf("5. Book Appointment\n");
  printf("6. Display Appointments\n");
  printf("7. Exit\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  switch(choice)
  {
   case 1: insertPatient(); break;
   case 2: displayPatient(); break;
   case 3: addDoctor(); break;
   case 4: displayDoctor(); break;
   case 5: bookAppointment(); break;
   case 6: displayBooking(); break;
   case 7: return 0;
   default: printf("Invalid choice!\n");
  }
 } while(choice != 7);
}

