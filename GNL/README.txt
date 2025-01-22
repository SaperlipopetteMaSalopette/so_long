Get_next_line

Ce projet vise à faire une fonction qui retourne une ligne lue par un file descriptor.

File descriptor -> reference qui pointe vers un fichier ouvert sur l'ordinateur ?
Un file descriptor en C est un entier utilise pour identifier une ressource ouverte, comme un
fichier ou un socket, au sein d'un programme. Les file descriptors sont principalement
utilisés dans les systèmes Unix et Unix-like.
Référence qui pointe vers un fichier qui est ouvert dans l'ordinateur.

Points-clés :

1. Identification : Chaque file descriptor est un entier unique dans le contexte
d'un processus, généralement commençant à 0. Les trois premiers file descriptors sont :

- 0 : stdin (entrée standard)
- 1 : stdout (sortie standard)
- 2 : stderr (erreur standard)

2. Gestion des fichiers : Lorsque vous ouvrez un fichier en utilisant des fonctions comme
"open()", le système d'exploitation retourne un file descriptor qui représente ce fichier.
Vous pouvez ensuite utiliser ce file descriptor pour lire, écrire ou manipuler ce fichier.

3. Opérations sur les fichiers : Des fonctions telles que "read()", "write()" et "close()"
utilisent des file descriptors pour effectuer des opérations sur les fichiers.

4. Ressources variées : Les file descriptors ne sont pas limités aux fichiers. Ils peuvent
également représenter des sockets, des pipes ou d'autres types de ressources d'entrée/sortie.

En résumé, un file descriptor est un moyen abstrait pour un programme de gérer l'accès aux
ressources d'entrée/sortie, facilitant ainsi la communication avec le système d'exploitation.

--------------------------

Pour commencer ce projet, nous devons d'abord être en mesure d'ouvrir un fichier texte.
Une fois ouvert, nous pourrons le lire. Nous pouvons faire ceci en utilisant les fonctions
"open()" et "read()".

open() :

Pour que la fonction fonctionne, nous devons implémenter la library <fcntl.h>.
Cette fonction va nous permettre d'ouvrir et d'accéder à un fichier.
C'est prototypé de la façon suivante :

int open (const char* path, int flags [, int mode ]);

Path :

Ça correspond au titre du fichier que nous voulons ouvrir/créer.
Cela renseigne aussi sur l'emplacement du fichier. Si nous ne travaillons pas dans le
même dossier que le fichier, nous pouvons renseigner un chemin absolu qui commence par
"/".

Flags :

Nous devons dire à notre fonction quel type d'accès nous voulons. Cela est fait avec les flags.
Ici est la liste d'infos pour chaque flag :

- O_RDONLY : En mode lecture seule, ouvrir le fichier.
- O_WRONLY : En écriture seule, ouvrir le fichier.
- O_RDWR : Ouvrir le fichier en mode lecture-écriture uniquement.
- O_CREAT : Ce flag est appliqué pour créer un fichier si il n'existe pas encore
			dans le chemin/dossier spécifié.
- O_EXCL : Prévient la création du fichier si celui-ci existe déja dans le chemin/dossier.



Valeurs de return :

La return value de open() est un file descriptor, un petit int non-négatif qui est
l'index d'une entrée dans la process's table des open file descriptors.
Si il y a une erreur quelque part, la fonction va return (-1).

Exemple :

int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
}

Pour le moment, rien ne va être affiché car la fonction est uniquement utilisée pour ouvrir
un fichier. Nous aurons besoin d'utiliser une fonction additionelle pour rendre le tout utile.
Par exemple -> la fonction read() que nous allons voir.

read() :

La fonction est prototypée ainsi :

ssize_t read(int fildes, void *buf, size_t nbyte);

Cette fonction va tenter de lire "nbyte" bytes of data depuis l'objet référencé par le descriptor
"fildes" dans le buffer pointé par "buf". La fonction read() commence à une position donnée par
le pointeur associé à fildes. À la fin, le pointeur est incrémenté par le nombre de bytes ("nbyte")
qui ont été lus.

-------------------------------------

Variables statiques :

