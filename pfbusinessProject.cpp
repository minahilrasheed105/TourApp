#include <iostream>
#include <conio.h>

using namespace std;

// ===== Global Data =====
string adminId = "1001";
string adminPw  = "123";

string clientId[100]    = {"1", "2", "3"};
string clientPw[100]    = {"123", "123", "123"};
string clientName[100]  = {"Ahmad", "Ali", "Aliza"};
string clientEmail[100] = {"ahmad@example.com", "ali@example.com", "aliza@example.com"};
string clientPhone[100] = {"+923015600982", "+923896736432", "+923015890765"};
int t_clients = 3;

string tourId[100]      = {"1", "2"};
string tourTitle[100]   = {"North", "South"};
string tourPlace[100]   = {"Kalaam", "Hunza"};
string tourDate[100]    = {"12-07-2026", "19-07-2026"};
int tourT_capacity[100] = {12, 16};
int t_tours = 2;

string enid[10000]       = {"1", "2", "3"};
string enclientId[10000] = {"1", "1", "2"};
string entourId[10000]   = {"1", "2", "1"};
int t_enr = 3;

// ===== Function Declarations =====
void mainMenu();
void sortTours();
void deleteEnrollmentsByTour(string tourIdToDelete);
void adminLogin();

// admin side
void adminPanel();
void createTour();
void deleteTour();
void updateTour();
void viewTours();
void viewUsers();
void deleteUser();

// client side
void clientPanel();
void registerClient();
void clientLogin();
void loggedInMenu(string id, int cl_index);
void enrollTour(string id);
void cancelEnrollment(string id);
void viewMyEnrollments(string id);
void viewMyInfo(int cl_index);

// ===== MAIN =====
int main()
{
    sortTours();
    mainMenu();
    return 0;
}

// ===== MAIN MENU =====
void mainMenu()
{
    while(true)
    {
        system("cls");
        cout << "======================\n";
        cout << "    TOUR APP SYSTEM   \n";
        cout << "======================\n";
        cout << "1. Admin\n2. Client\n3. Exit\nEnter choice: ";
        int choice;
        cin >> choice; cin.ignore();

        if(choice == 1)      adminLogin();
        else if(choice == 2) clientPanel();
        else if(choice == 3) break;
        else  cout << "Wrong choice!\n\n";
    }
    cout << "Good Bye!";
}

// ===== ADMIN LOGIN =====
void adminLogin()
{
    string id, password;
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter the Admin ID: ";
        getline(cin, id);
        cout << "Enter the Admin password: ";
        getline(cin, password);

        if(id == adminId && password == adminPw)
        {
            cout << "\nLogin Successful!\n\n";
            adminPanel();
            return;
        }
        cout << "Wrong Password!\n";
    }
}

// ===== ADMIN PANEL =====
void adminPanel()
{
    while(true)
    {
        system("cls");
        cout << "====Admin Panel====\n";
        cout << "1. Create Tour\n2. Delete Tour\n3. Update Tour\n";
        cout << "4. View Tours\n5. View All Users\n6. Delete a User\n7. Logout\n\n";
        cout << "Enter your choice: ";
        int adChoice;
        cin >> adChoice; cin.ignore();

        if(adChoice == 1)      createTour();
        else if(adChoice == 2) deleteTour();
        else if(adChoice == 3) updateTour();
        else if(adChoice == 4) viewTours();
        else if(adChoice == 5) viewUsers();
        else if(adChoice == 6) deleteUser();
        else if(adChoice == 7) break;
        else  cout << "\nWrong Choice!\n\n";
    }
}

// ===== SORT TOURS =====
void sortTours()
{
    for(int j = 0; j < t_tours; j++)
    {
        for(int k = j + 1; k < t_tours; k++)
        {
            if(tourPlace[j][0] > tourPlace[k][0])
            {
                swap(tourId[j],         tourId[k]);
                swap(tourTitle[j],      tourTitle[k]);
                swap(tourPlace[j],      tourPlace[k]);
                swap(tourDate[j],       tourDate[k]);
                swap(tourT_capacity[j], tourT_capacity[k]);
            }
        }
    }
}

