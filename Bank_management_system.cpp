	#include<bits/stdc++.h>

	using namespace std;
	const int n = 100 ; 
	int client_count = 0 ;
	int index = -1;

//struture to save client information
	struct info{
		double id;
		string name;
		string username ; 
		string password;
		double balance;
		bool vip; 
		double acc_number;
	};
	info clients[n];

	// =======================================>admin functions
	void check()
	{	
		string pasword;
		pasword = "admin123";
		cout<<"Enter the admin password: " << endl;
		cin >> pasword;

		if (pasword == "admin123")
			cout << "Access granted." << endl;
			
		else
		{
			cout << "Access denied." << endl;
			exit(0);
		}	
	}

	
	void displayAllClients() {
		if (client_count == 0) {
			cout << "No clients available.\n";
			return;
		}
		for (int i = 0; i < client_count; i++) {
			cout << "\nID: " << clients[i].id
				<< "\nName: " << clients[i].name
				<< "\nAccount: " << clients[i].acc_number
				<< "\nBalance: " << clients[i].balance
				<< "\nVIP: " << (clients[i].vip ? "Yes" : "No") << "\n";
		}
	}
	 

	void displayVIPClients() {
		for (int i = 0; i < client_count; i++) {
			if (clients[i].vip) {
				cout << "\nName: " << clients[i].name
					<< " | Account: " << clients[i].acc_number
					<< " | Balance: " << clients[i].balance << "\n";
			}
		}
	}


//-----------------------------
     // search client by name and account number function
	int searchclient( string name_forsearch, double accnum_forsearch) {
		for( int i = 0 ; i < client_count; i++){
		if(clients[i].name == name_forsearch && clients[i].acc_number == accnum_forsearch){
			cout << "client found" << endl;
			return i;
		}
		
		
	}
	return -1;
	}
//update client information function
   void updateclient(){
	if( index == -1 ){
		cout<<"client not found" << endl;
	}
	else{
		cout<<"Enter new name: " ;
		cin >> clients[index].name ; 
		cout <<" Enter new balance: " ; 
		cin >> clients[index].balance; 
       cout<<"Is the client VIP? (1 for yes, 0 for no): " ;
		cin >> clients[index].vip;
        cout<<"Updated successfully." << endl;
	}
}

	void savetofile(){
		ofstream file("client.txt");
		for( int i = 0 ; i < client_count; i++){
			
			file<<  clients [i].id<<" ";
		  	file<<clients[i].name<<" ";
             file<<clients[i].username<<" ";
			 file<<clients[i].password<<" "	;
			 file<<clients[i].balance<<" "; 
			 file<<clients[i].vip<<" ";
			 file<<clients[i].acc_number<<" "<<endl;
	}
	file.close();
	cout<<"Data saved"<<endl ; 
   }


   void loadfromfile(){
		ifstream file("client.txt");
		if(!file)return;

		client_count = 0; 
		while(file >> clients[client_count].id
		>> clients[client_count].name
		>> clients[client_count].username
		>> clients[client_count].password
		>> clients[client_count].balance
		>> clients[client_count].vip
		>> clients[client_count].acc_number){
			client_count++;
   }
   		file.close();
		cout<<"Data loaded"<<endl;
   }


	//===================================================>client functions 

	



int loginClient(string username_client1, string passowrd_client1 ) {
		for (int i = 0; i < client_count; i++) {
			if (clients[i].username == username_client1 && clients[i].password == passowrd_client1) {
				cout << "Login successful. Welcome, " << clients[i].name << "!" << endl;
				return i;

			}
			
		}
		return -1;
	}

	
	double deposit( double amount)
	{
		clients[index].balance += amount;
		cout << "Deposit successful. New balance: " << clients[index].balance << endl;
		return clients[index].balance;
	}

	


	
