/*
 * author: @allisonoge
 * file: 100-elf_header.c
 */

/*
 * ELF stands for Executable and Linkable Format and an ELF file is
 * a binary file format in the Unix-based OSes. The ELF file header
 * contains essential information for the operating system to
 * correctly load and execute the binary file. The important information
 * contained in the ELF file header are:
 *
 * Magic number and file class: the first 16 bytes of an ELF file contain
 * a magic number that identifies the file as an ELF file. The magic number
 * is followed by a byte that specifies the file's class (32-bit or 64-bit)
 *
 * Object file type: this field specifies whether the file is an executable,
 * a shared object, a relocatable object, or a core dump.
 *
 * Machine architecture: this field specifies the target machine architecture
 * for which the file was compiled
 *
 * Entry point: this field specifies the virtual memory address of the entry
 * point into the program
 *
 * Program header table offset and size: this field specifies the offset and
 * size of the program header table
 *
 * Section header table offset and size: this specifies the offset and size
 * of the section header table
 *
 * Flags: contains preprocessor-specific flags
 *
 * Header size: specifies the size of the ELF file header
 *
 * Data: specifies whether the data in the ELF file is in little-endian or
 * big-endian byte order. A value of 1 indicates little-endian, while a value
 * of 2 indicates big-endian
 *
 * Version: specifies the version of the ELF specification that the file
 * conforms to. The value of this file is typically 1
 *
 * OS/ABI: specifies the operating system and ABI (Application Binary
 * Interface) for which the ELF file is intended. Some common values for this
 * field include:
 *	0x00: UNIX System V ABI
 *	0x03: Linux ABI
 *	0x06: Sun Solaris ABI
 *
 * ABI version: specifies the version of the ABI for which the ELF is intended.
 * The value of this field depends on the value of the OS/ABI field.
 *
 * Type: specifies the tpe of the ELF file. Some common values for this field
 * include:
 *	0x01: Relocatable file
 *	0x02: Execuatble file
 *	0x03: Shared object file
 *	0x04: Core file
 *
 * These are some of the fields in the ELF header as there are many other
 * fields that provide information about other aspects of the file format.
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <elf.h>
#include <stdlib.h>

/**
 * check_elf - check if file is ELF or not
 * @e_ident: field of the Elf_Ehdr struct
 * @fd: file descriptor
 *
 * Description: lookup the first 4 bytes which should contain
 * the magic number 0x7F followed by the characters ELF
 */
void check_elf(unsigned char *e_ident, int fd)
{
	if (e_ident[0] != 0x7F
		|| e_ident[1] != 'E'
		|| e_ident[2] != 'L'
		|| e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not a valid file\n");
		close(fd);
		exit(98);
	}
}

/**
 * print_magic - print the magic field of header
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_magic(unsigned char *e_ident)
{
	int idx;

	printf("  Magic:   ");
	for (idx = 0; idx < EI_NIDENT; idx++)
	{
		printf("%02x", e_ident[idx]);
		if (idx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class field of the header
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		case ELFCLASSNONE:
			printf("none\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the data field of the header
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little-endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big-endian\n");
			break;
		case ELFDATANONE:
			printf("none\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: pointer to pointer to strings
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	Elf64_Ehdr *ehdr;
	int fd, n;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	ehdr = malloc(sizeof(Elf64_Ehdr));
	if (!ehdr)
	{
		dprintf(STDERR_FILENO, "Error: Failed to allocate memory\n");
		free(ehdr);
		exit(98);
	}

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	n = read(fd, ehdr, sizeof(Elf64_Ehdr));
	if (n < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		close(fd);
		exit(98);
	}

	check_elf(ehdr->e_ident, fd);
	printf("ELF Header:\n");
	print_magic(ehdr->e_ident);
	print_class(ehdr->e_ident);
	print_data(ehdr->e_ident);

	free(ehdr);
	return (0);
}
