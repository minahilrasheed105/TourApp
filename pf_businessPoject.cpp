#include <iostream>
#include <conio.h>

using namespace std;
// two users 1. Admin 2. User/Client

// Function Declaration
	void mainMenu();
	void sortTours(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int t_tours);
    void deleteEnrollmentsByTour(string enid[], string enclientId[], string entourId[], int &t_enr, string tourIdToDelete);
	void adminLogin(string adminId, string adminPw, string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr, string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients);
	void adminPanel(string adminId, string adminPw, string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr, string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients);
    void createTour(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours);
	void deleteTour(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr);
	void updateTour(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int t_tours);
	void viewTours(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int t_tours, string entourId[], int t_enr);
	void viewUsers(string clientId[], string clientName[], string clientEmail[], string clientPhone[], int t_clients, string enclientId[], int t_enr);
	void deleteUser(string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients, string enid[], string enclientId[], string entourId[], int &t_enr);
	void clientPanel(string clientId[], string clientName[], string clientEmail[],string clientPhone[], string clientPw[], int &t_clients, string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int t_tours, string enid[], string enclientId[], string entourId[], int &t_enr);

main()
{
    // Admin 
    string adminId = "1001";
    string adminPw = "123";
   
    // Array Clients data: id, name, email, phone, password
    string clientId[100] = {"1", "2", "3"};
    string clientPw[100] = {"123", "123", "123"};
    string clientName[100] = {"Ahmad", "Ali", "Aliza"};
    string clientEmail[100] = {"ahmad@example.com", "ali@example.com", "aliza@example.com"};
    string clientPhone[100] = {"+923015600982", "+923896736432", "+923015890765"};
    int t_clients=3;

    // Tour Data : id, title, place, total capacity
    string tourId[100] = {"1", "2"};
    string tourTitle[100] = {"North", "South"};
    string tourPlace[100] = {"Kalaam", "Hunza"};
    int tourT_capacity[100] = {12, 16};
    string tourDate[100] = {"12-07-2026", "19-07-2026"};
    int t_tours=2;
 
    // enrollments data: id, client id, tour id
    string enid[10000] = {"1", "2", "3"};
    string enclientId[10000] = {"1", "1", "2"};
    string entourId[10000] = {"1", "2", "1"};
    int t_enr=3;

	// Sorting
    sortTours(tourId, tourTitle, tourPlace, tourDate, tourT_capacity, t_tours);
     
    mainMenu();
	return 0;
}

// ==== MAIN MENU ====
void mainMenu()
{
    cout << "======================\n";
    cout << "    TOUR APP SYSTEM   \n";
    cout << "======================\n";

    cout << "1. Admin\n2. Exit\nEnter choice: ";
    int choice;
    cin >> choice;
}	
		// ==== Admin login ====
    	void adminLogin(string adminId, string adminPw, string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr, string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients)
        if(choice==1)
        {
            string id, password;
            for(int i=0;i<3;i++)
            {
                cout << "Enter the Admin ID: ";
			    cin >> id;
                cout << "Enter the Admin password: "; 
				cin >> password;

                if(id==adminId && password==adminPw)
                { 
                    cout << "\nLogin Successful!\n\n";
					adminPanel(adminId, adminPw, tourId[], tourTitle[], tourPlace[], tourDate[], tourT_capacity[], &t_tours, enid[], enclientId[], entourId[], &t_enr, clientId[], clientName[], clientEmail[], clientPhone[], clientPw[], &t_clients);
					return;
				}
				 else
				{
					cout << "Wrong Password!\n";
				}
			}
		}
	     // ================= ADMIN PANEL =================
        void adminPanel(string adminId, string adminPw, string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr, string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients)
				{		
                    while(true)
                    { 
						system("cls");
						cout<<"====Admin Panel====\n";
                        // crud for tours
                        cout << "1. Create Tour\n";
                        cout << "2. Delete Tour\n";
                        cout << "3. Update Tour\n";
                        cout << "4. View Tours\n";
                        cout << "5. View All Users\n";
                        cout << "6. Delete a User\n";
                        cout << "7. Logout\n\n";
                        cout << "Enter your choice: ";

						int adChoice;
                        cin >> adChoice;

                        if(adChoice==1)
                        {
                            createTour(tourId, tourTitle, tourPlace, tourDate, tourT_capacity, t_tours);
						}
										                      
                        else if(adChoice==2)
                        {
							deleteTour(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours, string enid[], string enclientId[], string entourId[], int &t_enr);
                        	
						}
                    
                        else if(adChoice==3)
                        {
							updateTour(string tourId[], string tourTitle[], string tourPlace[],string tourDate[], int tourT_capacity[], int t_tours);                   
                            
                        }
                        else if(adChoice==4)
                        {
							viewTours(string tourId[], string tourTitle[], string tourPlace[],  string tourDate[], int tourT_capacity[], int t_tours, string entourId[], int t_enr);                      	
                        }
                        else if(adChoice==5)						 
					    {
                            viewUsers(string clientId[], string clientName[], string clientEmail[],string clientPhone[], int t_clients,string enclientId[], int t_enr);
					    }			
                        else if(adChoice==6)
						{
							void deleteUser(string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients, string enid[], string enclientId[], string entourId[], int &t_enr);
						}
						else if(adChoice == 7)
                        {
                            break;
                        }
                        else
                        {
                            cout << "\nWrong Choice!\n\n";
                        }
                    }
				
                }
                else 
                {
                	cout << "Wrong Password!\n\n";
				}
