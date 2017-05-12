/*
** bitmap_load.c for skill test bitmap in /home/sam
**
** Made by Alexis Viguié
** Login   <sam@epitech.net>
**
** Started on  Tue Dec  8 14:33:58 2015 Alexis Viguié
** Last update Tue Dec  8 16:44:41 2015 Alexis Viguié
*/

#include <lapin.h>
#include <lapin_enum.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_b { } __attribute__ ((packed)) t_b;
int			my_get_nbr(char *str);

void			my_set_pixel(t_bunny_pixelarray *pixarr,
				     int pos,
				     unsigned int color)
{
  int			*int_pixel;

  int_pixel = pixarr->pixels;
  int_pixel[pos] = color;
}

t_bunny_pixelarray	*load_bitmap(const char *file)
{
  int			fd;
  t_bunny_pixelarray	*ret_pxarr;
  int			junkbuff[2048];
  char			pixpos[4];
  char			pxarr_l[4];
  char		        pxarr_h[4];
  int			*ttpix;
  int			counter;
  char			*test;

  fd = open(file, O_RDONLY);
  test = malloc(sizeof(char) * 1000);
  read(fd, test, 1000);
  printf("%s", test);
  read(fd, junkbuff, 9);
  read(fd, pixpos, 4);
  read(fd, junkbuff, 4);
  read(fd, pxarr_l, 4);
  read(fd, pxarr_h, 4);
  printf("%d %d\n", my_get_nbr(pxarr_l), my_get_nbr(pxarr_h));
  ret_pxarr = bunny_new_pixelarray(my_get_nbr(pxarr_l), my_get_nbr(pxarr_h));
  ttpix = malloc(sizeof(int) * (my_get_nbr(pxarr_l) * my_get_nbr(pxarr_h)));
  counter = 0;
  read(fd, ttpix, my_get_nbr(pxarr_l) * my_get_nbr(pxarr_h));
  while (ttpix[counter])
    {
      my_set_pixel(ret_pxarr, counter, ttpix[counter]);
      counter++;
    }
  return (ret_pxarr);
}

int			main_loop(const t_bunny_window *window)
{
  bunny_display(window);
  return(GO_ON);
}

int			main(int ac, char **av)
{
  t_bunny_window	*lapwin;
  t_bunny_pixelarray	*lappix;
  void			*loopptr;
  t_bunny_position	lappos;

  if (ac != 2)
    return (1);
  lappix = load_bitmap(av[1]);
  lapwin = bunny_start(lappix->clipable.buffer.width,
		       lappix->clipable.buffer.height,
		       0, av[1]);
  lappos.x = 0;
  lappos.y = 0;
  bunny_blit(&lapwin->buffer, &lappix->clipable, &lappos);
  loopptr = &(main_loop);
  bunny_set_loop_main_function(loopptr);
  bunny_loop(lapwin, 60, lapwin);
  while (1);
  bunny_stop(lapwin);
  return (0);
}
