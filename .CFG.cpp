#include<bits/stdc++.h>
using namespace std;

bool pro_A(string& s, int& index, string& derivation);
bool pro_B(string& s, int& index, string& derivation);
string derivation2;

bool pro_S(string& s, int& index, string& derivation) {
    int start_index = index;
    string A_derivation, B_derivation;

    if (pro_A(s, index, A_derivation) && s[index] == '1' && pro_B(s, index, B_derivation)) {
        derivation += "S => A1B\n";
        derivation += A_derivation;
        derivation += B_derivation;
       // derivation2 += derivation;
        return true;
    } else {
        index = start_index;
        return false;
    }
}

bool pro_A(string& s, int& index, string& derivation) {
    int start_index = index;
    string A_derivation;

    if (s[index] == '0') {
        index++;
        if (pro_A(s, index, A_derivation)) {
            derivation += "A => 0A\n";
            derivation += A_derivation;
            //derivation2 += derivation;
            //derivation2 +=  "0A1B\n";
            return true;
        } else {
            index = start_index + 1;
            return false;
        }
    } else {
        derivation += "A => e\n";
        //derivation2 +="e";
        return true;
    }
}

bool pro_B(string& s, int& index, string& derivation) {
    int start_index = index;
    string B_derivation;

    if (s[index] == '0') {
        index++;
        if (pro_B(s, index, B_derivation)) {
            derivation += "B => 0B\n";
            //derivation2 +="0B";
            derivation += B_derivation;
            return true;
        } else {
            index = start_index + 1;
            return false;
        }
    } else if (s[index] == '1') {
        index++;
        if (pro_B(s,index, B_derivation)) {
            derivation += "B => 1B\n";
            //derivation2 +="1B";
            derivation += B_derivation;
            return true;
        } else {
            index = start_index + 1;
            return false;
        }
    } else {
        derivation += "B => e\n";
        //derivation2 += "e";
        return true;
    }
}

int main() {
    string s;
    cout<<"Given Grammer is :"<<endl;
    cout<<"S -> A1B "<<endl;
    cout<<"A -> 0A|e"<<endl;
    cout<<"B -> 0B|1B|e"<<endl;
    cout << endl<< "Enter a string: ";
    cin >> s;

    int index = 0;
    string derivation;
    if (pro_S(s,index, derivation) && index == s.length()) {
        cout << "String is accepted." << endl;
        cout << "Leftmost derivation:\n" << derivation << endl;
        //cout<<"\n New :"<<derivation2<<endl;
    } else {
        cout << "String is not accepted." << endl;
    }

    return 0;
}
