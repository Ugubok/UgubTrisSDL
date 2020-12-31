#include <SDL2/SDL_pixels.h>

#include "engine.h"
#include "figures.h"

int main() {
  init_default_figures();
  dump_figure_data(&default_figures.figure_f);
  return 0;
}
