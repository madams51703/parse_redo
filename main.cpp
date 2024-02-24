#include <iostream>
#include <fstream>
#include <antlr4-runtime/antlr4-runtime.h>
#include <getopt.h>

#define no_argument 0
#define required_argument 1 
#define optional_argument 2

#include "RedoLexer.h"
#include "RedoParser.h"
#include "RedoWalker.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[]) {
	string line;
        char raw_redo_file[5000]="NONE";
        char input_file[5000]="/dev/stdin";
        int enable_raw_redo=0;
        int print_option=0;
        int column_of_interest=-1;
const struct option longopts[] =
  {
    {"show-all-changes",      required_argument,        0, 's'},
    {"raw-redo",      required_argument,        0, 'r'},
    {"file",     required_argument,  0, 'f'},
    {"column-of-interest",     required_argument,  0, 'c'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;

  //turn off getopt error message
  opterr=1; 

  while(iarg != -1)
  {
    iarg = getopt_long(argc, argv, "c:f:r:s:", longopts, &index);

    switch (iarg)
    {
      case 'c':
        column_of_interest=atoi(optarg);
        break;

      case 'r':
        enable_raw_redo=1;
	strcpy(raw_redo_file,optarg);
        break;

      case 'f':
	strcpy(input_file,optarg);
        break;

      case 's':
        if (strcmp(optarg,"DISPLAY_ALL") == 0 )
        {
		print_option=1;
        }
        else if ( strcmp(optarg,"DIRECT_LOADER") == 0)
        {
		print_option=2;
	}
        break;

    }
  }

	ifstream RedoParserFile (input_file);
	if (RedoParserFile.is_open()) {
		ANTLRInputStream input(RedoParserFile);
		RedoLexer lexer(&input);
		CommonTokenStream tokens(&lexer);
/*
		tokens.fill();
		for (auto token : tokens.getTokens()) {
			std::cout << token->toString() << std::endl;
		}
*/

		RedoParser parser(&tokens);



		antlr4::tree::ParseTreeWalker walker;	
		antlr4::ParserRuleContext* redo_file = parser.redo_file();
 		RedoWalker * listener = new RedoWalker();		
                strcpy(listener->raw_redo_log_name , raw_redo_file);
                listener->enable_raw_redo = enable_raw_redo;
                listener->print_option = print_option;
               	listener->column_of_interest = column_of_interest;
  		walker.walk(listener, redo_file);
		RedoParserFile.close();
	}
}
