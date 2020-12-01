// MyImage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


///新建工程从以下拷贝///////////////////////////////////
#include <Windows.h>
void SaveAsBmp(const char *file, char* lpImg, int imWidth, int imHeight, bool bDir)
{
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	
	int nNumColors;

	short color =3;
	short wBitCount =color*8;
	long BytesPerLine = imWidth*3;  //WIDTHBYTES(wBitCount*imWidth);
	
    bi.biSize = sizeof(BITMAPINFOHEADER); 
    bi.biWidth = long(imWidth);         // fill in width from parameter 
    bi.biHeight =long(imHeight);       // fill in height from parameter 
    bi.biPlanes = 1;              // must be 1 
    bi.biBitCount = wBitCount;    // from parameter 
    bi.biCompression = BI_RGB;     
    bi.biSizeImage = BytesPerLine* imHeight;           // 0's here mean "default" 
    bi.biXPelsPerMeter = 0; 
    bi.biYPelsPerMeter = 0; 
    bi.biClrUsed = 0; 
    bi.biClrImportant = 0; 
	
	bf.bfType =0x4d42;
	bf.bfSize =sizeof(BITMAPFILEHEADER) +sizeof(BITMAPINFOHEADER)+bi.biSizeImage ;
	bf.bfReserved1 =0;
	bf.bfReserved2 =0;
	bf.bfOffBits =(DWORD)( sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER) );
	
	FILE *fd;
	fd =fopen(file,"wb" );
	
	fwrite( &bf, sizeof(BITMAPFILEHEADER), 1, fd);
	fwrite( &bi, sizeof(BITMAPINFOHEADER), 1, fd);
	
	char* /*lpLine0,*/ lpLine;
	short  nline;
	nline =imWidth*color;

	if(bDir)
			fwrite( lpImg, 1, bi.biSizeImage, fd); // 直接整块写入
		else
		{
			// 倒行写入
			lpLine =lpImg +BytesPerLine*(imHeight-1);
			for(int i=0; i<imHeight; i++)
			{
				fwrite( lpLine, 1, BytesPerLine, fd); // 一行写入
				lpLine -=BytesPerLine;
			}
		}

	
	fclose(fd);
}

char *lpImgData =NULL;
int colImg  =1024,  rowImg =1024; // 宽，高可以改，但是这里宽必须是4的整数倍

//设置像素，第i行，j列的像素 设置颜色为 (r,g,b)
inline void  SetPixel(int j, int i, char r, char g, char b)
{
	if(j>=0 && j< colImg && i>=0 && i< rowImg)  // 这里做了有效范围判断
	{
		char *v = lpImgData + (i*colImg +j)*3;
		v[0] =b;	v[1] =g;	v[2] =r;
	}
}

//修改该函数 ，通过 数学函数、循环条件控制语句，生成几何图案、或一些复杂图画
//可以通过设置坐标 x,y，数学计算的时候，x,y 可以按浮点数，  x相当于j   y相当于i， 进行图像赋值的时候，x,y 取整转成j,i
//如果坐标轴设置在图像中心，做下平移， j = x+ colImg/2,  i =y +rowImg/2
void  CeateImageData()
{
	int i, j;

	//////////////////////////
	//举例： 生成一个直线 y = 2x 
	float x, y;
	for(x=0.0; x<float(colImg/2); x+=1.0)
	{
		j = int(x+ colImg/2 +0.5);

		y= 2.0*x;
		i = int(y +rowImg/2+0.5);

		SetPixel(j, i, 255, 0, 0);
	}
	//////////////////////////////

}

int main(int argc, char* argv[])
{	
	//这里按24位真彩色图像来保存
	lpImgData= new char[colImg* rowImg *3];
	memset(lpImgData, 255, colImg*rowImg*3);  //默认设置为255 白色

	CeateImageData();
	
	const char* fileName ="d:\\wow.bmp";   //生成的图像的路径名
	SaveAsBmp(fileName, lpImgData, colImg, rowImg, true );

	delete lpImgData;

	return 0;
}


//////////////////////////////////////////////////
