
sales.exe: coffee_shop.c calculations.c
	gcc -Wall coffee_shop.c calculations.c -o sales.exe

clean:
	del -f coffee_shop.o calculations.o sales.exe 