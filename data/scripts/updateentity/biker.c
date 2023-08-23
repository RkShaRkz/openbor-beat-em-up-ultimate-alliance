void main()
{
	grenade();
	zLimit();
}

void grenade()
{// Throw Grenade with RANGE and HEALTH check (MOTO ENEMY)
    void self 	= getlocalvar("self");
	void target = findtarget(self);
	int Health 	= getentityproperty(self,"health");
	int x 		= getentityproperty(self, "x");
	int z 		= getentityproperty(self, "z");
	int Tx 		= getentityproperty(target, "x");
	int Tz 		= getentityproperty(target, "z");
	
	if(Health >=1 ){
		if(Tx <= x && Tx >= x-2 && Tz <= z+999 && Tz >= z-999)
		{
			executeanimation(self, openborconstant("ANI_FOLLOW1"), 1);
		}
	}
}

void zLimit()
{// Limit Z in st6b (MOTO/BIKERCOP)
    void self 	= getlocalvar("self");
	int z 		= getentityproperty(self, "z");
	int stage 	= openborvariant("current_stage");
	int level 	= openborvariant("current_level");
	int iR 		= rand()%99;
	int zR;
	
	if(iR >= 0 && iR <= 19){
		zR = 410;
	} else if(iR >= 20 && iR <= 39){
		zR = 420;
	} else if(iR >= 40 && iR <= 59){
		zR = 440;
	} else if(iR >= 60 && iR <= 79){
		zR = 450;
	} else if(iR >= 80 && iR <= 99){
		zR = 460;
	} else {
		zR = 430;
	}
	
	if(stage == 6 && level == 21){
		if(z <= 419)
		{
			changeentityproperty(self, "z", zR);
		}
	}
}