targets:
	echo anrlr grun

antlr:
	java -Xmx500M -cp deps/antlr-4.9.1-complete.jar org.antlr.v4.Tool -Dlanguage=Cpp -Werror -no-listener -visitor src/Tabs.g4

grun:
	java -Xmx500M -cp deps/antlr-4.9.1-complete.jar org.antlr.v4.Tool -Werror -o grun_src src/Tabs.g4
	cd grun_src/src && javac -cp ../../deps/antlr-4.9.1-complete.jar *.java
	cd grun_src/src && java -Xmx500M -cp .:../../deps/antlr-4.9.1-complete.jar org.antlr.v4.gui.TestRig Tabs tabs ../../samples/tabs.txt -tokens


