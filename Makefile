make:
	g++ -c Snake/cpp/*.cpp
	g++ *.o -o Build/Snake-app -lsfml-graphics -lsfml-window -lsfml-system
	rm *.o

clean:
	rm *.o Build/Snake-app