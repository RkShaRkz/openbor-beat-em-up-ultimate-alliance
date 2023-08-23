#import "data/scripts/updateentity/main.c"

void main()
{//Suicide if your caller is a Parent and with a specific Animation and Frame
	void self 	= getlocalvar("self");
	void target = getentityproperty(self, "parent");
	void tAniID = getentityproperty(target,"animationID");
	int Frame 	= getentityproperty(target,"animpos");
	
	if(tAniID == openborconstant("ANI_PAIN")||
	   tAniID == openborconstant("ANI_PAIN2")||
	   tAniID == openborconstant("ANI_FALL")||
	   tAniID == openborconstant("ANI_FALL6")||
	   tAniID == openborconstant("ANI_FALL7")||
	   tAniID == openborconstant("ANI_FALL8")||
	   tAniID == openborconstant("ANI_FALL9")||
	   tAniID == openborconstant("ANI_GRABBED")){
	   if(Frame == 0)
		{
			spawn01("burn", 0, 0 ,0);
			killentity(self);
		}
	}
}