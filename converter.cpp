#include <iostream>
#include <string>

using namespace std;

string convertFromDec(unsigned int decnum, unsigned int base);

int main(){
    string input;
    string binary;
    string octal;
    string hex;

    int numInput(0);

    do{
        cout << "Enter positive decimal number (anything else quits): ";
        cin >> input;

        for(int i(0); i < input.size(); i++){
            if(isdigit(input[i]) == 1){
                continue;
            }
            else{
                return 0;
            }
        }

        numInput = stoi(input);

        if(numInput > 0){
            binary = convertFromDec(numInput, 2);
            octal = convertFromDec(numInput, 8);
            hex = convertFromDec(numInput, 16);

            cout << numInput << " in binary is: " << binary << endl;
            cout << numInput << " in octal is: " << octal  << endl;
            cout << numInput << " in hex is: " << hex << endl << endl;
        }
    }while(numInput > 0);
    
    return 0;
}

string convertFromDec(unsigned int decnum, unsigned int base){
    string result;
    string temp;
    int remainder(0);

    if(base == 2){
        while(decnum > 0){
            remainder = decnum % 2;
            decnum = decnum / 2;
            temp = to_string(remainder);
            result = temp + result;
        }
    }
    if(base == 8){
        while(decnum > 0){
            remainder = decnum % 8;
            decnum = decnum / 8;
            temp = to_string(remainder);
            result = temp + result;
        }
    }
    if(base == 16){
        while(decnum > 0){
            remainder = decnum % 16;
            decnum = decnum / 16;
            temp = to_string(remainder);
            if(remainder == 10){
                temp = "A";
            }
            else if(remainder == 11){
                temp = "B";
            }
            else if(remainder == 12){
                temp = "C";
            }
            else if(remainder == 13){
                temp = "D";
            }
            else if(remainder == 14){
                temp = "E";
            }
            else if(remainder == 15){
                temp = "F";
            }
            else{
                temp = to_string(remainder);
            }
            result = temp + result;
        }
    }
    return result;
}