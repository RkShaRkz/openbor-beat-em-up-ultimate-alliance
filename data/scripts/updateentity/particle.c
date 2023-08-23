#import "data/scripts/updateentity/main.c"

void main()
{
	rageS();
}

void rageS()
{//Shadow copy frame for Rage
	void self 	= getlocalvar("self");
	void vAniID = getentityproperty(self, "animationID");
	int Frame	= getentityproperty(self, "animpos");
	void vSpawn1;
	void vSpawn2;
	
	if(vAniID == openborconstant("ANI_FREESPECIAL4"))
	{
		vSpawn1 = spawn01("ParticleS", -2, 0, -1);
		vSpawn2 = spawn01("ParticleS", 2, 0, -1);
		changeentityproperty(vSpawn1, "parent", self);
		changeentityproperty(vSpawn2, "parent", self);
		changeentityproperty(vSpawn1, "animation", openborconstant("ANI_IDLE"));
		changeentityproperty(vSpawn2, "animation", openborconstant("ANI_IDLE"));
		updateframe(vSpawn1, Frame);
		updateframe(vSpawn2, Frame);
	}
}