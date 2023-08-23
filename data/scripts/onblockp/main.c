void platform()
{//Up plataforms(ST7A)
	void self 	= getlocalvar("self");
	int stage 	= openborvariant("current_stage");
	int level 	= openborvariant("current_level");
	int x 		= getentityproperty(self, "x");
	int y 		= getentityproperty(self, "y");
	int z 		= getentityproperty(self, "z");
	
	if(stage == 7 && level == 22){
		if(x > 0 	&& x < 510
		|| x > 900 	&& x < 1150 && z < 250
		|| x > 1151 && x < 1250
		|| x > 1251 && x < 1400 && z > 240
		|| x > 1401	&& x < 1725
		|| x > 1726	&& x < 1850 && z > 240
		|| x > 1851 && y <= 0)
		{
			tossentity(self, 0.1, 0, 0);
		} 
	}
}