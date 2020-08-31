
# reMarkable-Qt
WIP Qt Client for managing files with the reMarkable Tablet.

Currently works with PDF file management only.
# Screenshot
![app](https://raw.githubusercontent.com/JohnCiubuc/reMarkable-Qt/master/Images/ss.png)
## Pre-Build Instructions
Requires the following build tools and maybe some others:
* ssh
* sshfs
* generic build tools

Create your public key for reMarkable, because this program can't login when prompted with a password:

```bash
$ ssh-copy-id root@server_ip_address
```

where server_ip_address can be found via `Menu->Settings->About->Bottom left (scroll down)`

Then the following needs to be done till I make it friendly:

	1. change line 12 in mainwindow.cpp with new ip


## Build Instructions
```bash
git clone https://github.com/JohnCiubuc/reMarkable-Qt
cd reMarkable-Qt
# -> Change IP on Line 12 in mainwindow.cpp <-
mkdir build && cd build
cmake .. && make
```

# Usage Instructions

* On startup, if IP is valid, should auto-mount the tablet to a random /tmp dir and connect to it
* Import new file lets you import a new PDF to your tablet
	* No progress bar on copy
	* Auto-refreshes when import is done
	* Can take long for larger files
* Delete file deletes any PDF on the tablet
	* Select pdf thumbnail
	* Delete
* Refresh
	* Refreshes the application's PDF view
	* Does NOT affect the tablet -- it's only for the application
* Sync
	* Restarts remarkable's xochitl service
	* Requires `ssh`
	* 9 times out of 10 PDF changes will be seen
	* 1 time out of 10 the tablet freezes 
		* No file damage has occurred, I promise.
* Reboot
	* Reboots your reMarkable tablet
	* Useful when Sync freezes
	

# TODO

* progress bar?
* Drag and drop
* Ip easy entry
* ebooks and other stuff?
