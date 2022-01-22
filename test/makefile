


link: compile
	g++ -o build/exe/main.exe build/obj/main.o



asseble: compile
	g++ -o build/obj/main.o build/ss/main.ss

compile: pre_process
	g++ -S build/pp/main.i -o build/ss/main.ss
	
pre_process:
	g++ -E src/main.cpp -o build/pp/main.i
