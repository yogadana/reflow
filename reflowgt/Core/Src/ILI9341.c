#include "ILI9341.h"
#include <string.h>
#include <stdlib.h>

uint8_t rotationNum = 1;
static bool _cp437    = false;

__STATIC_INLINE void DelayMicro(__IO uint32_t micros)
{
        micros *=(SystemCoreClock / 1000000) / 5;
        while (micros--);
}

void ILI9341_SendCommand(uint8_t com){
	*(__IO uint8_t*)(0x60000000) = com;
}

void ILI9341_SendData(uint8_t data){
	*(__IO uint8_t*)(0x60010000) = data;
}

void ILI9341_WriteReg(uint8_t Command, uint8_t *Parameters, uint8_t NbParameters)
{
  uint8_t   i;

  /* Send command */
  ILI9341_SendCommand(Command);

  /* Send command's parameters if any */
  for (i=0; i<NbParameters; i++)
  {
	  ILI9341_SendData(Parameters[i]);
  }
}

uint32_t ILI9341_ReadReg(uint8_t r)
{
        uint32_t id;
        uint8_t x;

        ILI9341_SendCommand(r);
        DelayMicro(50);

    	x=ADDR_DATA;
        id=x;
        id<<=8;
        DelayMicro(1);

        x=ADDR_DATA;
        id|=x;
        id<<=8;
        DelayMicro(1);

		x=ADDR_DATA;
        id|=x;
        id<<=8;

		DelayMicro(1);
        x=ADDR_DATA;
        id|=x;

		if(r==0xEF)
        {
                id<<=8;
                DelayMicro(5);
                x=ADDR_DATA;
                id|=x;
        }
        DelayMicro(150);
        return id;
}

void ILI9341_reset(void)
{
        RESET_ACTIVE;
        HAL_Delay(2);
        RESET_IDLE;
        ILI9341_SendCommand(0x01);
        for (uint8_t i=0;i<3;i++)
        	ILI9341_SendData(0xFF);
}

void ILI9341_Init(void)
{
	    ILI9341_reset();
	    HAL_Delay(1000);
	    ILI9341_Configuration();
	    ILI9341_setRotation(4);
	    HAL_Delay(1000);
}

