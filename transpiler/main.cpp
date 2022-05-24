#include "StolenFromStackOverflow.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
int main(){

	std::vector<std::string> scriptlines; // This is the vector that will contain the ENTIRETY of your code(besides comments)
	std::vector<std::string> cppcode; // This will contain EVERY SINGLE LINE of your transpiled code.
	std::string file;
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
		file = filename;
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
		scriptfile.close();
	}
	/*
	 * Parser.
	 * Tasks:
	 * - Read the code
	 * - Translate it to C++
	 * - Detect bad grammar(which Twitter stans can't do)
	 *
	 * */
	{
		std::cout << "If the transpiler has made it here, the preparser should have worked properly. Now, the transpiler will parse your Applejuice and transform it to C++. If code requires GUI, raylib will be called.\n";
		
		for(int i = 0; i < scriptlines.size(); i++){
			std::string temp;
			if(scriptlines.at(i).rfind("db", 0) == 0){ 
				scriptlines.at(i).erase(0, 3);
				//scriptlines.at(i).pop_back();
				temp = "std::string " + scriptlines.at(i);
				cppcode.push_back(temp);
			} 
			if(hasEnding(scriptlines.at(i), ".conwrite;")){
				scriptlines.at(i).resize(scriptlines.at(i).size()-10);
				temp = "std::cout << " + scriptlines.at(i) + ";";
				cppcode.push_back(temp);
			}

		}

	}
	/*
	 * Writer.
	 * Tasks:
	 * - Write the C++ code to a file
	 * - That's about it.*/
	{
		std::cout << "Now, the code is being written to a C++ file.\n";
		std::ofstream convertedfile;
		convertedfile.open({file + ".cpp"});
		convertedfile << "#include <iostream>\n#include <string.h>\n\nint main(){\n";
		std::cout << "Wrote first part of boilerplate. Now writing transpiled code\n";
		for(int i = 0; i < cppcode.size(); i++){
			printf("Writing line %i\n", i);
			convertedfile << cppcode.at(i) + "\n";
			printf("Wrote line %i\n", i);
		}
		std::cout << "Wrote transpiled code. Now writing second part of boilerplate.\n";
		convertedfile << "}\n/* This code was generated by Applejuice's transpiler. https://github.com/Safariminer/Applejuice */";
		std::cout << "Wrote everything. Thanks for using the Applejuice programming language!\n\n";
	}
	return 0;
}
