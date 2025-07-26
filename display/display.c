#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "lib/i2c.h"

int main() {
	int fd;
	I2CDevice device;
	const char *data = "HLOWRLD";  // Presumably adds to page_bytes (7 + null)
	ssize_t ret;

	if ((fd = i2c_open("/dev/i2c-0")) == -1) { 
		perror("Open i2c bus error");
		return -1;
	}

	// Fill device struct
	device.bus = fd;
	device.addr = 0x42;  // Placeholder
	device.tenbit = 0;
	device.delay = 10;
	device.flags = 0;
	device.page_bytes = 8; // Might be important; Placeholder
	device.iaddr_bytes = 0; // Set to 0 to ignore "chip" addressing
	
	// Write to I2C
	ret = i2c_ioctl_write(&device, 0x0, data, strlen(data));
	if (ret == -1 || (size_t)ret != strlen(data)) {
		perror("Bus write error");
		return -1;
	}
	

	i2c_close(fd);
	return 0;
}

