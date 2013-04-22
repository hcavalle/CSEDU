#include <iostream>
#include <string>
#include <fstream>
#include <locale> //for ispunct
#include <sstream> //for stringstream
#include <cctype> //for toupper, tolower

using namespace std;

//prototypes
bool firstIsVowel(char first, const string VOWEL){
	for (size_t j = 0; j < (VOWEL.length()-1); j++){
		//cout<<"Length is: "<<VOWEL.length() <<endl;
		//cout<<"J is: " <<j<<endl;
				if(first == VOWEL[j]){
					return true;
				}
	}
	return false;
}

int main(){
	//vars
	ifstream inFile;
	ofstream outFile;
	string filename;
	string inLine;
	//string outline;
	string PUNC = "\"!\'";
	string UPPER;
	const string VOWEL = "aeiouAEIOU";

	//loop for in and out files
	do{
		cout<<"Enter input file name: ";
		cin >> filename;
		inFile.open(filename);
	}while (inFile.fail());

	do{
		cout<<"Enter output file name: ";
		cin >> filename;
		outFile.open(filename);
	}while (outFile.fail());
	string a = " ";
	
	while(!inFile.eof()){
		//readline
		getline(inFile,inLine); //sets char delim to ' '
		string inWord;
		stringstream ss(inLine); //makes the inLine into a stream so we can read individual strings from it
		
		
		//readword from read line
		while (getline(ss, inWord, ' ')){ //sets char delim to ' '
			size_t i = 0;
			//translate to pig latin
			// this might be a better loop solution: http://www.cplusplus.com/forum/beginner/12207/
			string endPig = "ay";
			cout<<"Current word is:"<<inWord<<endl;
			while (ispunct(inWord[i])){
				cout<<"Current char is punct and is"<<inWord[i]<<endl;
				i++;
			}
			
			//if (inWord[i] is vowel) //ex: test_(lower.find_first_of(UPPER) == string::npos); //but change to if vowels
			if (firstIsVowel(inWord[i], VOWEL)){
				endPig = "way";
			}
				
			//if (inWord[i] is consonant) //ex: test_(lower.find_first_of(UPPER) == string::npos); //but change to if !vowels
			else{
				
				//inWord.erase(i);
				if (isupper(inWord[i])){
					cout <<"Char is caps and is: " <<inWord[i]<<endl;
					cout<<"Second Char is lower and is: "<< inWord[i+1]<<endl;
					inWord[i+1]=toupper(inWord[i+1]);
					inWord[i]=tolower(inWord[i]);
					cout <<"Second char is now upper too is: "<< inWord[i+1]<<endl;
					
				}
				endPig = inWord.at(i) + endPig;
				cout << "End pig is:" << endPig<<endl;
				if (i == 0){
					inWord.erase(i, i);
				}
				inWord.erase(i, 1);
			}//end consonant else
			
			//check for punc at end, append pigEnd
			
			int k = 1;
			while (ispunct(inWord[inWord.length()-k])){ //change to for loop that checks length minus j while j == punct 
				cout<<"Last char is punct and is: " <<inWord[inWord.length()-k]<<endl;
				k++;
			}
			k--;
			
			//inWord = inWord.insert((inWord.length()-k), endPig);//inserts endPig before end punc
			if (k>=1){
			inWord = inWord.insert((inWord.length() -k), endPig);//inserts endPig before end punc
			cout<<"Pig inserted before end punct char: "<< inWord<<endl;
			}
			
			else{
				inWord = inWord.insert((inWord.length()), endPig);
			}
			
			
			
			//else{	
				//inWord.insert((inWord.length()-k), endPig);
			//}
			
			
			
			/*if (ispunct(inLine[inLine.length() - 1]){
					inWord.append(inLine.length()-1, endPig)
			}
			else{
				.length-2
			} */
		
			//write line
			cout<<"Writing inWord to outfile: "<<inWord<<endl;
			outFile << inWord<<" ";
		}
		outFile << "\n";
	}
	
	
}