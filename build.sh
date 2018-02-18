antlr RedoParser.g4 RedoLexer.g4
javac -cp /home/mark/antlr-4.7.1-complete.jar:.:./org/antlr/v4/runtime *.java
cp CaseChangingCharStream.class ./org/antlr/v4/runtime/.
jar -cvf redo.jar *.class ./org/antlr/v4/runtime/*.class
rm *.class 
rm ./org/antlr/v4/runtime/*.class
