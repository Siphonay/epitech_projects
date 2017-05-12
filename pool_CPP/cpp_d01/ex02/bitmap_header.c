/*
** bitmap_header.c for Project-Master in /home/sam/Rendu/Piscine_CPP/cpp_d01/ex02
** 
** Made by Alexis Viguié
** Login   <alexis.viguie@epitech.eu>
** 
** Started on  Wed Jan  4 16:22:59 2017 Alexis Viguié
** Last update Thu Jan  5 09:53:12 2017 Alexis Viguié
*/

#include <stdlib.h>
#include "bitmap.h"

void	make_bmp_header(t_bmp_header *header, size_t size)
{
  header->magic = 19778;
  header->size = 54 + ((size * size) * 4);
  header->_app1 = header->_app2 = 0;
  header->offset = 54;
}

void	make_bmp_info_header(t_bmp_info_header *header, size_t size)
{
  header->size = 40;
  header->width = header->height = size;
  header->planes = 1;
  header->bpp = 32;
  header->compression = 0;
  header->raw_data_size = ((size * size) * 4);
  header->h_resolution = header->v_resolution = header->palette_size =
    header->important_colors = 0;
}
