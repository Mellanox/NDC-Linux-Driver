obj-m = ndc_driver.o
ndc_driver-objs += ndc_linux_driver_main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