void ILI9341_Configuration(){
	/* Steps
	 1:Software Reset
	 2:Display Off
	 3:POWER1 - POWER2 Configuration
	 4:VCOM1-VCOM2 Configuration
	 5: Memory Access Configuration(This command defines read/write scanning direction of frame memory.)
	 6:Pixel Format Set
	 7:Frame Rate Configuration
	 8:Column And Page Adress
	 9:Tearing Effect Off
	 10:Entry Mode Set
	 11:Display Function
	 12:Sleep Out
	 //13:Display On
	 */

	// 1: Software Reset
	ILI9341_SendCommand(ILI9341_RESET);
	HAL_Delay(120);

	// 2:Dislay Off
	ILI9341_SendCommand(ILI9341_DISPLAY_OFF);

	//3 POWER1 - POWER2 Configuration
	ILI9341_SendCommand(ILI9341_POWER1);
	ILI9341_SendData(0x26);
	DelayMicro(1);
	ILI9341_SendCommand(ILI9341_POWER2);
	ILI9341_SendData(0x11);       //BT[2:0] = 0 0 1 DDVDH=2 VGH=7 -VCI*3
	DelayMicro(1);

	//4 VCOM1-VCOM2
	ILI9341_SendCommand(ILI9341_VCOM1);
	ILI9341_SendData(0x35);				//VMH [6:0] = 0110101  VCOMH(V) =   4.025
	ILI9341_SendData(0x3e);				//VML [6:0] = 0111110  VCOML(V) =  -0.950v
	DelayMicro(1);

	ILI9341_SendCommand(ILI9341_VCOM2);
	ILI9341_SendData(0xbe);            // VMF[6:0]= 1000001 =>  VMH + 1 - VML + 1   When nVM(8.bit) set to “1”, setting
	DelayMicro(1);					  //of VMF [6:0] becomes valid and VCOMH/VCOML can be adjusted.


	/*5: Memory Access Configuration(This command defines read/write scanning direction of frame memory.)
	 [7:0]  ->
	           0-1.bit: Null
	           2.bit  : MH Horizontal Refresh ORDER LCD horizontal refreshing direction control
	           3.bit  : BGR RGB-BGR Order Color selector switch control(0=RGB color filter panel, 1=BGR color filter panel)
	           4.bit  : ML Vertical Refresh Order LCD vertical refresh direction control.
	           5.bit  : MV Row / Column Exchange
	           6.bit  : MX Column Address Order
	           7.bit  : MY Row Address Order
	 */
	ILI9341_SendCommand(ILI9341_MAC);
	ILI9341_SendData(0x48);        // [7:0] = 0 1 0 0 1 0 0 0
//	ILI9341_SendData(0x08);
	DelayMicro(1);


	/*6: Pixel Format Configuration
	  [7:0] => DBI[2:0]  MCU Interface Format = 1 1 1 (Reserved)
	 	 	=> DPI[2:0]  RGB Interface Format = 1 1 0 (18 bits / pixel )
	 	 	=> 7.Bit     Null
	  */
	ILI9341_SendCommand(ILI9341_PIXEL_FORMAT);
	ILI9341_SendData(0x55); // [7:0] = 0 1 1 0 1 1 1 Pixel format 18bit seçildi
	DelayMicro(1);

	// 7:Frame Rate Configuration
	ILI9341_SendCommand(ILI9341_FRC);
	ILI9341_SendData(0);     //Clock Division 1
	ILI9341_SendData(0x3D);  //RTNA [4:0] = 1 0 1 1 1  => Frame Rate(Hz) = 83 Hz
	DelayMicro(1);			 //RTNA [4:0] = 1 0 0 0 0  => Frame Rate(Hz) = 119 Hz


	//8:Column And Page Adress
	ILI9341_SendCommand(ILI9341_COLUMN_ADDR);
	ILI9341_SendData(0x00);   // x0_HIGH---0
	ILI9341_SendData(0x00);	  // x0_LOW----0
	ILI9341_SendData(0x00);   // x1_HIGH---240
	ILI9341_SendData(0xEF);   // x1_LOW----240

	ILI9341_SendCommand (ILI9341_PAGE_ADDR); // page address set
	ILI9341_SendData   (0x00); // y0_HIGH---0
	ILI9341_SendData   (0x00); // y0_LOW----0
	ILI9341_SendData   (0x01); // y1_HIGH---320
    ILI9341_SendData   (0x3F); // y1_LOW----320


    //9:Tearing Effect Off
    ILI9341_SendCommand (ILI9341_TEARING_OFF);

    /* 10:Entry Mode Set
     D[7:0]  : 0 0 0 0 0 GON DTE GAS
     GAS    : Low voltage detection control => 1 low voltage detection disable
     GON/DTE: Set the output level of gate driver G1 =>1 1 = Normal display
     */
    ILI9341_SendCommand (ILI9341_Entry_Mode_Set);
    ILI9341_SendData(0x07);

    /*11:Display Function
     1st parameter : 0 0 0 0 PTG [1:0] PT [1:0]
     2nd parameter : REV GS SS SM ISC [3:0] 8
     3rd parameter : 0 0 NL [5:0]
     4th parameter : 0 0 PCDIV [5:0]
     * */
    ILI9341_SendCommand (ILI9341_DFC);
    ILI9341_SendData   (0x0a);
    ILI9341_SendData   (0x82);
    ILI9341_SendData   (0x27);
    ILI9341_SendData   (0x00); // clock divisor

    //12:Sleep Out
    ILI9341_SendCommand (ILI9341_SLEEP_OUT);
    HAL_Delay(100);

    //13:Display On
    ILI9341_SendCommand (ILI9341_DISPLAY_ON);
    HAL_Delay(100);

    //14:Memory Write
    ILI9341_SendCommand (ILI9341_GRAM); // memory write
    HAL_Delay(5);
}

void ILI9341_SetCursorPosition(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
  ILI9341_SendCommand (ILI9341_COLUMN_ADDR);
  ILI9341_SendData(x1>>8);
  ILI9341_SendData(x1 & 0xFF);
  ILI9341_SendData(x2>>8);
  ILI9341_SendData(x2 & 0xFF);

  ILI9341_SendCommand (ILI9341_PAGE_ADDR);
  ILI9341_SendData(y1>>8);
  ILI9341_SendData(y1 & 0xFF);
  ILI9341_SendData(y2>>8);
  ILI9341_SendData(y2 & 0xFF);
  ILI9341_SendCommand (ILI9341_GRAM);
}

