#include "../../inc/include.h"





static s16 y = 0;



void write ( char *str, u16 pal, s16 inc )
{
	u16 x = ( screenWidth  >> 4 ) - ( strlen(str) >> 1 );

	VDP_setTextPalette ( pal );

	drawText( str, x, y );

	y += inc;
}



void screen_credits ( )
{
	if ( DEV ) return;

	displayOff(0);
	VDP_setScreenWidth320( );
	VDP_setPlanSize ( 64, 32 );
	vram_init ( VRAM_DEFAULT );
	font_load ( 1 );
	resetScroll ( );
	resetScreen ( );

	preparePal ( PAL0, (u16*) palette_black );
	preparePal ( PAL1, (u16*) palette_get(6)->data );
	prepareColor ( PAL1 * 16 + 1, 0xf0f );
	prepareColor ( PAL2 * 16 + 1, 0xf88 );

	y = 9;

	write ( "L'Abbaye des morts for", PAL1, 1 );
	write ( "Sega Genesis / Megadrive", PAL1, 1 );
	write ( "Mun @MoonWatcherMD", PAL2, 1  );
	write ( "2011 - 2017", PAL2, 3  );

	write ( "Original game", PAL1, 1 );
	write ( "Locomalito & Gryzor87", PAL2, 1 );
	write ( "2010", PAL2, 9 );

	write ( "Made with Stef's SGDK", PAL1, 0 );


	displayOn ( 10 );
	waitJoySc ( 6 );

	if ( joy1_pressed_abc || joy1_pressed_start )
	{
		goto end;
	}

	displayOff ( 10 );
	resetScreen ( );

	y = 1;





	write ( "MSX skin", PAL1, 1 );
	write ( "Gerardo Herce @pipagerardo", PAL2, 2  );

	write ( "GB, CGA & PCW skins", PAL1, 1 );
	write ( "Felipe Monge @vakapp", PAL2, 2 );

	write ( "Megadrive skin", PAL1, 1 );
	write ( "Daniel Nevado @DanySnowyman", PAL2, 2 );

	write ( "C64 skin & music", PAL1, 1 );
	write ( "Igor Errazkin @Errazking", PAL2, 1 );
	write ( "Manuel Gomez 'Baron Ashler'", PAL2, 2 );

	write ( "Music & SFX", PAL1, 1 );
	write ( "'DaRkHoRaCe' @oongamoonga", PAL2, 2 );

	write ( "Testers", PAL1, 1 );
	write ( "Alfonso Martinez @_SrPresley_", PAL2, 1 );
	write ( "Ruben Vaquer @TitoAdol3", PAL2, 1 );
	write ( "Jimy @TodoMegaDrive", PAL2, 2 );

	write ( "Special thanks to", PAL1, 1 );
	write ( "Leander @leanderpixel", PAL2, 1 );
	write ( "Stef @MegadriveDev", PAL2, 1 );
	write ( "Jose Zanni @josepzin", PAL2, 1 );
	write ( "David Lara @nevat", PAL2, 3 );

	displayOn ( 10 );
	waitJoySc ( 10 );





end:

	displayOff ( 10 );
	vram_destroy();
}

