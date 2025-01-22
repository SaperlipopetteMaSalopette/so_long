---------------------------get_next_line_utils.c

void	ft_bzero(void *s, size_t n)
{
	Sert à initialiser toute la string à 0.
	void *s -> argument indiquant la string à mettre à 0.
	size_t n -> longueur à initialiser à 0.
}


size_t ft_strlen(const char *str)
{
	Sert à mesurer la longueur d'une string.
	return la longueur de la string str.
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	Sert à concatener les strings s1 et s2 dans une new string.
	return (la nouvelle string (result)).
}

void	*ft_calloc(size_t count size_t size)
{
	Sert à malloc + bzero (tout init à 0).
}

char	*ft_strchr(const char *s, int c)
{
	Sert à trouver la première occurence de c dans la string s.
	Return(pointeur vers le caractère trouvé ou NULL si rien).
}


-------------get_next_line.c

char	*ft_free_buffer(char *buffer, char *buf)
{
	Sert à combiner buffer et buf dans une new string.
	Free ensuite buffer et return(la new string).
}

char	*ft_next(char *buffer)
{
	Sert à avancer buffer après le '\n'.
	Return(la data restante en tant que new_buffer).
	En gros on skip d'abord la première ligne,
	on vérifie si on est arrivés à un '\0' ou un '\n',
	si on est arrivés sur un '\0' on return NULL (EOF).
	Si on est arrivés à un '\n', on met tout le reste dans le new buffer.
	La fonction sert juste à effacer du buffer ce qui a déjà été "processed".
}

char *ft_line(char *buffer)
{
	Extrait une ligne (jusqu-au '\n' inclus mais pas plus loin)
	depuis le buffer et le return en tant que new string (line).
}

char *read_file(int fd, char *res)
{
	Lit BUFFER_SIZE de data depuis le fd donné en argument dans un
		buffer temporaire, en boucle jusqu'à trouver
		un '\n' ou un '\0' (EOF End Of File).
	Cette data est ajoutée a la string de resultat (res)
	Cette fonction gère les allocation dynamiques de mémoire pour
		le buffer et la string de résultat.
		Si un '\n' est trouvé, la fonction arrête de lire + loin
			et return(la string de résultat mise à jour).
	Si une erreur se produit pendant la lecture, la fonction return(NULL)
		et free la mémoire.
	En résumé : lit et inspecte morceau par morceau et regarde si il y a un '\n'.
}

char	*get_next_line(int fd)
{
	Fonction principale.
	Récupère la prochaine ligne depuis le fd (fd -> fichier qu'on appelle).
	Lit la data, extrait la ligne d'après et update le buffer.
}
-------------------------------main test

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}

	char	*line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s, line);
		free(line);
	}
	close(fd);
	return (0);
}

On ouvre le fichier en read-only.
Si il n'y a pas de fichier, on affiche une erreur.
On imprime la ligne puis on free la mémoire.
Puis on close le fichier et on return(0).

---------------MISC infos

la fonction read :
read lit jusqu'à count octets depuis le fd et le stocks dans un buffer.
La lecture commence à la position actuelle du pointeur de fichier du fd.
Retour : La fonction read() return(le nombre d'octets lus, peut < count).
Si read() atteint la fin du fichier, return(0).
En cas d'erreur, return(-1).


