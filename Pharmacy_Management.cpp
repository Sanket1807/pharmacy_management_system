#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;

class medicineType
{
    public:

        void take_order();
        void modify();
        void order_list();
        void daily_summary();
        void exit();
};

struct node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
    "Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link;

}*q, *temp;


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;


void medicineType::take_order()
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details : \n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"**************************************************************************\n";
				cout<<"| MEDICINE ID |"<<"   \t| MEDICINE NAME |"<<"          | MEDICINE PRICE(INR) |"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"0001"<<"\t"<<"\t\t"<<"Probiotics"<<"\t\t\t    2.00"<<endl;
                cout<<"0002"<<"\t"<<"\t\t"<<"Vitamin C(500mg)"<<"\t\t    3.00"<<endl;
                cout<<"0003"<<"\t"<<"\t\t"<<"Acid Free C(500mg)"<<"\t\t    1.00"<<endl;
                cout<<"0004"<<"\t"<<"\t\t"<<"Women'S Multivate"<<"\t\t    4.00"<<endl;
                cout<<"0005"<<"\t"<<"\t\t"<<"Marino Tablet"<<"\t\t\t    1.00"<<endl;
                cout<<"0006"<<"\t"<<"\t\t"<<"Maxi Cal Tablet"<<"\t\t\t    5.00"<<endl;
                cout<<"0007"<<"\t"<<"\t\t"<<"Amino Zinc Tablet"<<"\t\t    7.00"<<endl;
                cout<<"0008"<<"\t"<<"\t\t"<<"Burnex"<<"\t\t\t\t    4.00"<<endl;
                cout<<"0009"<<"\t"<<"\t\t"<<"Fabuloss 5"<<"\t\t\t    3.00"<<endl;
                cout<<"0010"<<"\t"<<"\t\t"<<"Royal Propollen"<<"\t\t\t    5.00"<<endl;
                cout<<endl;

	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout << "How many Types of Medicine would you like to order ( Maximum is 10 order for each transaction ) : ";
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order! \n";
		system("pause");
	}
	else
    {
        for (i=0; i<temp->x; i++)
        {

            cout << "Please enter your selection : ";
            cin>> temp->menu2[i];
            if(temp->menu2[i]<1)
            {
                cout<<"Invalid Choice... "<<endl;
                exit();
                take_order();
            }
            else if(temp->menu2[i]>10)
            {
                cout<<"Invalid Choice... "<<endl;
                exit();
                take_order();
            }
            else
            {
                cout<< "Medicine Name : " <<temp->medicineName[temp->menu2[i]-1]<<endl;
                cout << "How many number of medicine do you want : ";
                cin >> temp->quantity[i];
                temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
                cout << "The amount You need to pay is : " << temp->amount[i]<<" INR"<<endl;
                system("PAUSE");
            }

        }
        cout<<"==========================================================================="<<endl;
        cout << "\t\tOrder Taken Successfully..."<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        cout << "\t\tGo to Receipt Menu to Pay The Bill."<<endl;
        cout<<"==========================================================================="<<endl;
        system ("PAUSE");

        temp->next=NULL;
        if(start_ptr!=NULL)
        {
            temp->next=start_ptr;
        }
        start_ptr=temp;
        system("cls");
    }
}


void medicineType::order_list()
{
	int i, num, num2;
	bool found;
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;

	cout<<" Enter the Receipt Number To Print The Receipt : ";
	cin>>num2;
    cout<<"\n";
    cout<<"==========================================================================="<<endl;
    cout <<"\t\t\t  Here is the Order List : \n";
    cout<<"==========================================================================="<<endl;
    cout <<"Reciept Number : "<<temp->reciept_number<<endl;
    cout<<"Customer Name : "<<temp->customerName<<endl;


	if(temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show!!!\n\t\t\t The List is Empty...\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)
        {


            cout << "----------------------------------------------------------------------------------" << endl;
            cout << "\t|\tMedicine Name\t   |\tQuantity\t|\tTotal Price\t|" << endl;
            cout << "----------------------------------------------------------------------------------" << endl;

            for (i=0;i<temp->x;i++)
            {

                cout<<"\t\t";
                cout<<temp->medicineName[temp->menu2[i]-1];
                cout<<"\t\t";
                cout<<temp->quantity[i];
                cout<<"\t\t\t";
                cout<< temp->amount[i]<<" INR\t"<<endl;


                cout<<"_________________________________________________________________________________"<<endl;
            }

            temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
                            +temp->amount[8]+temp->amount[9];
            cout<<"Total Bill is : "<<temp->total;
            cout<<"\n";
            cout << "Type the exact amount you are paying : ";
            cin >> num;

            cout <<"\n";
            cout <<"\n";
            cout<<"Payment Done\nThank You\n";
            cout <<"\n_______________________________________________________________________________\n";
		}


}
}

