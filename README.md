# openrc-bsd-scripts
A collection of openrc scripts, which are designed to replace the BSD init rc scripts, to make switching init systems easier. To add or update a script, simply create a new branch, work on the problem and then file and submit a push request.

<h1>Extended Description</h1>

<h2>Repository Hierarchy</h2>
The Hierarchy of this repository consists of two main folders, named <b>rc.d</b> and <b>init.d</b>. As the name would suggest, rc.d is the folder that is holding the bsd init rc.d scripts, while init.d is holding the scripts edited to work, or rewritten for openrc-init. 
The rc.d folder's starting condition is everything i happened to find accumulated in my own rc.d folder. The init.d folder's starting condition are the scripts that automatically installed together with openrc, namely consisting of: adjkerntz, bootmisc, dumpon, encswap, fsck, functions.sh, hostid, hostname, ipfw, local, localmount, loopback, mixer, modules, moused, netmount, network, newsyslog, nscd, osclock, pf, powerd, rarpd, rc-enabled, root, rpcbind, runsvdir, s6-svscan, staticroute, swap, swclock, syscons, sysctl, syslogd, urandom. They are just in this repository, to be used as reference, together with their counterparts in the rc.d folder.

<h2>Why does this repository exist?</h2>
To make establishing an init.d script base easier, aswell as making maintaining the whole script pack easier, due to the usual open source benefits. 

<h2>How to participate?</h2>
If you want to commit, the steps you need to perform vary, mainly between two possibilities: <u>1.</u> You want to add a script to the rc.d folder, in the hopes of it being converted to init.d somewhere in the future. <u>2.</u> You either want to convert a script from the rc.d folder to init.d, or want to add an init.d service right away.
<b>1.</b> You will have to clone the repository to your computer, then create a new branch (naming scheme: "folder_filename", of the file you want to add), then add the file, commit and file a pull request. <i>[DISCLAIMER: If you are just adding scripts to the rc.d folder, without stating that you will also be responsible for the development, there is a chance that your pull request may be refused, due to too much workload and too few active developers.]</i>
<b>2.</b> You will have to clone the repository to your computer, then create a new branch, same naming scheme as above, same steps as above, but this time your chance to be accepted is higher.
No matter if you  choose 1, or 2, if the file you want to add already exist as branch, you should try to contact the person which created the branch, to not interfere with their work. If not answered for long enough, you may open an issue, or just commit to the branch, since the former owner probably rejected it.

<h2>What to do if i just finished converting a scriptset for a whole package?</h2>
First of all: Awesome work! The best place to store the files in, would be this repo and even better: The original package maintainers, of the package to which the service scripts belongs to, so go to their repository aswell and try submitting your work. If they accept, the load to maintain the scripts won't be on us, but on the original maintainers, which would be better due to them having a better knowledge of future updates.
