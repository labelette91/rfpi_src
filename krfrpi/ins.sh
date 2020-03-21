make
sudo rmmod gpio_freq.ko
sudo rmmod krfrpi.ko
sudo insmod krfrpi.ko 
lsmod 
sudo chown pi /dev/rfrpi*
ls  /dev/rfrpi*
dmesg
