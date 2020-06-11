

#ifndef LCD4_H_
#define LCD4_H_

/*Khai bao ket noi chan */
#define LCD_EN	1	/*EN = PD2*/
//#define LCD_RW	1	/*RW = PD1*/
#define LCD_RS	0	/*RS = PD0*/
#define LCD_D4	4
#define LCD_D5 	5
#define LCD_D6 	6
#define LCD_D7 	7
#define LCD_PORT PORTD
#define LCD_DDR 	DDRD
/*-------------------------------------*-
	LCD commands
-*-------------------------------------*/
#define _LCD_CLEAR				1
#define _LCD_RETURN_HOME		2
#define _LCD_ENTRY_MODE			6
#define _LCD_TURN_OFF			8
#define _LCD_TURN_ON			12
#define _LCD_CURSOR_OFF			12
#define _LCD_UNDERLINE_ON		14
#define _LCD_BLINK_CURSOR_ON	15
#define _LCD_MOVE_CURSOR_LEFT	16
#define _LCD_MOVE_CURSOR_RIGHT	17
#define _LCD_SHIFT_LEFT			24
#define _LCD_SHIFT_RIGHT		28
#define _LCD_4BIT_1LINE_5x7FONT	0x20
#define _LCD_4BIT_2LINE_5x7FONT	0x28
#define _LCD_8BIT_1LINE_5x7FONT	0x30
#define _LCD_8BIT_2LINE_5x7FONT	0x38
#define _LCD_FIRST_ROW			128
#define _LCD_SECOND_ROW			192

void LCD_Send1Byte(unsigned char c);
void LCD_Clear();
void LCD_Str(char *str);
void LCD_Str_Cursor(unsigned char row, unsigned char col, char *s);
void LCD_Char(unsigned char chr);
void LCD_Char_Cursor(unsigned char row,unsigned char col,unsigned char chr);
void LCD_Init();
void LCD_Enable();
void LCD_SetCursor(unsigned char row, unsigned char col);
void LCD_Left();
void LCD_Right();


#endif /* LCD4_H_ */
