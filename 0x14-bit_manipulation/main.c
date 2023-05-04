#include "main.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main()
{
  /*ssize_t n;

  if (ac != 2) {
    dprintf(2, "Usage: %s filename\n", av[0]);
    exit(1);
  }
  n = read_textfile(av[1], 114);
  printf("\n(printed chars: %li)\n", n);
  n = read_textfile(av[1], 1024);
  printf("\n(printed chars: %li)\n", n);*/
  /*int res;

  if (ac != 3) {
    dprintf(2, "Usage: %s filename text\n", av[0]);
    exit(1);
  }
  res = create_file(av[1], av[2]);
  printf("-> %i)\n", res);*/
  /*unsigned int n;

  n = binary_to_uint("1");
  printf("%u\n", n);
  n = binary_to_uint("101");
  printf("%u\n", n);
  n = binary_to_uint("1e01");
  printf("%u\n", n);
  n = binary_to_uint("1100010");
  printf("%u\n", n);
  n = binary_to_uint("0000000000000000000110010010");
  printf("%u\n", n);*/
  print_binary(0);
  printf("\n");
  print_binary(1);
  printf("\n");
  print_binary(98);
  printf("\n");
  print_binary(1024);
  printf("\n");
  print_binary((1 << 10) + 1);
  printf("\n");
  /*int n;

  n = get_bit(1024, 10);
  printf("%d\n", n);
  n = get_bit(98, 1);
  printf("%d\n", n);
  n = get_bit(1024, 0);
  printf("%d\n", n);*/
  /*unsigned long int n;

  n = 1024;
  set_bit(&n, 5);
  printf("%lu\n", n);
  n = 0;
  set_bit(&n, 10);
  printf("%lu\n", n);
  n = 98;
  set_bit(&n, 0);
  printf("%lu\n", n);*/
  /*unsigned long int n;

  n = 1024;
  clear_bit(&n, 10);
  printf("%lu\n", n);
  n = 0;
  clear_bit(&n, 10);
  printf("%lu\n", n);
  n = 98;
  clear_bit(&n, 1);
  printf("%lu\n", n);*/
  /*unsigned int n;

  n = flip_bits(1024, 1);
  printf("%u\n", n);
  n = flip_bits(402, 98);
  printf("%u\n", n);
  n = flip_bits(1024, 3);
  printf("%u\n", n);
  n = flip_bits(1024, 1025);
  printf("%u\n", n);*/
  /*int n;

  n = get_endianness();
  if (n != 0)
  {
      printf("Little Endian\n");
  }
  else
  {
      printf("Big Endian\n");
  }*/
  return 0;
}