Une variable statique en C et une variable spéciale qui possède deux caractéristiques principales :

1. Elle conserve sa valuer entre les appels de fonction.

2. Elle a une portée limitée à son bloc de déclaration.

caractéristiques principales :

- Durée de vie : une variable statique existe pendant toute la durée d'exécution du programme.

- Initialisation : Elle est initialisée une seule fois, au début de l'exécution du programme.

 - Valeur par défaut : Si non initialisée explicitement, elle est automatiquement
 initialisée à 0.

 - Stockage : Elle est stockée dans la zone de mémoire statique, pas sur la pile.

 Utilisation :

 Pour déclarer une variable statique, on utilise le mot-clé 'static' :

 static int compteur = 0;

 Exemple pratique :

 Voici un exemple simple pour illustrer l'utilisation d'une variable statique :

 #include <stdio.h>

 void	incrementer()
 {
	static int compteur = 0;
	compteur++;
	printf("Compteur : %d\n", compteur);
 }

 int main()
 {
	incrementer();
	incrementer();
	incrementer();
	return 0;
 }

 Dans cet exemple, 'compteur' conservera sa valeur entre les appels de la fonction 'incrementer'.
 Le résultat sera :

 Compteur : 1
 Compteur : 2
 Compteur : 3

Avantages :
1. Persistance des données : Utile pour conserver des informations entre les appels
de fonction.

2. Encapsulation : La variable reste accessible uniquement dans son bloc de déclaration, limitant
les risques d'erreurs.

Points importants à retenir :

- Les variables statiques sont initialisées une seule fois, au début du programme.

- Elles conservent leur valeur entre les appels de fonction.

- Leur portée est limitée au fichier ou à la fonction où elles sont déclarées.

- Elles sont utiles pour créer des compteurs ou des flags qui doivent persister entre les appels
de fonction.

Conseils du pro :

Fonction de Libft :

Pour ce projet, nous aurons besoin de certaines fonctions de libft :

- ft_strchr;
- ft_strdup;
- ft_strlen;
- ft_substr;
- ft_strjoin;

Fonctions additionelles :
Outre les fonctions ci-dessus, nous pourrious aussi avoir besoin de ces 3 autres fonctions :

- char *get_next_line(int fd);
- char *_fill_line_buffer(int fd, char *left_c, char *buffer);
- char *_set_line(char *line_buffer);

--------------------Explications des fonctions :-------------------


------char *get_next_line(int fd)

La fonction principale get_next_line est simplement responsable de faire quelques checks sur
le file descriptor et les allocations de mémoire qui pourraient causer des erreurs.

Une fois que tous les checks ont été faits, la fonction appelle la fonction
_file_line_buffer pour lire dans le file descriptor jusqu'à ce que ça trouve un '\n'
ou un '\0'.

Une fois que la variable de ligne est remplie, on va free le buffer afin de ne pas avoir
de leak de mémoire, vu que ce n'est plus utilisé.

Une fois que le buffer est free, nous mettons la ligne avec la fonction "_set_line"
et nous retournons la ligne, en storant la valeur de return() de set_line dans une
variable static afin que la prochaine fois que nous appelons get_next_line, nous avons
accès au premier caractère de la ligne qui a pu être lue au préalable.

Par exemple, notre fichier contient "1\n234\0", notre BUFFER_SIZE est de 4.
La première fois que nous allons lire dans le fichier, nous allons lire "1\n23"
donc ce que nous allons stocker dans notre variable static est "23" parce que la
prochaine fois que nous allons appeler la fonction sur le même fd, ça va commencer
en lisant à partir du '4' dans notre fichier.



-----char *_fill_line_buffer(int fd, char *left_c, char *buffer)

Cette fonction est le buffer de "line".
Elle va lire "BUFFER_SIZE" caractères dans chaque itération jusqu'à ce qu'il y ai
un '\n' ou un '\0' dans le buffer de line.

À chaque fois dans la boucle, elle va checker si il y a déjà de la data dans
le buffer "left_c". Si il y en a, elle va rajouter les nouveaux caractères lus à la suite.
Si il n'y en a pas,

