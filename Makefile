Ordonnancement:	Ordonancement.c Main.c Ordonancement.h 
	gcc -o Ordonancement Main.c Ordonancement.c  
run :Ordonancement
	./Ordonancement  process.txt
clean :
	run Ordonancement  process.txt
