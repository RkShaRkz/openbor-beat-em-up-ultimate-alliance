void main()
{
	laughSeated();
}

void laughSeated()
{// Mrx laugh seated 
    void self 		= getlocalvar("self");
	void target1 	= getplayerproperty(0, "entity");
	void target2 	= getplayerproperty(1, "entity");
	void target3 	= getplayerproperty(2, "entity");
	void target4 	= getplayerproperty(3, "entity");
	void vAniID		= getentityproperty(self, "animationID");
	int iHealth 	= getentityproperty(self, "health");
	int tHealth1	= getentityproperty(target1, "health");
	int tHealth2	= getentityproperty(target2, "health");
	int tHealth3	= getentityproperty(target3, "health");
	int tHealth4	= getentityproperty(target4, "health");
	
	if(tHealth1 >= 1 && iHealth >=1)
    {
		setlocalvar("counter1",0);
    }
	
	if(tHealth2 >= 1 && iHealth >=1)
    {
		setlocalvar("counter2",0);
    }
	
	if(tHealth3 >= 1 && iHealth >=1)
    {
		setlocalvar("counter3",0);
    }
	
	if(tHealth4 >= 1 && iHealth >=1)
    {
		setlocalvar("counter4",0);
    }
	
	if(tHealth1 <= 0 && iHealth >=1){
		if(vAniID == openborconstant("ANI_FOLLOW3")){
			void counter1 = getlocalvar("counter1");
			while(counter1!=1)
			{
				clearlocalvar();
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
				counter1 = setlocalvar("counter1", 1);
			}
		} 
	} else if(tHealth2 <= 0 && iHealth >=1){
		if(vAniID == openborconstant("ANI_FOLLOW3")){
			void counter2 = getlocalvar("counter2");
			while(counter2!=1)
			{
				clearlocalvar();
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
				counter2 = setlocalvar("counter2", 1);
			}
		} 
	} else if(tHealth3 <= 0 && iHealth >=1){
		if(vAniID == openborconstant("ANI_FOLLOW3")){
			void counter3 = getlocalvar("counter3");
			while(counter3!=1)
			{
				clearlocalvar();
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
				counter3 = setlocalvar("counter3", 1);
			}
		} 
	} else if(tHealth4 <= 0 && iHealth >=1){
		if(vAniID == openborconstant("ANI_FOLLOW3")){
			void counter4 = getlocalvar("counter4");
			while(counter4!=1)
			{
				clearlocalvar();
				changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW4"));
				counter4 = setlocalvar("counter4", 1);
			}
		} 
	}
}