void medicineType::modify()
{
    system("cls");
    int i, ch, sid;
    bool found;
    found = false;
    temp = start_ptr;
    cout<<"Enter Receipt Number To Modify : ";
    cin>>sid;
    if (temp==NULL && sid==0)
    {
        cout<<"NO RECORD TO MODIFY..!"<<endl;
    }

    else
    {
        while(temp !=NULL && !found)
        {
            if (temp->reciept_number==sid)
            {
                found = true;
            }
            else
            {
                temp = temp -> next;
            }
            if (found)
            {
                cout << "Change  Order Number : ";
                cin >> temp->reciept_number;
                cout<< "Change Customer Name : ";
                cin>> temp->customerName;
                cout << "How many New Medicine would you like to Change : ";
                cin >> temp->x;
                if (temp->x >10)
                {
                    cout << "The Medicine you ordered has exceeded the maximum amount of order !!";
                    system("pause");
                }
                else{
                for (i=0; i<temp->x; i++)
                {

                    cout <<"**************************************************************************\n";
                    cout<<"| MEDICINE ID |"<<"   \t| MEDICINE NAME |"<<"          | MEDICINE PRICE(INR) |"<<endl;
                    cout <<"**************************************************************************\n";
                    cout<<"0001"<<"\t"<<"\t\t"<<"Probiotics"<<"\t\t\t    2.00"<<endl;
                    cout<<"0002"<<"\t"<<"\t\t"<<"Vitamin C(500mg)"<<"\t\t    3.00"<<endl;
                    cout<<"0003"<<"\t"<<"\t\t"<<"Acid Free C(500mg)"<<"\t\t    1.00"<<endl;
                    cout<<"0004"<<"\t"<<"\t\t"<<"Women'S Multivate"<<"\t\t    4.00"<<endl;
                    cout<<"0005"<<"\t"<<"\t\t"<<"Marino Tablet"<<"\t\t\t    1.00"<<endl;
                    cout<<"0006"<<"\t"<<"\t\t"<<"Maxi Cal Tablet"<<"\t\t\t    5.00"<<endl;
                    cout<<"0007"<<"\t"<<"\t\t"<<"Amino Zinc Tablet"<<"\t\t    7.00"<<endl;
                    cout<<"0008"<<"\t"<<"\t\t"<<"Burnex"<<"\t\t\t\t    4.00"<<endl;
                    cout<<"0009"<<"\t"<<"\t\t"<<"Fabuloss 5"<<"\t\t\t    3.00"<<endl;
                    cout<<"0010"<<"\t"<<"\t\t"<<"Royal Propollen"<<"\t\t\t    5.00"<<endl;
                    cout<<endl;
                    cout << "Please enter your selection of medicine to Change : "<<endl;
                    cin>> temp->menu2[i];
                    cout<< "Change Medicine Name : " <<temp->medicineName[temp->menu2[i]-1]<<endl;
                    cout << "How many New medicine do you want : ";
                    cin >> temp->quantity[i];
                    temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
                    cout << "The amount you need to pay after modification  is : " << temp->amount[i]<<" RM"<<endl;
                    system("PAUSE");
                }
                temp = temp->next;
                system("cls");

            }

            cout<<"RECORD MODIFIED....!"<<endl;
            }
            else
            {
                if(temp != NULL && temp->reciept_number != sid)
                {
                    cout<<"Invalid Reciept Number...!"<<endl;
                }
             }
        }
    }
}

void medicineType::daily_summary()
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL)
	{
		cout << "\t\t\tThere is no Order to show!!!\n\t\t\tThe List is Empty...\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders : \n";
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{

				cout <<"Reciept Number : "<<temp->reciept_number<<endl;

				cout<<"Customer Name: "<<temp->customerName<<endl;


				cout << "=============================================================================" << endl;
				cout << "|   Medicine Type   |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=============================================================================" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout <<"\t"<< temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" INR"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;

			cout <<"\n";
			cout <<"\n";

			temp=temp->next;
		}
	}
}
void medicineType::exit()
{
	cout<<"\nYou choose to Exit.\n"<<endl;
}

int main()
{

	system("COLOR 70");
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t---------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t3. Print the Receipt and Make Payment \t ||\n";
		cout<<"\t\t||\t4. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t5. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t---------------------------------------------------\n";
		cout<<"Enter choice : ";
		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();
				break;
			}

		case 2:
			{
				medicine.modify();
				system("PAUSE");
				break;
			}

		case 3:
			{
				medicine.order_list();
				system("PAUSE");
				break;
			}
		case 4:
			{
				medicine.daily_summary();
				system("PAUSE");
				break;
			}
        case 5:
			{
				medicine.exit();
				goto a;
				break;
			}

		default:
			{
				cout<<"You entered invalid input \n Re-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=5);
	a:
	cout<<"Thank You..."<<endl;
	system ("EXIT");
	return 0;
}
