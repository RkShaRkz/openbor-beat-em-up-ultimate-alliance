#import "data/scripts/updateentity/main.c"

void main()
{
	rageS();
	grabIdle();
}

void rageS()
{//Shadow copy frame for Rage
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self, "animationID");
	int Frame	= getentityproperty(self, "animpos");
	void vSpawn1;
	void vSpawn2;
	
	if(vAniID == openborconstant("ANI_FREESPECIAL"))
	{
		vSpawn1 = spawn01("Baby2S", -2, 0, -1);
		vSpawn2 = spawn01("Baby2S", 2, 0, -1);
		changeentityproperty(vSpawn1, "parent", self);
		changeentityproperty(vSpawn2, "parent", self);
		updateframe(vSpawn1, Frame);
		updateframe(vSpawn2, Frame);
	}
}

void grabIdle()
{//Set idle if no grab
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "grabbing");
	void vAniID = getentityproperty(self, "animationID");

	if(vAniID == openborconstant("ANI_GRABATTACK")){
		if(target == NULL())
		{
			setidle(self);
		}
	}
}