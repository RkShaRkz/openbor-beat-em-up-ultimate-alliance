void main()
{//Suicide if your caller is a Owner and with a specific Animation and frame
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "owner");
	void tAniID = getentityproperty(target, "animationID");
	int Frame 	= getentityproperty(target, "animpos");
	
	if(tAniID == openborconstant("ANI_FREESPECIAL") ||
	   tAniID == openborconstant("ANI_FREESPECIAL2")){
		if(Frame >= 2 )
		{
			killentity(self);
		}
	}
}