#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

int BtoD(string b){ //bianry to decimal using stack
	int i = 0, ans = 0, x = 0;
	stack<int> st;
	while(i < b.length()) st.push(b[i] - '0'), i++; //MUST USE -'0' to convert char to int
	while(!st.empty()){
		if(st.top() == 1) ans += pow(2,x);
		st.pop();
		x++;
	}
	return ans;
}

string DtoB(int d){ //decimal to binary using a queue
	string ans = "";
	int x = 2;
	while(x*2-1 < d) x*=2;

	queue<char> Q;
	while(d > 0){
		if(d>=x) Q.push('1'), d-=x;
		else Q.push('0');
		x/=2;
	}
	while(x>=1) Q.push('0'), x/=2; //add remaining 0's until x reaches 2^0 (1)

	while(!Q.empty()) ans+= Q.front(), Q.pop();
	return ans;
}

string binaryAddCheck(string a, string b){ //convert to decimal
	int Anum = BtoD(a);
	int Bnum = BtoD(b);
	return DtoB(Anum+Bnum);
}

string binaryAdd(string a, string b){
	string ans = "";
	int sum = 0;

	for(int i = a.length()-1, j = b.length()-1; i >=0 || j>=0 || sum==1; i--, j--){
		//Wow big ol' for loop. Iterate through a & b til the end of both, and no carry left.
		sum += ((i >= 0) ? a[i] - '0' : 0);
		sum += ((j >= 0) ? b[j] - '0' : 0);

		ans = char(sum % 2 + '0') + ans; //If current digit sum is 1 or 3, add 1 to ans
		sum /= 2; // Carry
	}
	return ans;
}

string binarySubCheck(string a, string b){ //convert to decimal
	int Anum = BtoD(a);
	int Bnum = BtoD(b);
	return DtoB(Anum-Bnum);
}

string binarySub(string a, string b){
	string ans = "";
	bool carry = 0;
	return ans;
}

string binaryMulCheck(string a, string b){ //convert to decimal
	int Anum = BtoD(a);
	int Bnum = BtoD(b);
	return DtoB(Anum*Bnum);
}

string binaryMul(string a, string b){
	string ans = "0";
	stack<char> st;
	for(int i = 0; i < a.length(); i++) st.push(a[i]);
	while(!st.empty()){
		if(st.top()=='1') ans = binaryAddCheck(ans, b);
		st.pop(); //"Shift right"
		b += "0"; //"Shift left"
	}
	return ans;
}

string binaryDivCheck(string a, string b){ //convert to decimal
	int Anum = BtoD(a);
	int Bnum = BtoD(b);
	return DtoB(Anum/Bnum);
}

string binaryDiv(string a, string b){
	
	return "";
}
