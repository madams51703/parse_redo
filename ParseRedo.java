import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CaseChangingCharStream;
import java.nio.file.Path;
import java.nio.file.Paths;

public class ParseRedo {
  public static void main( String[] args) throws Exception
  {
    CharStream stream = CharStreams.fromFileName(args[0] );
    CaseChangingCharStream upper = new CaseChangingCharStream(stream, true);
    
    RedoLexer lexer = new RedoLexer( upper );

    CommonTokenStream tokens = new CommonTokenStream( lexer );
    RedoParser parser = new RedoParser( tokens );
    ParseTree tree = parser.redo_file();
    ParseTreeWalker walker = new ParseTreeWalker();
    walker.walk( new RedoWalker(), tree );
  }
}