void sortTours(string tourId[], string tourTitle[], string tourPlace[],
               string tourDate[], int tourT_capacity[], int t_tours)
{
    for(int j = 0; j < t_tours; j++)
    {
        for(int k = j + 1; k < t_tours; k++)
        {
            if(tourPlace[j][0] > tourPlace[k][0])
            {
                swap(tourId[j], tourId[k]);
                swap(tourTitle[j], tourTitle[k]);
                swap(tourPlace[j], tourPlace[k]);
                swap(tourDate[j], tourDate[k]);
                swap(tourT_capacity[j], tourT_capacity[k]);
            }
        }
    }
}

void deleteEnrollmentsByTour(string enid[], string enclientId[], string entourId[], int &t_enr, string tourIdToDelete)
{
    for(int j = 0; j < t_enr; j++)
    {
        if(entourId[j] == tourIdToDelete)
        {
            for(int k = j; k < t_enr - 1; k++)
            {
                enid[k] = enid[k + 1];
                enclientId[k] = enclientId[k + 1];
                entourId[k] = entourId[k + 1];
            }
            t_enr--;
            j--; // important: recheck same index
        }
    }
}

void createTour(string tourId[], string tourTitle[], string tourPlace[],string tourDate[], int tourT_capacity[], int &t_tours)
{
	if(t_tours==100)
        {
          cout << "The memory is full!";
         return;
        }
		//getting tour data
		string id_t;
		while(true)
		{
			cout << "Enter the tour ID: ";
			cin >> id_t;

			bool isFound = false;

			for(int i=0;i<t_tours;i++)
			{
				if(id_t==tourId[i])
				{
					cout << "Tour ID Already Exist!\n\n";
					isFound = true;
					break;
				}
			}
			if(!isFound)
			{
				break;
			}
		}
		tourId[t_tours] = id_t;

		cout << "Enter the tour Title: ";
		cin >> tourTitle[t_tours];
		cout << "Enter the tour Place: ";
		cin >> tourPlace[t_tours];
		cout << "Enter the tour Capacity: ";
		cin >> tourT_capacity[t_tours];
		cout << "Enter the tour Date: ";
		cin >> tourDate[t_tours];
		t_tours++;

		// SORT
		sortTours(tourId, tourTitle, tourPlace, tourDate, tourT_capacity, t_tours);

		cout<<"Tour Added!\n";

		 cout << "\nPress any key...";
         getch();
	}
	void deleteTour(string tourId[], string tourTitle[], string tourPlace[], string tourDate[], int tourT_capacity[], int &t_tours,string enid[], string enclientId[], string entourId[], int &t_enr)
{
		// delete a tour!
		if(t_tours==0)
		{
			cout << "No Tours Existed!\n\n";
			return;
		}
		cout << "Enter the tour ID to delete: ";
		string t_id;
		cin >> t_id;
		int index=-1;
		for(int i=0;i<t_tours;i++)
		{
			if(t_id==tourId[i])
			{
				index = i;
				break;
			}
		}
		if(index==-1)
		{
			cout << "Tour Not Found!\n\n";
			getch();
	    	return;
		}
		else
		{	
			// deleting enrollments related to the tour
			deleteEnrollmentsByTour(enid, enclientId, entourId, t_enr, tourId[index]);
		
			cout << "Tour id: " << tourId[index] << " has been deleted along with its enrollments!\n\n";
			 
			// shift arrays
			for(int i=index;i<t_tours;i++)
			{
			tourId[i] = tourId[i+1];
			tourTitle[i] = tourTitle[i+1];
			tourPlace[i] = tourPlace[i+1];
			tourT_capacity[i] = tourT_capacity[i+1];
			tourDate[i] = tourDate[i+1];	
			}
			t_tours--;	
		}
		 cout << "\nPress any key...";
         getch();
}
void updateTour(string tourId[], string tourTitle[], string tourPlace[],string tourDate[], int tourT_capacity[], int t_tours)
{
	// updating a tour
	if(t_tours==0)
	{
		cout << "No Tours Existed!\n\n";
		getch();
		return;
	}
	cout << "Enter the tour ID to update: ";
	string t_id; 
	cin >> t_id;

	int index=-1;
	for(int i=0;i<t_tours;i++)
	{
		if(t_id==tourId[i])
		{
			index = i;
			break;
		}
	}
	if(index==-1)
	{
		cout << "Tour Not Found!\n\n";
		getch();
		return;
	}
	else
	{
		cout << "Enter the new tour Title: ";
		cin >> tourTitle[index];
		cout << "Enter the new tour Place: ";
		cin >> tourPlace[index];
		cout << "Enter the new tour Capacity: ";
		cin >> tourT_capacity[index];
		cout << "Enter the new tour Date: ";
		cin >> tourDate[index];
		cout << "the tour was updated successfully!\n\n";
		
		// re-sorting tour after update
		sortTours(tourId, tourTitle, tourPlace, tourDate, tourT_capacity, t_tours);
		
		cout<<"\nPress any key...";
		getch();
    }
}
void viewTours(string tourId[], string tourTitle[], string tourPlace[],  string tourDate[], int tourT_capacity[], int t_tours, string entourId[], int t_enr)
	// view all tours
	cout << "ID\tTitle\tPlace\tDate\tCpacity\tEnrolments\n\n";
	for(int i=0;i<t_tours;i++)
	{	
		// total enrolments in 1 tour
		int enr = 0;
		for(int j=0;j<t_enr;j++)
		{
			if(entourId[j]==tourId[i])
			{
				enr++;
			}
		}
		
		cout << tourId[i] << "\t" << tourTitle[i] << "\t" << tourPlace[i] << "\t" << tourDate[i] << "\t" << tourT_capacity[i] << "\t" << enr << endl;
	}
		cout << "\nPress any key to continue...";
		getch();
}
           
