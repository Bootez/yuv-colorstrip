#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 *Y'= 0.299 x R + 0.587 x G + 0.144 x B
 *U = -0.147 x R - 0.289 x G + 0.436 x B
 *V = 0.615 x R - 0.515 x G - 0.100 x B
 */

/*Make 3color image,Frame Image*/

static void FillImage444(uint8_t *image, int width, int height)
{
    uint8_t *pY = (uint8_t *)(image);
    int y = 0;

    /*Red*/
    for (y = 0; y < width * height / 3; y++) {
        *pY++ = 0x52;   //Y
        *pY++ = 0x5b;   //U
        *pY++ = 0xf0;   //V
    }
    /*Green*/
    for( y = 0; y < width * height / 3; y++)
    {
        *pY++ = 0x91;   //Y
        *pY++ = 0x23;   //U
        *pY++ = 0x37;   //V
    }
    /*Blue*/
    for( y = 0; y < height * width / 3; y++)
    {
        *pY++ = 0x29;   //Y
        *pY++ = 0xf0;   //U
        *pY++ = 0x6f;   //V
    }
}

static void _FillImage420(unsigned char *image,int width,int height)
{
    uint8_t *pY = (uint8_t *)(image);
    uint8_t *pU = (uint8_t *)(image + width * height);
    uint8_t *pV = (uint8_t *)(image + width * height * 5/4);

    int y,x;

    /*Red*/
    memset(pY, 0x52, width*height/4);
    memset(pU, 0x5b, width*height/16);
    memset(pV, 0xf0, width*height/16);

    pY += width*height/4;
    pU += width*height/16;
    pV += width*height/16;
    /*Green*/
    memset(pY, 0x91, width*height/4);
    memset(pU, 0x37, width*height/16);
    memset(pV, 0x23, width*height/16);

    pY += width*height/4;
    pU += width*height/16;
    pV += width*height/16;
    /*Blue*/
    memset(pY, 0x29, width*height/4);
    memset(pU, 0xf0, width*height/16);
    memset(pV, 0x6f, width*height/16);

    pY += width*height/4;
    pU += width*height/16;
    pV += width*height/16;
    /*White*/
    memset(pY, 0xeb, width*height/4);
    memset(pU, 0x80, width*height/16);
    memset(pV, 0x80, width*height/16);

    pY += width*height/4;
    pU += width*height/16;
    pV += width*height/16;
}

static void FillImage420_(unsigned char *image,int width,int height)
{
    uint8_t *pY = (uint8_t *)(image);
    uint8_t *pU = (uint8_t *)(image + width * height);
    uint8_t *pV = (uint8_t *)(image + width * height * 5/4);

    int y,x;

    /*Red*/
    for( y = 0; y < height/8; y ++)
    {
        // 2 line in a loop
        memset(pY, 0x52, width*2);
        memset(pU, 0x5b, width/2);
        memset(pV, 0xf0, width/2);

        pY += width*2;
        pU += width/2;
        pV += width/2;
    }
    /*Green*/
    for( y = 0; y < height/8; y ++)
    {
        // 2 line in a loop
        memset(pY, 0x91, width*2);
        memset(pU, 0x37, width/2);
        memset(pV, 0x23, width/2);

        pY += width*2;
        pU += width/2;
        pV += width/2;
    }
    /*Blue*/
    for( y = 0; y < height/8; y ++)
    {
        // 2 line in a loop
        memset(pY, 0x29, width*2);
        memset(pU, 0xf0, width/2);
        memset(pV, 0x6f, width/2);

        pY += width*2;
        pU += width/2;
        pV += width/2;
    }
    /*White*/
    for( y = 0; y < height/8; y ++)
    {
        // 2 line in a loop
        memset(pY, 0xeb, width*2);
        memset(pU, 0x80, width/2);
        memset(pV, 0x80, width/2);

        pY += width*2;
        pU += width/2;
        pV += width/2;
    }
}

