#include<iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <math.h>
using namespace std;

int main()
{	setlocale(LC_ALL,"Russian"); 

	ifstream inputFile("input.txt",ios_base::binary|ios_base::in);
	ifstream cipherFile("cipher.txt",ios_base::in);
	
	char temp_read, decimal_string[1000], bynary_string[1000], bynary_string2[1000]={'\0'}, cipher_letter, decipher[1000], decipher1[10], ansver;
	int first_iterator=-1, array[1000], second_iterator, third_iterator=-1, size_array[1000], decipher_temp, decipher_array[1000], add_temp;
	string additional_string, cipher_string,cipher_string2, cipher_string3;
	
	while(!inputFile.eof())			//получаем с файла десятичные числа
	{	first_iterator++;
		inputFile.read((char*)&temp_read,sizeof(char));
		array[first_iterator]=int(temp_read)-48;
		itoa(array[first_iterator],decimal_string,10);
		second_iterator=first_iterator;
	}
	
	for (int i=0;i<=second_iterator-1;i++)			//перевод в двоичные числа
	{	itoa(array[i],bynary_string,2);	
		strcat(bynary_string2,bynary_string);
		third_iterator++;
		size_array[third_iterator]=strlen(bynary_string);
	}
	cout<<"Зашифрованный двоичный код: ";
	for (int j=0;j<strlen(bynary_string2);j++)			
	{	additional_string+=bynary_string2[j];
		if (additional_string.size()==8)
		{	while(!cipherFile.eof())			//нахождение соответствий в файле с шифром
			{	getline(cipherFile,cipher_string);
				cipher_letter=cipher_string[9];
				cipher_string.erase(8,2);
				if (cipher_string==additional_string) 
				{	cout<<cipher_letter;
					cipher_string2+=cipher_letter;
				}
			}
		cipherFile.seekg(ios::beg);
		additional_string.clear();
		}
	}
	cout<<endl;

	for(int i=0;i<=cipher_string2.size();i++)
	{	cipher_letter=cipher_string2[i];
		while(!cipherFile.eof())
			{	getline(cipherFile,cipher_string);
				if (cipher_string[9]==cipher_letter) 
				{	cipher_string.erase(8,2);
					cipher_string3+=cipher_string;
				}
			}
		cipherFile.seekg(ios::beg);
		additional_string.clear();
	}
	cout<<"Сделать дешифровку(y/n)?\n";
	cin>>ansver;
	if (ansver=='y' || ansver=='Y')
	{	cout<<"Дешифровка: ";
		for(int i=0;i<=third_iterator;i++)
		{	strncpy(decipher,cipher_string3.c_str(),size_array[i]);
			cipher_string3.erase(0,size_array[i]);
			decipher_temp=0;
			for(int j=0;j<size_array[i];j++)
			{
				decipher1[0]=decipher[j];
				if (decipher1[0]!='0') decipher_temp+=atoi(decipher1)*pow(2,(size_array[i]-1-j));
			}
			decipher_array[i]=decipher_temp;
			cout<<decipher_array[i];
		}
	}
	
	inputFile.close();
	cipherFile.close();
	
	getch();
	return 0;
}

