#include <mlx.h>
#include <stdio.h>

int	func(int key, void *parma)
{
	if (key == 126 || key == 13)
		printf("TOP\n");
	if (key == 124 || key == 2)
		printf("RIGHT\n");
	if (key == 123 || key == 0)
		printf("LEFT\n");
	if (key == 125 || key == 1)
		printf("DOWN\n");
	return (0);
}

int	main(void)
{
	void	*win;
	void	*mlx;
	void	*img;
	int x,y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "test");
	img = mlx_xpm_file_to_image(mlx, "img.xpm", &x, &y);
	mlx_put_image_to_window(mlx, win, img, 170, 170);
	int i = 0, j = 10;
	while (i < 500)
	{
		mlx_pixel_put(mlx, win,i,j, 0xFFFFFF);
		i++;
	}
	j = 490;
	while (i > 0)
	{
		mlx_pixel_put(mlx, win, i, j, 0xFFFFFF);
		i--;
	}
	mlx_key_hook(win, func, (void *)0);
	mlx_loop(mlx);
}