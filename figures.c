#include "figures.h"
#include "colors.h"
#include "engine.h"

void init_default_figures() {
  default_figures.figure_i = create_figure(1, 4, color_i, "****");
  default_figures.figure_z = create_figure(3, 2, color_z, "**  **");
  default_figures.figure_s = create_figure(3, 2, color_s, " **** ");
  default_figures.figure_o = create_figure(2, 2, color_o, "****");
  default_figures.figure_l = create_figure(2, 3, color_l, "* * **");
  default_figures.figure_f = create_figure(2, 3, color_f, " * ***");
  default_figures.figure_t = create_figure(3, 2, color_t, "*** * ");
}

void destroy_default_figures() {}
