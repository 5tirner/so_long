#include <mlx.h>
#include <stdio.h>

typedef struct s_moves
{
	int	nb_mv;
} t_moves;

int	moves(int keys, void *param)
{

	if (keys == 126 || keys == 13)
	{
		printf("TOP\n");
	
	}
	if (keys == 125 || keys == 1)
	{
		printf("DOWN\n");
	
	}
	if (keys == 123 || keys == 0)
	{
		printf("LEFT\n");
	
	}
	if (keys == 124 || keys == 2)
	{
		printf("RIGHT\n");

	}

	return (0);
}
int main()
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	int x, y;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "ZAKARIA_MLX");
	int i = 0, j = 0 ;
	while (j < 20)
	{
		i = 0;
		while (i < 500)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, i, j, 0xFF000F);
			i++;
		}
		j++;
	}
	j = 500;
	while (j > 480)
	{
		i = 0;
		while (i < 500)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, i, j, 0xFF000F);
			i++;
		}
		j--;
	}
	mlx_img = mlx_xpm_file_to_image(mlx_ptr, "moves.xpm", &x,&y);
	printf("%d----%d\n", x,y);
	mlx_put_image_to_window(mlx_ptr, mlx_win, mlx_img, 100, 100);
	mlx_key_hook(mlx_win, moves, (void *)0);
	mlx_loop(mlx_ptr);
}