java -jar ./antlr-4.13.1-complete.jar  RedoParser.g4 RedoLexer.g4 -Dlanguage=Cpp 
g++ -I /usr/local/include/antlr4-runtime RedoWalker.cpp RedoLexer.cpp RedoParser.cpp main.cpp -I . -L/usr/local/lib64  -lstdc++ -lantlr4-runtime
