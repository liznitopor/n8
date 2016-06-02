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
	
	while(!inputFile.eof())			//ïîëó÷àåì ñ ôàéëà äåñÿòè÷íûå ÷èñëà
	{	first_iterator++;
		inputFile.read((char*)&temp_read,sizeof(char));
		array[first_iterator]=int(temp_read)-48;
		itoa(array[first_iterator],decimal_string,10);
		second_iterator=first_iterator;
	}
	
	for (int i=0;i<=second_iterator-1;i++)			//ïåðåâîä â äâîè÷íûå ÷èñëà
	{	itoa(array[i],bynary_string,2);	
		strcat(bynary_string2,bynary_string);
		third_iterator++;
		size_array[third_iterator]=strlen(bynary_string);
	}
	cout<<"Çàøèôðîâàííûé äâîè÷íûé êîä: ";
	for (int j=0;j<strlen(bynary_string2);j++)			
	{	additional_string+=bynary_string2[j];
		if (additional_string.size()==8)
		{	while(!cipherFile.eof())			//íàõîæäåíèå ñîîòâåòñòâèé â ôàéëå ñ øèôðîì
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
	//Alex Birukov
			cout <<endl<< "Length: "<<cipher_string2.length()<<endl;
		int row, col, mas_col[100], mas_row[100], kol_col=0, kol_row=0;//çàäàëè ñòðîêèè ñòîëáöû
		char **mas_ciph;
		string slovo1, slovo2;
		
		cin>>slovo1>>slovo2;//ââåëè ñòðîêè è ñòîëáöû
		row=slovo2.size();
		col=slovo1.size();
		mas_ciph=new char*[row+1];//ñäåëàëè äèíàìèåñêèé ìàññèâ
		for(int i=0;i<row+1;i++)
			mas_ciph[i]=new char [col+1];
		
		for(int i=1;i<col+1;i++)
			mas_ciph[0][i]=slovo1[i-1];
			
		for(int i=1;i<row+1;i++)
			mas_ciph[i][0]=slovo2[i-1];
		mas_ciph[0][0]=' ';
		int add_c=0;	
		for(int i=1;i<row+1;i++){
			for(int j=1;j<col+1;j++){
				mas_ciph[i][j]=cipher_string2[add_c];
				add_c++;
			}
		}

		for(int i=1;i<col;i++){
			if(mas_ciph[0][i]>mas_ciph[0][i+1]){
				for(int j=0;j<row+1;j++){
					swap(mas_ciph[j][i],mas_ciph[j][i+1]);
				}
				mas_col[kol_col]=i;
				kol_col++;
				i=0;
			}
		}
		for(int i=1;i<row;i++){
			if(mas_ciph[i][0]>mas_ciph[i+1][0]){
				for(int j=0;j<col+1;j++){
					swap(mas_ciph[i][j],mas_ciph[i+1][j]);
				}
				mas_row[kol_row]=i;
				kol_row++;
				i=0;
			}
		}
		for(int i=0;i<row+1;i++){
			for(int j=0;j<col+1;j++){
				cout<<mas_ciph[i][j];
			}
			cout<<endl;
		}
	cout<<endl;
		for(int i=kol_col-1;i!=-1;i--){
			for(int j=0;j<row+1;j++){
				swap(mas_ciph[j][mas_col[i]],mas_ciph[j][mas_col[i]+1]);
			}
		}
		for(int i=kol_row-1;i!=-1;i--){
			for(int j=0;j<col+1;j++){
				swap(mas_ciph[mas_row[i]][j],mas_ciph[mas_row[i]+1][j]);
			}
		}	
		for(int i=0;i<row+1;i++){
			for(int j=0;j<col+1;j++){
				cout<<mas_ciph[i][j];
			}
			cout<<endl;
		}
		add_c=0;
		for(int i=1;i<row+1;i++){
			for(int j=1;j<col+1;j++){
				cipher_string2[add_c]=mas_ciph[i][j];
				add_c++;
			}
		}
		cout<<cipher_string2;
	//end Alex Birukov
	cout<<"Ñäåëàòü äåøèôðîâêó(y/n)?\n";
	cin>>ansver;
	if (ansver=='y' || ansver=='Y')
	{	cout<<"Äåøèôðîâêà: ";
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

