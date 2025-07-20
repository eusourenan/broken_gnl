# include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		puts("Execute com o nome de arguivo como argumento");
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		puts("Arquivo inválido");
		return 2;
	}

	int qtd_linhas = 3;
	char *line = NULL;

	for (;qtd_linhas > 0; qtd_linhas--)
	{
		line = get_next_line(fd);
		printf("- |%s", line);
		free(line);
	}

	return 0;
}