#include "SkBitmap.h"
#include "SkDevice.h"
#include "SkPaint.h"
#include "SkRect.h"
#include "SkStream.h"
#include "SkImageDecoder.h"
#include "SkCamera.h"
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


SkBitmap *pskBitmap;  
SkCanvas *pskCanvas;  
SkBitmap *bkBitmap;//背景图片  
SkRect   g_rtImg;// 图片最初按钮。  
SkRect   g_rtClip;//矩阵裁剪用 ，做图片旋转时，每次旋转时的裁剪会用到上一次的裁剪范围。 
using namespace std;

#define BACKGROUND "background.png"
#define IMAGE "apple.png"

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
    int size = w*h*vinfo.bits_per_pixel/8;

    fd = open("fb0:", O_RDWR);
//buf == 显存首地址，向里面写数据即可显示
    unsigned short* buf = (unsigned short*)sys_linux_mmap(0, size,0,0, fd, 0);
    cprintf("linux_mmap %08x\n", buf);

    bitmap.setPixels(buf);
    memset(buf, 0x1f, size);
}

void MyInitBkImage(char *filename)  
{  
    SkFILEStream stream(filename);  
    SkImageDecoder * coder = SkImageDecoder::Factory(&stream);  
    if (coder)  
    {  
        bkBitmap = new SkBitmap();  
        coder->decode(&stream,bkBitmap,SkBitmap::kRGB_565_Config,SkImageDecoder::kDecodePixels_Mode);
    }  
}  

//整体初始化  
void MyInit()  
{  
    pskBitmap = new SkBitmap(); 
    build_pixel_map(*pskBitmap); 
    pskCanvas = new SkCanvas();  
    pskCanvas->setBitmapDevice(*pskBitmap); 
    MyInitBkImage(BACKGROUND);  
    g_rtImg.setXYWH(140,0,200,246);  
}  

void DrawImage(char * filename,SkCanvas *canvas, SkRect rt, SkPaint *paint)  
{  
    SkFILEStream stream(filename);  
    SkImageDecoder* coder = SkImageDecoder::Factory(&stream);  
    SkBitmap *bitmap;  
    if (coder)  
    {  
        //printf(" file %s code success\n",filename);  
        bitmap = new SkBitmap();  
        coder->decode(&stream, bitmap, SkBitmap::kRGB_565_Config,  
        SkImageDecoder::kDecodePixels_Mode);  
    }  
    else 
    {  
        printf(" file %s code fail\n",filename);  
        return;  
    }  
    canvas->drawBitmap(*bitmap,rt.fLeft, rt.fTop);   
    delete bitmap;  
    return;  
}  

//画背景  
void DrawBKImage()  
{  
    SkIRect rt;  
    rt.setXYWH(0,0,480,800);  
    pskCanvas->drawBitmap(*bkBitmap,rt.fLeft,rt.fTop);   
}  

//画图片filename，效果使其绕Y轴旋转rotateY角度，调用DrawImage()  
void DrawRotateYImage(char * filename,int rotateY,SkRect rtImg)  
{  
    SkRect rtClip = g_rtClip;//保留上次裁剪范围  
    pskCanvas->resetMatrix();  
    SkMatrix matrix;  
    Sk3DView    sk3DView;  
    sk3DView.rotateY(rotateY); //绕Y轴旋转  
    sk3DView.getMatrix(&matrix);  
    matrix.preTranslate(-(rtImg.fLeft+rtImg.width()/2), 0);  
    matrix.postTranslate((rtImg.fLeft+rtImg.width()/2), 0);  
    matrix.mapRect(&g_rtClip,rtImg); //两个参数都是SkRect类型  
    //matrix.mapRect 作用：src经过matrix变化，形成dst  
    //图片的最初范围经过matrix变化(每次绕Y轴旋转角度不一样)，得出新的裁剪范围  
    rtClip.join(g_rtClip);              //计算最终裁剪范围  
    g_rtClip = rtClip ;                 //保存裁剪范围,供下次计算最终裁剪范围  
    DrawBKImage();//此处画背景，不然会保留不同ratateY角度图片的痕迹  ，放在此处 画背景用时多 ，为4或者3，  
    pskCanvas->save();  
    pskCanvas->clipRect(rtClip);//矩阵裁剪  
    //DrawBKImage();//此处画背景，不然会保留不同ratateY角度图片的痕迹    放在此处 画背景用时小 ，为0或者1，  
    //具体画的内容，与pskCanvas画布的裁剪有关系？  
    //pskCanvas->save(SkCanvas::kMatrix_SaveFlag); 可以去掉，之前已经有pskCanvas->save();  
    pskCanvas->concat(matrix);  
    DrawImage(filename,pskCanvas,rtImg,NULL);  
    //此处的位置参数须是图片原始位置，不能是裁剪范围，否则显示的位置偏离  
    //pskCanvas->restore();     与save对应  
    pskCanvas->restore();  
    //pskCanvas->resetMatrix();  
}  

int main()
{
    printf("start\n");
    MyInit();
    DrawBKImage();
    int i=0;
    while (1)
    {  
        i+=5;
        DrawRotateYImage(IMAGE,i,g_rtImg);  
        usleep(200000);
        printf("%d\n",i);
    }  
    return 0;
}
