objects = main.o consume.o graph.o

ImperialMessagers : $(objects)
	gcc -o ImperialMessagers $(objects)
	
main.o : main.c
	gcc -c main.c
	
consume.o : consume.c
	gcc -c consume.c
	
graph.o : graph.c
	gcc -c graph.c
	
.PHONY : clean

clean :
	del ImperialMessagers $(objects) ImperialMessagers.exe