mvn clean antlr4:antlr4 install shade:shade
java -Xmx500M -cp "target/erable-1.0-SNAPSHOT.jar:$CLASSPATH" com.qiufeng.erable.Main $*