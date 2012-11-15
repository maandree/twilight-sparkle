SHELL=bash


all:
	@echo -e '\e[31mNothing to do\e[39m'


install:
	@echo -e '\e[31mNothing to do\e[39m'


uninstall:
	@echo -e '\e[31mNothing to do\e[39m'


clean:
	exts="o so out gch";			\
	for ext in $$exts; do			\
	    find . | grep '.\.'"$$ext"'$$'	\
	    while read file; do			\
	        unlink "$$file"			\
	    done				\
	done
	if [ -d "/bin" ]; then  rmdir "/bin";  done



.PHONY: clean

