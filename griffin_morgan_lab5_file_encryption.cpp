/*
Griffin Morgan
CSC 102L Spring 2022
Lab 5
*/

#include <iostream>
#include <string>
#include "griffin_morgan_lab5_file_encryption.h"

using namespace std;

int main()
{
	Encrypter c(15); //Try it with 15 first.
	string msg1 = "Somebody once told me";
	string msg2 = "iwt ldgas xh vdccp gdaa bt";
	string encmsg = "";
	string decmsg = "";

	c.encrypt(msg1, encmsg);
	c.decrypt(msg2, decmsg);

	cout << "First Statement: " << msg1 << endl;
	cout << "Encrypted---> " << encmsg << endl;
	cout << "2nd Statement: " << msg2 << endl;
	cout << "Decrypted---> " << decmsg << endl;

	return 0;
}