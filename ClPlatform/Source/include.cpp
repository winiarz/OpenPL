#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <sstream>
#include "logs.hpp"

using namespace std;
void findInclude(const char[],ofstream*,set<string>&);

void findInclude(const char inputFile[],const char outputFile[],set<string>& includeDirectories)
{
	ofstream output(outputFile);
	findInclude(inputFile,&output,includeDirectories);
	output.close();
}

void findInclude(const char inputFile[],ofstream* output,set<string>& includeDirectories)
{
	ifstream input;
	for(set<string>::iterator i=includeDirectories.begin(); i!= includeDirectories.end(); i++)
	{
	  ostringstream fileNameStream;
	  fileNameStream << (*i) << "/" << inputFile;
	  string fileName = fileNameStream.str();
	  input.open( fileName.c_str() , ios::in);
	  if( input.is_open() )
	    break;
	}
	if(!input.is_open())
	{
        ERROR << "can't find file '" << inputFile << "'";
        ERROR << "include directiories are:";
        for(set<string>::iterator i=includeDirectories.begin(); i!= includeDirectories.end(); i++)
        {
            ERROR << " ------ " << (*i);
        }

        (*output) << "Can't find file " << inputFile << "\n";
	}
	string line;
	while(getline(input,line))
	{
		if((line.size()>7)&&(line[0] == '#')&&(line[1]=='i')&&(line[2]=='n')&&(line[3]=='c')&&(line[4]=='l')&&(line[5]=='u')&&(line[6]=='d')&&(line[7]=='e'))
		{
			int i=8;
			while(line[i] != '"') i++;
			char includeFileName[100];
			i++;
			int j=0;
			while(line[i] != '"')
			{
				includeFileName[j] = line[i];
				i++; j++;
			}
			includeFileName[j] = 0;
			findInclude(includeFileName,output,includeDirectories);
		}
		else
		{
			(*output) << line << endl;
		}
	}
	input.close();
}
