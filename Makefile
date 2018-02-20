
JAVA=/usr/bin/java
OUTPUT=output
GENERATED=generated
GRAMMAR=RedoParser.g4

# here is where you plug in the runtime for your OS
RUNTIME=/usr/local/antlr4_cpp_runtime/usr/local
CC=g++
CCARGS=-c -I $(RUNTIME)/include/antlr4-runtime/ -I $(GENERATED) -std=c++11	
LDARGS=-g
LIBS=$(RUNTIME)/lib/libantlr4-runtime.a

all: hello

hello: dirs antlr4 hello.cpp
	$(CC) $(CCARGS) hello.cpp  -o $(OUTPUT)/hello.o 
	$(CC) $(CCARGS) $(GENERATED)/RedoParserBaseListener.cpp -o $(OUTPUT)/RedoParserBaseListener.o 
	$(CC) $(CCARGS) $(GENERATED)/RedoLexer.cpp -o $(OUTPUT)/RedoLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/RedoParserListener.cpp -o $(OUTPUT)/RedoParserListener.o 
	$(CC) $(CCARGS) $(GENERATED)/RedoParser.cpp -o $(OUTPUT)/RedoParser.o 
	$(CC) $(LDARGS) $(OUTPUT)/hello.o $(OUTPUT)/RedoParserBaseListener.o $(OUTPUT)/RedoLexer.o $(OUTPUT)/RedoParserListener.o $(OUTPUT)/RedoParser.o $(LIBS) -o hello

antlr4: $(GRAMMAR)
	$(JAVA) -jar antlr-4.7.1-complete.jar -Dlanguage=Cpp -o $(GENERATED) $(GRAMMAR)



dirs:
	mkdir -p $(OUTPUT) 
	mkdir -p $(GENERATED) 

clean:
	rm -rf $(OUTPUT)
	rm -rf $(GENERATED)

