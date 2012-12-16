#include "SkBitmap.h"
#include "SkDevice.h"
#include "SkPaint.h"
#include "SkRect.h"
#include "SkImageEncoder.h"
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>


using namespace std;

#ifndef __u32
#define __u32 uint32_t
#endif

#define cprintf printf
#define sys_linux_mmap mmap

struct fb_bitfield {
        __u32 offset;                   /* beginning of bitfield        */
        __u32 length;                   /* length of bitfield           */
        __u32 msb_right;                /* != 0 : Most significant bit is */ 
                                        /* right */ 
};

struct fb_var_screeninfo {
        __u32 xres;                     /* visible resolution           */
        __u32 yres;
        __u32 xres_virtual;             /* virtual resolution           */
        __u32 yres_virtual;
        __u32 xoffset;                  /* offset from virtual to visible */
        __u32 yoffset;                  /* resolution                   */

        __u32 bits_per_pixel;           /* guess what                   */
        __u32 grayscale;                /* != 0 Graylevels instead of colors */

        struct fb_bitfield red;         /* bitfield in fb mem if true color, */
        struct fb_bitfield green;       /* else only length is significant */
        struct fb_bitfield blue;
        struct fb_bitfield transp;      /* transparency                 */      

        __u32 nonstd;                   /* != 0 Non standard pixel format */

        __u32 activate;                 /* see FB_ACTIVATE_*            */

        __u32 height;                   /* height of picture in mm    */
        __u32 width;                    /* width of picture in mm     */

        __u32 accel_flags;              /* (OBSOLETE) see fb_info.flags */

        /* Timing: All values in pixclocks, except pixclock (of course) */
        __u32 pixclock;                 /* pixel clock in ps (pico seconds) */
        __u32 left_margin;              /* time from sync to picture    */
        __u32 right_margin;             /* time from picture to sync    */
        __u32 upper_margin;             /* time from sync to picture    */
        __u32 lower_margin;
        __u32 hsync_len;                /* length of horizontal sync    */
        __u32 vsync_len;                /* length of vertical sync      */
        __u32 sync;                     /* see FB_SYNC_*                */
        __u32 vmode;                    /* see FB_VMODE_*               */
        __u32 rotate;                   /* angle we rotate counter clockwise */
        __u32 reserved[5];              /* Reserved for future compatibility */
};

#define FBIOGET_VSCREENINFO     0x4600

#define GetPixelR(x) ((x>>16)&((1<<8)-1))
#define GetPixelG(x) ((x>>8)&((1<<8)-1))
#define GetPixelB(x) ((x>>0)&((1<<8)-1))

static void build_pixel_map(SkBitmap &bitmap){
  int fd;
  struct fb_var_screeninfo vinfo;
  int logo_height= bitmap.height();
  int logo_width= bitmap.width();
    int i,j;
    int w = 800;
    int h = 600;
    int x = (w - logo_width)/2;
    int y = (h - logo_height)/2;
    int v = 2, u = 2;
//以下打开framebuffer并映射内存
    fd = open("fb0:", O_RDWR);
    if (ioctl(fd, FBIOGET_VSCREENINFO, &vinfo) <0) {
    	cprintf("ioctl error\n");
    	bitmap.setConfig(SkBitmap::kRGB_565_Config, w, h);
    	bitmap.allocPixels();
        bitmap.eraseColor(0);
    	return;
    } else {
      cprintf("fb0 vinfo: %dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);
      w = vinfo.xres;
      h = vinfo.yres;
    }
    close(fd);
    bitmap.setConfig(SkBitmap::kRGB_565_Config, w, h);

    
   // assert(logo_height < h && logo_width < w);

    int size = w*h*vinfo.bits_per_pixel/8;

    fd = open("fb0:", O_RDWR);
//buf == 显存首地址，向里面写数据即可显示
    unsigned short* buf = (unsigned short*)sys_linux_mmap(0, size,0,0, fd, 0);
    cprintf("linux_mmap %08x\n", buf);

    bitmap.setPixels(buf);
    //close(fd);

    //unsigned short* buf = (unsigned short*)malloc(size);
    //assert(buf);
//清屏
    memset(buf, 0x1f, size);
    /*unsigned short color;
    for(int i=0;i<logo_height;i++){
      for(int j=0;j<logo_width;j++){
    	  unsigned short pixel=bitmap.getColor(i,j);
        color = ((GetPixelR(pixel)>>3)<<11)
          |((GetPixelG(pixel)>>2)<<5)
          |((GetPixelB(pixel)>>3));
        buf[i*w + j] = *bitmap.getAddr16(i,j);
      }
    }*/
}


int main()
{
       // Declare a raster bitmap, which has an integer width and height,
       // and a format (config), and a pointer to the actual pixels.
       // Bitmaps can be drawn into a SkCanvas, but they are also used to
       // specify the target of a SkCanvas' drawing operations.
		printf("start\n");
       SkBitmap bitmap;
       build_pixel_map(bitmap);

       // A Canvas encapsulates all of the state about drawing into a
       // device (bitmap).  This includes a reference to the device itself,
       // and a stack of matrix/clip values. For any given draw call (e.g.
       // drawRect), the geometry of the object being drawn is transformed
       // by the concatenation of all the matrices in the stack. The
       // transformed geometry is clipped by the intersection of all of the
// clips in the stack.
       SkCanvas canvas(bitmap);

       // SkPaint class holds the style and color information about how to
       // draw geometries, text and bitmaps.
       SkPaint paint;
       // SkIRect holds four 32 bit integer coordinates for a rectangle.
       SkRect r;
       paint.setARGB(255, 255, 0, 0);
       r.set(25, 25, 145, 145);
       canvas.drawRect(r, paint);
       sleep(1);

       paint.setARGB(255, 0, 255, 0);
       r.offset(20, 20);
       canvas.drawRect(r, paint);
       sleep(1);

       paint.setARGB(255, 0, 0, 255);
       r.offset(20, 20);
       canvas.drawRect(r, paint);
       sleep(1);

       paint.setARGB(255, 255, 255, 255);
       //canvas.drawText("Hello, world", 12, 10, 10, paint);
       /*for (int i=0;i<20;i++) {
           for (int j=0;j<20;j++) {
        	   u_int32_t ans=bitmap.getColor(i,j);
        	   printf("%d",((ans >> 0) & (( 1 << 8 ) - 1)));
           }
           printf("\n");
       }*/

//	SkImageEncoder is the base class for encoding compressed images
//	from a specific SkBitmap.
	printf("%d\n", SkImageEncoder::EncodeFile("snapshot.png", bitmap,
		SkImageEncoder::kPNG_Type,
		100));
	getchar();
       return 0;
}
