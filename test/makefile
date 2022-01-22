


link: assemble
	g++ build/obj/main.o -o build/exe/main.exe 



assemble: compile
	g++ -c build/ss/main.s -o build/obj/main.o

compile: pre_process
	g++ -S build/pp/main.i -o build/ss/main.s
	
pre_process:
	g++ -E src/main.cpp -o build/pp/main.i