void ILI9341_SetWindow(uint16_t start_x, uint16_t start_y, uint16_t end_x, uint16_t end_y) {
	ILI9341_SendCommand(0x2a);
	ILI9341_SendData(start_x >> 8);
	ILI9341_SendData(0xFF & start_x);
	ILI9341_SendData(end_x >> 8);
	ILI9341_SendData(0xFF & end_x);
	ILI9341_SendCommand(0x2b);
	ILI9341_SendData(start_y >> 8);
	ILI9341_SendData(0xFF & start_y);
	ILI9341_SendData(end_y >> 8);
	ILI9341_SendData(0XFF & end_y);
}

void ILI9341_DrawPixel(uint16_t x, uint16_t y, uint16_t color) {
  ILI9341_SetCursorPosition(x, y, x, y);
	ILI9341_SendData(color>>8);
	ILI9341_SendData(color&0xFF);
}

void ILI9341_Fill(uint16_t color){
	uint32_t n = ILI9341_PIXEL_COUNT;
	if(rotationNum==1 || rotationNum==3)
	{
		ILI9341_SetCursorPosition(0, 0,   ILI9341_WIDTH -1, ILI9341_HEIGHT -1);
	}
	else if(rotationNum==2 || rotationNum==4)
	{
		ILI9341_SetCursorPosition(0, 0, ILI9341_HEIGHT -1, ILI9341_WIDTH -1);
	}

	while(n){
		n--;
		ILI9341_SendData(color>>8);
		ILI9341_SendData(color);
	}
}

