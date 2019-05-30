mkdir -p ./org/antlr/v4/runtime/
java -jar ./antlr4-4.7.3-complete.jar RedoParser.g4 RedoLexer.g4

javac -cp ./antlr4-4.7.3-complete.jar:./org/antlr/v4/runtime *.java
cp CaseChangingCharStream.class ./org/antlr/v4/runtime/.
jar -cvf redo.jar *.class ./org/antlr/v4/runtime/*.class
rm *.class 
rm ./org/antlr/v4/runtime/*.class
