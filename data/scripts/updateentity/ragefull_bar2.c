void main()
{// Animation changer with MP check
	void self 	= getlocalvar("self");
    void target = getplayerproperty(1, "entity");
	int tLives	= getplayerproperty(1, "lives");
	int THp 	= getentityproperty(target, "health");
	int TMp		= getentityproperty(target, "mp");
	
	if(TMp <= 119)
    {
		setlocalvar("counter0",0);
    }
	
	if(TMp <= 79)
    {
		setlocalvar("counter1",0);
    }
	
	if(TMp <= 39)
    {
		setlocalvar("counter2",0);
    }
	
	if(TMp >= 40)
    {
		setlocalvar("counter3",0);
    }
	
	if(THp >= 1 && TMp >= 120)
	{
		void counter0 = getlocalvar("counter0");
		while(counter0!=1)
		{
		clearlocalvar();
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW3"));
		counter0 = setlocalvar("counter0", 1);
		} 
	} else if(THp >= 1 && TMp >= 80 && TMp <= 119)
	{
		void counter1 = getlocalvar("counter1");
		while(counter1!=1)
		{
		clearlocalvar();
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW2"));
		counter1 = setlocalvar("counter1", 1);
		} 
	} else if(THp >= 1 && TMp >= 40 && TMp <= 79)
	{
		void counter2 = getlocalvar("counter2");
		while(counter2!=1)
		{
		clearlocalvar();
		changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
		counter2 = setlocalvar("counter2", 1);
		} 
	} else if(THp >= 1 && TMp <= 39 || THp <= 0 || tLives <= 0)
	{
		void counter3 = getlocalvar("counter3");
		while(counter3!=1)
		{
		clearlocalvar();
		changeentityproperty(self, "animation", openborconstant("ANI_IDLE"));
		counter3 = setlocalvar("counter3", 1);
		}
	}
}