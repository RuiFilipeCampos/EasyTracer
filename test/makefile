


link: compile
	g++ -o build/exe/main.exe build/obj/main.o
	echo "\n\n\n\n\n\n\n\n\n\n\n\n"



compile: assemble
	g++ -o build/obj/main.o build/pp/main.ss

assemble: pre_process
	g++ -S build/pp/main.i -o build/ss/main.ss
	
pre_process:
	g++ -E src/main.cpp -o build/pp/main.i
