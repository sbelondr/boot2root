
## ssh

Nmap scan report for 192.168.1.47
Host is up (0.00017s latency).
Not shown: 994 closed ports
PORT    STATE SERVICE
21/tcp  open  ftp
22/tcp  open  ssh
80/tcp  open  http
143/tcp open  imap
443/tcp open  https
993/tcp open  imaps

PORT    STATE SERVICE
21/tcp  open  ftp
22/tcp  open  ssh
80/tcp  open  http
143/tcp open  imap
443/tcp open  https
993/tcp open  imaps
MAC Address: 08:00:27:37:54:C2 (Oracle VirtualBox virtual NIC)
Device type: general purpose
Running: Linux 3.X
OS CPE: cpe:/o:linux:linux_kernel:3
OS details: Linux 3.2 - 3.16
Network Distance: 1 hop

PORT    STATE SERVICE    VERSION
21/tcp  open  ftp        vsftpd 2.0.8 or later
|_ftp-anon: got code 500 "OOPS: vsftpd: refusing to run with writable root inside chroot()".
22/tcp  open  ssh        OpenSSH 5.9p1 Debian 5ubuntu1.7 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   1024 07:bf:02:20:f0:8a:c8:48:1e:fc:41:ae:a4:46:fa:25 (DSA)
|   2048 26:dd:80:a3:df:c4:4b:53:1e:53:42:46:ef:6e:30:b2 (RSA)
|_  256 cf:c3:8c:31:d7:47:7c:84:e2:d2:16:31:b2:8e:63:a7 (ECDSA)
80/tcp  open  http       Apache httpd 2.2.22 ((Ubuntu))
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_http-title: Hack me if you can
143/tcp open  imap       Dovecot imapd
|_imap-capabilities: ENABLE IMAP4rev1 have listed OK capabilities SASL-IR LOGINDISABLEDA0001 STARTTLS more LOGIN-REFERRALS ID LITERAL+ IDLE Pre-login post-login
|_ssl-date: 2020-10-04T10:11:28+00:00; -23s from scanner time.
443/tcp open  ssl/http   Apache httpd 2.2.22
|_http-server-header: Apache/2.2.22 (Ubuntu)
|_http-title: 404 Not Found
| ssl-cert: Subject: commonName=BornToSec
| Not valid before: 2015-10-08T00:19:46
|_Not valid after:  2025-10-05T00:19:46
|_ssl-date: 2020-10-04T10:11:28+00:00; -23s from scanner time.
993/tcp open  ssl/imaps?
|_ssl-date: 2020-10-04T10:11:28+00:00; -23s from scanner time.
MAC Address: 08:00:27:37:54:C2 (Oracle VirtualBox virtual NIC)
Device type: general purpose
Running: Linux 3.X
OS CPE: cpe:/o:linux:linux_kernel:3
OS details: Linux 3.2 - 3.16
Network Distance: 1 hop
Service Info: Host: 127.0.1.1; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: mean: -23s, deviation: 0s, median: -23s

## ssh_version

[+] 192.168.1.47:22       - SSH server version: SSH-2.0-OpenSSH_5.9p1 Debian-5ubuntu1.7 ( service.version=5.9p1 openssh.comment=Debian-5ubuntu1.7 service.vendor=OpenBSD service.family=OpenSSH service.product=OpenSSH service.cpe23=cpe:/a:openbsd:openssh:5.9p1 os.vendor=Ubuntu os.family=Linux os.product=Linux os.version=12.04 os.cpe23=cpe:/o:canonical:ubuntu_linux:12.04 service.protocol=ssh fingerprint_db=ssh.banner )

## ftp_version

[+] 192.168.1.47:21       - FTP Banner: '220 Welcome on this server\x0d\x0a'



