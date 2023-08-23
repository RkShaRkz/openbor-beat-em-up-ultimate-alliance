void main() 
{//Animation changer with Parent caller animation check using spawnbind
 //AniT: Target animation
 //AniC: self animation to Change
 //JACK SHADOW SPAWNED KNIFE
    void self 	= getlocalvar("self");
	void target = getentityproperty(self, "parent");
	void vAniID = getentityproperty(self,"animationID");
	void tAniID = getentityproperty(target,"animationID");
	
	if(vAniID == openborconstant("ANI_IDLE")){
		if(tAniID == openborconstant("ANI_PAIN")||
		   tAniID == openborconstant("ANI_PAIN2")||
		   tAniID == openborconstant("ANI_GRABBED")||
		   tAniID == openborconstant("ANI_FALL")||
		   tAniID == openborconstant("ANI_FALL6")||
		   tAniID == openborconstant("ANI_FALL7")||
		   tAniID == openborconstant("ANI_FALL8")||
		   tAniID == openborconstant("ANI_FALL9"))
		{
			changeentityproperty(self, "animation", openborconstant("ANI_FOLLOW1"));
		}
	}
	
	if(vAniID == openborconstant("ANI_IDLE")){
		if(tAniID == openborconstant("ANI_ATTACK2")||
		   tAniID == openborconstant("ANI_SPECIAL"))
		{
			killentity(self);
		}
	}
}