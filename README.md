# DEFCON CTF VM Files #

This repository contains the files necessary for the DEFCON CTF VM that I created. You can grab a copy of the VM
itself [from my blog](http://fuzyll.com/2016/the-defcon-ctf-vm/).

To use this VM, simply start it up in VMware and do the following to connect to a given service:

```
nc defcon.local <port>  # for TCPv4 services
nc6 defcon.local <port>  # for TCPv6 services
```

*NOTE: Your network settings may not resolve "defcon.local" as a hostname. You can log in and run `ifconfig` from
inside the VM to get its IP address. You can also try using just "defcon" or "defcon.<your local domain>" and see if
those work.*

Getting the flag for each service is, obviously, an exercise left to the reader.


## List of Services ##

### DEFCON 13 (2005) ###

* **Organizers:** Kenshoto
* **Operating System:** FreeBSD 5.4

*NOTE: Check `/root/kinit.py` for how to run these services! Many of these were `xinetd` services that don't contain
their own server setup code.*

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| apachectl         | ?????         | ????? | ??????    | NOT RUNNING |
| befunge           | bfg           | ????? | ??????    | NOT RUNNING: Requires the `PyFunge` library |
| bparkd            | bparkd        | ????? | ??????    | NOT RUNNING: Requires `enigma` and `.bpconfig` to run |
| echod             | ?????         | ????? | ??????    | NOT RUNNING |
| fingerd           | ?????         | ????? | ??????    | NOT RUNNING |
| fucktcpd          | ?????         | ????? | ??????    | NOT RUNNING |
| HowAreYouToday.py | frat          | ????? | ??????    | NOT RUNNING |
| inetd             | ?????         | ????? | ??????    | NOT RUNNING |
| kmud.py           | kmud          | ????? | ??????    | NOT RUNNING |
| kpub.py           | pub           | ????? | ??????    | NOT RUNNING |
| named             | ?????         | ????? | ??????    | NOT RUNNING |
| postfix           | ?????         | ????? | ??????    | NOT RUNNING |
| tomcat50ctl       | www           | ????? | ??????    | NOT RUNNING |
| transformd        | transform     | ????? | ??????    | NOT RUNNING: Requires `joshua` to run? |
| UserAdder.py      | ?????         | ????? | ??????    | NOT RUNNING |
| wumpus            | wumpus        | ????? | ??????    | NOT RUNNING |

Other binaries I've come across that may have been part of this year:

* alice
* b16
* kstrings
* nettoe
* readmail
* smtpd
* vacation

### DEFCON 14 (2006) ###

* **Organizers:** Kenshoto
* **Operating System:** Solaris ???

Notably absent from the VM are the services from DEFCON 14. These challenges were built for and ran on Solaris.
Since I haven't created a Solaris VM to host them (and a Solaris translation layer for FreeBSD doesn't appear to exist),
I can't get them running. I do, however, have what I *think* are all of the services if anyone would like to play with
them. Their names are:

* CookieMonster
* CustomHeap
* FingerLickinGood
* FuckTcpd2
* Heisenberg
* IFallDown
* InMyMemory
* KuFtpd
* NPComplete
* OhShitD
* SpamMe
* Vanilla
* YouHadMeAtHello

### DEFCON 15 (2007) ###

* **Organizers:** Kenshoto
* **Operating System:** FreeBSD 6.3?

*NOTE: Many of the following services require the `compat6x-i386` package to be installed.*

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| arpsd             | arps          | 1331  | TCPv4     | |
| blowlogd          | blowlog       | 1500  | UDPv4     | |
| hfd               | hfd           | 1024  | TCPv4     | Needs `server.pem`, `dh1024.pem`, `root.pem` in `/home/hfd` |
| kftpd             | kftp          | 2121  | TCPv4     | |
| kimjong           | kimjong       | 9999  | TCPv4     | |
| kuftpd            | kuftpd        | 21    | TCPv4     | |
| madlibd           | madlib        | 4042  | TCPv4     | Needs `articles.txt`, `nouns.txt`, `objects.txt`, `verbs.txt` in `/home/madlib` |
| menageatrois      | menageatrois  | 3339  | TCPv4     | |
| neurod            | wintermute    | 5953  | TCPv4     | Requires the `dlmalloc` package to be installed |
| perudo            | perudo        | 3822  | TCPv4     | |
| rolodex           | rolodex       | 8224  | TCPv4     | |
| sammichd          | sammich       | 8365  | TCPv4     | |
| shellcat          | shellcat      | 7890  | TCPv4     | |
| sor               | sor           | 9051  | TCPv4     | |
| supd              | sup           | ????? | ?????     | NOT RUNNING: Requires `python2.5` and the socket module (also may actually have been from DEFCON 16..? need to confirm with someone) |

