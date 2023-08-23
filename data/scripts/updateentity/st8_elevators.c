void main()
{//Suicide if your caller is a Parent and with a specific Animation
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "parent");
	void tAniID = getentityproperty(target, "animationID");
	
	if(tAniID == openborconstant("ANI_FOLLOW6"))
	{
		killentity(self);
	}
}