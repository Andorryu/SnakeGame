make:
	g++ -c Snake/cpp/*.cpp
	g++ *.o -o Build/Snake-app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o Build/Snake-app