double withdraw( double amount)
	{
		
		if (amount > clients[index].balance)
		{
			cout << "Insufficient balance." << endl;
			return clients[index].balance;
		}
		else
		{
			clients[index].balance -= amount;
			cout << "Withdrawal successful. New balance: " << clients[index].balance << endl;
			return clients[index].balance;
		}
	}
	//=====================================================>main function display





	int main()
	{
		loadfromfile();
		
	int user_choice; // ---------------------->user_choice 1
	do{
		string password ;
		
	cout <<"===============================" << endl;
	cout << "Welcome to Bank Management System" << endl;
	cout <<"===============================" << endl;
	cout << " 1. Admin" << endl;
	cout << " 2. Client" << endl;
	cout << " 3. Exit" << endl;
	cin >> user_choice;

	if(user_choice ==1 ){
	//---------------------->user_choice 1	
	check();
	
	int choice;

	do{
	cout<<"----- Welcome to the admin panel -----"<<endl;
	cout<<"1.Display client"<<endl;
	cout<<"2. Display VIP clients"<<endl;
	cout<<"3.Search client"<<endl; 
	cout<<"4.Update client information"<<endl; 
	cout<<"5.Save to file"<<endl; 
	cout<<"6.Load from file"<<endl;
	cout<<"7.Exit"<<endl;
	cin >> choice;
	if(choice == 1){
	displayAllClients();	
	}
	else if (choice == 2){
	displayVIPClients();
	}
	else if (choice == 3){
		
		cout<<"Searching for client..."<<endl;
		string name_forsearch;
		double accnum_forsearch;
		cout << "Enter name: ";
		cin >> name_forsearch;
		cout << "Enter account number: ";
		cin >> accnum_forsearch;
		index = searchclient(name_forsearch, accnum_forsearch);
                    if (index != -1) {
                        cout << "Found: " << clients[index].name
                             << " Balance: " << clients[index].balance << endl;
                    } else {
                        cout << "Not found.\n";
                    } 
	
					
	}
	else if (choice == 4){
		cout<<"Updating client information..."<<endl;
    updateclient();
	}
	else if (choice == 5){
		cout<<"Saving to file..."<<endl;
	savetofile();
		
	}
	else if (choice == 6){
		cout<<"Loading from file..."<<endl;
	loadfromfile();
	}
	else if (choice == 7){
		cout<<"Exiting admin panel..."<<endl;
	
	}
	else{
		cout<<"Invalid choice."<<endl;
	}
	


	}while(choice != 7);//
}
	else if(user_choice == 2){
	cout<<"----- Welcome to the client panel -----"<<endl;
	cout << " register or login? : " << endl;
		string x;
		cin >> x;
	if ( x == "register" ){	
	 if (client_count >= n) {
                        cout << "Max clients reached.\n";
                        continue;
                    }

                    info c;
                    cout << "Enter ID: "; 
					cin >> c.id;
                    cout << "Enter Name: "; 
					cin >> c.name;
                    cout << "Enter Username: "; 
					cin >> c.username;
                    cout << "Enter Password: "; 
					cin >> c.password;
                    cout << "Enter Balance: "; 
					cin >> c.balance;
					
					if (c.balance >= 10000) {
						c.vip = true;
					} else {
						c.vip = false;
					}
                   
                    cout << "Enter Account Number: "; 
					cin >> c.acc_number;

                    clients[client_count++] = c;
					index = client_count - 1;
                    cout << "Client added.\n";
	}
	else if (x == "login") {
    string username_client1, password_client1;
    cout << "Enter username: "; 
	cin >> username_client1;
    cout << "Enter password: "; 
	cin >> password_client1;
    index = loginClient(username_client1, password_client1);

    if (index == -1) {
        cout << "Invalid credentials!" << endl;
        continue; 
    }
}
	int client_choice;
	do{
	 cout <<"1. Check balance"<<endl;
	cout <<"2. Deposit money"<<endl;
	cout <<"3. Withdraw money"<<endl;
	cout <<"4. Exit"<<endl;
	cin >> client_choice;
if (client_choice == 1){
		if (index!= -1) {

    cout << "Balance: " << clients[index].balance<<endl;
}

	}
	else if (client_choice == 2){
		cout << "Enter amount to deposit: " << endl;
		double amount;
		cin >> amount;
		deposit(amount);
		savetofile();
		
	}
	else if (client_choice == 3){
		cout << "Enter amount to withdraw: " << endl;
		double amount;
		cin >> amount;
		withdraw( amount);
		savetofile();
	}
	else if (client_choice == 4){
		cout << "Exited from client panel." << endl;
	}
	else{
		cout << "Invalid choice." << endl;
	}
	
		

	}while(client_choice != 4);
	
	}
		
	}

while(user_choice != 3);
return 0;


} 