//#include "shell.h"
#include <vector>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sstream>
using namespace std;
// ~~~~~ from video ~~~~~~
char** vec_to_char_array (vector<string>& parts){
	char ** result = new char* [parts.size()+1]; //add 1 to nullptr at the end
	for(int i = 0; i<parts.size(); i++){
		result[i] = (char*) parts [i].c_str();
	}
	result[parts.size()]=NULL;
	return result;
}

// ~~~~~ from video ~~~~~~
string trim (string input){
   int i = 0;
	while (i < input.size() && input[i] == ' '){
		i++;
		if(i < input.size())
			input = input.substr(i);
		else
			return "";
	}
	
	i = input.size() - 1;
	while (i>=0 && input[i] == ' ')
		i--;
	if (i>=0)
		input = input.substr(0, i+1);
	else
		return "";
		
	return input;
}

vector <string> split(string inputline, char splitChar = ' '){////
    string temp;
    stringstream il(inputline);
    vector<string> inputs;
    while (getline(il, temp, splitChar)) {
        inputs.push_back(temp);
    }
    return inputs;
}

int main(){
	vector<int> bgs;
	char carray[50];
	//string oldd = "";
	string curd = getcwd(carray, sizeof(carray));
	//char path[50];
	string username = getenv("USER");
	time_t t = time(0);
	char* time = ctime(&t);
	
	// Troubleshooting from campuswire
	int in_def = dup(0);
	int out_def = dup(1);

  
	cout<< "Ryley's Shell"<< endl; //print a prompt
	while (true){
		dup2(in_def, 0);
		dup2(out_def, 1);
	// ~~~~~ from video ~~~~~~
		for (int i=0; i<bgs.size(); i++){ //preemptive check for background processes
			//waitpid(bgs[i], 0, 0); //blocking wait
			if (waitpid (bgs[i], 0, WNOHANG) == bgs[i]){
				cout << "Process: " << bgs[i]<< " ended" <<endl;
				bgs.erase(bgs.begin()+i); 
				i--; // keeps i at the same spot
			}
		}
		
		cout << time << username << "$  ";// print prompt
		
		string inputline; 
		getline (cin, inputline); //get a inputline from standard input

		if (inputline == string("exit")){
			cout << "Adios amigo!! End of shell" <<endl;
			break;
		}
		
		// could not get the other functions in CD to work, so right now it just prints the current dir
		if(inputline[0]=='c'){////
			if(inputline[1]=='d'){
		    	//string cd = trim(split(inputs[i],' ')[1]);
				//if (cd == "-")
				//	chdir(oldd.c_str());
				//else if(cd [0] == '/')
				//	chdir(cd.c_str());
				//oldd = curd;
				curd = getcwd(carray, sizeof(carray));
				cout << curd << endl;
				}
			}
				

				
		// ~~~~~ from video ~~~~~~
		vector <string> inputs = split(inputline, '|'); /// inputs def
		for (int i = 0; i < inputs.size(); i++){

			bool bg = false;
			//string oinputline = inputline;
			//inputline = trim(inputline);
			//cout << inputline << endl;
			
			//cout << inputs[i] << endl;
			
				if((inputline)[inputline.size()-1] == '&'){
					//cout << "Background Process Found" <<endl;
					bg = true;
					inputs[i] = inputs[i].substr(0, inputs[i].size()-1);
					//inputline = trim(inputline);
					
					dup2(1,10); ////
				}
			
			inputs[i] = trim(inputs[i]);
			int fds[2]; 
		 	pipe(fds);
		 	
			int pid = fork();
			if (pid == 0) { // if child process
				if (i < inputs.size()-1){
        			dup2(fds[1],1);
        			//close(fds[1]);
        		}
			

				

          // Start of solo implementation of File I/O Redirection
      		int redirection = inputs[i].find('>');
			if(redirection >= 0){
				string arg = trim(inputs[i].substr(0,redirection));
				string filename = trim(inputs[i].substr(redirection+1));
				inputs[i] = arg;
				int fd = open(filename.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				dup2(fd,1);
				}
			redirection = inputs[i].find('<');
 			if(redirection >= 0){
				string arg = trim(inputs[i].substr(0,redirection));
				string filename = trim(inputs[i].substr(redirection+1));
				inputs[i] = arg;
				int fd = open(filename.c_str(), O_RDONLY, S_IWUSR|S_IRUSR);
				dup2(fd,0);
			}
			if (i < inputs.size()-1)
				dup2(fds[1],1);  
						
				
			vector <string> parts = split(trim(inputs[i]));
			char** args = vec_to_char_array(parts);
			execvp (args [0], args);

		                

			}
				// ~~~~~ from video ~~~~~~
		else{ // if parent
			dup2(fds[0],0);
		    close(fds[1]);
			if(!bg)
				waitpid(pid, 0, 0); // parent will wait for child
			else{
				bgs.push_back(pid);
				}
			}
		}
	}
}