// ===== DELETE ENROLLMENTS BY TOUR =====
void deleteEnrollmentsByTour(string tourIdToDelete)
{
    for(int j = 0; j < t_enr; j++)
    {
        if(entourId[j] == tourIdToDelete)
        {
            for(int k = j; k < t_enr - 1; k++)
            {
                enid[k]       = enid[k + 1];
                enclientId[k] = enclientId[k + 1];
                entourId[k]   = entourId[k + 1];
            }
            t_enr--;
            j--;
        }
    }
}

// ===== CREATE TOUR =====
void createTour()
{
    if(t_tours == 100) {
        cout << "The memory is full!"; 
        return;
        }

    string id_t;
    while(true)
    {
        cout << "Enter the tour ID: ";
        getline(cin, id_t);
        bool isFound = false;
        for(int i = 0; i < t_tours; i++)
            if(id_t == tourId[i]) { cout << "Tour ID Already Exist!\n\n"; isFound = true; break; }
        if(!isFound) break;
    }
    tourId[t_tours] = id_t;
    cout << "Enter the tour Title: ";    getline(cin, tourTitle[t_tours]);
    cout << "Enter the tour Place: ";    getline(cin, tourPlace[t_tours]);
    cout << "Enter the tour Capacity: "; cin >> tourT_capacity[t_tours]; cin.ignore();
    cout << "Enter the tour Date: ";     getline(cin, tourDate[t_tours]);
    t_tours++;
    sortTours();  // SORTING 
    cout << "Tour Added!\n\nPress any key...";
    getch();
}

// ===== DELETE TOUR =====
void deleteTour()
{
    if(t_tours == 0) { cout << "No Tours Existed!\n\n"; return; }

    cout << "Enter the tour ID to delete: ";
    string t_id; getline(cin, t_id);

    int index = -1;
    for(int i = 0; i < t_tours; i++)
        if(t_id == tourId[i]) { index = i; break; }

    if(index == -1) { cout << "Tour Not Found!\n\n"; getch(); return; }

    deleteEnrollmentsByTour(tourId[index]);
    cout << "Tour id: " << tourId[index] << " deleted along with its enrollments!\n\n";

    for(int i = index; i < t_tours - 1; i++)
    {
        tourId[i]         = tourId[i + 1];
        tourTitle[i]      = tourTitle[i + 1];
        tourPlace[i]      = tourPlace[i + 1];
        tourT_capacity[i] = tourT_capacity[i + 1];
        tourDate[i]       = tourDate[i + 1];
    }
    t_tours--;
    cout << "\nPress any key...";
    getch();
}

// ===== UPDATE TOUR =====
void updateTour()
{
    if(t_tours == 0) { cout << "No Tours Existed!\n\n"; getch(); return; }

    cout << "Enter the tour ID to update: ";
    string t_id; getline(cin, t_id);

    int index = -1;
    for(int i = 0; i < t_tours; i++)
        if(t_id == tourId[i]) { index = i; break; }

    if(index == -1) { cout << "Tour Not Found!\n\n"; getch(); return; }

    cout << "Enter the new tour Title: ";    getline(cin, tourTitle[index]);
    cout << "Enter the new tour Place: ";    getline(cin, tourPlace[index]);
    cout << "Enter the new tour Capacity: "; cin >> tourT_capacity[index]; cin.ignore();
    cout << "Enter the new tour Date: ";     getline(cin, tourDate[index]);
    sortTours();
    cout << "Tour updated successfully!\n\nPress any key...";
    getch();
}

// ===== VIEW TOURS =====
void viewTours()
{
    cout << "ID\tTitle\tPlace\tDate\tCapacity\tEnrolments\n\n";
    for(int i = 0; i < t_tours; i++)
    {
        int enr = 0;
        for(int j = 0; j < t_enr; j++)
            if(entourId[j] == tourId[i]) enr++;
        cout << tourId[i] << "\t" << tourTitle[i] << "\t" << tourPlace[i] << "\t"
             << tourDate[i] << "\t" << tourT_capacity[i] << "\t" << enr << endl;
    }
    cout << "\nPress any key to continue...";
    getch();
}

