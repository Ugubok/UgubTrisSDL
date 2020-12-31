#include <SDL2/SDL_pixels.h>

#include "engine.h"

int main() {
  SDL_Color default_color = {0, 0, 0, 0};

  Figure figure_i = create_figure(1, 4, default_color, "****");
  Figure figure_z = create_figure(3, 2, default_color, "**  **");
  Figure figure_s = create_figure(3, 2, default_color, " **** ");
  Figure figure_o = create_figure(2, 2, default_color, "****");
  Figure figure_l = create_figure(2, 3, default_color, "* * **");
  Figure figure_f = create_figure(2, 3, default_color, " * ***");
  Figure figure_t = create_figure(3, 2, default_color, "*** * ");

  printf(":: I\n");
  dump_figure_data(&figure_i);

  printf(":: Z\n");
  dump_figure_data(&figure_z);

  printf(":: S\n");
  dump_figure_data(&figure_s);

  printf(":: O\n");
  dump_figure_data(&figure_o);

  printf(":: L\n");
  dump_figure_data(&figure_l);

  printf(":: F\n");
  dump_figure_data(&figure_f);

  printf(":: T\n");
  dump_figure_data(&figure_t);

  return 0;
}