Other binaries I've come across that may have been part of this year:

* xserver (looks like a web challenge...drops to user "xserver")
* UserAdder and makeuser? (looks like just a way to create users...drops to user "makeuser")
* I have a "serverd" somehow that I have listed as being from this year, but honestly no idea where this is from or what it's for

### DEFCON 16 (2008) ###

* **Organizers:** Kenshoto
* **Operating System:** FreeBSD 6.3

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| antipastod        | antipasto     | 7482  | TCPv4     | |
| aspd              | asp           | ????? | ?????     | NOT RUNNING: Won't run for some reason...just prints "Done" |
| bakalakadakaChat  | durka         | 15641 | TCPv4     | |
| barista           | barista       | ????? | ?????     | NOT RUNNING: `1: Syntax error: ")" unexpected` |
| catdoord          | catdoor       | 4341  | TCPv4     | |
| duckshootd        | duckshoot     | 3888  | TCPv4     | |
| EmergencyBrake    | EmergencyBrake| 2028  | TCPv4     | |
| grimcreeper.d     | grimcreeper   | 9001  | TCPv4     | |
| hashpiped         | hashpipe      | 5641  | TCPv4     | |
| iMagick           | iMagick       | 4141  | TCPv4     | |
| kdnsd             | kdns          | ????? | ?????     | NOT RUNNING: Requires `kdns.conf`, `python2.5`, and the `socket` module to run |
| kmaild            | kmail         | 17722 | TCPv4     | |
| kmsgd             | kmsg          | 10001 | TCPv4     | |
| kryptod           | krypto        | 20020 | TCPv4     | |
| lockstep          | lockstep      | ????? | ?????     | NOT RUNNING: Requires `python2.5` and the `md5` module |
| moatd             | moat          | 6810  | TCPv4     | |
| roflcode          | roflcode      | 4000  | TCPv4     | |
| sockringd         | sockring      | 14340 | TCPv4     | |
| supd              | sup           | ????? | ?????     | NOT RUNNING |
| superd            | super         | 8126  | TCPv4     | |

Other binaries I've come across that may have been part of this year:

* SupaFlyTNT
* Something that would have used a user named "nubbin"?

### DEFCON 17 (2009) ###

