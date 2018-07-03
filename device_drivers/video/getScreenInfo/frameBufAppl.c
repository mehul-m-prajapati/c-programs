#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

struct fb_var_screeninfo vinfo;

int main(int argc, char *argv[])
{
	int fbfd, fbsize, i;
	unsigned char *fbbuf;

	/* Open video memory */
	if ((fbfd = open("/dev/fb0", O_RDWR)) < 0) 
	{
		printf("Frame buffer node opening failed !!!\n");
		exit(1);
	}

	/* Get variable display parameters */
	if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo))
	{
	
		printf("Bad vscreeninfo ioctl\n");
		exit(2);
	}

	/* Size of frame buffer = (X-resolution * Y-resolution * bytes per pixel) */
	fbsize = vinfo.xres * vinfo.yres * (vinfo.bits_per_pixel/8);

	printf("xres = %d yres = %d bits = %d\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

	/* Map video memory */
	if ((fbbuf = mmap(0, fbsize, PROT_READ|PROT_WRITE, MAP_SHARED, fbfd, 0)) == (void *) -1)
	{
		exit(3);
	}

	/* Clear the screen */
	for (i = 0; i < fbsize; i++) 
	{
		*(fbbuf+i) = 0x00;
	}

	munmap(fbbuf, fbsize);
	close(fbfd);

	return 0;
}

