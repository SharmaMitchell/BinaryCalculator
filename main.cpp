#include <iostream>
#include "BinaryCalculator.h"
using namespace std;


int main() {
	bool cont;
	string v1, v2, op, ans;
	do{
		cout << "Enter binary operation (separate with spaces): " << endl;
		cin >> v1 >> op >> v2;
		if(op=="+") ans = binaryAdd(v1, v2);
		else if(op=="-") ans = binarySubCheck(v1, v2);
		else if(op=="*" || op=="x") ans = binaryMul(v1, v2);
		else if(op=="/") ans = binaryDivCheck(v1, v2);
		else if(op=="BtoD") ans = to_string(BtoD(v2));
		else if(op=="DtoB") ans = DtoB(stoi(v2));
		else{
			cout << "Please enter a valid operation, ex. '101 + 101'" << endl;
			cout << "For binary conversion, enter: 'do BtoD 101' or 'do DtoB 101'" << endl;
		}
		cout << "Answer: " << ans << endl; 

		cout << "Enter 'Q' to quit, or press any key to continue" << endl;
		string temp;
		cin >> temp;
		if(temp=="Q" || temp=="q") cont = false;
		else cont = true;
	}while(cont);
	cout << "Thanks for using the Binary Calculator!" << endl;
	return 0;
} 