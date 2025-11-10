#include<iostream>
#include<string>
using namespace std;
	
	class Bank
	{
	private:
	    string StoredUserName1;
	    string StoredPassword1;
	    string StoredUserName2;
	    string StoredPassword2;
	    double balance1 = 50000;
	    double balance2 = 30000;
	    string UserName;
	    string Password;
	    bool LoggedIn = false; 
	
	public:
	    Bank()
	    {
	        StoredUserName1 = "Kalim";
	        StoredPassword1 = "123";
	        StoredUserName2 = "Ali";
	        StoredPassword2 = "456";
	    }
	
	    void LoginAccount()
	    {
	        if (!LoggedIn) 
	        {
	            cout << "Enter Your UserName: ";
	            cin >> UserName;
	            cout << "Enter Your Password: ";
	            cin >> Password;
	
	            if ((UserName == StoredUserName1 && Password == StoredPassword1) || 
	                (UserName == StoredUserName2 && Password == StoredPassword2))
	            {
	                LoggedIn = true; 
	                cout << "You have logged into your Account Successfully, Mr " << UserName << endl;
	            }
	            else
	                cout << "Invalid Password or UserName..!!" << endl;
	        }
	        else
	            cout << "You are already logged in as " << UserName << endl;
	    }
	
	    void LogoutAccount()
	    {
	        LoggedIn = false; 
	        UserName = "";
	        Password = "";
	        cout << "You have logged out successfully." << endl;
	    }
	
	    void CheckBalance()
	    {
	        if (LoggedIn)
	        {
	            if (UserName == StoredUserName1)
	            {
	                cout << "Your Current Balance is: " << balance1 << endl;
	            }
	            else
	                cout << "Your Current Balance is: " << balance2 << endl;
	        }
	        else
	            cout << "Please log in to check your balance." << endl;
	    }
	
	    void Deposit()
	    {
	        if (LoggedIn)
	        {
	            double amount;
	            cout << "Enter Amount You Want to deposit: ";
	            cin >> amount;
	            if (amount > 0)
	            {
	                if (UserName == StoredUserName1)
	                {
	                    balance1 += amount;
	                }
	                else
	                {
	                    balance2 += amount;
	                }
	                cout << "Deposited: " << amount << endl;
	            }
	            else
	                cout << "Invalid Deposit Amount.." << endl;
	        }
	        else
	            cout << "Please log in to deposit money." << endl;
	    }
	
	    void Withdraw()
	    {
	        if (LoggedIn)
	        {
	            double amount;
	            cout << "Enter Amount You Want to Withdraw: ";
	            cin >> amount;
	            if (UserName == StoredUserName1 && amount > 0 && amount <= balance1)
	            {
	                balance1 -= amount;
	                cout << "Amount you have withdrawn is " << amount << endl;
	            }
	            else if (UserName == StoredUserName2 && amount > 0 && amount <= balance2)
	            {
	                balance2 -= amount;
	                cout << "Amount you have withdrawn is " << amount << endl;
	            }
	            else
	                cout << "Invalid Amount.." << endl;
	        }
	        else
	            cout << "Please log in to withdraw money." << endl;
	    }
	
	    void Transfer()
	    {
	        if (LoggedIn)
	        {
	            double amount;
	            string recipient;
	            cout << "Enter UserName whom you want to transfer money: ";
	            cin >> recipient;
	            cout << "Enter Amount You Want to transfer: ";
	            cin >> amount;
	
	            if (UserName == StoredUserName1 && recipient == StoredUserName2)
	            {
	                if (amount > 0 && amount <= balance1)
	                {
	                    balance1 -= amount;
	                    balance2 += amount;
	                    cout << "Amount you have transferred to " << recipient << " is " << amount << endl;
	                }
	                else
	                    cout << "Invalid Amount.." << endl;
	            }
	            else if (UserName == StoredUserName2 && recipient == StoredUserName1)
	            {
	                if (amount > 0 && amount <= balance2)
	                {
	                    balance2 -= amount;
	                    balance1 += amount;
	                    cout << "Amount you have transferred to " << recipient << " is " << amount << endl;
	                }
	                else
	                    cout << "Invalid Amount.." << endl;
	            }
	            else
	                cout << "Invalid Amount.." << endl;
	        }
	        else
	            cout << "Please log in to transfer money." << endl;
	    }
	};
	
	int main()
	{
	    Bank a;
	    int choice;
		cout << "\n==== WELCOME TO BANK ====\n";
	        do
			{
	            cout << "\n==== WHAT YOU WANT TO DO ====\n";
	           	cout << "1. LOGIN\n";
			    cout << "2. CHECK BALANCE\n";
	            cout << "3. WITHDRAW CASH\n";
	            cout << "4. TRANSFER CASH\n";
	            cout << "5. DEPOSIT CASH\n";
	            cout << "6. LOGOUT\n";
	            cout << "7. Exit\n";
	            cout << "Enter your choice: ";
	            cin >> choice;
	
	            switch (choice)
	            {
	            case 1:
	                a.LoginAccount();
	                break;	
	            case 2:
	                a.CheckBalance();
	                break;
	            case 3:
	                a.Withdraw();
	                break;
	            case 4:
	                a.Transfer();
	                break;
	            case 5:
	                a.Deposit();
	                break;
	            case 6:
	                a.LogoutAccount(); 
	                break;
	            case 7:
	                cout << "Exiting BANK PORTAL... Goodbye!" << endl;
	                return 0; 
	            default:
	                cout << "Invalid choice. Please try again." << endl;
	            }
	        } 
	        while (choice != 7);
	}
