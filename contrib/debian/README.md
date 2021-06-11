
Debian
====================
This directory contains files used to package timelockcoind/timelockcoin-qt
for Debian-based Linux systems. If you compile timelockcoind/timelockcoin-qt yourself, there are some useful files here.

## timelockcoin: URI support ##


timelockcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install timelockcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your timelockcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/timelockcoin128.png` to `/usr/share/pixmaps`

timelockcoin-qt.protocol (KDE)

