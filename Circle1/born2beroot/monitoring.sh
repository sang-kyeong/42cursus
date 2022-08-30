#!/bin/bash

ARCH_INFO=`uname -a`
CPUS=`lscpu | awk -F ":" 'BEGIN {core=1}; $1=="Socket(s)" {core*=$2}; $1=="Core(s) per socket" {core*=$2}; END {print core}'`
V_CPUS=`lscpu | awk -F ":" 'BEGIN {thread='$CPUS'}; $1=="Thread(s) per core" {thread*=$2}; END {print thread}'`
M_USED=`free -m | awk '$1=="Mem:" {print $3}'`
M_TOTAL=`free -m | awk '$1=="Mem:" {print $2}'`
M_RATIO=$(($((${M_USED} * 100)) / ${M_TOTAL}))
D_USED=`df -BM --total | awk '$1=="total" {print $3}' | sed 's/[^0-9]//g'`
D_TOTAL=`df -BM --total | awk '$1=="total" {print $4}' | sed 's/[^0-9]//g'`
D_RATIO=`df -BM --total | awk '$1=="total" {print $5}' | sed 's/[^0-9]//g'`
CPU_LOAD=`top -n1 | grep "%Cpu(s)" | awk '{print 100-$8}'`
LAST_BOOT=`last boot --time-format iso | sed 's/[T+]/ /g' | awk 'NR==2 {print $3 " " $4}'`
LVM_USE=`lsblk -l | awk 'BEGIN {lvm="no"}; $6=="lvm" {lvm="yes"}; END {print lvm}'`
TCPS=`ss -t | grep ESTAB | wc -l`
LOGINS=`last | grep "still logged in" | wc -l`
IP_ADDR=`ip -br addr show | sed 's/[/]/ /' | awk '$2=="UP" {print $3}' | head -1`
MAC_ADDR=`ip -br link show | awk '$2=="UP" {print $3}' | head -1`

echo "#Architecture    : ${ARCH_INFO}"
echo "#CPU physical    : ${CPUS}"
echo "#vCPU            : ${V_CPUS}"
echo "#Memory Usage    : ${M_USED}/${M_TOTAL}M (${M_RATIO}%)"
echo "#Disk Usage      : ${D_USED}/${D_TOTAL}M (${D_RATIO}%)"
echo "#CPU load        : ${CPU_LOAD}%"
echo "#Last boot       : ${LAST_BOOT}"
echo "#LVM use         : ${LVM_USE}"
echo "#Connections TCP : ${TCPS} ESTABLISHED"
echo "#User log        : ${LOGINS}"
echo "#Network         : IP ${IP_ADDR} (${MAC_ADDR})"
echo "#Sudo            : ${SUDOS} cmd"
