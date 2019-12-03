minishell: minishell.c
	gcc -o minishell minishell.c -I.
clean:
	rm -f minishell *.o *.err core *~
