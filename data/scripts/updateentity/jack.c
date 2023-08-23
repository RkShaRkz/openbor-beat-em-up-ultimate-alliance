void main()
{
	jack();
	jack0();
	jack1();
	jack2();
}

void jack()
{//Damage self to reset weapon status
	void self 	= getlocalvar("self");
    void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	
	if(vModel != "Jack")
    {
		setlocalvar("counter",0);
    }
	
	
	if(vModel == "Jack" && vAniID == openborconstant("ANI_WALK"))
	{
		void counter = getlocalvar("counter");
		while(counter!=1)
		{
		clearlocalvar();
		damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL3"));
		counter = setlocalvar("counter", 1);
		} 
	}
}

void jack0()
{//Damage self to reset weapon status
	void self 	= getlocalvar("self");
    void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	
	if(vModel != "Jack0")
    {
		setlocalvar("counter0",1);
    }
	
	
	if(vModel == "Jack0" && vAniID == openborconstant("ANI_WALK"))
	{
		void counter0 = getlocalvar("counter0");
		while(counter0!=1)
		{
		clearlocalvar();
		damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL3"));
		counter0 = setlocalvar("counter0", 1);
		} 
	}
}

void jack1()
{//Damage self to reset weapon status
	void self 	= getlocalvar("self");
    void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	
	if(vModel != "Jack1")
    {
		setlocalvar("counter1",0);
    }
	
	
	if(vModel == "Jack1" && vAniID == openborconstant("ANI_WALK"))
	{
		void counter1 = getlocalvar("counter1");
		while(counter1!=1)
		{
		clearlocalvar();
		damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL3"));
		counter1 = setlocalvar("counter1", 1);
		} 
	}
}

void jack2()
{//Damage self to reset weapon status
	void self 	= getlocalvar("self");
    void vModel	= getentityproperty(self,"model");
	void vAniID = getentityproperty(self,"animationID");
	
	if(vModel != "Jack2")
    {
		setlocalvar("counter2",0);
    }
	
	
	if(vModel == "Jack2" && vAniID == openborconstant("ANI_WALK"))
	{
		void counter2 = getlocalvar("counter2");
		while(counter2!=1)
		{
		clearlocalvar();
		damageentity(self, self, 0, 0, openborconstant("ATK_NORMAL3"));
		counter2 = setlocalvar("counter2", 1);
		} 
	}
}