/*Make 3color image,Frame Image*/
static void FillImage420(unsigned char *image,int width,int height)
{
    uint8_t *pY = (uint8_t *)(image);
    uint8_t *pU = (uint8_t *)(image + width * height);
    uint8_t *pV = (uint8_t *)(image + width * height * 5/4);

    int y,x;

    /*Red*/
    for( y = 0; y < height/8; y ++)
    {
        // 2 line
        for( x = 0; x < width/2; x ++)
        {
            *pY++ = 0x52;
            *pY++ = 0x52;
            *pY++ = 0x52;
            *pY++ = 0x52;
            *pU++ = 0x5b;
            *pV++ = 0xf0;
        }
    }
    /*Green*/
    for( y = 0; y < height/8; y ++)
    {
        for( x = 0; x < width/2; x ++)
        {
            *pY++ = 0x91;
            *pY++ = 0x91;
            *pY++ = 0x91;
            *pY++ = 0x91;
            *pU++ = 0x37;
            *pV++ = 0x23;
        }
    }
    /*Blue*/
    for( y = 0; y < height/8; y ++)
    {
        for( x = 0; x < width/2; x ++)
        {
            *pY++ = 0x29;
            *pY++ = 0x29;
            *pY++ = 0x29;
            *pY++ = 0x29;
            *pU++ = 0xf0;
            *pV++ = 0x6f;
        }
    }
    /*White*/
    for( y = 0; y < height/8; y ++)
    {
        for( x = 0; x < width/2; x ++)
        {
            *pY++ = 0xeb;
            *pY++ = 0xeb;
            *pY++ = 0xeb;
            *pY++ = 0xeb;
            *pU++ = 0x80;
            *pV++ = 0x80;
        }
    }
}

/*Make 3color image,Frame Image*/
static void FillImage422(unsigned char *image,int width,int height)
{
    uint8_t *pY = (uint8_t *)(image);
    //uint8_t *pU = (uint8_t *)(image + width * height);
    //uint8_t *pV = (uint8_t *)(image + width * height * 5/4);

    int y,x;

    /*Red*/
    for( y = 0; y < height*width/8; y ++)
    {
        *pY++ = 0x5b;
        *pY++ = 0x52;
        *pY++ = 0xf0;
        *pY++ = 0x52;
    }
    /*Green*/
    for( y = 0; y < height*width/8; y ++)
    {
        *pY++ = 0x37;
        *pY++ = 0x91;
        *pY++ = 0x23;
        *pY++ = 0x91;
    }
    /*Blue*/
    for( y = 0; y < height*width/8; y ++)
    {
        *pY++ = 0xf0;
        *pY++ = 0x29;
        *pY++ = 0x6f;
        *pY++ = 0x29;
    }
    /*White*/
    for( y = 0; y < height*width/8; y ++)
    {
        *pY++ = 0x80;
        *pY++ = 0xeb;
        *pY++ = 0x80;
        *pY++ = 0xeb;
    }
}

#define CONST_WIDTH 640
#define CONST_HEIGHT 480
/*#define CONST_SIZE  (int)(CONST_WIDTH*CONST_HEIGHT*2) //YUV422*/
/*#define CONST_SIZE  (int)(CONST_WIDTH*CONST_HEIGHT*3) //YUV444*/
#define CONST_SIZE  (int)(CONST_WIDTH*CONST_HEIGHT*3/2) //YUV420

int main(int argc, char** argv)
{
    FILE *fp = fopen("out.yuv", "wb");

    uint8_t buffer[CONST_SIZE];

    /*FillImage422(buffer, CONST_WIDTH, CONST_HEIGHT);*/
    /*FillImage444(buffer, CONST_WIDTH, CONST_HEIGHT);*/
    /*FillImage420(buffer, CONST_WIDTH, CONST_HEIGHT);*/
    /*FillImage420_(buffer, CONST_WIDTH, CONST_HEIGHT);*/
    _FillImage420(buffer, CONST_WIDTH, CONST_HEIGHT);
    fwrite(buffer, sizeof(buffer), 1, fp);
    fclose(fp);

    return 0;
}
