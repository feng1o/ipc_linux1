.PHONY:clean all
cc=gcc
CFLAG=-Wall -g
BIN=msgget msgctl
all:$(BIN)
%.o:%.cc
	$(cc) $(CFLAG) -c $< -o $@
clean:
	rm  -f *.o $(BIN)