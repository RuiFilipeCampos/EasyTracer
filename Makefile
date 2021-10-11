all:
	g++ -Iexternal/src/include -Lexternal/src/lib -o EasyTracer_WIN src/main.c src/tracer.c src/primitives.c src/types.c -lmingw32 -l:libSDL2main.a -l:libSDL2.dll.a 
