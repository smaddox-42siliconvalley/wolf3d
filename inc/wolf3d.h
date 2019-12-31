#include <stdlib.h>
#include <unistd.h>
#include <ft_printf.h>
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

# define WINDOW_X 600
# define WINDOW_Y 400
# define MAX_MAP_SIZE 4096
# define WINDOW_NAME "wolf3d"

typedef struct	s_vector
{
	float		x;
	float		y;
}				t_vector;

typedef struct	s_player
{
	t_vector	pos; //position
	t_vector	dir;
	t_vector	cam_plane;
}				t_player;

typedef struct	s_ray
{
	t_vector	dir;
	t_vector	sd; // side distance
	t_vector	delta_dist;
	int			mpx; //map position x
	int			mpy; //map position y
	float		cam_x; //cameraX
	float		pwall; //perpwalldist
	int			stepx;
	int			stepy;
	int			collision;
	int			side;
	int			lh;	//lineHeight
	int			dstart; //draw_start
	int			dend; //draw_end
}				t_ray;

typedef struct	s_map
{
	int			size;
	int			size_line;
	int			map[MAX_MAP_SIZE];
}				t_map;


typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_game
{
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*mlx_win;
	t_image		img;
}				t_game;

/*				parsing maps */
//t_map			get_map(char *file);
void			get_map(char *file, t_game *g);
void			print_map(t_map map);
int				key_hook(int key_code, t_game *g);

int				render(t_game *g);


/*				general utils */
int				is_perfect_square(int num);
void			panic(int num);
void			get_player(t_game *g);
void			mlx_start(t_game *game);
