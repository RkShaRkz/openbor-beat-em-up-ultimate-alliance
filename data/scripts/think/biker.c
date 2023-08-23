void main()
{//Set idle if no grab
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	void vAniID = getentityproperty(self, "animationID");

	if(vAniID == openborconstant("ANI_GRAB")){
		if(target == NULL())
		{
			setidle(self);
		}
	}
}