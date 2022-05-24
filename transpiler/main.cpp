#include "StolenFromStackOverflow.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
int main(){

	std::vector<std::string> scriptlines; // This is the vector that will contain the ENTIRETY of your code(besides comments)
	

	/* Preparser.
	 * Tasks:
	 * - Read the file
	 * - Remove comments
	 * - Make sure every line ends with a semicolon
	 *
	 * Note: An Applejuice code line CANNOT END WITH A COMMENT */
	{
		std::cout << "Which Applejuice file do you want to transpile to C++? : ";
		std::string filename;
		std::cin >> filename;
		std::string currentline;
		std::ifstream scriptfile(filename);
		if(scriptfile.is_open()){
			int line = 0;
			while(getline(scriptfile, currentline)){
				line++;
				if(currentline.rfind("#", 0) == 0) std::cout << "Info: Glanced over a comment\n";
				else if(currentline == "") std::cout << "Info: Skipped empty line\n";
				else if(!hasEnding(currentline, ";") && currentline.length() > 1){
					//std::cout << "ERROR: LINE " + (std::string)line + " HAS NO SEMICOLON!\n";
					printf("ERROR: LINE %i HAS NO SEMICOLON!\n", line);
					return 1;
				}
				else{
					scriptlines.push_back(currentline);
				}
			}
			std::cout << "Lines kept:\n";
			for(int i = 0; i < scriptlines.size(); i++){
				std::cout << scriptlines.at(i) + "\n";
			}
		}
	}

}