void viewUsers(string clientId[], string clientName[], string clientEmail[],string clientPhone[], int t_clients,string enclientId[], int t_enr)
{
	// view all clients
	cout << "ID\tName\tEmail\tPhone\tEntrollments\n\n";
	for(int i=0;i<t_clients;i++)
	{
		// total enrolments in tours by client 
		int enr = 0;
		for(int j=0;j<t_enr;j++)
		{
			if(enclientId[j]==clientId[i])
			{
				enr++;
			}
		}
		cout << clientId[i] << "\t" << clientName[i] << "\t" << clientEmail[i] << "\t" << clientPhone[i] << "\t" << enr << endl;
	}  

		cout << "\nPress any key to continue...";
		getch();
}	
void deleteUser(string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients, string enid[], string enclientId[], string entourId[], int &t_enr) 
{
	if(t_clients==0)
	{
		cout << "No Clients Existed!\n\n";
		getch();
		return;
	}
	cout << "Enter the Cleint ID to delete: ";
	string c_id;
    cin >> c_id;

	int index=-1;
	for(int i=0;i<t_clients;i++)
	{
		if(c_id==clientId[i])
		{
			index = i;
			break;
		}
	}
	if(index==-1)
	{
		cout << "Client Not Found!\n\n";
	    getch();
		return;
	}
	else
	{
		for(int j = 0; j < t_enr; j++)
    {
    if(enclientId[j] == clientId[index])
    {
        for(int k = j; k < t_enr - 1; k++)
        {
            enid[k] = enid[k+1];
            enclientId[k] = enclientId[k+1];
            entourId[k] = entourId[k+1];
        }

        t_enr--;
        j--;  // very important
    }
    }
		
		cout << "Client id: " << clientId[index] << " has been deleted! and " << index_count << " enrolments are also deleted!" << "\n\n";

		//deleting user
		for(int i=index;i<t_clients - 1;i++)
		{
			clientId[i] = clientId[i+1];
			clientName[i] = clientName[i+1];
			clientEmail[i] = clientEmail[i+1];
			clientPhone[i] = clientPhone[i+1];
			clientPw[i] = clientPw[i+1];	
		}
		t_clients--;	
	}
	cout << "\nPress any key to continue...";
	cout<<"Press any key...";
	getch();
}	

       else if (choice==2)
        { 
			void clientPanel(string clientId[], string clientName[], string clientEmail[], string clientPhone[], string clientPw[], int &t_clients,string tourId[], string tourTitle[], string tourPlace[],  string tourDate[], int tourT_capacity[], int t_tours, string enid[], string enclientId[], string entourId[], int &t_enr)
			{
            //user operations
            while(true)
            {
				system("cls");

				cout<<"====Client Panel====\n";
                cout << "1. Register\n2. Login\n3. Exit\nEnter Your Choice: ";
                int choice_user;
                cin >> choice_user;

				//====Register====
                if(choice_user==1)
                {
                    if(t_clients==100)
                    {
                        cout << "The memory is full!";
                        return;
                    }
                    //getting tour data
                    string id_c;
                    while(true)
                    {
                        cout << "Enter the tour ID: ";
                        cin >> id_c;
						bool isFound = false;
                        for(int n=0;n<t_clients;n++)
                        {
                            if(id_c==clientId[n])
                            {
                                cout << "Client ID Already Exist!\n\n";
                                isFound = true;
                                break;
                            }
                        }
                        if(!isFound)
                        {
                            break;
                        }
                    }
                    clientId[t_clients] = id_c;
                    cout << "Enter your name: ";
                    cin >> clientName[t_clients];
                    cout << "Enter your email: ";
                    cin >> clientEmail[t_clients];
                    cout << "Enter your phone no.: ";
                    cin >> clientPhone[t_clients];
                    cout << "Enter Password: ";
                    cin >> clientPw[t_clients];
                    t_clients++;
                }

				//===Login===
                else if(choice_user==2)
                {
                    string id, password;
					
                    for(int i=0;i<3;i++)
                    {
                        cout << "Enter the User ID: "; cin >> id;
                        cout << "Enter the User password: "; cin >> password;
                        int cl_index;
                        for(int j=0;j<t_clients;j++)
                        {
                            if(id==clientId[j] && password==clientPw[j])
                            { 
                            	cl_index = j; // using for tracing logged in users
                                i=3; // user can logout for main menu
                                // User Logged IN
                                cout << "\nLogin Successful!\n\n";
                                while(true)
                                {
                                    cout << "1. View All tours\n"; // copy code from admin side
                                    cout << "2. Enrol Into Tour\n"; // user can enrol 1 time in 1 tour
                                    cout << "3. Cancel Enrolment\n";
                                    cout << "4. View your all enrolments\n";
                                    cout << "5. Your Information\n";//just show te logged in user info
                                    cout << "6. Exit\n"; 
                                    cout << "Enter Your Choice: ";
                                    int c_choice;
                                    cin >> c_choice;

                                    if(c_choice == 1)
                                    {
                                        // view all tours
                                        cout << "ID\tTitle\tPlace\tDate\tCpacity\tEnrolments\n\n";
                                        for(int i=0;i<t_tours;i++)
                                        {	
                                            // total enrolments in 1 tour
                                            int enr = 0;
                                            for(int j=0;j<t_enr;j++)
                                            {
                                                if(entourId[j]==tourId[i])
                                                {
                                                    enr++;
                                                }
                                            }
                                            
                                            cout << tourId[i] << "\t" << tourTitle[i] << "\t" << tourPlace[i] << "\t" << tourDate[i] << "\t" << tourT_capacity[i] << "\t" << enr << endl;
                                        }
                                    }

                                    else if(c_choice==2)
                                    {
                                        string t_id;
                                        int t_cap;
                                        cout << "Enter the Tour ID: ";
                                        cin >> t_id;
                                        // check if tour exists
                                        for(int k=0;k<t_tours;k++)
                                        {
                                        	if(t_id==tourId[k])
                                        	{
                                        		t_cap = tourT_capacity[k];
                                        		break;
											}
											if(k==t_tours-1)
											{
												t_id="-65";	
											}
										}
										if(t_id=="-65")
										{
											cout << "Tour Not Found!\n";
											continue;
										}
										
										// checking availible slots
                                		int count_b_s = 0;
                                		for(int n=0;n<t_enr;n++)
                                		{
                                			if(entourId[n]==t_id)
                                			{
                                				count_b_s++;
											}
										}
										if(t_cap <= count_b_s)
										{
											cout << "No More Slots Availible for that tour!" << endl << endl;
											continue;
										}
										
										// check if the user already enrolled
										for(int k=0;k<t_enr;k++)
										{
											if(id==enclientId[k] && t_id==entourId[k])
											{
												cout << "You are Already Enrolled to that event!\n\n";
												t_id = "-65";
												break;
											}
										}
										if(t_id=="-65")
										{
											continue;
										}
										
										// add the enrolment
										string en_id;
										while(true)
										{
											cout << "Enter the Enrollment ID: ";
											cin >> en_id;
											// check if the id already their
											for(int k=0;k<t_enr;k++)
											{
												if(enid[k]==en_id)
												{
													en_id="-65";
													break;
												}	
											}
											if(en_id!="-65")
											{
												break;
											}
											cout << "Please Choose a different ID this id already taken!\n\n";
										}
										
										enid[t_enr] = en_id;
										enclientId[t_enr] = id;
										entourId[t_enr] = t_id;
										t_enr++;
										cout << "You are Successfully Enrolled For the Tour!\n\n";
                                    }

                                	else if(c_choice==3)
                                	{
                                		cout << "Enter the Enrollment ID: ";
                                		string e_id; cin >> e_id;
                                		int index=-1;
                                		for(int k=0;k<t_enr;k++)
                                		{
                                			// finding enrollment that is owned by user
                                			if(id==enclientId[k] && e_id==enid[k])
                                			{
												index = k;	 
												break;                          				
											}
										}
										if(index==-1)
										{
											cout << "Enrollment Not Found!\n\n";
										}
										else
										{
											for(int k=index;k<t_enr;k++)
											{
												enid[k] = enid[k+1];
												enclientId[k] = enclientId[k+1];
												entourId[k] = entourId[k+1];
											}
											t_enr--;
											cout << "Enrollment Cancceled Successfully!\n\n";
										}
									}
									else if(c_choice==4)
                                	{
                                		cout << "id\ttour\n\n";
                                		for(int k=0;k<t_enr;k++)
                                		{
                                			if(id==enclientId[k])
                                			{
                                				cout << enid[k] << "\t" << entourId[k] << endl;
                                			}
										}
									}
									else if(c_choice==5)
                                	{
                                		cout << "Name: " << clientName[cl_index] << endl;
                                		cout << "Email: " << clientEmail[cl_index] << endl;
                                		cout << "Phone: " << clientPhone[cl_index] << endl << endl;
									}
									else if(c_choice==6)
                                	{
                                		break;
									}
									else
                                	{
                                		cout << "Wrong Choice!\n\n";
									}
								}
                                                                



                                //  user can enrol for events, user can see his enrollments, user can remove his enrolments, user can see his information

                            }
                            if(j==t_clients-1 && i!=3)
                            {
                            	id = "-65";
							}
                        }
                        if(id=="-65") 
                        {
                            cout << "Wrong Password!\n\n";
                        }
                    }
                    
                }
                else if(choice_user==3)
                {
                    break;
                }
                else
                {
                    cout << "Wrong Choice!\n\n";
                }
            }
                
        }
        else if(choice==3)
        {
            break;
        }
        else
        {
            cout << "wrong choice!\n\n";   
        }
    }
    cout << "Good Bye!";
}