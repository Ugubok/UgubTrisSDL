#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL_pixels.h>

typedef char block;

typedef struct FigureFrame_t {
  struct FigureFrame_t *next;
  struct FigureFrame_t *prev;

  int width;
  int height;

  block *matrix;
} Frame;

typedef struct Figure_t {
  SDL_Color color;

  Frame *current_frame;
} Figure;

typedef struct Stack_t {
  int width;
  int height;

  block *data;
} Stack;

/* Create figure
 * */
Figure create_figure(int width, int height, SDL_Color color,
                     block *init_matrix);

/*
** Create empty stack
*/
Stack create_stack(int width, int height);

/*
** Print figure data to stdout
*/
void dump_figure_data(Figure *figure);

void stack_push(Stack *stack, Figure *figure);
Figure *stack_pop(Stack *stack);

void destroy_figure(Figure *figure);
void destroy_stack(Stack *stack);

#endif
