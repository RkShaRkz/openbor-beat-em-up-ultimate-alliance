void main()
{
	bindBoss1();
	bindBoss2();
}

void bindBoss1()
{//Bind defined Entity in st8b elevator
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void target = findtarget(self);
	void tName 	= getentityproperty(target, "defaultname");
	
	if(tName == "Mrx0" && vAniID != openborconstant("ANI_FOLLOW6"))
	{
		clearlocalvar();
		bindentity(target, self, 235, -546, 0, 0);
		setlocalvar("counter0",0);
	}
	if(tName == "Mrx0" && vAniID == openborconstant("ANI_FOLLOW6"))
	{
		void counter0 = getlocalvar("counter0");
		while(counter0!=1)
		{
			bindentity(target, NULL());
			counter0 = setlocalvar("counter0", 1);
		}
	}
}

void bindBoss2()
{//Bind defined Entity in st8b elevator
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self,"animationID");
	void target = findtarget(self);
	void tName 	= getentityproperty(target, "defaultname");
	
	if(tName == "Shiva0" && vAniID != openborconstant("ANI_FOLLOW6"))
	{
		clearlocalvar();
		bindentity(target, self, 295, -553, 0, 0);
		setlocalvar("counter1",0);
	}
	if(tName == "Shiva0" && vAniID == openborconstant("ANI_FOLLOW6"))
	{
		void counter1 = getlocalvar("counter1");
		while(counter1!=1)
		{
			bindentity(target, NULL());
			counter1 = setlocalvar("counter1", 1);
		}
	}
}