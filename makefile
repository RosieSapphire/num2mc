EXECUTABLE=num2mc
COMPILE_COMMAND=gcc -o $(EXECUTABLE) $(EXECUTABLE).c \
	-Werror -Wall -O2 -ansi -pedantic
CLEAN_COMMAND=rm -rf *.o $(EXECUTABLE)

all:
	$(CLEAN_COMMAND)
	$(COMPILE_COMMAND)

clean:
	$(CLEAN_COMMAND)

install:
	$(CLEAN_COMMAND)
	$(COMPILE_COMMAND)
	sudo cp -rvf $(EXECUTABLE) /usr/local/bin/

uninstall:
	$(CLEAN_COMMAND)
	sudo rm -rvf /usr/local/bin/$(EXECUTABLE)
