#include <iostream>
#include <conio.h>

using namespace std;
// two users 1. Admin 2. User/Client

main()
{
    // Admin Data e.g: id, password, name, email, phone 
    string adminId = "1001";
    string adminPw = "123";
    string name = "Admin";
    string email = "admin@example.com";
    string phone = "+923074545321";
    
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
    
    // sorting tours by place : 3. camparison, swaping, repeat the cycle : Bubble Sort -> adjacent elements comparison and swap
    for(int j=0;j<t_tours;j++)
    {
    	for(int k=j;k<t_tours;k++)
    	{
    		if(tourPlace[j][0] > tourPlace[k][0])
    		{
    			string temp = tourId[j]; // a=3, b = 7  => a=7, b=3
    			tourId[j] = tourId[k];
    			tourId[k] = temp;
    			
    			temp = tourTitle[j];
    			tourTitle[j] = tourTitle[k];
    			tourTitle[k] = temp;
    			
    			temp = tourPlace[j];
    			tourPlace[j] = tourPlace[k];
    			tourPlace[k] = temp;
    			
    			temp = tourDate[j];
    			tourDate[j] = tourDate[k];
    			tourDate[k] = temp;
    			
    			int temp_ = tourT_capacity[j];
    			tourT_capacity[j] = tourT_capacity[k];
    			tourT_capacity[k] = temp_;
			}
		}
	}
    
    while(true)
    {
		system("cls");
		
		cout<<"======================\n";
		cout<<"    TOUR APP SYSTEM   \n";
		cout<<"======================\n";
        cout << "Hello, Welcome to Tour App!\nWhat is your role?\n1. Admin\n2. User\n3. Exit the System\nEnter you choice: ";
        int choice;
        cin >> choice;
        if(choice==1)
        {
            string id, password;
            for(int i=0;i<3;i++)
            {
                cout << "Enter the Admin ID: "; cin >> id;
                cout << "Enter the Admin password: "; cin >> password;
                if(id==adminId && password==adminPw)
                { 
                	i=3; // admin can logout for main menu
                    // Admin Logged IN
                    cout << "\nLogin Successful!\n\n";
                    int adChoice;
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
                        cin >> adChoice;
                        if(adChoice==1)
                        {
                            if(t_tours==100)
                            {
                                cout << "The memory is full!";
                                continue;
                            }
                            //getting tour data
                            string id_t;
                            while(true)
                            {
                                cout << "Enter the tour ID: ";
                                cin >> id_t;
                                for(int n=0;n<t_tours;n++)
                                {
                                    if(id_t==tourId[n])
                                    {
                                        cout << "Tour ID Already Exist!\n\n";
                                        id_t="-65";
                                        break;
                                    }
                                }
                                if(id_t != "-65")
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
                            
                            // sorting tours by place : 3. camparison, swaping, repeat the cycle : Bubble Sort -> adjecent elements camprison and swap
                            for(int j=0;j<t_tours;j++)
                            {
                            	for(int k=j;k<t_tours;k++)
                            	{
                            		if(tourPlace[j][0] > tourPlace[k][0])
                            		{
                            			string temp = tourId[j]; // a=3, b = 7  => a=7, b=3
                            			tourId[j] = tourId[k];
                            			tourId[k] = temp;
                            			
                            			temp = tourTitle[j];
                            			tourTitle[j] = tourTitle[k];
                            			tourTitle[k] = temp;
                            			
                            			temp = tourPlace[j];
                            			tourPlace[j] = tourPlace[k];
                            			tourPlace[k] = temp;
                            			
                            			temp = tourDate[j];
                            			tourDate[j] = tourDate[k];
                            			tourDate[k] = temp;
                            			
                            			int temp_ = tourT_capacity[j];
                            			tourT_capacity[j] = tourT_capacity[k];
                            			tourT_capacity[k] = temp_;
									}
								}
							}
                            
                        }
                        else if(adChoice==2)
                        {
                        	// delete a tour!
                        	if(t_tours==0)
							{
								cout << "No Tours Existed!\n\n";
								continue;
							}
							cout << "Enter the tour ID to delete: ";
							string t_id; cin >> t_id;
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
								continue;
							}
							else
							{	
								// delletig enrollments related to the tour
								
								// total enrolments in 1 tour add remembering their indexes
								int index_enr[100];
								int index_count=0;
								for(int j=0;j<t_enr;j++)
                        		{
                        			if(entourId[j]==tourId[index])
                        			{
                        				index_enr[index_count] = j;
                        				index_count++;
									}
								}
								
								// deleting enrollments for that tour
								for(int j=0;j<index_count;j++)
								{
									for(int k=index_enr[j];k<t_enr;k++)
									{
											enid[k] = enid[k+1];
											enclientId[k] = enclientId[k+1];
											entourId[k] = entourId[k+1];
									}
									for(int k=0;k<index_count;k++)
									{
										index_enr[k]--;
									}
								}
								
								cout << "Tour id: " << tourId[index] << " has been deleted! and " << index_count << " enrolments are also deleted!" << "\n\n";
								
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
                        }
                        else if(adChoice==3)
                        {
                        	// updating a tour
                        	if(t_tours==0)
							{
								cout << "No Tours Existed!\n\n";
								continue;
							}
							cout << "Enter the tour ID to update: ";
							string t_id; cin >> t_id;
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
								continue;
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
	                            
	                            // sorting tours by place : 3. camparison, swaping, repeat the cycle : Bubble Sort -> adjecent elements camprison and swap
	                            for(int j=0;j<t_tours;j++)
	                            {
	                            	for(int k=j;k<t_tours;k++)
	                            	{
	                            		if(tourPlace[j][0] > tourPlace[k][0])
	                            		{
	                            			string temp = tourId[j]; // a=3, b = 7  => a=7, b=3
	                            			tourId[j] = tourId[k];
	                            			tourId[k] = temp;
	                            			
	                            			temp = tourTitle[j];
	                            			tourTitle[j] = tourTitle[k];
	                            			tourTitle[k] = temp;
	                            			
	                            			temp = tourPlace[j];
	                            			tourPlace[j] = tourPlace[k];
	                            			tourPlace[k] = temp;
	                            			
	                            			temp = tourDate[j];
	                            			tourDate[j] = tourDate[k];
	                            			tourDate[k] = temp;
	                            			
	                            			int temp_ = tourT_capacity[j];
	                            			tourT_capacity[j] = tourT_capacity[k];
	                            			tourT_capacity[k] = temp_;
										}
									}
								}
							}
                            
                        }
                        else if(adChoice==4)
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
                        else if(adChoice==5)
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
                        }
                        else if(adChoice==6)
                        {
                        	if(t_clients==0)
							{
								cout << "No Clients Existed!\n\n";
								continue;
							}
							cout << "Enter the Cleint ID to delete: ";
							string c_id; cin >> c_id;
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
								continue;
							}
							else
							{
								
								// total enrolments in 1 tour add remembering their indexes
								int index_enr[100];
								int index_count=0;
								for(int j=0;j<t_enr;j++)
                        		{
                        			if(enclientId[j]==clientId[index])
                        			{
                        				index_enr[index_count] = j;
                        				index_count++;
									}
								}
								
								// deleting enrollments for that user
								for(int j=0;j<index_count;j++)
								{
									for(int k=index_enr[j];k<t_enr;k++)
									{
											enid[k] = enid[k+1];
											enclientId[k] = enclientId[k+1];
											entourId[k] = entourId[k+1];
									}
									for(int k=0;k<index_count;k++)
									{
										index_enr[k]--;
									}
								}
								
								cout << "Client id: " << clientId[index] << " has been deleted! and " << index_count << " enrolments are also deleted!" << "\n\n";
								for(int i=index;i<t_clients;i++)
								{
									clientId[i] = clientId[i+1];
		                            clientName[i] = clientName[i+1];
		                            clientEmail[i] = clientEmail[i+1];
		                            clientPhone[i] = clientPhone[i+1];
		                            clientPw[i] = clientPw[i+1];	
								}
	                            t_clients--;	
							}
                        }
                        else if(adChoice==7)
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
            }
        }
        else if (choice==2)
        {
            //user operations
            while(true)
            {
				system("cls");
				cout<<"====Client Panel====\n";
                cout << "1. Register\n2. Login\n3. Exit\nEnter Your Choice: ";
                int choice_user;
                cin >> choice_user;
                if(choice_user==1)
                {
                    if(t_clients==100)
                    {
                        cout << "The memory is full!";
                        continue;
                    }
                    //getting tour data
                    string id_c;
                    while(true)
                    {
                        cout << "Enter the tour ID: ";
                        cin >> id_c;
                        for(int n=0;n<t_clients;n++)
                        {
                            if(id_c==clientId[n])
                            {
                                cout << "Client ID Already Exist!\n\n";
                                id_c="-65";
                                break;
                            }
                        }
                        if(id_c != "-65")
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