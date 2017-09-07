CC = g++
CFlags = -Wall -std=c++11
LIBHARU = -L'../libharu/src' -I'../libharu/include'
HTAGS = -lhpdfs -lz -lm

spiralPDF: HaruPDF.o Spiral.o spiralPDF.cpp
	$(CC) $(CFLAGS) -o spiralPDF Spiral.o HaruPDF.o spiralPDF.cpp $(LIBHARU) $(HTAGS)

HaruPDF.o: HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp -L$(LIBHARU) $(HTAGS)

Spiral.o: Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

clean:
	rm *.o *.~

test:
	./spiralPDF "This is a test, this is a test, this is a test"
