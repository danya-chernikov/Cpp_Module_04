CXX=c++

NAME=animal

CXXFLAGS=-Wall -Wextra -Werror -std=c++98 -O0 -g3

all: $(NAME)

$(NAME): main.o Animal.o Brain.o Cat.o Dog.o WrongAnimal.o WrongCat.o
	$(CXX) $(CXXFLAGS) main.o Animal.o Brain.o Cat.o Dog.o WrongAnimal.o WrongCat.o -o $(NAME)

main.o: main.cpp Animal.h Brain.h Cat.h Dog.h WrongAnimal.h WrongCat.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Animal.o: Animal.cpp Animal.h
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Brain.o: Brain.cpp Brain.h
	$(CXX) $(CXXFLAGS) -c Brain.cpp

Cat.o: Cat.cpp Cat.h Animal.h Brain.h
	$(CXX) $(CXXFLAGS) -c Cat.cpp

Dog.o: Dog.cpp Dog.h Animal.h Brain.h
	$(CXX) $(CXXFLAGS) -c Dog.cpp

WrongAnimal.o: WrongAnimal.cpp WrongAnimal.h
	$(CXX) $(CXXFLAGS) -c WrongAnimal.cpp

WrongCat.o: WrongCat.cpp WrongCat.h WrongAnimal.h
	$(CXX) $(CXXFLAGS) -c WrongCat.cpp

clean:
	rm -f main.o Animal.o Brain.o Cat.o Dog.o WrongAnimal.o WrongCat.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
