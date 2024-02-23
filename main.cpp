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

const struct option longopts[] =
  {
    {"raw-redo",      required_argument,        0, 'r'},
    {"file",     required_argument,  0, 'f'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;

  //turn off getopt error message
  opterr=1; 

  while(iarg != -1)
  {
    iarg = getopt_long(argc, argv, "f:r:", longopts, &index);

    switch (iarg)
    {
      case 'r':
        enable_raw_redo=1;
	strcpy(raw_redo_file,optarg);
        break;

      case 'f':
	strcpy(input_file,optarg);
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
  		walker.walk(listener, redo_file);
		RedoParserFile.close();
	}
}
