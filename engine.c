#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "engine.h"

void rotate_matrix_cw(int width, int height, block *matrix, block *result) {
  /*
       *matrix      *result
     ===========    =======
      1 2 3 4 5      A 6 1
      6 7 8 9 0  ->  B 7 2
      A B C D E      C 8 3
                     (...)
  */

  int i = 0;

  for (int x = 0; x < width; x++) {
    for (int y = height - 1; y >= 0; y--) {
      result[i++] = matrix[width * y + x];
    }
  }
}

Figure create_figure(int width, int height, SDL_Color color,
                     block *init_matrix) {

  size_t block_count = (size_t)(width * height);

  Figure figure;
  figure.color = color;

  Frame *frame1 = (Frame *)calloc(1, sizeof(Frame));
  frame1->height = height;
  frame1->width = width;
  frame1->matrix = (block *)calloc(block_count, sizeof(block));

  figure.current_frame = frame1;

  // Fill first frame with initial matrix
  for (int i = 0; i < width * height; i++) {
    if (init_matrix[i] && init_matrix[i] != ' ') {
      frame1->matrix[i] = 1;
    }
  }

  // :: FRAME 2
  Frame *frame2 = (Frame *)calloc(1, sizeof(Frame));
  frame2->height = width;
  frame2->width = height;
  frame2->matrix = (block *)calloc(block_count, sizeof(block));

  rotate_matrix_cw(width, height, frame1->matrix, frame2->matrix);

  // Check if figure is full-symmetric
  if (height == width && !memcmp(frame1->matrix, frame2->matrix, block_count)) {
    link_frames(frame1, frame1);
    free(frame2);
    return figure;
  }

  link_frames(frame1, frame2);

  // :: FRAME 3
  Frame *frame3 = (Frame *)calloc(1, sizeof(Frame));
  frame3->height = height;
  frame3->width = width;
  frame3->matrix = (block *)calloc(block_count, sizeof(block));

  rotate_matrix_cw(height, width, frame2->matrix, frame3->matrix);

  // Check if figure is half-symmetric
  if (!memcmp(frame1->matrix, frame3->matrix, block_count)) {
    link_frames(frame2, frame1);
    free(frame3);
    return figure;
  }

  link_frames(frame2, frame3);

  // :: FRAME 4
  Frame *frame4 = (Frame *)calloc(1, sizeof(Frame));
  frame4->height = width;
  frame4->width = height;
  frame4->matrix = (block *)calloc(block_count, sizeof(block));

  rotate_matrix_cw(width, height, frame3->matrix, frame4->matrix);

  link_frames(frame3, frame4);
  link_frames(frame4, frame1); // create loop

  return figure;
}

void link_frames(Frame *frame_a, Frame *frame_b) {
  frame_a->next = frame_b;
  frame_b->prev = frame_a;
}

void dump_figure_data(Figure *figure) {
  Frame *current_frame = figure->current_frame;
  int frame_num = 1;

  do {
    printf("====== FRAME %d (%dx%d) ======\n", frame_num++,
           current_frame->width, current_frame->height);

    for (int i = 0; i < current_frame->width * current_frame->height; i++) {
      char c = current_frame->matrix[i] ? '*' : ' ';
      printf("%c", c);

      if ((i + 1) % current_frame->width == 0) {
        printf("\n");
      }
    }

    printf("\n");

    current_frame = current_frame->next;
  } while (current_frame != figure->current_frame);
}
