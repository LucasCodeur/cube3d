#include "mlx.h"
#include <stdio.h>
int main() {
    void *mlx = mlx_init();
    printf("mlx_init: %p\n", mlx);
    if (!mlx) { perror("mlx_init"); return 1; }
    void *win = mlx_new_window(mlx, 400, 300, "TEST");
    printf("mlx_new_window: %p\n", win);
    if (!win) { perror("mlx_new_window"); return 1; }
    void *img = mlx_new_image(mlx, 400, 300);
    printf("mlx_new_image: %p\n", img);
    sleep(2);
    mlx_destroy_image(mlx, img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    return 0;
}
