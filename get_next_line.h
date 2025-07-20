#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// Headers
# include <unistd.h>
# include <stdlib.h>

// Pra testar na main
char	*get_next_line(int fd);

#endif