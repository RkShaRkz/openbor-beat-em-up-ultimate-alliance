void main()
{// Animation changer with Player check
	void self 	= getlocalvar("self");
	int tLives	= getplayerproperty(3, "lives");
	
	if(tLives <= 0)
	{
		changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
	}else if(tLives >= 1)
	{
		changeentityproperty(self, "animation", openborconstant("ANI_IDLE2"));
	}
}