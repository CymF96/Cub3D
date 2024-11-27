#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub.h"

// Initialize the game state
t_state	*init_state(char *file_path);

// Free all memory alocated to the game state
void	free_state(t_state *state);

// Display a simple error on terminal and exit the program.
void	no_mem_free_err(char *message);
// Display a simple error on terminal, free the string and exit the program.
void	err_and_free_char(char *message, char *to_free);
// Display a simple error on terminal, free the whole state and exit the program.
void	err_and_free_state(char *message, t_state *state);

/**
 * Validate if the program is been called with the correct input, exit program on error
 * Valid example: ./cub3d <path_to_.cub_file>
*/
void	validate_args(int argc, char **argv);

// Read and return the file content in a string, exit program on error
char	*read_file(char const *file_name);

// Parse the textures from the config file to the state->map.style
void	parse_textures(t_state *state);

// Parse the colours from the config file to the state->map.style
void	parse_colours(t_state *state);

// Validate if the file has the proper configs and have a map
void	validate_file(t_state *state);

// Free texures memory on state->map.style
void free_textures(t_state *state);

// Free colours memory on state->map.style
void free_colours(t_state *state);

// Free matrix generated when parsing the file spliting by new line
void free_matrix(t_state *state);

#endif