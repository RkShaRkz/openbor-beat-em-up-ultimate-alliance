#import "data/scripts/updateentity/main.c"

void main()
{//Spawn Smoke every 2 frames
	void self 	= getlocalvar("self");
	int Frame	= getentityproperty(self, "animpos");
	
	if(Frame == 1 ||
	   Frame == 3 ||
	   Frame == 5 ||
	   Frame == 7 ||
	   Frame == 9 ||
	   Frame == 11 ||
	   Frame == 13 ||
	   Frame == 15 ||
	   Frame == 17 ||
	   Frame == 19 ||
	   Frame == 21 ||
	   Frame == 23 ||
	   Frame == 25 ||
	   Frame == 27)
	{
		spawn01("smoke", 0, 0, 0);
	}
}