// ===== VIEW USERS =====
void viewUsers()
{
    cout << "ID\tName\tEmail\tPhone\tEnrolments\n\n";
    for(int i = 0; i < t_clients; i++)
    {
        int enr = 0;
        for(int j = 0; j < t_enr; j++)
            if(enclientId[j] == clientId[i]) enr++;
        cout << clientId[i] << "\t" << clientName[i] << "\t" << clientEmail[i] << "\t"
             << clientPhone[i] << "\t" << enr << endl;
    }
    cout << "\nPress any key to continue...";
    getch();
}

// ===== DELETE USER =====
void deleteUser()
{
    if(t_clients == 0) { cout << "No Clients Existed!\n\n"; getch(); return; }

    cout << "Enter the Client ID to delete: ";
    string c_id; getline(cin, c_id);

    int index = -1;
    for(int i = 0; i < t_clients; i++)
        if(c_id == clientId[i]) { index = i; break; }

    if(index == -1) { cout << "Client Not Found!\n\n"; getch(); return; }

    int enr_count = 0;
    for(int j = 0; j < t_enr; j++)
    {
        if(enclientId[j] == clientId[index])
        {
            for(int k = j; k < t_enr - 1; k++)
            {
                enid[k]       = enid[k + 1];
                enclientId[k] = enclientId[k + 1];
                entourId[k]   = entourId[k + 1];
            }
            t_enr--;
            j--;
            enr_count++;
        }
    }
    cout << "Client id: " << clientId[index] << " deleted! " << enr_count << " enrolments also deleted!\n\n";

    for(int i = index; i < t_clients - 1; i++)
    {
        clientId[i]    = clientId[i + 1];
        clientName[i]  = clientName[i + 1];
        clientEmail[i] = clientEmail[i + 1];
        clientPhone[i] = clientPhone[i + 1];
        clientPw[i]    = clientPw[i + 1];
    }
    t_clients--;
    cout << "\nPress any key to continue...";
    getch();
}

// ===== CLIENT PANEL =====
void clientPanel()
{
    while(true)
    {
        system("cls");
        cout << "====Client Panel====\n";
        cout << "1. Register\n2. Login\n3. Exit\nEnter Your Choice: ";
        int choice;
        cin >> choice; cin.ignore();

        if(choice == 1)      registerClient();
        else if(choice == 2) clientLogin();
        else if(choice == 3) break;
        else                 cout << "Wrong Choice!\n\n";
    }
}

// ===== REGISTER CLIENT =====
void registerClient()
{
    if(t_clients == 100) { cout << "The memory is full!"; return; }

    string id_c;
    while(true)
    {
        cout << "Enter your Client ID: ";
        getline(cin, id_c);
        bool isFound = false;
        for(int n = 0; n < t_clients; n++)
            if(id_c == clientId[n]) { cout << "Client ID Already Exist!\n\n"; isFound = true; break; }
        if(!isFound) break;
    }
    clientId[t_clients] = id_c;
    cout << "Enter your name: ";      getline(cin, clientName[t_clients]);
    cout << "Enter your email: ";     getline(cin, clientEmail[t_clients]);
    cout << "Enter your phone no.: "; getline(cin, clientPhone[t_clients]);
    cout << "Enter Password: ";       getline(cin, clientPw[t_clients]);
    t_clients++;
    cout << "Registered Successfully!\n\nPress any key...";
    getch();
}

// ===== CLIENT LOGIN =====
void clientLogin()
{
    string id, password;
    bool loggedIn = false;
    for(int i = 0; i < 3 && !loggedIn; i++)
    {
        cout << "Enter the User ID: ";       getline(cin, id);
        cout << "Enter the User password: "; getline(cin, password);

        int cl_index = -1;
        for(int j = 0; j < t_clients; j++)
            if(id == clientId[j] && password == clientPw[j]) { cl_index = j; break; }

        if(cl_index != -1)
        {
            loggedIn = true;
            cout << "\nLogin Successful!\n\n";
            loggedInMenu(id, cl_index);
        }
        else
        {
            cout << "Wrong Password!\n\n";
        }
    }
}

