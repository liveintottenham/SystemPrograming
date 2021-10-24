OBJS = divide.o add.o subtract.o multiply.o
staticout : staticlib.a
	cd..; gcc -I./lib -L./lib main.c lib/$^ -o $@
divide.o : divide.c
	gcc -c -fPIC $<
add.o : add.c
	gcc -c $<
subtract.o : subtract.c
	gcc -c $<
multiply.o : multiply.c
	gcc -c $<
staticlib.a : $(OBJS)
	ar rcs $@ $^
clean :
	rm -f staticlib.a $(OBJS)
	cd..; rm staticout
