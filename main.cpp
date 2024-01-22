#include <iostream>
#include <fstream>
#include <antlr4-runtime/antlr4-runtime.h>

#include "RedoLexer.h"
#include "RedoParser.h"
#include "RedoWalker.h"

using namespace antlr4;
using namespace std;

int main(int argc, char *argv[]) {
	string line;
	ifstream RedoParserFile (argv[1]);
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
  		walker.walk(listener, redo_file);
		RedoParserFile.close();
	}
}
