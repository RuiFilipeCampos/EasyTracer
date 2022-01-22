


link: compile
	g++ -o build/exe/main.exe build/obj/main.o
	echo "\n\n\n\n\n\n\n\n\n\n\n\n"
compile: pre_process
	g++ -o build/obj/main.o build/pp/main.i
	echo "\n\n\n\n\n\n\n\n\n\n\n\n"
pre_process:
	g++ -E src/main.cpp -o build/pp/main.i
	echo "\n\n\n\n\n\n\n\n\n\n\n\n"