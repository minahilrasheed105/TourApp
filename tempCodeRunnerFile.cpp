
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
                                            if(ento