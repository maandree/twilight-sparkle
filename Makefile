SHELL=bash

PREFIX=
CC=cc

CPPFLAGS=-DDISC='"sda"'

CFLAGS=-g -std=gnu99 -pedantic -Wall -Wextra
LDFLAGS=


all:
	cd src; $(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o mbrreader.{out,h,c}


install:
	@echo -e '\e[31mNothing to do\e[39m'


uninstall:
	@echo -e '\e[31mNothing to do\e[39m'


clean:
	exts="o so out gch";			\
	for ext in $$exts; do			\
	    find . | grep '.\.'"$$ext"'$$' |	\
	    while read file; do			\
	        unlink "$$file";		\
	    done				\
	done
	if [ -d "/bin" ]; then  rmdir "/bin";  done



.PHONY: clean

