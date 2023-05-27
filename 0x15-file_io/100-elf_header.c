#include "main.h"


#include <elf.h>

void print_osabi_more(Elf64_Ehdr h);

/**
 * print_magic - prints magic bytes
 * @h: header struct
 */
void print_magic(Elf64_Ehdr h)
{
	int j;

	printf("  Magic:   ");
	for (j = 0; j < EI_NIDENT; j++)
	{
		printf("%2.2x%s", h.e_ident[j], j == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - prints  class
 * @h: header struct
 */
void print_class(Elf64_Ehdr h)
{
	printf("  Class:                             ");
	switch (h.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
		break;
		case ELFCLASS32:
			printf("ELF32");
		break;
		case ELFCLASSNONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_data - prints data
 * @h: header struct
 */
void print_data(Elf64_Ehdr h)
{
	printf("  Data:                              ");
	switch (h.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
		break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
		break;
		case ELFDATANONE:
			printf("none");
		break;
	}
	printf("\n");
}

/**
 * print_version - prints ELF version
 * @h: the ELF header struct
 */
void print_version(Elf64_Ehdr h)
{
	printf("  Version:                           %d", h.e_ident[EI_VERSION]);
	switch (h.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
		break;
		case EV_NONE:
			printf("%s", "");
		break;
		break;
	}
	printf("\n");
}

/**
 * print_osabi - prints ELF osabi
 * @h: the ELF header struct
 */
void print_osabi(Elf64_Ehdr h)
{
	printf("  OS/ABI:                            ");
	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_osabi_more(h);
			break;
	}
	printf("\n");
}


/**
 * print_osabi_more - prints ELF osabi more
 * @h: the ELF header struct
 */
void print_osabi_more(Elf64_Ehdr h)
{
	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_MODESTO:
			printf("Novell - Modesto");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - OpenBSD");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App");
			break;
		case ELFOSABI_ARM:
			printf("ARM");
			break;
		default:
			printf("<unknown: %x>", h.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion  - prints ELF ABI version
 * @h: the ELF header struct
 */
void print_abiversion(Elf64_Ehdr h)
{
	printf("  ABI Version:                       %d\n",
		h.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints the ELF type
 * @h: the ELF header struct
 */
void print_type(Elf64_Ehdr h)
{
	char *p = (char *)&h.e_type;
	int j = 0;

	printf("  Type:                              ");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		j = 1;
	switch (p[j])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", p[j]);
		break;
	}
	printf("\n");
}

/**
 * print_entry - elf  address
 * @h: header struct
 */
void print_entry(Elf64_Ehdr h)
{
	int j = 0, len = 0;
	unsigned char *p = (unsigned char *)&h.e_entry;

	printf("  Entry point address:               0x");
	if (h.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		j = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[j])
		{
			j--;
		}
		printf("%x", p[j--]);
		for (; j >= 0; j--)
		{
			printf("%02x", p[j]);
		}
		printf("\n");
	}
	else
	{
		j = 0;

		len = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!p[j])
		{
			j++;
		}
		printf("%x", p[j++]);
		for (; j <= len; j++)
		{
			printf("%02x", p[j]);
		}
		printf("\n");
	}
}

/**
 * main - program
 * @ac: argument
 * @av:list argument
 *
 * Return: one on success zero on failure
 */
int main(int ac, char **av)
{
	int df;
	Elf64_Ehdr h;
	ssize_t m;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	df = open(av[1], O_RDONLY);
	if (df == -1)
	{
		dprintf(STDERR_FILENO, "Can't open file: %s\n", av[1]);
		exit(98);
	}
	m = read(df, &h, sizeof(h));
	if (m < 1 || m != sizeof(h))
	{
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", av[1]);
		exit(98);
	}
	if (h.e_ident[0] == 0x7f && h.e_ident[1] == 'E' && h.e_ident[2] == 'L' &&
			h.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", av[1]), exit(98);

	print_magic(h);
	print_class(h);
	print_data(h);
	print_version(h);
	print_osabi(h);
	print_abiversion(h);
	print_type(h);
	print_entry(h);
	if (close(df))
	{
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", df), exit(98);
	}
	return (EXIT_SUCCESS);
}
