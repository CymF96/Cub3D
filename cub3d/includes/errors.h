#ifndef ERRORS_H
# define ERRORS_H

# define WRONG_ARGS_ERR				"Invalid arguments, Usage: ./cub3D <path_to_map>"
# define WRONG_FILE_FORMAT_ERR		"The map should be in the '.cub' format"
# define INVALID_MAP_ERR			"Invalid map file"
# define NEWLINE_ON_MAP_ERR			"Invalid map file, newline found"
# define READ_MAP_ERR				"Error trying to read the file"
# define INIT_STATE_ERR				"Error starting the game state"
# define INVALID_MAP_ATTR_ERR		"Invalid char on map"
# define TEXTURE_COUNT_ERR			"You should config exactly 4 textures"
# define COLOURS_COUNT_ERR			"You should config exactly 2 colours"
# define TEXTURE_ARGS_ERR			"You should config exactly 4 textures: N,S,W,E or NO,SO,WE,EA"
# define COLOURS_ARGS_ERR			"You should config exactly 2 colours: F and C"

#endif