// ===== LOGGED-IN CLIENT MENU =====
void loggedInMenu(string id, int cl_index)
{
    while(true)
    {
        cout << "1. View All tours\n2. Enrol Into Tour\n3. Cancel Enrolment\n";
        cout << "4. View your all enrolments\n5. Your Information\n6. Exit\n";
        cout << "Enter Your Choice: ";
        int c_choice;
        cin >> c_choice; cin.ignore();

        if(c_choice == 1)      viewTours();
        else if(c_choice == 2) enrollTour(id);
        else if(c_choice == 3) cancelEnrollment(id);
        else if(c_choice == 4) viewMyEnrollments(id);
        else if(c_choice == 5) viewMyInfo(cl_index);
        else if(c_choice == 6) break;
        else   cout << "Wrong Choice!\n\n";
    }
}

// ===== ENROL INTO TOUR =====
void enrollTour(string id)
{
    cout << "Enter the Tour ID: ";
    string t_id; getline(cin, t_id);

    int t_cap = 0;
    bool tourFound = false;
    for(int k = 0; k < t_tours; k++)
        if(t_id == tourId[k]) { t_cap = tourT_capacity[k]; tourFound = true; break; }

    if(!tourFound) { cout << "Tour Not Found!\n\n"; return; }

    int count_b_s = 0;
    for(int n = 0; n < t_enr; n++)
        if(entourId[n] == t_id) count_b_s++;

    if(t_cap <= count_b_s) { cout << "No More Slots Available for that tour!\n\n"; return; }

    for(int k = 0; k < t_enr; k++)
        if(id == enclientId[k] && t_id == entourId[k])
            { cout << "You are Already Enrolled to that event!\n\n"; return; }

    string en_id;
    while(true)
    {
        cout << "Enter the Enrollment ID: ";
        getline(cin, en_id);
        bool idTaken = false;
        for(int k = 0; k < t_enr; k++)
            if(enid[k] == en_id) { idTaken = true; break; }
        if(!idTaken) break;
        cout << "Please Choose a different ID, this id is already taken!\n\n";
    }

    enid[t_enr]       = en_id;
    enclientId[t_enr] = id;
    entourId[t_enr]   = t_id;
    t_enr++;
    cout << "You are Successfully Enrolled For the Tour!\n\n";
}

// ===== CANCEL ENROLLMENT =====
void cancelEnrollment(string id)
{
    cout << "Enter the Enrollment ID: ";
    string e_id; getline(cin, e_id);

    int enr_index = -1;
    for(int k = 0; k < t_enr; k++)
        if(id == enclientId[k] && e_id == enid[k]) { enr_index = k; break; }

    if(enr_index == -1) { cout << "Enrollment Not Found!\n\n"; return; }

    for(int k = enr_index; k < t_enr - 1; k++)
    {
        enid[k]       = enid[k + 1];
        enclientId[k] = enclientId[k + 1];
        entourId[k]   = entourId[k + 1];
    }
    t_enr--;
    cout << "Enrollment Cancelled Successfully!\n\n";
}

// ===== VIEW MY ENROLLMENTS =====
void viewMyEnrollments(string id)
{
    cout << "id\ttour\n\n";                                    
    for(int k = 0; k < t_enr; k++)
        if(id == enclientId[k]) cout << enid[k] << "\t" << entourId[k] << endl;
    cout << "\nPress any key...";
    getch();
}

// ===== VIEW MY INFO =====
void viewMyInfo(int cl_index)
{
    cout << "Name: "  << clientName[cl_index]  << endl;
    cout << "Email: " << clientEmail[cl_index] << endl;
    cout << "Phone: " << clientPhone[cl_index] << endl << endl;
    cout << "\nPress any key...";
    getch();
}