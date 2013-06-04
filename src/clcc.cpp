#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
#include <string.h>
using namespace std;

#include "clSystem/system.h"



int main(int argc,char* argv[])
{
  if(argc <= 1)
  {
    cout << "brak plikow do kompilacji - koncze ;)" << endl;
    exit(0);
  }
  clSystem system;
  if(!system)
  {
    cerr << "Blad tworzenia clSystem!!" << endl;
    exit(1);
  }
  
  char input_file[200];
  char input_file2[200];
  char output_file[200];
  strcpy(input_file,argv[1]);
  strcpy(output_file,argv[1]);
  strcpy(input_file2,argv[1]);
  strcat(input_file2,".2");
  strcat(output_file,"bin");
  
  for(int i=2;i<argc;i++)
  {
    if( !strcmp(argv[i],"-o") )
    {
      if( i+1 >= argc )
      {
	cout << "Brak nazwy pliku po opcji -o!!!\n";
	exit(1);
      }
      i++;
      strcpy(output_file,argv[i]);
    }
  } 
  int pid;
  if(!( pid = fork() ))
     execl("script/include.sh", "include.sh", input_file, (char*) 0);
  else
    {
      wait(&pid);
    }
  cl_program program = CreateProgram(system.getContext(),system.getDevice(), input_file2);
  if( !program )
    exit(1);
  SaveProgramBinary(program,system.getDevice(),output_file);
}