* **Organizers:** DDTEK
* **Operating System:** FreeBSD 7.2

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| baaaad            | sheepc        | ????? | ?????     | NOT RUNNING: Unable to register (MESSAGEPROG, MESSAGEVERS, udp) |
| casino            | casino        | ????? | ?????     | NOT RUNNING: syntax error on line 1 |
| cheese.pl         | cheese        | ????? | ?????     | NOT RUNNING: Some web service..? Not sure I even have this on the VM right now... |
| cmd               | cm            | 4546  | TCPv4     | Requires `cjd` in `/usr/local/sbin` |
| deltad            | delta         | 1787  | TCPv4     | |
| deuced            | deuce         | 2056  | TCPv4     | |
| elfd              | buddy         | 7331  | TCPv4     | |
| lazrus            | lazrus        | 1905  | TCPv4     | |
| magicd            | magic         | 4343  | TCPv4     | |
| mdljserver        | mdlj          | ????? | ?????     | NOT RUNNING: Requires a `.pem`, `.crt`, and `.key` file, fails to load private key, and subsequently dies with SSL ERROR (certs are currently in `/home/mdlj` but don't work) |
| mymqld            | mymql         | 4242  | TCPv4     | |
| nickd             | nickster      | 2337  | TCPv4     | |
| rsatesp           | rsatesp       | 5500  | TCPv4     | Requires `sqlite3` package and has an `auth.db` created by `createdb.sh` in `/home/rsatesp` that don't appear to work |
| tucod             | tuco          | 57005 | TCPv4     | |
| wwcd              | wwcd          | 6977  | TCPv4     | |

### DEFCON 18 (2010) ###

* **Organizers:** DDTEK
* **Operating System:** FreeBSD 8.0

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| cohend            | cohend        | 7532  | TCPv4     | |
| ddftpd            | ddftp         | 1776  | UDPv4     | |
| diablo            | diablo        | ????? | ????      | NOT RUNNING: Requires `diablo-jvm` 1.6.10 or something (might also require Launcher.class and a few other things?) |
| food              | food          | ????? | ????      | NOT RUNNING: Requires `libutil.so.8` (and is a frozen `python2.6` service that complains about no module named "_socket") |
| houdini           | houdini       | ????? | ????      | NOT RUNNING: This is a PE binary and I have no idea how it ever ran (WINE as a custom kernel module?) - very aptly named service |
| libra             | libra         | 1495  | TCPv4     | |
| mashup            | mashup        | 5539  | TCPv4     | |
| memix             | memix         | 9911  | ????      | NOT RUNNING: Appears to not be able to read a "local auth file" and is also missing the patch it downloaded from DDTEK's servers to make it vulnerable |
| mqdbd             | mqdb          | 2001  | TCPv4     | |
| nadel             | nadel         | 3248  | TCPv4     | |
| natord            | nator         | 2985  | TCPv4     | |
| noprotas          | noprotas      | 23945 | UDPv4     | |
| santad            | santa         | ????? | ????      | NOT RUNNING: Won't run for some reason...just prints "Done" |
| slickd            | slick         | 7391  | TCPv4     | |
| spelunk           | spelunk       | 8362  | TCPv4     | Requires `adv.key` and `adv.rec` in `/home/spelunk` |
| sushid            | sushi         |       | RAWv4     | |

### DEFCON 19 (2011) ###

* **Organizers:** DDTEK
* **Operating System:** FreeBSD 8.2

*NOTE: In addition to the services below, there was also a service called "finch" that interacted with some remote
control cars in a chicken coop. To my knowledge, no team ever figured out how to score successfully (you were supposed
to drive your car into the lighted area matching your car's color). Since "finch" was a Linux binary that was meant to
run on your own machine, it isn't included below.*

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| bowser            | bowser        | NONE  | TCPv6     | Local service with usage: `/usr/local/sbin/bowser <host>` |
| bunny             | bunny         | 15323 | TCPv6     | |
| castle            | castle        | 7629  | TCPv6     | Requires `sandy` in `/usr/local/sbin` |
| cleaner           | cleaner       | 26987 | TCPv6     | |
| forgetu           | forgetu       | 3128  | TCPv6     | |
| gold              | gold          | 2069  | TCPv6     | |
| hiver             | hiver         | 44366 | TCPv6     | |
| htlame            | htlame        | 42737 | TCPv6     | |
| pisa              | pisa          | 6765  | TCPv6     | |
| rotary            | rotary        | 3375  | TCPv6     | |
| sheepster         | sheepster     | 5775  | TCPv6     | |
| telephone         | bell          | 1477  | TCPv6     | |
| tomato            | tomato        | 6391  | TCPv6     | |
| war               | war           | 14273 | TCPv6     | |

### DEFCON 20 (2012) ###

* **Organizers:** DDTEK
* **Operating System:** FreeBSD 9.0

*NOTE: All these services bound the interface `em1` in the game, but I patched them to bind `em0` for the VM to work.*

| Service Name      | User          | Port  | Protocol  | Notes                                        |
| ----------------- | ------------- | ----- | --------- | -------------------------------------------- |
| cashew            | cashew        | 7979  | TCPv6     | |
| cherry            | cherry        | 24359 | TCPv6     | |
| coney             | coney         | 65214 | TCPv6     | |
| desheepd          | desheepd      | 547   | UDPv6     | |
| dog               | dog           | ????? | ???v6     | NOT RUNNING: Cannot open `/usr/local/ctp/lib/perl5/5.16.0/i386-freebsd/CORE/libperl.so` |
| gallows           | gallows       | 6666  | TCPv6     | |
| intception        | dealer        | 8888  | TCPv6     | |
| jerkin            | jerkin        | 63715 | TCPv6     | |
| mixology          | mixology      | 35575 | TCPv6     | |
| nom               | nom           | 7368  | TCPv6     | |
| nssds             | nssds         | 54339 | TCPv6     | |
| ocrd              | ocrd          | 31967 | TCPv6     | |
| parrot            | parrot        | ????? | ???v6     | NOT RUNNING: Cannot open `/usr/local/ctp/lib/perl5/5.16.0/i386-freebsd/CORE/libperl.so` |
| ralph             | ralph         | 57553 | TCPv6     | |
| scool             | scool         | 4637  | TCPv6     | |
| semem             | semem         | 6941  | TCPv6     | |
| tictactoe         | tictactoe     | 25375 | TCPv6     | |
| torqux            | torqux        | ????? | ???v6     | NOT RUNNING: Must be run with `python2.7` directly (still doesn't seem to work?) |
| zul               | zul           | 25201 | TCPv6     | |


## Setting Up Your Own VM ##

In case you don't like the VM I've created, here's some quick documentation on how I set up the VM myself!

### Initial Setup ###

The initial setup is simple:

* Installed FreeBSD 9.1 with default options from the i386 install media
* Uncommented and set "PermitRootLogin" to "yes" in /etc/ssh/sshd_config with `vi`
* Ran `/etc/rc.d/sshd restart` so I could SSH/SCP

*NOTE: In the real CTF, each team would actually get a FreeBSD jail, rather than a VM. For simplicity, I've set
everything up outside of a jail. I hope to find my documentation on jails and include it here in the future if anyone
wants to set things up more authentically. For now, you'll just have to make do with this approximation.*

## Service Setup ##

Setting up services was a little more involved. In order to run a given service, you will generally have to create a
user and home directory for that user. This is because most DEFCON CTF services will "drop" privileges from root to an
unprivileged user specific to the service, just like real services. The ownership of the binary will also need to be
changed to prevent unwanted modifications. To do this:

```
# create a user with a given name (-n), shell (-s), and home directory (-m)
pw useradd -n <username> -s /usr/bin/false -m
chmod 750 /usr/home/<username>
chown root:<username> /path/to/service
chmod 750 /path/to/service
```

Binaries before DEFCON 19 were located inside each service's home folder. Starting in DEFCON 19, however, they were
moved to `/usr/local/sbin`. Either approach is fine, but I found it easier to place all the services in
`/usr/local/sbin`.

Flags were typically stored in a file called "key" inside of each user's home directory. A kernel module was used to
change these out periodically (about once every 2-5 minutes or so). Since I don't have a similar kernel module, I just
placed the `sha1sum` of the service into the flag file:

```
sha1 /path/to/service | cut -d' ' -f4 > /usr/home/<username>/key
chmod 540 /usr/home/<username>/key
```

At this point, running the service should be as easy as:

```
/path/to/service &
```

You can check if it is running/listening by doing:

```
ps aux | grep <service>  # check if it is running
sockstat | grep <service>  # check if it is listening (and on what port)
```

If that doesn't work, check the table above to see if there are any caveats for a particular service. Some services
require extra stuff to be installed, configured, or otherwise present in order for it to function. Some were also not
actually network services and had to be run locally.

Once a service is running, you should be able to use netcat to connect to it:

```
nc <hostname or address> <port>  # for IPv4
nc6 <hostname or address> <port>  # for IPv6
```

Note that services won't start up by default unless you create an `/etc/rc.d` startup script for them. The template I
created for these, if you'd like to develop your own, is called rc_d_template in the top level of this repository.

