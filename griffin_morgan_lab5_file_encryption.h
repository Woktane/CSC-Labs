#pragma once
#pragma once
#include <string>
#include <cctype>

using std::islower;
using std::isupper;
using std::string;

class Encrypter
{
private:
	const string alpha_lower = "abcdefghijklmnopqrstuvwxyz";
	const string alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	char shift_char(char c, bool encrypt)
	{
		int original_index, shift_index{};

		const string* alpha_set;

		if (islower(c))
		{
			original_index = get_alpha_index(c, false);
			alpha_set = &alpha_lower;
		}

		else if (isupper(c))
		{
			original_index = get_alpha_index(c, true);
			alpha_set = &alpha_upper;
		}

		else
			return c;

		int new_index;
		int size;

		if (encrypt == true)
		{
			new_index = original_index + shift_index;
			size = alpha_set->size();
		}

		else
		{
			new_index = original_index - shift_index;
			size = alpha_set->size();
		}

		if (new_index >= size)
			shift_index = (new_index - alpha_set->size()) % alpha_set->size();
		else if (new_index < 0)
			shift_index = (new_index + alpha_set->size()) % alpha_set->size();
		else
			shift_index = new_index % alpha_set->size();

		return (*(alpha_set))[shift_index];
	}

	int get_alpha_index(char c, bool shift)
	{
		const string* alpha_set;

		if (shift == true)
			alpha_set = &alpha_upper;
		else
			alpha_set = &alpha_lower;

		for (int i = 0; i < alpha_set->size(); i++)
		{
			if (c == (*(alpha_set))[i])
				return i;
		}

		return -1;
	}


public:

	char* std_alphabet;
	char* c_alphabet;

	Encrypter(int shift = 0)
	{
		std_alphabet = new char[27];
		c_alphabet = new char[27];

		for (int i = 0; i < 26; i++)
			std_alphabet[i] = ('a' + i);
			std_alphabet[26] = '\0';

		for (int i = 0; i < 26; i++)
				c_alphabet[i] = std_alphabet[(i + shift) % 26];
				c_alphabet[26] = '\0';
	}
	int encrypt(const string& msg, string& encmsg)
	{
		for (int i = 0; i < msg.length(); i++)
		{
			if (msg[i] == ' ' || msg[i] == '.')
				encmsg += msg[i];
			else
			{
				char c = msg[i];
				int a = c - 'a';
				encmsg += c_alphabet[a];
			}
		}
		return msg.length();
	}
	int decrypt(const string& msg, string& decmsg)
	{
		int shift = 0;
		while (std_alphabet[shift] != c_alphabet[0])
			shift++;
		for (int i = 0; i < msg.length(); i++)
		{
			if (msg[i] == ' ' || msg[i] == '.')
				decmsg += msg[i];
			else
			{
				char c = msg[i];
				int a = c - 'a';
				decmsg += std_alphabet[(a - shift + 26) % 26];
				
			}
		}
		return msg.length();
	}
};