void ILI9341_setRotation(uint8_t rotation){

	switch (rotation) {
		case 2:
			rotationNum = 2;
			ILI9341_SendCommand(ILI9341_MEMCONTROL);
			ILI9341_SendData(ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
			break;
		case 3:
			rotationNum = 3;
			ILI9341_SendCommand(ILI9341_MEMCONTROL);
			ILI9341_SendData(ILI9341_MADCTL_MX | ILI9341_MADCTL_BGR);
			break;
		case 4:
			rotationNum = 4;
			ILI9341_SendCommand(ILI9341_MEMCONTROL);
			ILI9341_SendData(ILI9341_MADCTL_MX | ILI9341_MADCTL_MY | ILI9341_MADCTL_MV | ILI9341_MADCTL_BGR);
			break;
		default:
			rotationNum = 1;
			ILI9341_SendCommand(ILI9341_MEMCONTROL);
			ILI9341_SendData(ILI9341_MADCTL_MY | ILI9341_MADCTL_BGR);
			break;

	}

}

void ILI9341_Fill_Rect(unsigned int x0,unsigned int y0, unsigned int x1,unsigned int y1, uint16_t color) {
	uint32_t n = ((x1+1)-x0)*((y1+1)-y0);
	if (n>ILI9341_PIXEL_COUNT) n=ILI9341_PIXEL_COUNT;
	ILI9341_SetCursorPosition(x0, y0, x1, y1);
	while (n) {
			n--;
      ILI9341_SendData(color>>8);
				ILI9341_SendData(color&0xff);
	}
}

void ILI9341_drawChar(int16_t x,int16_t y,unsigned char c,uint16_t color,uint16_t bg,uint16_t size){

	uint16_t width = ILI9341_WIDTH;
	uint16_t height = ILI9341_HEIGHT;

	if(rotationNum == 2 || rotationNum == 4){
		width = ILI9341_HEIGHT;
		height = ILI9341_WIDTH;

	}

	if(	(x>=width)  ||
		(y>=height) ||
		((x+6*size-1)<0)	||
		((y+8*size-1)<0)){
		return;
	}

	if((!_cp437)&&(c>=176)) c++;

	for(int8_t i = 0; i<6;i++){
		uint8_t line;
		if(i==5)
			line = 0x00;

		else
			line = pgm_read_byte(font1 + (c*5)+i);

		for(int8_t j = 0;j < 8;j++){
			if(line & 0x1){
				if(size == 1)
					ILI9341_DrawPixel(x+i,y+j,color);
		        else {  // big size
		          ILI9341_Fill_Rect(x+(i*size), y+(j*size), size + x+(i*size), size+1 + y+(j*size), color);
		        }
			}
			line >>= 1;
		}
	}
}

void ILI9341_printText(char text[], int16_t x, int16_t y, uint16_t color, uint16_t bg, uint8_t size)
{
	int16_t offset;
	offset = size*6;
	for(uint16_t i=0; i<40 && text[i]!='\0'; i++)
	{
		ILI9341_drawChar(x+(offset*i), y, text[i],color,bg,size);
	}
}


// baruu //


/* Asumsikan makro berikut sudah didefinisikan, misalnya di ILI9341.h */
#ifndef ILI9341_WIDTH
  #define ILI9341_WIDTH   320
#endif

#ifndef ILI9341_HEIGHT
  #define ILI9341_HEIGHT  240
#endif

/* Variabel global untuk batas window tampilan */
static uint16_t WindowXstart = 0;
static uint16_t WindowYstart = 0;
static uint16_t WindowXend   = ILI9341_WIDTH - 1;
static uint16_t WindowYend   = ILI9341_HEIGHT - 1;

void ILI9341_SetDisplayWindow(uint16_t Xpos, uint16_t Ypos, uint16_t Width, uint16_t Height)
{
    if (Xpos < ILI9341_WIDTH)
    {
        WindowXstart = Xpos;
    }
    else
    {
        WindowXstart = 0;
    }

    if (Ypos < ILI9341_HEIGHT)
    {
        WindowYstart = Ypos;
    }
    else
    {
        WindowYstart = 0;
    }

    if ((Width + Xpos) <= ILI9341_WIDTH)
    {
        WindowXend = Width + Xpos - 1;
    }
    else
    {
        WindowXend = ILI9341_WIDTH - 1;
    }

    if ((Height + Ypos) <= ILI9341_HEIGHT)
    {
        WindowYend = Height + Ypos - 1;
    }
    else
    {
        WindowYend = ILI9341_HEIGHT - 1;
    }
}

static void ILI9341_DrawRGBHLine(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint8_t *pdata)
{
  uint32_t i = 0;
  uint32_t posX;
  uint16_t *rgb565 = (uint16_t*)pdata;

  /* Prepare to write to LCD RAM */
  ILI9341_WriteReg(ILI9341_GRAM, (uint8_t*)NULL, 0);   /* RAM write data command */

  for (posX = Xpos; posX < (Xsize + Xpos); posX++)
  {
    if ((posX >= WindowXstart) && (Ypos >= WindowYstart) &&     /* Check we are in the defined window */
        (posX <= WindowXend) && (Ypos <= WindowYend))
    {
      if (posX != (Xsize + Xpos))     /* When writing last pixel when size is odd, the third part is not written */
      {
    	  ILI9341_SendData(rgb565[i] >> 8);
    	  ILI9341_SendData(rgb565[i] & 0xFF);
      }
      i++;
    }
  }
}


//void ILI9341_DrawBitmap(uint16_t Xpos, uint16_t Ypos, uint8_t *pbmp)
//{
//  uint32_t index = 0, size = 0;
//  uint32_t posY;
//  uint32_t nb_line = 0;
//  uint16_t Xsize = WindowXend - WindowXstart + 1;
//  uint16_t Ysize = WindowYend - WindowYstart + 1;
//
//  /* Read bitmap size */
//  size = *(volatile uint16_t *) (pbmp + 2);
//  size |= (*(volatile uint16_t *) (pbmp + 4)) << 16;
//  /* Get bitmap data address offset */
//  index = *(volatile uint16_t *) (pbmp + 10);
//  index |= (*(volatile uint16_t *) (pbmp + 12)) << 16;
//  size = (size - index)/2;
//  pbmp += index;
//
//  for (posY = (Ypos + Ysize); posY > Ypos; posY--)  /* In BMP files the line order is inverted */
//  {
//    /* Set Cursor */
//		ILI9341_SetCursor(Xpos, posY - 1);
//
//    /* Draw one line of the picture */
//		ILI9341_DrawRGBHLine(Xpos, posY - 1, Xsize, (pbmp + (nb_line * Xsize * 2)));
//    nb_line++;
//  }
//}

void ILI9341_DrawRGBImage(uint16_t Xpos, uint16_t Ypos, uint16_t Xsize, uint16_t Ysize, uint8_t *pdata)
{
  uint16_t posY;
  uint16_t nb_line = 0;

  for (posY = Ypos; posY < (Ypos + Ysize); posY ++)
  {
    /* Set Cursor */
	  ILI9341_SetCursorPosition(Xpos, posY, Xpos + Xsize - 1, posY + Ysize -1);

    /* Draw one line of the picture */
	  ILI9341_DrawRGBHLine(Xpos, posY, Xsize, (pdata + (nb_line * Xsize * 2)));
    nb_line++;
  }
}

/**
 * @file lv_port_disp_templ.c
 *
 */

/*Copy this file as "lv_port_disp.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>

/*********************
 *      DEFINES
 *********************/
#define MY_DISP_HOR_RES    320
#define MY_DISP_VER_RES    240

#define BYTE_PER_PIXEL (LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_RGB565)) /*will be 2 for RGB565 */

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void disp_init(void);

static void disp_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_disp_init(void)
{
    /*-------------------------
     * Initialize your display
     * -----------------------*/
    disp_init();

    /*------------------------------------
     * Create a display and set a flush_cb
     * -----------------------------------*/
    lv_display_t * disp = lv_display_create(MY_DISP_HOR_RES, MY_DISP_VER_RES);
    lv_display_set_flush_cb(disp, disp_flush);

    /* Example 1
     * One buffer for partial rendering*/
//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_1_1[MY_DISP_HOR_RES * 10 * BYTE_PER_PIXEL];            /*A buffer for 10 rows*/
//    lv_display_set_buffers(disp, buf_1_1, NULL, sizeof(buf_1_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* Example 2
     * Two buffers for partial rendering
     * In flush_cb DMA or similar hardware should be used to update the display in the background.*/
    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_1[MY_DISP_HOR_RES * 10 * BYTE_PER_PIXEL];
//
    LV_ATTRIBUTE_MEM_ALIGN
    static uint8_t buf_2_2[MY_DISP_HOR_RES * 10 * BYTE_PER_PIXEL];
    lv_display_set_buffers(disp, buf_2_1, buf_2_2, sizeof(buf_2_1), LV_DISPLAY_RENDER_MODE_PARTIAL);

//    /* Example 3
//     * Two buffers screen sized buffer for double buffering.
//     * Both LV_DISPLAY_RENDER_MODE_DIRECT and LV_DISPLAY_RENDER_MODE_FULL works, see their comments*/
//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_3_1[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
//
//    LV_ATTRIBUTE_MEM_ALIGN
//    static uint8_t buf_3_2[MY_DISP_HOR_RES * MY_DISP_VER_RES * BYTE_PER_PIXEL];
//    lv_display_set_buffers(disp, buf_3_1, buf_3_2, sizeof(buf_3_1), LV_DISPLAY_RENDER_MODE_DIRECT);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*Initialize your display and the required peripherals.*/
static void disp_init(void)
{
    /*You code here*/
	ILI9341_Init();
}

volatile bool disp_flush_enabled = true;

/* Enable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_enable_update(void)
{
    disp_flush_enabled = true;
}

/* Disable updating the screen (the flushing process) when disp_flush() is called by LVGL
 */
void disp_disable_update(void)
{
    disp_flush_enabled = false;
}

/*Flush the content of the internal buffer the specific area on the display.
 *`px_map` contains the rendered image as raw pixel map and it should be copied to `area` on the display.
 *You can use DMA or any hardware acceleration to do this operation in the background but
 *'lv_display_flush_ready()' has to be called when it's finished.*/
static void disp_flush(lv_display_t * disp_drv, const lv_area_t * area, uint8_t * px_map)
{
    int16_t Height = area->y2 - area->y1 + 1;
	int16_t Width = area->x2 - area->x1 + 1;
	ILI9341_SetDisplayWindow(area->x1, area->y1, Width, Height);
	ILI9341_DrawRGBImage(area->x1, area->y1, Width, Height, (uint8_t *) px_map);

	//coba
//	uint16_t * buf16 = (uint16_t *)px_map; /* Anggap layar menggunakan format RGB565 */
//	int32_t x, y;
//
//	for(y = area->y1; y <= area->y2; y++) {
//		for(x = area->x1; x <= area->x2; x++) {
//			ILI9341_DrawPixel(x, y, *buf16); // Gunakan ILI9341_DrawPixel
//			buf16++;
//		}
//	}



    /*IMPORTANT!!!
     *Inform the graphics library that you are ready with the flushing*/
    lv_display_flush_ready(disp_drv);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif







