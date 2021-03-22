#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/mman.h>
#include<time.h>
#include<stdlib.h>
#include<linux/input.h>

int a[16][25] = {0};
int fd = 0;
int *plcd=NULL;//全局变量，方便在不同函数中访问统一地址的值

int read_bmp(char*,int,int);
void test_block(int j,int i);
/*验证mmap的用法*/

/*
	初始化lcd屏
*/
void lcd_init(void)
{
	/*1、打开要映射的文件*/
	fd = open("/dev/fb0",O_RDWR);
	if(fd == -1)
	{
		perror("open lcd error");
		return;
	}
	
	/*2、映射文件到内存中*/
	plcd = mmap(NULL,//映射内存的地址，NULL表示系统自动选择
					800*480*4,//映射内存的大小
					PROT_READ|PROT_WRITE,//映射权限
					MAP_SHARED,//映射方式，共享映射
					fd,//文件描述符，表示要映射的那个文件
					0);//映射文件的起始位置
	if(plcd == MAP_FAILED)
	{
		perror("mmap error");
		close(fd);
		return;
	}
}

/*
	解除屏幕控制
*/
void lcd_uninit(void)
{
	munmap(plcd,800*480*4);
	close(fd);
}

/*
	画点函数
	x/y		点坐标
	color   点颜色
*/
void lcd_draw_point(int x,int y,unsigned int color)
{
	/*（x,y）对应的地址空间推导公式*/
	*(plcd+x+y*800) = color;
}

/*
	清屏函数
	color     清屏颜色
*/
void lcd_clear(unsigned int color)
{
	int x,y;
	for(y=0;y<480;y++)
		for(x=0;x<800;x++)
			lcd_draw_point(x,y,color);
}

/*
	清屏随机颜色
*/
void lcd_rand(void)
{
	int x,y;
	unsigned int color; 
	//教学演示
	while(1)
	{
		srand(time(0));
		color = rand()%0xffffff;
		
		lcd_clear(color);
		
		usleep(400000);
	}
}


/*
	画格子函数
	w       格子宽度
	h       格子高度
	x0/y0   格子起点坐标
	color	格子颜色	
*/
void lcd_draw_block(int x0,int y0,int w,int h,unsigned int color)
{
	int x,y;
	for(y=0;y<h;y++)
	{
		for(x=0;x<w;x++)
		{
			lcd_draw_point(x0+x,y0+y,color);
		}
	}
}

/*
	画n*n格子函数
	n   一行多少个格子
*/
void lcd_draw_nblock(int n)
{
	unsigned int color[2] = {0xff0000,0x00ff00}; 
	int w,h;
	int i;
	w = 800/n;//每个格子宽度
	h = 480/n;//每个格子高度
	
	for(i=0;i<n*n;i++)
	{
		lcd_draw_block(i%n*w,i/n*h,w,h,color[i%2]);
	}
}

/*
	解析bmp图片函数
	file	图片文件名
	x0/y0   图片显示的起始坐标
*/
int read_bmp(char *file,int x0,int y0)
{
	int fd = open(file,O_RDONLY);
	if(fd == -1)
	{
		perror("open bmp error");
		return -1;
	}
	
	/*解析图片大小*/
	int x,y;
	int a=0,r,g,b;
	int color;
	int len;
	int w,h,pix,pix_offset,pix_size;
	unsigned char ch[4] = {0};
	lseek(fd,0x00,SEEK_SET);
	read(fd,ch,2);
	if(ch[0] != 0x42 && ch[1] != 0x4d)
	{
		printf("the image isn't bmp\n");
		return -1;
	}
	
	lseek(fd,0x02,SEEK_SET);
	read(fd,ch,4);
	//bmp图片中整数是以小端模式存放的
	len = ch[0] | ch[1]<<8 | ch[2]<<16 | ch[3]<<24;
	//printf("len=%d\n",len);
	
	/*位图宽度*/
	lseek(fd,0x12,SEEK_SET);
	read(fd,ch,4);
	w = ch[0] | ch[1]<<8 | ch[2]<<16 | ch[3]<<24;
	//printf("w=%d\n",w);
	
	/*位图高度*/
	lseek(fd,0x16,SEEK_SET);
	read(fd,ch,4);
	h = ch[0] | ch[1]<<8 | ch[2]<<16 | ch[3]<<24;
	//printf("h=%d\n",h);
	
	/*位图色深*/
	lseek(fd,0x1c,SEEK_SET);
	read(fd,ch,2);
	pix = ch[0] | ch[1]<<8;
	//printf("pix=%d\n",pix);
	
	/*位图大小,像素数组的大小*/
	pix_size = w*h*pix/8;
	//printf("pix_size=%d\n",pix_size);
	
	/*位图数据地址偏移*/
	lseek(fd,0x0a,SEEK_SET);
	read(fd,ch,4);
	pix_offset = ch[0] | ch[1]<<8 | ch[2]<<16 | ch[3]<<24;
	//printf("pix_offset=%d\n",pix_offset);
	
	/*解析像素数组*/
	unsigned char *tmp;
	unsigned char *p = malloc(pix_size);//定义并分配一个保存像素数组的空间
	lseek(fd,pix_offset,SEEK_SET);
	read(fd,p,pix_size);
	tmp = p;
	for(y=h-1;y>=0;y--)
	{
		for(x=0;x<w;x++)
		{
			b = *tmp++;
			g = *tmp++;
			r = *tmp++;
			if(pix == 32)
			{
				a = *tmp++;
			}
			color =b | g<<8 | r<<16 | a<<24;//0xargb
			//printf("(%d,%d),0x%x\n",x,y,color);
			lcd_draw_point(x+x0,y+y0,color);
		}
	}
	free(p);
	close(fd);
	return 0;
}

int add_lei(void)
{
	int i,j;
	int n = 0;
	int m;
	int b[100] = {0};
	while(1)
	{
		m = rand()%(16*25);
		
		for(j=0;j<=n;j++)
		{
			if(b[j] == m)
			{
				break;
			}
			if(b[j] == 0)
			{
				a[m/25][m%25] = 9;
				b[j] = m;
				n++;
				break;
			}
		}
		if(n == 99)
			break;
		
	}
	
	n=0;
	printf("\n\n\n");
	for(i=0;i<16;i++)
	{
		for(j=0;j<25;j++)
		{
			if(a[i][j] == 9)
				n++;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("n=%d \n",n);
	return 0;
}

int test_num(int i,int j)
{
	if(i<0 || j<0 || i==25 || j==16 || a[i][j] != 9)
		return 0;
	if(a[i][j] == 9)
		return 1;
}

int add_num(int i,int j)
{
	int n =  (test_num(i-1,j-1) + test_num(i,j-1) + test_num(i+1,j-1)
		    +  test_num(i-1,j) +  test_num(i+1,j)
		    +  test_num(i-1,j+1) + test_num(i,j+1) + test_num(i+1,j+1));
	//printf("(%d,%d) %d\n",i,j,n);
	return n;
}

int num_lei(void)
{
	int i,j;
	int n = 0;
	for(i=0;i<16;i++)
	{
		for(j=0;j<25;j++)
		{
			if(a[i][j] == 9)
				continue;
			a[i][j] = add_num(i,j);
			
		}
	}
}

void init_inter(void)
{
	int i;
	for(i=0;i<16*25;i++)
	{
		read_bmp("i.bmp",20+(i%25)*29,7+(i/25)*29);
	}
}

void show_block(int i,int j)
{
	char file[10] = {0};
	if(i>=0&&i<15&&j>0&&j<25)
	{
		sprintf(file,"%d.bmp",a[i][j]);
		read_bmp(file,20+j*29,7+(14-i)*29);
		if(a[i][j] == 0)
			test_block(i,j);
	}
	return;
}

void test_block(int j,int i)
{
	(j-1&&i-1)?show_block(j-1,i-1):0;(j-1)?show_block(j,i-1):0;(j+i&&i-1)?show_block(j+1,i-1):0;
	(j-1)?show_block(j-1,i):0;(j+1)?show_block(j+1,i):0;
	(j-1&&i+1)?show_block(j-1,i+1):0;(i+1)?show_block(j,i+1):0;(j+1&&i+1)?show_block(j+1,i+1):0;
	return;
}

int input(void)
{
	int i = 0,j=0;
	int fd = open("/dev/event0",O_RDWR);
	if(fd == -1)
	{
		perror("open input error");
		return -1;
	}
	
	int x,y,x0,y0;
	struct input_event ev;
	char file[10] = {0};
	while(1)
	{
		read(fd,&ev,sizeof(ev));
		if(ev.type==EV_ABS && ev.code == ABS_X)
		{
			x = ev.value;
		}
		if(ev.type==EV_ABS && ev.code == ABS_Y)
		{
			y = ev.value;
		}
		if(ev.type==EV_ABS && ev.code == ABS_PRESSURE && ev.code > 0)
		{
			x0 = x;
			y0 = y;
		}
		
		if(ev.type==EV_ABS && ev.code == ABS_PRESSURE && ev.value == 0)
		{
			if(abs(x-x0)<25 && abs(y-y0)<25)
			{
				printf("(%d,%d)\n",x,y);
				//read_bmp("0.bmp",20+(i%25)*29,20+(i/25)*29);
				for(i=0;i<25;i++)
				{
					for(j=15;j>=0;j--)
					{
						if(x>20+i*29 && x<49+i*29 
						 &&y>7+j*29 && y<36+j*29)
						{
							printf("%d %d\n",i,j);
							sprintf(file,"%d.bmp",a[j][i]);
							read_bmp(file,20+i*29,7+(15-j)*29);
							if(a[j][i] == 9)
							{
								for(i=0;i<16*25;i++)
								{
									if(a[i/25][i%25] == 9)
										read_bmp("9.bmp",20+(i%25)*29,7+(i/25)*29);
							
								}
								return -1;
							}
							if(a[j][i] == 0)
							{
								test_block(j,i);
							}
						}
					}
				}
			}
		}
		
	}
}


int main(void)
{
	int i,j;
	//lcd_init();
	//lcd_clear(0xffffff);
	add_lei();
	num_lei();
	//init_inter();
	//input();
	printf("\n\n\n");
	for(i=0;i<16;i++)
	{
		for(j=0;j<25;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	lcd_uninit();
	return 0;
}