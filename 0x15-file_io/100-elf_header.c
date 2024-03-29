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
 * print_version - print the version field in the header
 * @e_ident: feild of the Elf64_Ehdr struct
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
	}
}

/**
 * close_elf - wrapper function to close file and handle errors
 * @fd: file descriptor
 */
void close_elf(int fd)
{
	if (close(fd) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", fd);
		exit(98);
	}
}

/**
 * print_osabi - print the OS/ABI field in the header
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - print the ABI version field in the header
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - print the type field in the header
 * @e_type: field of the Elf64_Ehdr struct
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	/* if big-endianness order bytes */
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf("  Type:                              ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocation file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - prints the entry field in the header
 * @e_entry: address of the entry point
 * @e_ident: field of the Elf64_Ehdr struct
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");
	/* if big-endianness order of bytes */
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
				((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	/* print based on operating system bits */
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
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
		close_elf(fd);
		exit(98);
	}
	check_elf(ehdr->e_ident, fd);
	printf("ELF Header:\n");
	print_magic(ehdr->e_ident);
	print_class(ehdr->e_ident);
	print_data(ehdr->e_ident);
	print_version(ehdr->e_ident);
	print_osabi(ehdr->e_ident);
	print_abi(ehdr->e_ident);
	print_type(ehdr->e_type, ehdr->e_ident);
	print_entry(ehdr->e_entry, ehdr->e_ident);

	free(ehdr);
	close_elf(fd);
	return (0);
}
