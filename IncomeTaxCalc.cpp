//taxstuff
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double income;
    double dependents;
    double taxpaid;
	double taxable_income;
	double totaltax;
	const int minimum_dependents=10;
	const int deduction_dependents =5000;
	const double basicamount = 12000;
	const double firstbracket = 20000;
	const double firstpercent = 0.15;
	const double secondbracket =50000;
	const double secondpercent = 0.20;
	const double thirdpercent = 0.18;
	const double thirdbracket = 100000;
	const double fourthbracket = 10000000;
	const double basetax20k = 3000;
	const double surtax = 0.035;
	double surtaxamount;



    double balance;
	double refund;


    cout << "Please enter your total income before any deductions for income tax" << endl;
    cin >> income;
	if (income < 0) {
	  cout << "Error: your income cannot be < 0\n";
	  return 0; }


	
    cout << "Please enter the number of children you support" <<endl;
	cin >> dependents;
	if (dependents >= minimum_dependents){
	  dependents = 10;}
	  

    else if (dependents<0){
	  cout<<"Error: You cannot have a negative number of dependents\n";
	  return 0;}
    

	if ((dependents*deduction_dependents) < income){
	  taxable_income = (income - (dependents*deduction_dependents));}
	else if ((dependents*deduction_dependents) >= income)
	  taxable_income = 0;    

	cout <<"Please enter the amount of income tax your employer already deducted\n";  
	cin >> taxpaid;
	if (taxpaid < 0){
	  cout<<"Error: You cannot prepay negative amounts of tax\n";
	  return 0;}
	else if (taxpaid > income){ 
	  cout<<"You cannot prepay more in tax than you recieve in income\n";
	  return 0;}

	cout << endl;
	cout << endl;

	cout << left << setw(40)<<"Amount of income:" << "$" << right << setw(10) << fixed << setprecision(2) << income<<endl;
	cout << left << setw(40)<<"Number of qualifying dependents:" << " " << right << setw(10) << dependents <<endl;
	cout << left << setw(40)<<"Taxable income:" << "$" << right << setw(10) << fixed << setprecision(2) << taxable_income <<endl;
	cout << left << setw(40)<<"Amount of income tax deducted:"  << "$" << right << setw(10) << fixed << setprecision(2) << taxpaid<< endl;


	if (taxable_income < basicamount){
		cout << "You do not owe any income tax\n";
		cout << left << setw(40)<< "You will receive a refund of" << "$" <<right <<setw(10) << taxpaid << endl;
		return 0;


	}

	if (taxable_income >= basicamount && taxable_income <= firstbracket){
		totaltax = taxable_income * firstpercent;
		if (totaltax >= taxpaid){
			balance = totaltax - taxpaid;
			cout << balance;

		}	

		if (totaltax < taxpaid){
			refund = taxpaid - totaltax;
			cout << refund;

		}

		


	}

	if (taxable_income >= firstbracket && taxable_income <= secondbracket){
		totaltax = (((taxable_income - firstbracket) * secondpercent) + basetax20k);
		if (totaltax >= taxpaid){
			balance = totaltax - taxpaid;
			cout << balance;

		}

		if (totaltax < taxpaid){
			refund = taxpaid - totaltax;
			cout <<refund;
		}
	

	}

	if (taxable_income > secondbracket && taxable_income <= thirdbracket){
		totaltax = (taxable_income * thirdpercent);
		if (totaltax >= taxpaid){
		    balance = totaltax - taxpaid;
		    cout << balance;
		}

		

		if (totaltax < taxpaid){
			refund = taxpaid - totaltax;
			cout <<refund;
		}
		
		
		
		
	}

	if (taxable_income > thirdbracket && taxable_income <= fourthbracket){
			surtaxamount = ((taxable_income - thirdbracket) * surtax);
		    totaltax = (taxable_income * thirdpercent);
			if (totaltax >= taxpaid){
			balance = totaltax - taxpaid;
			cout << balance<< endl;
			cout << surtaxamount;

		}

		if (totaltax < taxpaid){
			refund = taxpaid - totaltax;
			cout <<refund;
		}


	}	


















	




	  

	
	  

	 
	
	 


	

	






	

	return 0; 



	






}








