CC = clang++
CFLAGS = -g  -Wall -std=c++11 -I.

ODIR = ./obj


# 添加config.h
DEPS = tabu.h

# 添加一个mian.c 
SOURCE = tabu.cpp
SOURCE_PLUS_MAIN = main.cpp $(SOURCE)


_OBJ = $(patsubst %.cpp, %.o ,$(SOURCE_PLUS_MAIN))
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))


$(ODIR)/%.o :  %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tabu.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o