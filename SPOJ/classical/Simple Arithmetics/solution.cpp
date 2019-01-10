/*
* tested with C++14(gcc 6.3)
*/

#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

// adds a and b, and returns result in a string
string add(string a, string b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, j = b.length() - 1, carry = 0, sum;
	while(i >= 0 && j >= 0){
		sum = (a[i] - 48) + (b[j] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		i--;j--;
	}
	while(i >= 0){
		sum = (a[i] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		i--;
	}
	while(j >= 0){
		sum = (b[j] - 48) + carry;
		st.push(sum % 10);
		carry = sum / 10;
		j--;
	}
	while(carry){
		st.push(carry % 10);
		carry /= 10;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return res;
}

// removes leading zeros from s
string removeLeadingZeros(string s){
	string res = "";
	int i;
	// move pass all the leading zeros in s
	for(i=0;i<s.length() && s[i] == '0';i++);
	// append rest of the digits to the result
	while(i<s.length()){
		res.append(1, s[i]);
		i++;
	}
	if(res == "")
		res = "0";
	return res;
}

// substracts a from b and returns result in a string
string subtract(string a, string b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, j = b.length() - 1;
	while(i >= 0 && j >= 0){
		if(a[i] >= b[j])
			st.push(a[i] - b[j]);
		else{
			int k = i-1;
			while(k >= 0 && a[k] == '0'){
				a[k] = '9';
				k--;
			}
			a[k]--;
			st.push(10 + a[i] - b[j]);
		}
		i--;
		j--;
	}
	while(i >= 0){
		st.push(a[i] - 48);
		i--;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return removeLeadingZeros(res);
}

// splits string into two operands and operator
vector<string> splitString(string s){
	string a = "", b = ""; // operands
	int i;
	// operand a everything up to operator
	for(i=0;i<s.length();i++){
		if(s[i] == '*' || s[i] == '+' || s[i] == '-')
			break;
		a.append(1, s[i]);
	}
	string op; // operator
	op.append(1, s[i]);
	// operand b everything after operator
	for(int j=i+1;j<s.length();j++){
		b.append(1, s[j]);
	}
	vector<string> res;
	res.push_back(a);
	res.push_back(op);
	res.push_back(b);
	return res;
}

// prints operands, operator and result
void display(vector<string> s, string res){
	// maximum length of the output line
	int maxLength = max(res.length(), max(s[0].length(), s[2].length() + 1));
	string first, second, result, dashes;
	// preceed first operand with required empty spaces
	first.append(maxLength - s[0].length(), ' ');
	first.append(s[0]);
	printf("%s\n", first.c_str());
	// preceed second operand with required empty spaces and operator
	second.append(maxLength - s[2].length() - 1, ' ');
	second.append(s[1]);
	second.append(s[2]);
	printf("%s\n", second.c_str());
	// preceed dashes with required empty spaces
	dashes.append(maxLength - max(s[2].length() + 1, res.length()), ' ');
	dashes.append(max(s[2].length() + 1, res.length()), '-');
	printf("%s\n", dashes.c_str());
	// preceed result with required empty spaces
	result.append(maxLength - res.length(), ' ');
	result.append(res);
	printf("%s\n", result.c_str());
}

// returns result of multiplication of a with b in a string
string intMultiply(string a, int b){
	stack<int> st;
	string res = "";
	int i = a.length() - 1, carry = 0, sum;
	while(i >= 0){
		sum = (b * (a[i] - 48)) + carry;
		carry = sum / 10;
		st.push(sum % 10);
		i--;
	}
	while(carry){
		st.push(carry % 10);
		carry /= 10;
	}
	while(!st.empty()){
		res.append(1, st.top() + 48);
		st.pop();
	}
	return res;
}

// multiplies s and t
// saves itermediate results in a vector of strings
vector<string> multiply(string s, string t){
	vector<string> product;
	int power = 0; // keeps track of the number of steps
	string res = "0", tmp = "", dispTmp = "";
	stack<int> st;
	// traverse second operand from right to left
	for(int i=t.length() - 1;i>=0;i--){
		// multiply first operand with the current digit
		tmp = intMultiply(s, t[i] - 48);
		tmp = removeLeadingZeros(tmp);
		dispTmp = tmp;
		// trailing zeros
		tmp.append(power, '0');
		// trailing empty spaces
		dispTmp.append(power, ' ');
		// save intermediate result 
		product.push_back(dispTmp);
		power++;
		// add tmp to result
		res = add(res, tmp);
	}
	product.push_back(res);
	return product;
}

// formats the output accordingly using 
// operands and operator saved in s
// and results of multiplication saved in result
void display(vector<string> s, vector<string> result){
	// find the length of the longest line in output
	int maxLength = max(s[0].length(), s[2].length() + 1);
	for(int i=0;i<result.size();i++){
		maxLength = max((int)result[i].length(), maxLength);
	}
	string tmp, first, second, dashes1, dashes;
	// preceed first operand with required empty spaces
	first.append(maxLength - s[0].length(), ' ');
	first.append(s[0]);
	printf("%s\n", first.c_str());
	// preceed second operand with required empty spaces and the operator
	second.append(maxLength - s[2].length() - 1, ' ');
	second.append(s[1]);
	second.append(s[2]);
	printf("%s\n", second.c_str());
	// print dashes preceeded by required empty spaces
	dashes1.append(maxLength - max(result[0].length(), s[2].length() + 1), ' ');
	dashes1.append(max(result[0].length(), s[2].length() + 1), '-');
	printf("%s\n", dashes1.c_str());
	// traverse results
	int i;
	for(i=0;i<result.size() - 1;i++){
		// print each with required leading empty spaces
		tmp = "";
		tmp.append(maxLength - result[i].length(), ' ');
		tmp.append(result[i]);
		printf("%s\n", tmp.c_str());
	}
	// finish with dashes and final result formatted accordingly
	if(result.size() != 2){
		dashes.append(maxLength - max(result[i].length(), result[result.size() - 1].length()), ' ');
		dashes.append(max(result[i].length(), result[result.size() - 1].length()), '-');
		printf("%s\n", dashes.c_str());
		tmp = "";
		tmp.append(maxLength - result[result.size() - 1].length(), ' ');
		tmp.append(result[result.size() - 1]);
		printf("%s\n", tmp.c_str());
	}
}

int main(){
	
	string s;
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> s;
		vector<string> split = splitString(s);
		if(split[1] == "*"){
			// one of the operands equal to zero
			if(split[0] == "0" || split[2] == "0"){
				display(split, "0");
			}
			else{
				display(split, multiply(split[0], split[2]));
			}
		}
		else if(split[1] == "+"){
			display(split, add(split[0], split[2]));
		}
		else{
			display(split, subtract(split[0], split[2]));
		}
		printf("\n");
	}
    return 0;
}