#ifndef FIGURES_H
#define FIGURES_H

#include "engine.h"

struct {
  Figure figure_i;
  Figure figure_z;
  Figure figure_s;
  Figure figure_o;
  Figure figure_l;
  Figure figure_f;
  Figure figure_t;
} default_figures;

void init_default_figures();
void destroy_default_figures();

#endif
